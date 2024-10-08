cmake_minimum_required(VERSION 3.29)
project(Vehicle_mounted_software_experiment_report_one)

set(CMAKE_CXX_STANDARD 11)

add_executable(Vehicle_mounted_software_experiment_report_one main.cpp
        SmartCar.h
        Student.h
        Chassis.h
        Tyre.h
        AGXKit.h
        StereoVisionCamera.h
        MultiLineLidar.h
        NineAxisGyroscope.h
        LCD.h
        BatteryModule.h
        Student.cpp
        SmartCar.cpp
        main.h)
