#pragma once

#include <iostream>
#include <vector>
#include <string>

class Automata {
public:
    void on(); // Включение автомата
    void off(); // Выключение автомата
    void coin(int value); // Зачисление денег на баланс
    void getMenu(); // Считывание меню с напитками и ценами для пользователя
    void choice(int option); // Выбор напитка пользователем
    void check(); // Проверка наличия необходимой суммы
    void cook(); // Приготовление напитка
    void finish(); // Завершение заказа и выдача напитка

private:
    enum class STATES {OFF, WAIT, ACCEPT, CHECK, COOK, FINISH};
    STATES state = STATES::OFF; // Текущее состояние автомата
    std::vector<std::string> menu; // Меню напитков
    std::vector<int> prices; // Цены на напитки
    int cash = 0; // Текущий баланс пользователя
    int option = -1; // Выбранный пользователем вариант напитка
};
