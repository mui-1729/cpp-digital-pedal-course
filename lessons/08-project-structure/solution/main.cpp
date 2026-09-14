#include "Distortion.h"
#include <iostream>

int main() {
    Distortion distortion;
    distortion.SetDrive(4.0f);
    distortion.SetMode(ClipMode::Soft);
    std::cout << distortion.Process(0.4f) << '\n';
}
