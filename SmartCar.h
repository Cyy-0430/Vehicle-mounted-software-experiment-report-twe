//
// Created by Zephyrus-Desktop on 2024/10/5.
//

#ifndef SMART_CAR_H
#define SMART_CAR_H

#include <string>
#include <vector>

#include "AGXKit.h"
#include "BatteryModule.h"
#include "Chassis.h"
#include "LCD.h"
#include "MultiLineLidar.h"
#include "NineAxisGyroscope.h"
#include "StereoVisionCamera.h"

using std::string;

struct SmartCar {
    string id;
    Chassis chassis;
    AGXKit agx_kit;
    StereoVisionCamera stereo_camera;
    MultiLineLidar multi_line_lidar;
    NineAxisGyroscope nine_axis_gyroscope;
    LCD lcd;
    BatteryModule battery_module;
};

void save_smart_car_data();
std::vector<SmartCar> load_smart_car_data();
#endif //SMART_CAR_H
