// Copyright 2022 GHA Test Team
#include "Automata.h"
#include <gtest/gtest.h>

class AutomataTest : public ::testing::Test {
protected:
    Automata automata;
};

TEST_F(AutomataTest, On) {
    automata.on();
    EXPECT_EQ(automata.getState(), WAIT);
    automata.on();
    EXPECT_EQ(automata.getState(), WAIT);
}

TEST_F(AutomataTest, Off) {
    automata.off();
    EXPECT_EQ(automata.getState(), OFF);
    automata.on();
    automata.off();
    EXPECT_EQ(automata.getState(), OFF);
    automata.choice(1);
    automata.off();
    EXPECT_EQ(automata.getState(), CHECK);
}

TEST_F(AutomataTest, Coin) {
    automata.coin(10);
    EXPECT_EQ(automata.getState(), WAIT);
    EXPECT_EQ(automata.cash, 10);
    automata.choice(1);
    automata.coin(20);
    EXPECT_EQ(automata.getState(), ACCEPT);
    EXPECT_EQ(automata.cash, 30);
}

TEST_F(AutomataTest, GetMenu) {
    automata.getMenu();
    EXPECT_EQ(automata.getState(), WAIT);
}

TEST_F(AutomataTest, Choice) {
    automata.choice(0);
    EXPECT_EQ(automata.getState(), WAIT);
    automata.choice(10);
    EXPECT_EQ(automata.getState(), WAIT);
    automata.choice(1);
    EXPECT_EQ(automata.getState(), ACCEPT);
    EXPECT_EQ(automata.sum, 50);
}

TEST_F(AutomataTest, Check) {
    EXPECT_FALSE(automata.check());
    automata.choice(1);
    automata.coin(20);
    EXPECT_TRUE(automata.check());
}

TEST_F(AutomataTest, Cancel) {
    automata.choice(1);
    automata.coin(20);
    automata.check();
    automata.cancel();
    EXPECT_EQ(automata.getState(), WAIT);
    EXPECT_EQ(automata.cash, 0);
    EXPECT_EQ(automata.choice_, 0);
}

TEST_F(AutomataTest, Cook) {
    automata.choice(1);
    automata.coin(50);
    automata.check();
    automata.cook();
    EXPECT_EQ(automata.getState(), WAIT);
    EXPECT_EQ(automata.cash, 0);
    EXPECT_EQ(automata.choice_, 0);
}
