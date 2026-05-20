#include "string_basics.h"
#include <iostream>
#include <string>

void runStringBasicsDemo() {
    std::string name = "Анна";
    std::cout << "Привет, " << name << "!" << std::endl;

    // .length() возвращает количество символов
    std::cout << "Длина имени: " << name.length() << std::endl;

    // .at(0) безопасно возвращает символ по индексу 0
    std::cout << "Первый символ: " << name.at(0) << std::endl;
}
