#include "Automata.h"
#include <iostream>

Automata::Automata() {
    menu = {"Coffee", "Tea", "Cocoa"};
    prices = {50, 30, 40};
    cash = 0;
    state = OFF;
}

void Automata::on() {
    state = WAIT;
    std::cout << "The coffee machine is ON\n";
}

void Automata::off() {
    state = OFF;
    std::cout << "The coffee machine is OFF\n";
}

void Automata::coin(int value) {
    if (state == ACCEPT) {
        cash += value;
        std::cout << "Inserted " << value << " rubles\n";
        check();
    }
    else {
        std::cout << "Error: Invalid state\n";
    }
}

void Automata::printMenu() {
    for (int i = 0; i < menu.size(); i++) {
        std::cout << i+1 << ". " << menu[i] << " - " << prices[i] << " rubles\n";
    }
}

void Automata::choice(int item) {
    if (state == WAIT) {
        chosen_item = item;
        state = ACCEPT;
        std::cout << "Chosen item: " << menu[item-1] << "\n";
    }
    else {
        std::cout << "Error: Invalid state\n";
    }
}

void Automata::cancel() {
    if (state == ACCEPT) {
        std::cout << "Cancelled\n";
        state = WAIT;
    }
    else {
        std::cout << "Error: Invalid state\n";
    }
}

void Automata::cook() {
    if (state == CHECK) {
        std::cout << "Cooking " << menu[chosen_item-1] << "...\n";
        state = WAIT;
    }
    else {
        std::cout << "Error: Invalid state\n";
    }
}

void Automata::check() {
    if (cash >= prices[chosen_item-1]) {
        std::cout << "Enough money\n";
        state = CHECK;
        cash -= prices[chosen_item-1];
        cook();
    }
}

int Automata::getCash() {
    return cash;
}

void Automata::setCash(int value) {
    cash = value;
}

void Automata::setState(State state) {
    this->state = state;
}
