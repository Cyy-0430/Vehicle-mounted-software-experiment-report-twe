#include <iostream>
#include <fstream>
#include <windows.h>

#include "SmartCar.h"
#include "Student.h"
#include "main.h"

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);

    save_data();

    vector<Student> students = load_student_data();
    vector<SmartCar> smart_cars = load_smart_car_data();

    int idx = 0;
    while (idx < 10) {
        show(students[idx], smart_cars[idx]);

        cout << "输入 p 显示上一辆小车信息，输入 q 显示下一辆小车信息：";
        char ch;
        cin >> ch;

        switch (ch) {
            case 'n':
                if (idx != 9) idx++;
                break;
            case 'p':
                if (idx != 0) idx--;
                break;
            default:
                break;
        }
    }

    return 0;
}

void save_data() {
    save_student_data();
    save_smart_car_data();
}

void show(const Student& student, const SmartCar& smartCar) {
    cout << "-----智能小车基本信息-----" << endl
        << "编号：" << smartCar.id << endl
        << "底盘" << endl
        << "\t编号；" << smartCar.chassis.id << endl
        << "\t型号：" << smartCar.chassis.model << endl
        << "\t轴距：" << smartCar.chassis.wheel_base << endl
        << "\t轮距：" << smartCar.chassis.wheel_track << endl
        << "\t最小离地间隙：" << smartCar.chassis.minimum_ground_clearance << endl
        << "\t最小转弯半径：" << smartCar.chassis.minimum_turning_radius << endl
        << "\t驱动形式：" << smartCar.chassis.maximum_stroke << endl
        << "\t轮胎" << endl
        << "\t\t型号：" << smartCar.chassis.tyre[0].model << endl
        << "\t\t尺寸：" << smartCar.chassis.tyre[0].size << endl
        << "AGX套件" << endl
        << "\t型号：" << smartCar.agx_kit.model << endl
        << "\tAI：" << smartCar.agx_kit.ai << endl
        << "\tCUDA核心：" << smartCar.agx_kit.cuda_cores << endl
        << "\tTensor CORE：" << smartCar.agx_kit.tensor_core << endl
        << "\t显存：" << smartCar.agx_kit.video_memory << endl
        << "\t存储：" << smartCar.agx_kit.storage << endl
        << "双目摄像头" << endl
        << "\t型号：" << smartCar.stereo_camera.model << endl
        << "\t摄像头：" << smartCar.stereo_camera.camera << endl
        << "\tRGB帧分辨率：" << smartCar.stereo_camera.rgb_frame_resolution << endl
        << "\tRGB帧率：" << smartCar.stereo_camera.rgb_fps << endl
        << "\tFOV：" << smartCar.stereo_camera.fov << endl
        << "\t深度帧率：" << smartCar.stereo_camera.deep_fps << endl
        << "多线激光雷达" << endl
        << "\t型号：" << smartCar.multi_line_lidar.model << endl
        << "\t通道数：" << smartCar.multi_line_lidar.channel << endl
        << "\t测试范围：" << smartCar.multi_line_lidar.test_range << endl
        << "\t功耗：" << smartCar.multi_line_lidar.power << endl
        << "九轴陀螺仪" << endl
        << "\t型号：" << smartCar.nine_axis_gyroscope.model << endl
        << "\t厂家：" << smartCar.nine_axis_gyroscope.manufacturers << endl
        << "液晶显示屏" << endl
        << "\t尺寸：" << smartCar.lcd.size << endl
        << "\t型号：" << smartCar.lcd.model << endl
        << "电池模块" << endl
        << "\t参数：" << smartCar.battery_module.parameter << endl
        << "\t对外供电：" << smartCar.battery_module.external_power_supply << endl
        << "\t充电时长：" << smartCar.battery_module.charging_time << endl;

    cout << "-----学生信息-----" << endl
        << "学号：" << student.id << endl
        << "姓名：" << student.name << endl;
}