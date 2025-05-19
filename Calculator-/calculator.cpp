#include <iostream>
#include <string>
#include <cstdlib> // Для std::strtod
#include <cmath>   // Для std::pow
#include "calculator.h"

bool ReadNumber(Number& result) {
    std::string input;
    if (!(std::cin >> input)) {
        std::cerr << "Error: Numeric operand expected" << std::endl;
        return false;
    }

    char* end;
    result = std::strtod(input.c_str(), &end); // Преобразование строки в число

    // Проверка, было ли успешно прочитано число
    if (end == input.c_str() || *end != '\0') {
        std::cerr << "Error: Numeric operand expected" << std::endl;
        return false; // Если не удалось прочитать число
    }

    return true; // Успешное чтение числа
}

bool RunCalculatorCycle() {
    Number current = 0; // Текущее значение калькулятора
    Number memory = 0;  // Ячейка памяти
    bool memorySet = false; // Флаг для проверки, сохранено ли число в памяти

    // Запрашиваем первое число
    if (!ReadNumber(current)) return false;

    while (true) {
        std::string command;

        if (!(std::cin >> command)) {
            break; // Завершение работы
        }

        if (command == "+") {
            Number operand;
            if (!ReadNumber(operand)) return false;
            current += operand;
        } else if (command == "-") {
            Number operand;
            if (!ReadNumber(operand)) return false;
            current -= operand;
        } else if (command == "*") {
            Number operand;
            if (!ReadNumber(operand)) return false;
            current *= operand;
        } else if (command == "/") {
            Number operand;
            if (!ReadNumber(operand)) return false;
            if (operand == 0) {
                current=INFINITY; // Деление на ноль
                continue; // Продолжаем цикл, не изменяя текущее значение
            }
            current /= operand;
        } else if (command == "**") {
            Number operand;
            if (!ReadNumber(operand)) return false;
            current = std::pow(current, operand);
        } else if (command == "=") {
            std::cout << current << std::endl; // Вывод текущего значения
        } else if (command == ":") {
            if (!ReadNumber(current)) return false; // Установка нового значения
        } else if (command == "c") {
            current = 0; // Очистка
        } else if (command == "s") {
            memory = current; // Сохранение в память
            memorySet = true; // Установка флага
        } else if (command == "l") {
            if (!memorySet) {
                std::cerr << "Error: Memory is empty" << std::endl; // Ошибка, если память пуста
                return false;
            }
            current = memory; // Загрузка из памяти
        } else if (command == "q") {
            return true; // Завершение работы
        } else {
            std::cerr << "Error: Unknown token " << command << std::endl; // Ошибка для неизвестной команды
            return false;
        }
    }
    return true;
}