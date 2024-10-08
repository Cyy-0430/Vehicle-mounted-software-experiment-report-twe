//
// Created by Zephyrus-Desktop on 2024/10/8.
//
#include "MultiLineLidar.h"

#include <fstream>
#include <iostream>

void MultiLineLidar::set_model(const string &model) {
    this->model = model;
}

void MultiLineLidar::set_channel(int channel) {
    this->channel = channel;
}

void MultiLineLidar::set_test_range(const string &test_range) {
    this->test_range = test_range;
}

void MultiLineLidar::set_power(const string &power) {
    this->power = power;
}

void MultiLineLidar::print() const {
    using namespace std;
    cout<< "多线激光雷达" << endl
        << "\t型号：" << model << endl
        << "\t通道数：" << channel << endl
        << "\t测试范围：" << test_range << endl
        << "\t功耗：" << power << endl;
}

void MultiLineLidar::save() const {
    std::ofstream fileMultiLineLidar;
    fileMultiLineLidar.open("multiLineLidar.txt");

    fileMultiLineLidar << model << " " << channel
            << " " << test_range << " " << power << std::endl;
    fileMultiLineLidar.close();
}

void MultiLineLidar::load() {
    std::ifstream multiLineLidarFile;
    multiLineLidarFile.open("multiLineLidar.txt");

    multiLineLidarFile >>model >>channel
            >> test_range >> power;
    multiLineLidarFile.close();
}
