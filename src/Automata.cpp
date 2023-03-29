#include "Automata.h"

Automata::Automata() {
    cash = 0;
    state = STATES::OFF;
}

void Automata::on() {
    if (state == STATES::OFF) {
        state = STATES::WAIT;
    }
}

void Automata::off() {
    if (state == STATES::WAIT || state == STATES::ACCEPT) {
        state = STATES::OFF;
        cash = 0;
    }
}

void Automata::coin(int money) {
    if (state == STATES::ACCEPT) {
        cash += money;
    }
}

void Automata::getMenu(std::vector<std::string> menu, std::vector<int> prices) {
    this->menu = menu;
    this->prices = prices;
}

void Automata::getState() {
    switch (state) {
        case STATES::OFF:
            std::cout << "Автомат выключен" << std::endl;
            break;
        case STATES::WAIT:
            std::cout << "Ожидание действий пользователя" << std::endl;
            break;
        case STATES::ACCEPT:
            std::cout << "Принятие денег" << std::endl;
            break;
        case STATES::CHECK:
            std::cout << "Проверка суммы" << std::endl;
            break;
        case STATES::COOK:
            std::cout << "Приготовление напитка" << std::endl;
            break;
        case STATES::FINISH:
            std::cout << "Завершение обслуживания" << std::endl;
            break;
    }
}

void Automata::choice(int option) {
    if (state == STATES::WAIT) {
        if (option >= 0 && option < menu.size()) {
            state = STATES::ACCEPT;
            this->option = option;
        } else {
            std::cout << "Неверный выбор напитка" << std::endl;
        }
    }
}

bool Automata::check() {
    if (state == STATES::ACCEPT) {
        if (cash >= prices[option]) {
            state = STATES::CHECK;
            return true;
        } else {
            std::cout << "Недостаточно денег" << std::endl;
            state = STATES::WAIT;
            return false;
        }
    }
    return false;
}

void Automata::cancel() {
    if (state == STATES::ACCEPT || state == STATES::CHECK) {
        cash = 0;
        state = STATES::WAIT;
    }
}

void Automata::cook() {
    if (state == STATES::CHECK) {
        std::cout << "Напиток готовится..." << std::endl;
        cash -= prices[option];
        state = STATES::COOK;
    }
}

void Automata::finish() {
    if (state == STATES::COOK) {
        std::cout << "Заберите напиток" << std::endl;
        state = STATES::FINISH;
    }
}
