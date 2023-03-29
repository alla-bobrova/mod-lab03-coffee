#include "Automata.h"
#include <iostream>

Automata::Automata() {
    cash = 0;
    state = OFF;
    sum = 0;
    choice_ = 0;
}

void Automata::on() {
    if (state == OFF) {
        state = WAIT;
        std::cout << "The automata is on." << std::endl;
    }
    else {
        std::cout << "The automata is already on." << std::endl;
    }
}

void Automata::off() {
    if (state == OFF) {
        std::cout << "The automata is already off." << std::endl;
    }
    else if (state == WAIT) {
        state = OFF;
        std::cout << "The automata is off." << std::endl;
    }
    else {
        std::cout << "Please finish the current transaction before turning off the automata." << std::endl;
    }
}

void Automata::coin(int money) {
    if (state == WAIT) {
        cash += money;
        std::cout << "Cash balance: " << cash << std::endl;
    }
    else {
        std::cout << "Please make your choice first." << std::endl;
    }
}

void Automata::getMenu() {
    if (state == WAIT) {
        std::cout << "Menu:" << std::endl;
        for (int i = 0; i < menu.size(); i++) {
            std::cout << i+1 << ". " << menu[i] << " - " << prices[i] << " rubles" << std::endl;
        }
    }
    else {
        std::cout << "Please make your choice first." << std::endl;
    }
}

STATES Automata::getState() {
    return state;
}

void Automata::choice(int option) {
    if (state == WAIT) {
        if (option < 1 || option > menu.size()) {
            std::cout << "Invalid choice." << std::endl;
        }
        else {
            choice_ = option;
            state = ACCEPT;
            sum = prices[option-1];
            std::cout << "You have chosen " << menu[option-1] << "." << std::endl;
        }
    }
    else {
        std::cout << "Please finish the current transaction before making a new choice." << std::endl;
    }
}

bool Automata::check() {
    if (state == ACCEPT) {
        if (cash < sum) {
            std::cout << "Not enough money. Please insert more." << std::endl;
            return false;
        }
        else {
            state = CHECK;
            std::cout << "Please wait. Checking the availability of ingredients." << std::endl;
            return true;
        }
    }
    else {
        std::cout << "Please make your choice first." << std::endl;
        return false;
    }
}

void Automata::cancel() {
    if (state == ACCEPT || state == CHECK) {
        std::cout << "Transaction canceled. Returning " << cash << " rubles." << std::endl;
        cash = 0;
        state = WAIT;
        sum = 0;
        choice_ = 0;
    }
    else {
        std::cout << "Please make your choice first." << std::endl;
    }
}

void Automata::cook() {
    if (state == CHECK) {
        state = COOK;
        std::cout << "Making your " << menu[choice_ - 1] << "...\n";
std::cout << "Please, wait...\n";
std::this_thread::sleep_for(std::chrono::seconds(5)); // имитация процесса приготовления напитка в течение 5 секунд
std::cout << "Your " << menu[choice_ - 1] << " is ready! Enjoy!\n";
finish(); // завершение обслуживания пользователя
}
}

void Automata::finish() {
state = WAIT;
cash = 0; // обнуление текущей суммы
choice_ = 0; // обнуление выбора пользователя
}
