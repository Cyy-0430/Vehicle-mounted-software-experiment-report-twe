//
// Created by Zephyrus-Desktop on 2024/10/8.
//
#include "Chassis.h"

#include <fstream>
#include <iostream>

void Chassis::set_tyre(const std::vector<Tyre> &tyre) {
    this->tyre = tyre;
}

void Chassis::set_id(const string &id) {
    this->id = id;
}

void Chassis::set_model(const string &model) {
    this->model = model;
}

void Chassis::set_wheel_base(const string &wheel_base) {
    this->wheel_base = wheel_base;
}

void Chassis::set_wheel_track(const string &wheel_track) {
    this->wheel_track = wheel_track;
}

void Chassis::set_minimum_ground_clearance(const string &minimum_ground_clearance) {
    this->minimum_ground_clearance = minimum_ground_clearance;
}

void Chassis::set_minimum_turning_radius(const string &minimum_turning_radius) {
    this->minimum_turning_radius = minimum_turning_radius;
}

void Chassis::set_driving_form(const string &driving_form) {
    this->driving_form = driving_form;
}

void Chassis::set_maximum_stroke(const string &maximum_stroke) {
    this->maximum_stroke = maximum_stroke;
}

void Chassis::print() const{
    using namespace std;
    cout << "底盘" << endl
        << "\t编号；" << id << endl
        << "\t型号：" << model << endl
        << "\t轴距：" << wheel_base << endl
        << "\t轮距：" << wheel_track << endl
        << "\t最小离地间隙：" << minimum_ground_clearance << endl
        << "\t最小转弯半径：" << minimum_turning_radius << endl
        << "\t驱动形式：" << maximum_stroke << endl;
        tyre[0].print();
}

void Chassis::save() const {
    std::ofstream fileChassis;
    fileChassis.open("chassis.txt");

    fileChassis << id << " " << model
            << " " << wheel_base << " " <<wheel_track
            << " " <<minimum_ground_clearance << " " << minimum_turning_radius
            << " " << driving_form << " " << maximum_stroke
            << std::endl;
    fileChassis.close();
}

void Chassis::load() {
    std::vector<Tyre> tyres;
    for (int i = 0; i < 4; i++) {
        Tyre tyre;
        tyre.load();
        tyres.push_back(tyre);
    }
    tyre = tyres;

    std::ifstream chassisFile;
    chassisFile.open("chassis.txt");

    chassisFile >> id >>model
            >>wheel_base >> wheel_track
            >> minimum_ground_clearance
            >> minimum_turning_radius
            >> driving_form >> maximum_stroke;
    chassisFile.close();
}
