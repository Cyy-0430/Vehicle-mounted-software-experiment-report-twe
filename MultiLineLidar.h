//
// Created by Zephyrus-Desktop on 2024/10/7.
//

#ifndef MULTILINELIDAR_H
#define MULTILINELIDAR_H

#include <string>

using std::string;

class MultiLineLidar {
    string model;
    int channel;
    string test_range;
    string power;

public:
    void set_model(const string &model);

    void set_channel(int channel);

    void set_test_range(const string &test_range);

    void set_power(const string &power);

    void print() const;

    void save() const;

    void load();
};
#endif //MULTILINELIDAR_H
