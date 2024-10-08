//
// Created by Zephyrus-Desktop on 2024/10/7.
//

#ifndef LCD_H
#define LCD_H

#include <string>

using std::string;

class LCD {
    double size;
    string model;

public:
    void set_size(double size);

    void set_model(const string &model);

    void print() const;

    void save() const;

    void load();
};
#endif //LCD_H
