// Copyright 2022 UNN-IASR
#include "Automata.h"
#include <locale>
#include <iostream>

  int main() { 
      setlocale(LC_ALL, "Russian");
      Automata vendingMachine;
      vendingMachine.on();
      vendingMachine.coin(0.5);
      vendingMachine.coin(1.0);
      vendingMachine.coin(0.5);
      vendingMachine.getMenu();
      vendingMachine.choice(0);
      if (vendingMachine.check()) {
          vendingMachine.cook();
          vendingMachine.finish();
      } else {
          vendingMachine.cancel();
      }
      vendingMachine.off();
      return 0;
  }
