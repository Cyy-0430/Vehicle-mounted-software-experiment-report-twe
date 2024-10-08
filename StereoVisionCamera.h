//
// Created by Zephyrus-Desktop on 2024/10/7.
//

#ifndef STEREOVISIONCAMERA_H
#define STEREOVISIONCAMERA_H

#include <string>

using std::string;

struct StereoVisionCamera {
    string model;
    string camera;
    string rgb_frame_resolution;
    int rgb_fps;
    string fov;
    int deep_fps;
};

#endif //STEREOVISIONCAMERA_H
