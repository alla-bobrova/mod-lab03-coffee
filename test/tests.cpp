// Copyright 2022 GHA Test Team
#include "Automata.h"	
#include "Automata.h"

TEST(AutomataTest, TestDefaultConstructor) {
    Automata a;
    EXPECT_EQ(a.getState(), STATES::OFF);
}

TEST(AutomataTest, TestOn) {
    Automata a;
    a.on();
    EXPECT_EQ(a.getState(), STATES::WAIT);
    a.on(); // already on
    EXPECT_EQ(a.getState(), STATES::WAIT);
}

TEST(AutomataTest, TestOff) {
    Automata a;
    a.off(); // already off
    EXPECT_EQ(a.getState(), STATES::OFF);
    a.on();
    a.off();
    EXPECT_EQ(a.getState(), STATES::OFF);
}

TEST(AutomataTest, TestCoin) {
    Automata a;
    a.coin(10);
    EXPECT_EQ(a.getState(), STATES::ACCEPT);
    a.coin(20);
    EXPECT_EQ(a.getState(), STATES::ACCEPT);
    a.on();
    a.coin(50); // cannot add coins in WAIT state
    EXPECT_EQ(a.getState(), STATES::WAIT);
}

TEST(AutomataTest, TestChoice) {
    Automata a;
    a.choice(2); // cannot choose in ACCEPT state
    EXPECT_EQ(a.getState(), STATES::WAIT);
    a.on();
    a.choice(0); // wrong drink number
    EXPECT_EQ(a.getState(), STATES::WAIT);
    a.choice(4); // wrong drink number
    EXPECT_EQ(a.getState(), STATES::WAIT);
    a.choice(1);
    EXPECT_EQ(a.getState(), STATES::CHECK);
}

TEST(AutomataTest, TestCheck) {
    Automata a;
    a.check(); // cannot check in WAIT state
    EXPECT_EQ(a.getState(), STATES::WAIT);
    a.on();
    a.check(); // cannot check in ACCEPT state
    EXPECT_EQ(a.getState(), STATES::ACCEPT);
    a.choice(2);
    a.check();
    EXPECT_EQ(a.getState(), STATES::COOK);
}

TEST(AutomataTest, TestCancel) {
    Automata a;
    a.cancel(); // cannot cancel in WAIT state
    EXPECT_EQ(a.getState(), STATES::WAIT);
    a.on();
    a.cancel(); // can cancel in WAIT state
    EXPECT_EQ(a.getState(), STATES::WAIT);
    a.choice(3);
    a.check();
    a.cancel();
    EXPECT_EQ(a.getState(), STATES::WAIT);
}

TEST(AutomataTest, TestCook) {
    Automata a;
    a.cook(); // cannot cook in WAIT state
    EXPECT_EQ(a.getState(), STATES::WAIT);
    a.on();
    a.cook(); // cannot cook in CHECK state
    EXPECT_EQ(a.getState(), STATES::CHECK);
    a.choice(1);
    a.cook(); // can cook in COOK state
    EXPECT_EQ(a.getState(), STATES::WAIT);
}

TEST(AutomataTest, TestFinish) {
    Automata a;
    a.finish(); // cannot finish in COOK state
    EXPECT_EQ(a.getState(), STATES::WAIT);
    a.on();
    a.choice(3);
    a.check();
    a.finish(); // can finish in COOK state
    EXPECT_EQ(a.getState(), STATES::WAIT);
}
