
class Automata {
private:
    std::vector<std::string> menu;
    std::vector<int> prices;
public:
    Automata();
    void on();
    void off();
    void coin(int);
    void printMenu();
    void choice(int);
    void cancel();
    void cook();
    bool check();
    void finish();
    void setCash(int);
    void setState(State);
};
