#include "string_comparison.h"
#include <iostream>
#include <string>

void runStringComparisonDemo() {
    std::string pass1, pass2;
    std::cout << "Введите пароль: ";
    std::cin >> pass1;
    std::cout << "Подтвердите пароль: ";
    std::cin >> pass2;

    // Метод .compare() возвращает 0, если строки абсолютно идентичны
    if (pass1.compare(pass2) == 0) {
        std::cout << "Доступ разрешён" << std::endl;
    }
    else {
        std::cout << "Доступ запрещён: пароли не совпадают" << std::endl;
        if (pass1.length() == pass2.length()) {
            std::cout << "Пароли разной длины? (Длины равны, но символы разные)" << std::endl;
        }
    }
}
