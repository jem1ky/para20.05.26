#include "string_case_converter.h"
#include <iostream>
#include <string>
#include <cctype>

void runStringCaseConverterDemo() {
    std::string myString;
    std::cout << "Вход: ";
    std::getline(std::cin, myString);

    bool nextUpper = true;

    // Ссылка &c позволяет изменять символы внутри строки прямо в цикле
    for (char& c : myString) {
        if (std::isspace(c)) {
            nextUpper = true;
        }
        else if (nextUpper) {
            c = std::toupper(c);
            nextUpper = false;
        }
    }

    std::cout << "Выход: " << myString << std::endl;
}
