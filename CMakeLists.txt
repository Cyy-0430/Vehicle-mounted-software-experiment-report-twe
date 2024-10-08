cmake_minimum_required(VERSION 3.29)
project(Vehicle_mounted_software_experiment_report_two)

set(CMAKE_CXX_STANDARD 11)

add_executable(Vehicle_mounted_software_experiment_report_two main.cpp
        SmartCar.h
        Student.h
        Chassis.h
        StereoVisionCamera.h
        MultiLineLidar.h
        NineAxisGyroscope.h
        LCD.h
        Student.cpp
        SmartCar.cpp
        main.h
        AGXKit.cpp
        AGXKit.h
        BatteryModule.cpp
        BatteryModule.h
        Tyre.cpp
        Tyre.h
        Chassis.cpp
        LCD.cpp
        MultiLineLidar.cpp
        NineAxisGyroscope.cpp
        StereoVisionCamera.cpp)
