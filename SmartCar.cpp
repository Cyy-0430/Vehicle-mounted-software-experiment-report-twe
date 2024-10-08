//
// Created by Zephyrus-Desktop on 2024/10/7.
//
#include "SmartCar.h"

#include <fstream>
#include <iostream>

#include "LCD.h"
#include "Student.h"


void SmartCar::set_id(const string &id) {
    this->id = id;
}

void SmartCar::set_chassis(const Chassis &chassis) {
    this->chassis = chassis;
}

void SmartCar::set_agx_kit(const AGXKit &agx_kit) {
    this->agx_kit = agx_kit;
}

void SmartCar::set_stereo_camera(const StereoVisionCamera &stereo_camera) {
    this->stereo_camera = stereo_camera;
}

void SmartCar::set_multi_line_lidar(const MultiLineLidar &multi_line_lidar) {
    this->multi_line_lidar = multi_line_lidar;
}

void SmartCar::set_nine_axis_gyroscope(const NineAxisGyroscope &nine_axis_gyroscope) {
    this->nine_axis_gyroscope = nine_axis_gyroscope;
}

void SmartCar::set_lcd(const LCD &lcd) {
    this->lcd = lcd;
}

void SmartCar::set_battery_module(const BatteryModule &battery_module) {
    this->battery_module = battery_module;
}

void SmartCar::print() const {
    using namespace std;
    cout << "-----智能小车基本信息-----" << endl
            << "编号：" << id << endl;

    chassis.print();

    agx_kit.print();

    stereo_camera.print();

    multi_line_lidar.print();

    nine_axis_gyroscope.print();

    lcd.print();

    battery_module.print();
}


void SmartCar::save() {
    save_smart_car_data();
}

void SmartCar::load() {
    id = "Unknown";
    chassis.load();
    agx_kit.load();
    stereo_camera.load();
    multi_line_lidar.load();
    nine_axis_gyroscope.load();
    lcd.load();
    battery_module.load();
}

void save_smart_car_data() {
    string car_ids[10] = {
        "cqusnGoFBkd86Nkms5UV3",
        "cqusnoFUM0L9HfLm3dmbW",
        "cqusnpEKgeGHeZK1UCkdE",
        "cqusn8F98Kinc0xHh7RJz",
        "cqusncdLUBpbrufGD4TYQ",
        "cqusnkQeDk2Z4wvihZtA0",
        "cqusnopy5j3b1qQZMYqkF",
        "cqusnxCjBMfccisd2j2kh",
        "cqusnm9dLXBDC0KUU1YUX",
        "cqusnEn7aGGuwupNDeucU",
    };

    std::ofstream fileIds;
    fileIds.open("smart_car_ids.txt");

    for (auto &i: car_ids) {
        fileIds << i << "\n";
    }
    fileIds.close();


    std::vector<Tyre> tyres;
    for (int i = 0; i < 4; i++) {
        Tyre tyre;
        tyre.set_model("公路轮、麦克纳姆轮");
        tyre.set_size("175mm");
        tyre.save();
        tyres.push_back(tyre);
    }


    Chassis chassis;

    chassis.set_id("dp2oZUCZ6q");
    chassis.set_model("SCOUT_MINI");
    chassis.set_wheel_base("451mm");
    chassis.set_wheel_track("490mm");
    chassis.set_minimum_ground_clearance("115mm");
    chassis.set_minimum_turning_radius("0m");
    chassis.set_driving_form("四轮四驱");
    chassis.set_maximum_stroke("10KM");
    chassis.set_tyre(tyres);

    chassis.save();


    AGXKit agx_kit;

    agx_kit.set_model("AGX-Xavier");
    agx_kit.set_ai("32_TOPS");
    agx_kit.set_cuda_cores(512);
    agx_kit.set_tensor_core(64);
    agx_kit.set_storage("32G");
    agx_kit.set_video_memory("32G");

    agx_kit.save();


    StereoVisionCamera stereo_camera;

    stereo_camera.set_model("RealSense_D435i");
    stereo_camera.set_camera("D430");
    stereo_camera.set_rgb_frame_resolution("1920*1080");
    stereo_camera.set_rgb_fps(30);
    stereo_camera.set_fov("87*58");
    stereo_camera.set_deep_fps(90);

    stereo_camera.save();


    MultiLineLidar multi_line_lidar;

    multi_line_lidar.set_model("RS-Helios-16p");
    multi_line_lidar.set_channel(16);
    multi_line_lidar.set_test_range("100m");
    multi_line_lidar.set_power("8w");

    multi_line_lidar.save();


    NineAxisGyroscope nine_axis_gyroscope;

    nine_axis_gyroscope.set_model("CH110");
    nine_axis_gyroscope.set_manufacturers("NXP");

    nine_axis_gyroscope.save();


    LCD lcd;

    lcd.set_size(11.6);
    lcd.set_model("super");

    lcd.save();


    BatteryModule battery_module;

    battery_module.set_parameter("24V/15Ah");
    battery_module.set_external_power_supply("24v");
    battery_module.set_charging_time("2H");

    battery_module.save();
}


std::vector<SmartCar> load_smart_car_data() {
    std::vector<SmartCar> smartCars;

    std::ifstream idsFile;
    idsFile.open("smart_car_ids.txt");

    int cnt = 10;
    while (cnt--) {
        SmartCar smartCar;
        smartCar.load();

        string id;
        idsFile >> id;
        smartCar.set_id(id);

        smartCars.push_back(smartCar);
    }

    return smartCars;
}
