//
// Created by Zephyrus-Desktop on 2024/10/7.
//
#include "SmartCar.h"

#include <fstream>

#include "LCD.h"
#include "Student.h"

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

    Tyre tyres[4] = {
        {"公路轮、麦克纳姆轮", "175mm"},
        {"公路轮、麦克纳姆轮", "175mm"},
        {"公路轮、麦克纳姆轮", "175mm"},
        {"公路轮、麦克纳姆轮", "175mm"},
    };

    std::ofstream fileTyres;
    fileTyres.open("tyres.txt");
    for (auto &i: tyres) {
        fileTyres << i.model << " " << i.size << std::endl;
    }
    fileTyres.close();

    Chassis chassis = {
        "dp2oZUCZ6q",
        "SCOUT_MINI",
        "451mm",
        "490mm",
        "115mm",
        "0m",
        "四轮四驱",
        "10KM",
        tyres[0], tyres[1], tyres[2], tyres[3],
    };

    std::ofstream fileChassis;
    fileChassis.open("chassis.txt");


    fileChassis << chassis.id << " " << chassis.model
            << " " << chassis.wheel_base << " " << chassis.wheel_track
            << " " << chassis.minimum_ground_clearance << " " << chassis.minimum_turning_radius
            << " " << chassis.driving_form << " " << chassis.maximum_stroke
            << std::endl;
    fileChassis.close();


    AGXKit agx_kit = {
        "AGX-Xavier",
        "32_TOPS",
        512,
        64,
        "32G",
        "32G",
    };

    std::ofstream fileAGX;
    fileAGX.open("agx.txt");

    fileAGX << agx_kit.model << " " << agx_kit.ai
            << " " << agx_kit.cuda_cores << " " << agx_kit.tensor_core
            << " " << agx_kit.video_memory << " " << agx_kit.storage << std::endl;
    fileAGX.close();


    StereoVisionCamera stereo_camera = {
        "RealSense_D435i",
        "D430",
        "1920*1080",
        30,
        "87*58",
        90,
    };

    std::ofstream fileStereo;
    fileStereo.open("stereo.txt");

    fileStereo << stereo_camera.model << " " << stereo_camera.camera
            << " " << stereo_camera.rgb_frame_resolution << " " << stereo_camera.rgb_fps
            << " " << stereo_camera.fov << " " << stereo_camera.deep_fps << std::endl;
    fileStereo.close();


    MultiLineLidar multiLineLidar = {
        "RS-Helios-16p",
        16,
        "100m",
        "8w",
    };

    std::ofstream fileMultiLineLidar;
    fileMultiLineLidar.open("multiLineLidar.txt");

    fileMultiLineLidar << multiLineLidar.model << " " << multiLineLidar.channel
            << " " << multiLineLidar.test_range << " " << multiLineLidar.power << std::endl;
    fileMultiLineLidar.close();

    NineAxisGyroscope nineAxisGyroscope = {
        "CH110",
        "NXP",
    };

    std::ofstream fileNineAxisGyroscope;
    fileNineAxisGyroscope.open("nineAxisGyroscope.txt");

    fileNineAxisGyroscope << nineAxisGyroscope.model
            << " " << nineAxisGyroscope.manufacturers << std::endl;
    fileNineAxisGyroscope.close();

    LCD lcd = {
        11.6,
        "super"
    };

    std::ofstream fileLCD;
    fileLCD.open("lcd.txt");

    fileLCD << lcd.size << " " << lcd.model << std::endl;
    fileLCD.close();

    BatteryModule batteryModule = {
        "24V/15Ah",
        "24v",
        "2H",
    };

    std::ofstream fileBattery;

    fileBattery.open("battery.txt");

    fileBattery << batteryModule.parameter << " " << batteryModule.external_power_supply
            << " " << batteryModule.charging_time << std::endl;
    fileBattery.close();

    SmartCar smart_car = {
        "cquen-xxx",
        chassis,
        agx_kit,
        stereo_camera,
        multiLineLidar,
        nineAxisGyroscope,
        lcd,
        batteryModule,
    };
}


std::vector<SmartCar> load_smart_car_data() {
    std::ifstream tyresFile;
    tyresFile.open("tyres.txt");

    Tyre tyres[4];

    for (auto & i : tyres) {
        tyresFile >> i.size >> i.model;
    }
    tyresFile.close();


    std::ifstream chassisFile;
    chassisFile.open("chassis.txt");

    Chassis chassis;

    chassis.tyre[0] = tyres[0];
    chassis.tyre[1] = tyres[1];
    chassis.tyre[2] = tyres[2];
    chassis.tyre[3] = tyres[3];


    chassisFile >> chassis.id >> chassis.model
    >> chassis.wheel_base >> chassis.wheel_track
    >> chassis.minimum_ground_clearance
    >> chassis.minimum_turning_radius
    >> chassis.driving_form >> chassis.maximum_stroke;
    chassisFile.close();



    std::ifstream agxFile;
    agxFile.open("agx.txt");

    AGXKit agx_kit;

    agxFile >> agx_kit.model >> agx_kit.ai
    >> agx_kit.cuda_cores >> agx_kit.tensor_core
    >> agx_kit.video_memory >> agx_kit.storage;

    agxFile.close();

    std::ifstream stereoFile;
    stereoFile.open("stereo.txt");

    StereoVisionCamera stereo_camera;

    stereoFile >> stereo_camera.model >> stereo_camera.camera
    >> stereo_camera.rgb_frame_resolution >> stereo_camera.rgb_fps
    >> stereo_camera.fov >> stereo_camera.deep_fps;

    stereoFile.close();


    std::ifstream multiLineLidarFile;
    multiLineLidarFile.open("multiLineLidar.txt");

    MultiLineLidar multiLineLidar;

    multiLineLidarFile >> multiLineLidar.model >> multiLineLidar.channel
    >> multiLineLidar.test_range >> multiLineLidar.power;
    multiLineLidarFile.close();


    std::ifstream nineAxisGyroscopeFile;
    nineAxisGyroscopeFile.open("nineAxisGyroscope.txt");

    NineAxisGyroscope nineAxisGyroscope;

    nineAxisGyroscopeFile >> nineAxisGyroscope.model >> nineAxisGyroscope.manufacturers;
    nineAxisGyroscopeFile.close();


    std::ifstream lcdFile;
    lcdFile.open("lcd.txt");

    LCD lcd;

    lcdFile >> lcd.size >> lcd.model;
    lcdFile.close();


    std::ifstream batteryFile;
    batteryFile.open("battery.txt");

    BatteryModule batteryModule;

    batteryFile >> batteryModule.parameter >> batteryModule.external_power_supply
    >> batteryModule.charging_time;
    batteryFile.close();

    std::vector<SmartCar> smartCars;

    std::ifstream idsFile;
    idsFile.open("smart_car_ids.txt");

    int cnt = 10;
    while (cnt--) {
        string id;
        idsFile >> id;
        SmartCar smartCar = {
            id, chassis, agx_kit,
            stereo_camera, multiLineLidar,
            nineAxisGyroscope, lcd, batteryModule
        };

        smartCars.push_back(smartCar);
    }

    return smartCars;
}
