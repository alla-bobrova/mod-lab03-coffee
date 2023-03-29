#ifndef AUTOMATA_H
#define AUTOMATA_H

enum State {
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
    void coin(int value);
    void choice(int option);
    void cancel();
    void cook();
    bool check();
    int getCash();

private:
    int cash;
    State state;
};

#endif
