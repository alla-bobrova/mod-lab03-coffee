// Copyright 2022 GHA Test Team
#include <gtest/gtest.h>
#include "Automata.h"

TEST(AutomataTest, test_on) {
    Automata a;
    a.on();
    EXPECT_EQ(a.getState(), WAIT);
}

TEST(AutomataTest, test_off) {
    Automata a;
    a.off();
    EXPECT_EQ(a.getState(), OFF);
}

TEST(AutomataTest, test_coin) {
    Automata a;
    a.coin(50);
    EXPECT_EQ(a.getCash(), 50);
}

TEST(AutomataTest, test_getMenu) {
    Automata a;
    a.etMenu();
    std::vector<std::string> menu = a.getMenu();
    EXPECT_EQ(menu.size(), 3);
    EXPECT_EQ(menu[0], "Coffee");
    EXPECT_EQ(menu[1], "Tea");
    EXPECT_EQ(menu[2], "Cocoa");
}

TEST(AutomataTest, test_choice) {
    Automata a;
    a.etMenu();
    a.coin(50);
    a.choice(0);
    EXPECT_EQ(a.getState(), CHECK);
    EXPECT_EQ(a.check(), false);
    a.coin(50);
    EXPECT_EQ(a.check(), true);
    a.cook();
    EXPECT_EQ(a.getState(), WAIT);
    EXPECT_EQ(a.getCash(), 0);
}

TEST(AutomataTest, test_cancel) {
    Automata a;
    a.etMenu();
    a.coin(50);
    a.choice(0);
    a.cancel();
    EXPECT_EQ(a.getState(), WAIT);
    EXPECT_EQ(a.getCash(), 50);
}

TEST(AutomataTest, test_finish) {
    Automata a;
    a.etMenu();
    a.coin(50);
    a.choice(0);
    a.coin(50);
    a.cook();
    a.finish();
    EXPECT_EQ(a.getState(), WAIT);
    EXPECT_EQ(a.getCash(), 0);
}
