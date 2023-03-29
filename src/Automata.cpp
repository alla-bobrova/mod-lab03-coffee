#include "Automata.h"

Automata::Automata() {
    state = STATES::OFF;
    cash = 0;
}

void Automata::on() {
    state = STATES::WAIT;
    cout << "Welcome to the coffee machine!\n";
}

void Automata::off() {
    state = STATES::OFF;
    cout << "Turning off the coffee machine...\n";
}

void Automata::coin(int value) {
    if (state == STATES::WAIT || state == STATES::ACCEPT) {
        cash += value;
        state = STATES::ACCEPT;
        cout << "Amount of money entered: " << cash << endl;
    } else {
        cout << "You can't add coins right now.\n";
    }
}

void Automata::getMenu() {
    menu = {"Americano", "Cappuccino", "Latte"};
    prices = {50, 80, 100};
}

void Automata::getState() {
    cout << "Current state: ";
    switch (state) {
        case STATES::OFF:
            cout << "OFF\n";
            break;
        case STATES::WAIT:
            cout << "WAIT\n";
            break;
        case STATES::ACCEPT:
            cout << "ACCEPT\n";
            break;
        case STATES::CHECK:
            cout << "CHECK\n";
            break;
        case STATES::COOK:
            cout << "COOK\n";
            break;
        case STATES::FINISH:
            cout << "FINISH\n";
            break;
    }
}

void Automata::getMenu(vector<string> menu, vector<int> prices) {
    this->menu = menu;
    this->prices = prices;
}

void Automata::choice(int option) {
    if (option >= 0 && option < menu.size()) {
        this->option = option;
        state = STATES::CHECK;
    } else {
        cout << "Invalid option.\n";
    }
}

void Automata::check() {
    if (cash >= prices[option]) {
        state = STATES::COOK;
    } else {
        cout << "Not enough money.\n";
        state = STATES::ACCEPT;
    }
}

void Automata::cook() {
    cout << "Making your " << menu[option] << "...\n";
    cash -= prices[option];
    state = STATES::FINISH;
}

void Automata::cancel() {
    cout << "Canceling your order...\n";
    cash = 0;
    state = STATES::WAIT;
}

void Automata::finish() {
    if (state == STATES::FINISH) {
        cout << "Enjoy your " << menu[option] << "!\n";
        cash = 0;
        state = STATES::WAIT;
    } else {
        cout << "You haven't ordered anything yet.\n";
    }
}

