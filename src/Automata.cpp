#include "Automata.h"
#include <iostream>

Automata::Automata() {
    cash = 0;
    state = OFF;
}

void Automata::on() {
    state = WAIT;
    std::cout << "Automata is on\n";
}

void Automata::off() {
    state = OFF;
    std::cout << "Automata is off\n";
}

void Automata::coin(double money) {
    if (state == WAIT || state == CHECK) {
        state = ACCEPT;
        std::cout << "Cash balance: " << cash << "\n";
    }
    cash += money;
}

void Automata::getMenu() {
    std::cout << "Menu:\n";
       for (int i = 0; i < MENU_SIZE; ++i) {
           std::cout << i + 1 << ". " << menu[i] << " - " << prices[i] << "\n";
        }
}

Automata::STATES Automata::getState() {
    return state;
}

void Automata::choice(int drink) {
        if (state == ACCEPT) {
        chosenDrink = drink;
        if (cash >= prices[chosenDrin]) {
            state = CHECK;
            std::cout << "You have chosen " << menu[chosenDrink] << "\n";
        } else {
            state = ACCEPT;
             std::cout << "Error: invalid drink number\n";
        }
    }
}
    

bool Automata::check() {
    if (state == CHECK) {
        if (cash >= prices[chosenDrink]) {
            cook();
            return true;
        }
        else {
            return false;
        }
    }
    return false;
}

void Automata::cancel() {
    cash = 0;
    chosenDrink = -1;
    state = WAIT;
    std::cout << "Transaction canceled\n";
}

void Automata::cook() {
    if (state == CHECK) {
        state = COOK;
        std::cout << "Preparing " << menu[chosenDrink] << "\n";
    }
}
   
void Automata::finish() {
    cash -= prices[chosenDrink];
    chosenDrink = -1;
    state = WAIT;
    std::cout << "Transaction complete\n";
}

double Automata::getCash()
{
    return cash;
}

int Automata::getChosenDrink()
{
    return chosenDrink;
}
