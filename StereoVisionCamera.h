//
// Created by Zephyrus-Desktop on 2024/10/7.
//

#ifndef STEREOVISIONCAMERA_H
#define STEREOVISIONCAMERA_H

#include <string>

using std::string;

class StereoVisionCamera {
    string model;
    string camera;
    string rgb_frame_resolution;
    int rgb_fps;
    string fov;
    int deep_fps;

public:
    void set_model(const string &model);

    void set_camera(const string &camera);

    void set_rgb_frame_resolution(const string &rgb_frame_resolution);

    void set_rgb_fps(int rgb_fps);

    void set_fov(const string &fov);

    void set_deep_fps(int deep_fps);

    void print() const;

    void save() const;

    void load();
};

#endif //STEREOVISIONCAMERA_H
