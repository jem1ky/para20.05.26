#include "string_extraction.h"
#include <iostream>
#include <string>

void runStringExtractionDemo() {
    std::string text = "Код ошибки: 404 - Не найдено";
    size_t colonPos = text.find(':');

    if (colonPos != std::string::npos) {
        // .substr(индекс, длина) копирует часть строки
        size_t codeStart = colonPos + 2;
        std::string errorCode = text.substr(codeStart, 3);
        std::cout << "Извлечённый код: " << errorCode << std::endl;

        // .erase(индекс) удаляет всё начиная с индекса и до конца строки
        size_t erasePos = text.find(" - Не найдено");
        if (erasePos != std::string::npos) {
            text.erase(erasePos);
        }

        std::cout << "Изменённая строка: " << text << std::endl;
    }
}
