//
// Created by Zephyrus-Desktop on 2024/10/8.
//

#include "BatteryModule.h"

#include <fstream>
#include <iostream>
#include <ostream>

void BatteryModule::set_parameter(const string &parameter) {
    this->parameter = parameter;
}

void BatteryModule::set_external_power_supply(const string &external_power_supply) {
    this->external_power_supply = external_power_supply;
}

void BatteryModule::set_charging_time(const string &charging_time) {
    this->charging_time = charging_time;
}

void BatteryModule::print() const {
    using namespace std;
    cout << "电池模块" << endl
            << "\t参数：" << parameter << endl
            << "\t对外供电：" << external_power_supply << endl
            << "\t充电时长：" << charging_time << endl;
}

void BatteryModule::save() const {
    std::ofstream fileBattery;

    fileBattery.open("battery.txt");

    fileBattery << parameter << " " << external_power_supply
            << " " << charging_time << std::endl;
    fileBattery.close();
}

void BatteryModule::load() {
    std::ifstream batteryFile;
    batteryFile.open("battery.txt");

    batteryFile >> parameter >> external_power_supply
            >> charging_time;
    batteryFile.close();
}
