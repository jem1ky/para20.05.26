#include "string_clear_validate.h"
#include <iostream>
#include <string>

void runStringClearValidateDemo() {
    std::string msg = "Это важное сообщение";
    std::cout << "Исходная длина: " << msg.length() << std::endl;

    // Полностью освобождает строку, делая её размер равным 0
    msg.clear();

    std::cout << "Строка очищена. Длина: " << msg.length() << std::endl;
    std::cout << "Строка пуста: " << (msg.empty() ? "да" : "нет") << std::endl;
}
