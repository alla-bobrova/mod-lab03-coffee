#include "Automata.h"

Automata::Automata() {
    menu = {"Coffee", "Tea", "Cocoa"}; // fixed this line
    prices = {50, 30, 40}; // fixed this line
    cash = 0; // fixed this line
    state = OFF; // fixed these two lines
}

void Automata::on() {
    state = WAIT;
    printMenu();
}

void Automata::off() {
    cancelTransaction();
    state = OFF;
}

void Automata::coin(int n) {
    if (state == ACCEPT) {
        cash += n;
        state = CHECK;
    }
}

void Automata::printMenu() {
    for (int i = 0; i < menu.size(); i++) {
        std::cout << i+1 << ". " << menu[i] << " - " << prices[i] << " rubles" << std::endl;
    }
    state = ACCEPT;
}

void Automata::choice(int n) {
    int idx = findMenuIndex(n);
    if (idx >= 0) {
        if (cash >= prices[idx]) {
            cook();
        } else {
            state = WAIT;
        }
    }
}

void Automata::cancel() {
    cancelTransaction();
    state = WAIT;
}

void Automata::cook() {
    cash -= prices[findMenuIndex(state)];
    state = COOK;
}

void Automata::finish() {
    std::cout << "Enjoy your drink!" << std::endl;
    cash = 0;
    state = WAIT;
}

void Automata::cancelTransaction() {
    std::cout << "Transaction canceled. Returning " << cash << " rubles." << std::endl;
    cash = 0;
    state = WAIT;
}

int Automata::findMenuIndex(int n) {
    return n - 1;
}
