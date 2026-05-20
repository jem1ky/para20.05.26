#include <iostream>
#include "string_basics.h"
#include "string_input.h"
#include "string_search.h"
#include "string_case_converter.h"
#include "string_modification.h"
#include "string_extraction.h"
#include "string_back_mutator.h"
#include "string_comparison.h"
#include "string_clear_validate.h"

int main() {
    // Включение поддержки кириллицы в консоли Windows
    std::setlocale(LC_ALL, "Russian");

    std::cout << "=== Базовые методы (.length, .at) ===" << std::endl;
    runStringBasicsDemo();

    std::cout << "\n=== Ввод строк и конкатенация (getline) ===" << std::endl;
    runStringInputDemo();

    std::cout << "\n=== Поиск подстроки (.find) ===" << std::endl;
    runStringSearchDemo();

    std::cout << "\n=== Изменение регистра символов ===" << std::endl;
    runStringCaseConverterDemo();

    std::cout << "\n=== Вставка и замена (.insert, .replace) ===" << std::endl;
    runStringModificationDemo();

    std::cout << "\n=== Извлечение и стирание (.substr, .erase) ===" << std::endl;
    runStringExtractionDemo();

    std::cout << "\n=== Изменение конца строки (.push_back, .pop_back) ===" << std::endl;
    runStringBackMutatorDemo();

    std::cout << "\n=== Сравнение строк (.compare) ===" << std::endl;
    runStringComparisonDemo();

    std::cout << "\n=== Очистка и проверка (.clear, .empty) ===" << std::endl;
    runStringClearValidateDemo();

    return 0;
}
