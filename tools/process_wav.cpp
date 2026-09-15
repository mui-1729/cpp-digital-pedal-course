#include "dsp/PedalEngine.h"

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstring>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

namespace {

struct WavData {
    std::uint16_t channels = 0;
    std::uint32_t sampleRate = 0;
    std::vector<std::int16_t> samples;
};

template <typename T>
T ReadValue(std::istream& in) {
    T value{};
    in.read(reinterpret_cast<char*>(&value), sizeof(value));
    if (!in) throw std::runtime_error("unexpected end of file");
    return value;
}

void ExpectTag(std::istream& in, const char* expected) {
    char tag[4]{};
    in.read(tag, 4);
    if (!in || std::memcmp(tag, expected, 4) != 0) {
        throw std::runtime_error(std::string("expected tag: ") + std::string(expected, 4));
    }
}

WavData ReadPcm16Wav(const std::string& path) {
    std::ifstream in(path, std::ios::binary);
    if (!in) throw std::runtime_error("cannot open input: " + path);

    ExpectTag(in, "RIFF");
    (void) ReadValue<std::uint32_t>(in);
    ExpectTag(in, "WAVE");

    bool haveFmt = false;
    bool haveData = false;
    std::uint16_t audioFormat = 0;
    std::uint16_t channels = 0;
    std::uint32_t sampleRate = 0;
    std::uint16_t bitsPerSample = 0;
    std::vector<std::int16_t> samples;

    while (in && !(haveFmt && haveData)) {
        char id[4]{};
        in.read(id, 4);
        if (!in) break;
        const auto chunkSize = ReadValue<std::uint32_t>(in);

        if (std::memcmp(id, "fmt ", 4) == 0) {
            if (chunkSize < 16) throw std::runtime_error("invalid fmt chunk");
            audioFormat = ReadValue<std::uint16_t>(in);
            channels = ReadValue<std::uint16_t>(in);
            sampleRate = ReadValue<std::uint32_t>(in);
            (void) ReadValue<std::uint32_t>(in); // byte rate
            (void) ReadValue<std::uint16_t>(in); // block align
            bitsPerSample = ReadValue<std::uint16_t>(in);
            if (chunkSize > 16) in.seekg(static_cast<std::streamoff>(chunkSize - 16), std::ios::cur);
            haveFmt = true;
        } else if (std::memcmp(id, "data", 4) == 0) {
            if (chunkSize % sizeof(std::int16_t) != 0) {
                throw std::runtime_error("data chunk is not aligned to 16-bit samples");
            }
            samples.resize(chunkSize / sizeof(std::int16_t));
            in.read(reinterpret_cast<char*>(samples.data()), static_cast<std::streamsize>(chunkSize));
            if (!in) throw std::runtime_error("truncated data chunk");
            haveData = true;
        } else {
            in.seekg(static_cast<std::streamoff>(chunkSize), std::ios::cur);
        }

        if ((chunkSize & 1U) != 0U) in.seekg(1, std::ios::cur);
    }

    if (!haveFmt || !haveData) throw std::runtime_error("missing fmt or data chunk");
    if (audioFormat != 1 || bitsPerSample != 16) {
        throw std::runtime_error("only PCM 16-bit WAV is supported");
    }
    if (channels < 1 || channels > 2) {
        throw std::runtime_error("only mono/stereo WAV is supported");
    }
    if (sampleRate == 0) throw std::runtime_error("invalid sample rate");
    if (samples.size() % channels != 0) throw std::runtime_error("invalid interleaved sample count");

    return {channels, sampleRate, std::move(samples)};
}

void WritePcm16Wav(const std::string& path, const WavData& wav) {
    std::ofstream out(path, std::ios::binary);
    if (!out) throw std::runtime_error("cannot open output: " + path);

    const std::uint16_t bitsPerSample = 16;
    const std::uint16_t blockAlign = static_cast<std::uint16_t>(wav.channels * sizeof(std::int16_t));
    const std::uint32_t byteRate = wav.sampleRate * blockAlign;
    const std::uint32_t dataBytes = static_cast<std::uint32_t>(wav.samples.size() * sizeof(std::int16_t));
    const std::uint32_t riffSize = 36U + dataBytes;
    const std::uint32_t fmtSize = 16U;
    const std::uint16_t pcm = 1;

    auto write = [&](const auto& value) {
        out.write(reinterpret_cast<const char*>(&value), sizeof(value));
    };

    out.write("RIFF", 4); write(riffSize); out.write("WAVE", 4);
    out.write("fmt ", 4); write(fmtSize); write(pcm); write(wav.channels);
    write(wav.sampleRate); write(byteRate); write(blockAlign); write(bitsPerSample);
    out.write("data", 4); write(dataBytes);
    out.write(reinterpret_cast<const char*>(wav.samples.data()), static_cast<std::streamsize>(dataBytes));

    if (!out) throw std::runtime_error("failed while writing output");
}

float ParseFloat(const char* text, const char* name) {
    try {
        std::size_t used = 0;
        const float value = std::stof(text, &used);
        if (used != std::strlen(text) || !std::isfinite(value)) throw std::runtime_error("bad");
        return value;
    } catch (...) {
        throw std::runtime_error(std::string("invalid ") + name + ": " + text);
    }
}

} // namespace

int main(int argc, char** argv) {
    if (argc < 3 || argc > 7) {
        std::cerr << "usage: process_wav INPUT.wav OUTPUT.wav [drive] [sat] [tone] [level]\n";
        return 2;
    }

    try {
        const float drive = argc > 3 ? ParseFloat(argv[3], "drive") : 4.0f;
        const float sat = argc > 4 ? ParseFloat(argv[4], "sat") : 0.6f;
        const float tone = argc > 5 ? ParseFloat(argv[5], "tone") : 0.6f;
        const float level = argc > 6 ? ParseFloat(argv[6], "level") : 0.7f;

        auto wav = ReadPcm16Wav(argv[1]);
        std::vector<pedal::PedalEngine> engines(wav.channels);
        for (auto& engine : engines) {
            engine.Prepare(static_cast<float>(wav.sampleRate));
            engine.SetDrive(drive);
            engine.SetSaturation(sat);
            engine.SetTone(tone);
            engine.SetLevel(level);
        }

        for (std::size_t i = 0; i < wav.samples.size(); i += wav.channels) {
            for (std::size_t ch = 0; ch < wav.channels; ++ch) {
                const float input = static_cast<float>(wav.samples[i + ch]) / 32768.0f;
                const float output = std::clamp(engines[ch].Process(input), -1.0f, 1.0f);
                wav.samples[i + ch] = static_cast<std::int16_t>(std::lrint(output * 32767.0f));
            }
        }

        WritePcm16Wav(argv[2], wav);
        std::cout << "wrote " << argv[2] << " (" << wav.channels << "ch, "
                  << wav.sampleRate << " Hz)\n";
    } catch (const std::exception& e) {
        std::cerr << "error: " << e.what() << '\n';
        return 1;
    }

    return 0;
}
