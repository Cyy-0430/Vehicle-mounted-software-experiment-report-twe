//
// Created by Zephyrus-Desktop on 2024/10/7.
//
#include <fstream>

#include "Student.h"

#include <iostream>

#include <vector>

void Student::set_id(const string &id) {
    this->id = id;
}

void Student::set_name(const string &name) {
    this->name = name;
}

void Student::print() const {
    std::cout << "-----学生信息-----" << std::endl
            << "学号：" << id << std::endl
            << "姓名：" << name << std::endl;
}

void Student::save() const {
    std::ofstream outFile;
    outFile.open("student-" + id + ".txt");
    outFile << id << " " << name << std::endl;
    outFile.close();
}

void save_student_data() {
    constexpr int N = 10;

    Student student[N];

    student[0].set_id("E2021246");
    student[0].set_name("陈宇阳");
    student[0].save();

    for (int i = 1; i < N; i++) {
        student[i].set_id("E202199" + std::to_string(i));
        student[i].set_name("同学" + std::to_string(i));
        student[i].save();
    }
}

std::vector<Student> load_student_data() {
    std::vector<Student> students;

    std::ifstream inFile("student-E2021246.txt");

    string cyy_id, cyy_name;
    inFile >> cyy_id >> cyy_name;
    Student cyy;
    cyy.set_id(cyy_id);
    cyy.set_name(cyy_name);
    students.push_back(cyy);
    inFile.close();

    constexpr int N = 10;
    for (int i = 1; i < N; i++) {
        std::ifstream file("student-E202199" + std::to_string(i) + ".txt");

        Student s;
        students.push_back(s);
        string id, name;

        file >> id >> name;
        students[i].set_id(id);
        students[i].set_name(name);

        file.close();
    }

    return students;
}
