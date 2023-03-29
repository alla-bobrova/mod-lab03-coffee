#include "Automata.h"
#include <iostream>
using namespace std;

Automata::Automata() {
    cash = 0;
    state = OFF;
}

void Automata::on() {
    if (state == OFF) {
        state = WAIT;
        cout << "Автомат включен\n";
    }
}

void Automata::off() {
    if (state == WAIT) {
        state = OFF;
        cout << "Автомат выключен\n";
    }
}

void Automata::coin(int money) {
    if (state == WAIT || state == ACCEPT) {
        state = ACCEPT;
        cash += money;
        cout << "Добавлено " << money << " рублей. Всего " << cash << " рублей.\n";
    }
}

void Automata::getMenu() {
    cout << "Меню напитков:\n";
    for (int i = 0; i < sizeof(menu) / sizeof(menu[0]); i++) {
        cout << i + 1 << ". " << menu[i] << " - " << prices[i] << " рублей.\n";
    }
}

STATES Automata::getState() {
    return state;
}

void Automata::choice(int drink) {
    if (state == ACCEPT) {
        state = CHECK;
        choiceDrink = drink;
        cout << "Выбран напиток \"" << menu[choiceDrink] << "\" за " << prices[choiceDrink] << " рублей.\n";

    }
}

bool Automata::check() {
    if (state == CHECK) {
        if (cash >= prices[choiceDrink]) {
            cook();
            return true;
        }
        else {
            state = WAIT;
            cout << "Недостаточно денег\n";
            return false;
        }
    }
    return false;
}

void Automata::cancel() {
    if (state == ACCEPT || state == CHECK) {
        state = WAIT;
        cash -= prices[choiceDrink];
        cout << "Отмена заказа.\n";
    }
}

void Automata::cook() {
    if (state == COOK) {
        cout << "Приготовление напитка \"" << menu[choiceDrink] << "\"...\n";
        cash = 0;
        state = WAIT;
    }
}
void Automata::finish() {
    cash -= prices[choiceDrink];
    state = WAIT;
    cout << "Спасибо за покупку! Заберите свой \"" << menu[choiceDrink] << "\".\n";
}


