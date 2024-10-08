//
// Created by Zephyrus-Desktop on 2024/10/7.
//

#ifndef NINE_AXIS_GYROSCOPE_H
#define NINE_AXIS_GYROSCOPE_H

#include <string>

using std::string;


class NineAxisGyroscope {
    string model;
    string manufacturers;

public:
    void set_model(const string &model);

    void set_manufacturers(const string &manufacturers);

    void print() const;

    void save() const;

    void load();
};
#endif //NINE_AXIS_GYROSCOPE_H
