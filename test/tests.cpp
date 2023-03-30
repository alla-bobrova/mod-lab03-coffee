// Copyright 2022 GHA Test Team
#include "Automata.h"
#include <gtest/gtest.h>

TEST(AutomataTest, DefaultConstructor) {
    Automata a;
    EXPECT_EQ(a.getState(), Automata::OFF);
    EXPECT_EQ(a.getCash(), 0);
}

TEST(AutomataTest, On) {
    Automata a;
    a.on();
    EXPECT_EQ(a.getState(), Automata::WAIT);
}

TEST(AutomataTest, Off) {
    Automata a;
    a.on();
    a.off();
    EXPECT_EQ(a.getState(), Automata::OFF);
}

TEST(AutomataTest, Coin) {
    Automata a;
    a.on();
    a.coin(50);
    EXPECT_EQ(a.getCash(), 50);
    a.coin(25);
    EXPECT_EQ(a.getCash(), 75);
}


TEST(AutomataTest, Choice) {
    Automata a;
    a.on();
    testing::internal::CaptureStdout();
    a.choice(1);
    std::string output = testing::internal::GetCapturedStdout();
    std::string expected = "You have chosen Coffee\n";
    EXPECT_EQ(output, expected);
}

TEST(AutomataTest, CheckSuccess) {
    Automata a;
    a.on();
    a.coin(50);
    a.choice(1);
    EXPECT_TRUE(a.check());
    EXPECT_EQ(a.getState(), Automata::ACCEPT);
}

TEST(AutomataTest, GetMenu) {
    Automata a;
    a.on();
    std::stringstream ss;
    a.getMenu(ss);
    EXPECT_EQ(ss.str(), "Menu:\n1. Coffee - 50\n2. Tea - 30\n");
}

TEST(AutomataTest, CheckFailure) {
    Automata a;
    a.on();
    a.coin(25);
    EXPECT_FALSE(a.check());
    std::stringstream ss;
    a.getChoice(ss);
    EXPECT_EQ(ss.str(), "Not enough money\n");
    EXPECT_EQ(a.getState(), Automata::WAIT);
}

TEST(AutomataTest, Cancel) {
    Automata a;
    a.on();
    a.coin(50);
    a.choice(1);
    a.check();
    testing::internal::CaptureStdout();
    a.cancel();
    std::string output = testing::internal::GetCapturedStdout();
    std::string expected = "Transaction canceled\n";
    EXPECT_EQ(output, expected);
    EXPECT_EQ(a.getState(), Automata::WAIT);
    EXPECT_EQ(a.getCash(), 0);
}

TEST(AutomataTest, Cook) {
    Automata a;
    a.on();
    a.coin(50);
    a.choice(1);
    a.check();
    a.cook();
    EXPECT_EQ(a.getState(), Automata::COOK);
}


