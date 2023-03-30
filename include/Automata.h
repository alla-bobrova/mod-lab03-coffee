// Copyright 2022 UNN-IASR
#ifndef INCLUDE_AUTOMATA_H_
#define INCLUDE_AUTOMATA_H_
#include<string>

class Automata {
 public:
    Automata();
    void on();
    void off();
    void coin(double money);
    void getMenu();
    void choice(int drink);
    bool check();
    void cancel();
    void cook();
    void finish();

    enum STATES {
    OFF,
    WAIT,
    ACCEPT,
    CHECK,
    COOK
    };
    double getCash();
    int getChosenDrink();
    STATES getState();
    STATES state;

 private:
    double cash;
    int chosenDrink;
    static const int MENU_SIZE = 3;
    std::string menu[MENU_SIZE] = { "Coffee", "Tea", "Milk" };
    double prices[MENU_SIZE] = { 11.5, 10.0, 20.0 };
};
#endif  // INCLUDE_AUTOMATA_H_
