#include<string>
#ifndef AUTOMATA_H
#define AUTOMATA_H

enum STATES {
    OFF,
    WAIT,
    ACCEPT,
    COOK
};

class Automata {
public:
    Automata();
    void on();
    void off();
    void coin(double money);
    void getMenu();
    void getState();
    void choice(int drink);
    bool check();
    void cancel();
    void cook();
    void finish();

private:
    double cash;
    int chosenDrink;
    STATES state;
    static const int MENU_SIZE = 3;
    std::string menu[MENU_SIZE] = { "Coffee", "Tea", "Milk" };
    double prices[MENU_SIZE] = { 1.5, 1.0, 2.0 };
};

#endif // AUTOMATA_H
