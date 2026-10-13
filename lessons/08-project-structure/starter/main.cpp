#include "Distortion.h"
#include <iostream>

int main()
{
    Distortion distortion;

    distortion.SetDrive(4.0f);
    distortion.SetMode(ClipMode::Hard);

    float input = 0.4f;
    float output = distortion.Process(input);

    std::cout << output << '\n';
}