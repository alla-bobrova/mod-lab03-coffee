#pragma once

class Automata {
public:
    void on();
    void off();
    void coin(int money);
    void printMenu();
    void choice(int num);
    void check();
    void getMenu(); // добавляем метод
private:
    int state;
    int cash;
    int prices[4] = {60, 100, 120, 80};
    int choice; // изменяем доступ на public
    std::string menu[4] = {"Espresso", "Americano", "Latte", "Cappuccino"};
};
