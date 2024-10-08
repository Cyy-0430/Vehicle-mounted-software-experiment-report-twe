//
// Created by Zephyrus-Desktop on 2024/10/7.
//

#ifndef AGXKIT_H
#define AGXKIT_H

#include <string>

using std::string;

struct AGXKit {
    string model;
    string ai;
    int cuda_cores;
    int tensor_core;
    string video_memory;
    string storage;
};
#endif //AGXKIT_H
