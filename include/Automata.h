#ifndef AUTOMATA_H
#define AUTOMATA_H

#include <vector> // added this line

enum State { OFF, WAIT, ACCEPT, CHECK, COOK };

class Automata {
public:
    Automata();
    void on();
    void off();
    void coin(int);
    void printMenu();
    void choice(int);
    void cancel();
private:
    std::vector<std::string> menu;
    std::vector<int> prices;
    int cash;
    State state; // fixed this line
    void cook();
    void finish();
    void cancelTransaction();
    int findMenuIndex(int);
};

#endif // AUTOMATA_H
