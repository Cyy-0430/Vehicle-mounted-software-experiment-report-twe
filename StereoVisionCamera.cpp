//
// Created by Zephyrus-Desktop on 2024/10/8.
//
#include "StereoVisionCamera.h"

#include <fstream>
#include <iostream>

void StereoVisionCamera::set_model(const string &model) {
    this->model = model;
}

void StereoVisionCamera::set_camera(const string &camera) {
    this->camera = camera;
}

void StereoVisionCamera::set_rgb_frame_resolution(const string &rgb_frame_resolution) {
    this->rgb_frame_resolution = rgb_frame_resolution;
}

void StereoVisionCamera::set_rgb_fps(int rgb_fps) {
    this->rgb_fps = rgb_fps;
}

void StereoVisionCamera::set_fov(const string &fov) {
    this->fov = fov;
}

void StereoVisionCamera::set_deep_fps(int deep_fps) {
    this->deep_fps = deep_fps;
}

void StereoVisionCamera::print() const {
    using namespace std;
    cout << "双目摄像头" << endl
        << "\t型号：" << model << endl
        << "\t摄像头：" << camera << endl
        << "\tRGB帧分辨率：" << rgb_frame_resolution << endl
        << "\tRGB帧率：" << rgb_fps << endl
        << "\tFOV：" << fov << endl
        << "\t深度帧率：" << deep_fps << endl;
}

void StereoVisionCamera::save() const {
    std::ofstream fileStereo;
    fileStereo.open("stereo.txt");

    fileStereo << model << " " << camera
            << " " << rgb_frame_resolution << " " << rgb_fps
            << " " << fov << " " << deep_fps << std::endl;
    fileStereo.close();
}

void StereoVisionCamera::load() {
    std::ifstream stereoFile;
    stereoFile.open("stereo.txt");

    stereoFile >> model >> camera
            >> rgb_frame_resolution >> rgb_fps
            >> fov >> deep_fps;

    stereoFile.close();
}
