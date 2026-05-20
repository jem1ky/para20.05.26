#include "string_input.h"
#include <iostream>
#include <string>

void runStringInputDemo() {
    std::string fullName;
    std::cout << "Введите ваше имя и фамилию: ";

    // Считываем строку целиком, игнорируя разделители-пробелы
    std::getline(std::cin, fullName);

    // Конкатенация (склеивание) строк оператором +
    std::string greeting = "Добрый день, " + fullName + "!";
    std::cout << greeting << std::endl;
}
