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

        cout << "输入 p 显示上一辆小车信息，输入 n 显示下一辆小车信息：";
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

void show(const Student &student, const SmartCar &smartCar) {
    smartCar.print();

    student.print();
}
