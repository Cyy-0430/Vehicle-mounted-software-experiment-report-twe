//
// Created by Zephyrus-Desktop on 2024/10/8.
//

#ifndef AGXKIT_H
#define AGXKIT_H

#include <string>

using std::string;

class AGXKit {
    string model;
    string ai;
    int cuda_cores;
    int tensor_core;
    string video_memory;
    string storage;

public:
    void set_model(const string &model);

    void set_ai(const string &ai);

    void set_cuda_cores(int cuda_cores);

    void set_tensor_core(int tensor_core);

    void set_video_memory(const string &video_memory);

    void set_storage(const string &storage);

    void print() const;

    void save() const;

    void load();
};



#endif //AGXKIT_H
