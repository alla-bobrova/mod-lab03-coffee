#pragma once
#include <string>
#include <vector>

using namespace std;

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
    vector<string> menu;
    vector<int> prices;
    int balance = 0;
    int choice = 0;
};
