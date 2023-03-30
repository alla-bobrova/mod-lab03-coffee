// Copyright 2022 UNN-IASR
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
    if (state == WAIT) {
        cash += money;
        std::cout << "Cash balance: " << cash << "\n";
    } else {
        std::cout << "Error: invalid state\n";
    }
}

void Automata::getMenu() {
    if (state == WAIT) {
        std::cout << "Menu:\n";
        for (int i = 0; i < MENU_SIZE; ++i) {
            std::cout << i + 1 << ". " << menu[i] << " - " << prices[i] << "\n";
        }
    } else {
        std::cout << "Error: invalid state\n";
    }
}

Automata::STATES Automata::getState() {
    return state;
}

void Automata::choice(int drink) {
    if (state == WAIT) {
        if (drink > 0 && drink <= MENU_SIZE) {
            chosenDrink = drink - 1;
            state = ACCEPT;
            std::cout << "You have chosen " << menu[chosenDrink] << "\n";
        } else {
            std::cout << "Error: invalid drink number\n";
        }
    } else {
        std::cout << "Error: invalid state\n";
    }
}

bool Automata::check() {
    if (cash >= prices[chosenDrink]) {
        return true;
    } else {
        std::cout << "Not enough money\n";
        state = WAIT;
        return false;
    }
}

void Automata::cancel() {
    cash = 0;
    chosenDrink = -1;
    state = WAIT;
    std::cout << "Transaction canceled\n";
}

void Automata::cook() {
    state = COOK;
    std::cout << "Preparing " << menu[chosenDrink] << "\n";
}

void Automata::finish() {
    cash -= prices[chosenDrink];
    chosenDrink = -1;
    state = WAIT;
    std::cout << "Transaction complete\n";
}

double Automata::getCash() {
    return cash;
}

int Automata::getChosenDrink() {
    return chosenDrink;
}
