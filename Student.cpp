//
// Created by Zephyrus-Desktop on 2024/10/7.
//
#include <fstream>

#include "Student.h"

#include <iostream>

#include <vector>

void save_student_data() {
    constexpr int N = 10;
    const Student student[N] = {
        {"E2021246", "陈宇阳"},
        {"E2021999", "同学1"},
        {"E2021998", "同学2"},
        {"E2021997", "同学3"},
        {"E2021996", "同学4"},
        {"E2021995", "同学5"},
        {"E2021994", "同学6"},
        {"E2021993", "同学7"},
        {"E2021992", "同学8"},
        {"E2021991", "同学9"},
    };

    std::ofstream outFile;
    outFile.open("student_data.txt");

    for (const auto & s : student) {
        // std::cout << s.id << " " << s.name << std::endl;
        outFile << s.id << " " << s.name << std::endl;
    }

    outFile.close();
}

std::vector<Student> load_student_data() {
    std::vector<Student> students;

    std::ifstream inFile("student_data.txt");
    constexpr int N = 10;
    for (int i = 0; i < N; i++) {
        string id, name;
        inFile >> id >> name;
        Student s = {id, name};

        students.push_back(s);
    }
    inFile.close();

    return students;
}
