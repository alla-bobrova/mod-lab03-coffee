#include <iostream>
#include <string>
using namespace std;

enum STATES {OFF, ON, ACCEPT, CHECK, COOK};

class Automata {
private:
    int cash;
    string menu[3] = {"Coffee", "Tea", "Milk"};
    int prices[3] = {50, 30, 40};
    STATES state;

public:
    Automata() {
        cash = 0;
        state = OFF;
    }

    void on() {
        if (state == OFF) {
            state = ON;
            cout << "Automata is on\n";
        }
    }

    void off() {
        if (state == ON) {
            state = OFF;
            cout << "Automata is off\n";
        }
    }

    void coin(int sum) {
        if (state == ACCEPT) {
            cash += sum;
            cout << "Added " << sum << " to cash\n";
        }
    }

    void getMenu() {
        if (state == ACCEPT) {
            cout << "Menu:\n";
            for (int i = 0; i < 3; i++) {
                cout << i + 1 << ". " << menu[i] << " - " << prices[i] << " rubles\n";
            }
        }
    }

    void getState() {
        cout << "Current state is ";
        switch (state) {
            case OFF:
                cout << "OFF\n";
                break;
            case ON:
                cout << "ON\n";
                break;
            case ACCEPT:
                cout << "ACCEPT\n";
                break;
            case CHECK:
                cout << "CHECK\n";
                break;
            case COOK:
                cout << "COOK\n";
                break;
        }
    }

    void choice(int n) {
        if (state == ACCEPT) {
            if (n >= 1 && n <= 3) {
                int price = prices[n - 1];
                if (cash >= price) {
                    state = CHECK;
                    cout << "Selected " << menu[n - 1] << " for " << price << " rubles\n";
                } else {
                    cout << "Not enough money\n";
                }
            } else {
                cout << "Invalid choice\n";
            }
        }
    }

    void check() {
        if (state == CHECK) {
            cout << "Checking payment...\n";
            if (cash >= prices[state - 1]) {
                state = COOK;
                cout << "Payment accepted\n";
                cook();
            } else {
                cout << "Not enough money\n";
                state = ACCEPT;
            }
        }
    }

    void cancel() {
        if (state == CHECK || state == COOK) {
            int change = cash;
            cash = 0;
            state = ACCEPT;
            cout << "Canceled. Returning " << change << " rubles\n";
        }
    }

    void cook() {
        cout << "Cooking...\n";
        cout << "Your drink is ready. Enjoy!\n";
        cash -= prices[state - 1];
        finish();
    }

    void finish() {
        state = ACCEPT;
        cout << "Transaction complete. Returning to menu\n";
    }
};

