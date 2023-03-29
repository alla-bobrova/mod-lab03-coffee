#ifndef AUTOMATA_H
#define AUTOMATA_H

#include <string>

enum STATES { OFF, WAIT, ACCEPT, CHECK, COOK };

class Automata {
public:
    Automata();

    void on();
    void off();
    void coin(int money);
    void getMenu();
    STATES getState();
    void choice(int drink);
    bool check();
    void cancel();
    void cook();
    void finish();

private:
    int cash;
    std::string menu[3] = { "Чай", "Кофе", "Горячий шоколад" };
    int prices[3] = { 50, 70, 80 };
    const int menuSize = sizeof(menu) / sizeof(menu[0]);
    STATES state;
    int choiceDrink;
};

#endif  // AUTOMATA_H
