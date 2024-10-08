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

class SmartCar {
    string id;
    Chassis chassis;
    AGXKit agx_kit;
    StereoVisionCamera stereo_camera;
    MultiLineLidar multi_line_lidar;
    NineAxisGyroscope nine_axis_gyroscope;
    LCD lcd;
    BatteryModule battery_module;

public:
    void set_id(const string &id);

    void set_chassis(const Chassis &chassis);

    void set_agx_kit(const AGXKit &agx_kit);

    void set_stereo_camera(const StereoVisionCamera &stereo_camera);

    void set_multi_line_lidar(const MultiLineLidar &multi_line_lidar);

    void set_nine_axis_gyroscope(const NineAxisGyroscope &nine_axis_gyroscope);

    void set_lcd(const LCD &lcd);

    void set_battery_module(const BatteryModule &battery_module);

    void print() const;

    void save();

    void load();
};

void save_smart_car_data();

std::vector<SmartCar> load_smart_car_data();
#endif //SMART_CAR_H
