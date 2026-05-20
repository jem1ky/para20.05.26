#include "string_back_mutator.h"
#include <iostream>
#include <string>

void runStringBackMutatorDemo() {
    std::string word = "";

    // .push_back() цепляет по одному символу в конец
    for (char letter = 'A'; letter <= 'Z'; ++letter) {
        word.push_back(letter);
    }
    std::cout << "Полная строка: " << word << std::endl;

    // .pop_back() отрезает по одному символу с конца
    for (int i = 0; i < 5; ++i) {
        // .empty() гарантирует, что мы не удаляем из пустой строки
        if (!word.empty()) {
            word.pop_back();
        }
    }
    std::cout << "После удаления 5 символов: " << word << std::endl;
}
