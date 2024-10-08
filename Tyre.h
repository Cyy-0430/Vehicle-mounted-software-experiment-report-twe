//
// Created by Zephyrus-Desktop on 2024/10/8.
//

#ifndef TYRE_H
#define TYRE_H

#include <string>

using std::string;

class Tyre {
    string model;
    string size;

public:
    void set_model(const string &model);

    void set_size(const string &size);

    void print() const;

    void save() const;

    void load();
};


#endif //TYRE_H
