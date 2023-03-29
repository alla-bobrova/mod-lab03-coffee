#pragma once
#include <string>

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
void coin(int sum);
void getMenu();
void getState();
void choice(int num);
void check();
void cancel();
void cook();
void finish();
private:
STATES state;
int cash;
std::string menu[3] = {"Tea", "Coffee", "Milk"};
int prices[3] = {10, 15, 20};
int choice_num;
};
