// Copyright 2022 GHA Test Team
#include "Automata.h"
#include "gtest/gtest.h"

TEST(AutomataTest, TurnOnTest) {
    Automata a;
    a.on();
    EXPECT_EQ(a.getState(), WAIT);
}

TEST(AutomataTest, TurnOffTest) {
    Automata a;
    a.on();
    a.off();
    EXPECT_EQ(a.getState(), OFF);
}

TEST_F(AutomataTest_InsertCoinTest, InsertCoinTest) {
    Automata a;
    a.on();
    a.coin(10);
    EXPECT_EQ(a.getCash(), 10); // use the getter method instead of direct access
}

TEST_F(AutomataTest_CancelTest, CancelTest) {
    Automata a;
    a.on();
    a.coin(10);
    a.cancel();
    EXPECT_EQ(a.getCash(), 0); // use the getter method instead of direct access
}

TEST_F(AutomataTest_FinishTest, FinishTest) {
    Automata a;
    a.on();
    a.coin(10);
    a.choice(1);
    EXPECT_EQ(a.getCash(), 0); // use the getter method instead of direct access
}

TEST(AutomataTest, GetMenuTest) {
    Automata a;
    std::stringstream ss;
    std::streambuf* old_cout = std::cout.rdbuf(ss.rdbuf());
    a.getMenu();
    std::cout.rdbuf(old_cout); // restore cout buffer
    std::string expected_output =
        "Меню напитков:\n"
        "1. Кофе - 50 рублей.\n"
        "2. Чай - 30 рублей.\n"
        "3. Какао - 40 рублей.\n";
    EXPECT_EQ(ss.str(), expected_output);
}

TEST(AutomataTest, ChooseDrinkTest) {
    Automata a;
    a.on();
    a.coin(50);
    a.choice(1); // choose tea
    EXPECT_EQ(a.getState(), CHECK);
}

TEST(AutomataTest, CheckAvailabilityTest) {
    Automata a;
    a.on();
    a.coin(10);
    a.choice(1); // choose tea
    EXPECT_EQ(a.check(), false);
    a.coin(20);
    EXPECT_EQ(a.check(), false);
    a.coin(10);
    EXPECT_EQ(a.check(), false);
    a.coin(30);
    EXPECT_EQ(a.check(), true);
}

