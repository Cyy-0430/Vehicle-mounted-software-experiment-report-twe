//
// Created by Zephyrus-Desktop on 2024/10/7.
//

#ifndef CHASSIS_H
#define CHASSIS_H

#include <string>
#include <vector>

#include "Tyre.h"

using std::string;

class Chassis {
    string id;
    string model;
    string wheel_base;
    string wheel_track;
    string minimum_ground_clearance;
    string minimum_turning_radius;
    string driving_form;
    string maximum_stroke;
    std::vector<Tyre> tyre;

public:
    void set_tyre(const std::vector<Tyre> &tyre);

    void set_id(const string &id);

    void set_model(const string &model);

    void set_wheel_base(const string &wheel_base);

    void set_wheel_track(const string &wheel_track);

    void set_minimum_ground_clearance(const string &minimum_ground_clearance);

    void set_minimum_turning_radius(const string &minimum_turning_radius);

    void set_driving_form(const string &driving_form);

    void set_maximum_stroke(const string &maximum_stroke);

    void print() const;

    void save() const;

    void load();
};
#endif //CHASSIS_H
