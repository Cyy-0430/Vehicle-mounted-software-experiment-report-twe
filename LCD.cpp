//
// Created by Zephyrus-Desktop on 2024/10/8.
//
#include "LCD.h"

#include <fstream>
#include <iostream>

void LCD::set_size(double size) {
    this->size = size;
}

void LCD::set_model(const string &model) {
    this->model = model;
}

void LCD::print() const {
    using namespace std;
    cout << "液晶显示屏" << endl
            << "\t尺寸：" << size << endl
            << "\t型号：" << model << endl;
}

void LCD::save() const {
    std::ofstream fileLCD;
    fileLCD.open("lcd.txt");

    fileLCD << model << " " << size << std::endl;
    fileLCD.close();
}

void LCD::load() {
    std::ifstream lcdFile;
    lcdFile.open("lcd.txt");

    lcdFile >> model >> size;
    lcdFile.close();
}
