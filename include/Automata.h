#pragma once
#include <string>
#ifndef AUTOMATA_H
#define AUTOMATA_H
#include <vector>

enum STATES {
OFF,
WAIT,
ACCEPT,
CHECK,
COOK
};

class Automata {
public:
    Automata();
    void on();
    void off();
    void coin(int coin);
    void printMenu();
    void choice(int item);
    bool check();
    void cancel();
    int getBalance();

private:
    std::vector<std::string> menu;
    std::vector<int> prices;
    int balance;
    int chosen_item;
    void cook();
};

#endif  // AUTOMATA_H

