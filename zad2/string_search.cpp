#include "string_search.h"
#include <iostream>
#include <string>

void runStringSearchDemo() {
    std::string text = "C++ — мощный язык программирования. Класс string очень удобен.";

    // Метод .find() возвращает индекс начала подстроки или std::string::npos
    size_t position = text.find("string");

    if (position != std::string::npos) {
        std::cout << "Слово 'string' найдено на позиции " << position << std::endl;
    }
    else {
        std::cout << "Слово не найдено" << std::endl;
    }
}
