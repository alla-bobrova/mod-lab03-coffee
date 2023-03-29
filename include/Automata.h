#pragma once
#include <string>
#include <vector>

class Automata {
public:
    Automata();
    void on();
    void off();
    void coin(int coins);
    void printMenu();
    void select(int item);
    void cancel();
    void cook();
    void finish();
private:
    std::vector<std::string> menu;
    std::vector<int> prices;
    int balance = 0;
    int choice = 0;
};
