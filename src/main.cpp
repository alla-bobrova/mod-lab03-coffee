#include "Automata.h"
#include <locale>
#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    Automata coffeeMachine;
    coffeeMachine.on();
    coffeeMachine.getMenu(); // вызываем новый метод
    coffeeMachine.choice = 1; // изменяем choice через доступный public член
    coffeeMachine.check();
    coffeeMachine.off();

    return 0;
}

