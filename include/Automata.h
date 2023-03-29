#ifndef AUTOMATA_H
#define AUTOMATA_H

#include <string>
#include <vector>

enum STATES {OFF, WAIT, ACCEPT, CHECK, COOK};

class Automata {
public:
    Automata();
    void on();
    void off();
    void coin(int money);
    void getMenu();
    STATES getState();
    void choice(int option);
    bool check();
    void cancel();
    void cook();
    void finish();
    int cash; 
    int choice_;
    int sum;
private:
    
    std::vector<std::string> menu;
    std::vector<int> prices;
    STATES state;
   
};

#endif // AUTOMATA_H
