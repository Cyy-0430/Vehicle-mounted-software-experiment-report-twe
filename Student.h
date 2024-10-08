//
// Created by Zephyrus-Desktop on 2024/10/5.
//

#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>

using std::string;

class Student {
    string id;
    string name;

public:
    void set_id(const string &id);

    void set_name(const string &name);

    void print() const;

    void save() const;

    void load();
};

void save_student_data();

std::vector<Student> load_student_data();
#endif //STUDENT_H
