#include "string_modification.h"
#include <iostream>
#include <string>

void runStringModificationDemo() {
    std::string text = "Сегодня хорошая погода.";

    // Вставка подстроки по указанному индексу
    size_t insertPos = text.find("хорошая");
    if (insertPos != std::string::npos) {
        text.insert(insertPos, "очень ");
        std::cout << "После вставки: " << text << std::endl;
    }

    // Замена куска строки на другой текст (.replace)
    size_t replacePos = text.find("хорошая");
    if (replacePos != std::string::npos) {
        text.replace(replacePos, 7, "прекрасная");
        std::cout << "Конечный результат: " << text << std::endl;
    }
}
