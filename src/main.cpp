#include "Automata.h"
#include <locale>
#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    Automata coffeeMachine;
    coffeeMachine.on();
    coffeeMachine.coin(100);
    coffeeMachine.getMenu();
    coffeeMachine.choice(1);
    coffeeMachine.check();
    coffeeMachine.cook();
    coffeeMachine.finish();
    coffeeMachine.off();
    return 0;

}
