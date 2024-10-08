//
// Created by Zephyrus-Desktop on 2024/10/8.
//

#include "AGXKit.h"

#include <fstream>
#include <iostream>


void AGXKit::set_model(const string &model) {
    this->model = model;
}

void AGXKit::set_ai(const string &ai) {
    this->ai = ai;
}

void AGXKit::set_cuda_cores(const int cuda_cores) {
    this->cuda_cores = cuda_cores;
}

void AGXKit::set_tensor_core(const int tensor_core) {
    this->tensor_core = tensor_core;
}

void AGXKit::set_video_memory(const string &video_memory) {
    this->video_memory = video_memory;
}

void AGXKit::set_storage(const string &storage) {
    this->storage = storage;
}

void AGXKit::print() const {
    using namespace std;
    cout << "AGX套件" << endl
            << "\t型号：" << model << endl
            << "\tAI：" << ai << endl
            << "\tCUDA核心：" << cuda_cores << endl
            << "\tTensor CORE：" << tensor_core << endl
            << "\t显存：" << video_memory << endl
            << "\t存储：" << storage << endl;
}

void AGXKit::save() const {
    std::ofstream fileAGX;
    fileAGX.open("agx.txt");

    fileAGX << model << " " << ai
            << " " << cuda_cores << " " << tensor_core
            << " " << video_memory << " " << storage << std::endl;
    fileAGX.close();
}

void AGXKit::load() {
    std::ifstream agxFile;
    agxFile.open("agx.txt");

    agxFile >> model >> ai
            >> cuda_cores >> tensor_core
            >> video_memory >> storage;

    agxFile.close();
}
