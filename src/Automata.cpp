#include "Automata.h"
#include <iostream>

Automata::Automata() {
    cash = 0;
    menu = {"Coffee", "Tea", "Cocoa"};
    prices = {50, 30, 40};
    state = OFF;
}

void Automata::on() {
    if (state == OFF) {
        state = WAIT;
        std::cout << "Automata is on\n";
    } else {
        std::cout << "Automata is already on\n";
    }
}

void Automata::off() {
    if (state == WAIT) {
        state = OFF;
        std::cout << "Automata is off\n";
    } else if (state == ACCEPT) {
        std::cout << "Can't turn off while accepting money\n";
    } else if (state == COOK) {
        std::cout << "Can't turn off while cooking\n";
    } else {
        std::cout << "Automata is already off\n";
    }
}

void Automata::coin(int value) {
    if (state == ACCEPT) {
        cash += value;
        std::cout << "Accepted " << value << " rubles, total: " << cash << " rubles\n";
    } else {
        std::cout << "Can't accept coins in current state\n";
    }
}

void Automata::getMenu() {
    if (state == WAIT) {
        std::cout << "Menu:\n";
        for (int i = 0; i < menu.size(); i++) {
            std::cout << i + 1 << ". " << menu[i] << " - " << prices[i] << " rubles\n";
        }
    } else {
        std::cout << "Can't show menu in current state\n";
    }
}

void Automata::getState() {
    std::string state_str;
    switch (state) {
        case OFF:
            state_str = "OFF";
            break;
        case WAIT:
            state_str = "WAIT";
            break;
        case ACCEPT:
            state_str = "ACCEPT";
            break;
        case CHECK:
            state_str = "CHECK";
            break;
        case COOK:
            state_str = "COOK";
            break;
    }
    std::cout << "Current state: " << state_str << "\n";
}

void Automata::choice(int item) {
    if (state == WAIT) {
        if (item >= 1 && item <= menu.size()) {
            chosen_item = item;
            state = ACCEPT;
            std::cout << "You've chosen " << menu[item - 1] << ", price: " << prices[item - 1] << " rubles\n";
        } else {
            std::cout << "Invalid choice\n";
        }
    } else {
        std::cout << "Can't make a choice in current state\n";
    }
}

bool Automata::check() {
    if (state == CHECK) {
        if (cash >= prices[chosen_item - 1]) {
            state = COOK;
            return true;
        } else {
            std::cout << "Not enough money\n";
            state = ACCEPT;
            return false;
        }
    } else {
        std::cout << "Can't check in current state\n";
        return false;
    }
}

void Automata::cancel() {
    if (state == ACCEPT || state == CHECK) {
        cash = 0;
        state = WAIT;
        std::cout << "Cancelled\n";
    } else {std::cout << "Cannot cancel at this time\n";
}
}
void Automata::finish() {
if (state == COOK) {
cash = 0;
state = WAIT;
std::cout << "Thank you for your purchase!\n";
} else {
std::cout << "Cannot finish at this time\n";
}
}
       
