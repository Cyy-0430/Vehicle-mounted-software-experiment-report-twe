//
// Created by Zephyrus-Desktop on 2024/10/7.
//

#ifndef CHASSIS_H
#define CHASSIS_H

#include <string>

#include "Tyre.h"

using std::string;

struct Chassis {
    string id;
    string model;
    string wheel_base;
    string wheel_track;
    string minimum_ground_clearance;
    string minimum_turning_radius;
    string driving_form;
    string maximum_stroke;
    Tyre tyre[4];
};
#endif //CHASSIS_H
