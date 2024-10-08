//
// Created by Zephyrus-Desktop on 2024/10/8.
//
#include "NineAxisGyroscope.h"

#include <fstream>
#include <iostream>

void NineAxisGyroscope::set_model(const string &model) {
    this->model = model;
}

void NineAxisGyroscope::set_manufacturers(const string &manufacturers) {
    this->manufacturers = manufacturers;
}

void NineAxisGyroscope::print() const {
    using namespace std;
    cout << "九轴陀螺仪" << endl
        << "\t型号：" << model << endl
        << "\t厂家：" << manufacturers << endl;
}

void NineAxisGyroscope::save() const {
    std::ofstream fileNineAxisGyroscope;
    fileNineAxisGyroscope.open("nineAxisGyroscope.txt");

    fileNineAxisGyroscope << model
            << " " << manufacturers << std::endl;
    fileNineAxisGyroscope.close();

}

void NineAxisGyroscope::load() {
    std::ifstream nineAxisGyroscopeFile;
    nineAxisGyroscopeFile.open("nineAxisGyroscope.txt");

    nineAxisGyroscopeFile >> model >> manufacturers;
    nineAxisGyroscopeFile.close();
}
