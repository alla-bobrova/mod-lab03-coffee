#ifndef AUTOMATA_H
#define AUTOMATA_H

#include <string>

// Перечислимый тип для задания состояний автомата
enum STATES {
    OFF,
    WAIT,
    ACCEPT,
    CHECK,
    COOK
};

class Automata {
public:
    Automata(); // Конструктор

    void on(); // Включение автомата
    void off(); // Выключение автомата
    void coin(int money); // Занесение денег на счёт пользователем
    void getMenu(); // Считывание меню с напитками и ценами для пользователя
    void getState(); // Считывание текущего состояния для пользователя
    void choice(int index); // Выбор напитка пользователем
    void check(); // Проверка наличия необходимой суммы
    void cancel(); // Отмена сеанса обслуживания пользователем
    void cook(); // Имитация процесса приготовления напитка
    void finish(); // Завершение обслуживания пользователя

private:
    int cash; // Текущая сумма на счету
    std::string menu[3] = {"Чай", "Кофе", "Какао"}; // Меню напитков
    int prices[3] = {30, 50, 40}; // Цены напитков
    STATES state; // Текущее состояние автомата
    int choiceIndex; // Индекс выбранного напитка
};

#endif // AUTOMATA_H

