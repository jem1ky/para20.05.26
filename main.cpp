#include <iostream>
#include "SmartArray.h"

int main() {
    // Работа с целыми числами
    SmartArray<int> intArray;
    for (int i = 1; i <= 10; i++) {
        intArray.push_back(i * 10);
    }
    std::cout << "Size: " << intArray.size() << std::endl;

    // Поиск элемента
    int index = intArray.find(50);
    if (index != -1) {
        std::cout << "Found 50 at index: " << index << std::endl;
    }

    // Работа со строками
    SmartArray<std::string> strArray;
    strArray.push_back("Hello");
    strArray.push_back("World");
    strArray.push_back("C++");

    // Демонстрация работы итератора (range-based for использует методы begin и end)
    std::cout << "String array elements: ";
    for (const auto& str : strArray) {
        std::cout << str << " ";
    }
    std::cout << std::endl;

    return 0;
}
