//
// Created by Zephyrus-Desktop on 2024/10/8.
//

#include "Tyre.h"

#include <fstream>
#include <iostream>
#include <ostream>

void Tyre::set_model(const string &model) {
    this->model = model;
}

void Tyre::set_size(const string &size) {
    this->size = size;
}

void Tyre::print() const {
    using namespace std;
    cout << "\t轮胎" << endl
            << "\t\t型号：" << model << endl
            << "\t\t尺寸：" << size << endl;
}

void Tyre::save() const {
    std::ofstream fileTyres;
    fileTyres.open("tyres.txt");
    fileTyres << model << " " << size << std::endl;
    fileTyres.close();
}

void Tyre::load() {
    std::ifstream tyresFile;
    tyresFile.open("tyres.txt");

    tyresFile >> model >> size;
    tyresFile.close();
}
