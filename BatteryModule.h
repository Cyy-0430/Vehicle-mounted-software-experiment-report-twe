//
// Created by Zephyrus-Desktop on 2024/10/8.
//

#ifndef BATTERYMODULE_H
#define BATTERYMODULE_H

#include <string>

using std::string;

class BatteryModule {
    string parameter;
    string external_power_supply;
    string charging_time;

public:
    void set_parameter(const string &parameter);

    void set_external_power_supply(const string &external_power_supply);

    void set_charging_time(const string &charging_time);

    void print() const;

    void save() const;

    void load();
};



#endif //BATTERYMODULE_H
