#include "Automata.h"
#include <iostream>

Automata::Automata() {
    menu = {"Coffee", "Tea", "Cocoa"};
    prices = {50, 30, 40};
}

void Automata::on() {
    std::cout << "Machine is on" << std::endl;
}

void Automata::off() {
    std::cout << "Machine is off" << std::endl;
}

void Automata::coin(int coins) {
    balance += coins;
}

void Automata::printMenu() {
    for (int i = 0; i < menu.size(); i++) {
        std::cout << i+1 << ". " << menu[i] << " - " << prices[i] << " rubles" << std::endl;
    }
}

void Automata::select(int item) {
    if (item >= 1 && item <= menu.size()) {
        choice = item;
        std::cout << "Selected item: " << menu[choice-1] << std::endl;
    } else {
        std::cout << "Invalid item" << std::endl;
    }
}

void Automata::cancel() {
    std::cout << "Canceled" << std::endl;
    balance = 0;
    choice = 0;
}

void Automata::cook() {
    std::cout << "Cooking..." << std::endl;
}

void Automata::finish() {
    std::cout << "Enjoy your drink!" << std::endl;
}
