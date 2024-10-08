//
// Created by Zephyrus-Desktop on 2024/10/5.
//

#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>

using std::string;

struct Student {
    string id;
    string name;
};

void save_student_data();

std::vector<Student> load_student_data();
#endif //STUDENT_H
