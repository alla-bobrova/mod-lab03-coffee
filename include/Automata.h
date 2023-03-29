#ifndef AUTOMATA_H
#define AUTOMATA_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Automata {
public:
    Automata();
    void on();
    void off();
    void coin(int);
    void printMenu();
    void choice(int);
    void cancel();
    void cook();
private:
    int cash;
    vector<string> menu;
    vector<int> prices;
    int choiceNumber;
    int currentState;
    bool isEnough(int);
    void setState(int);
    int getState();
    void getMenu(vector<string>, vector<int>);
};

#endif // AUTOMATA_H
