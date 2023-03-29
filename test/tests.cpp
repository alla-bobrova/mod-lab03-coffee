// Copyright 2022 GHA Test Team
#include <gtest/gtest.h>
#include "Automata.h"

TEST(task1, test1) {
    Automata a;
    EXPECT_EQ(Automata::State::OFF, a.getState());
}

TEST(task2, test2) {
    Automata a;
    a.on();
    EXPECT_EQ(Automata::State::WAIT, a.getState());
    a.off();
    EXPECT_EQ(Automata::State::OFF, a.getState());
}

TEST(task3, test3) {
    Automata a;
    a.on();
    a.coin(100);
    a.choice(0);
    ASSERT_EQ(a.getState(), Automata::State::CHECK);
    ASSERT_TRUE(a.check());
    ASSERT_EQ(a.getState(), Automata::State::COOK);
}

TEST(task4, test4) {
    Automata a;
    a.on();
    a.coin(50);
    a.choice(0);
    ASSERT_EQ(Automata::State::ACCEPT, a.getState());
    int refund = a.cancel();
    ASSERT_EQ(50, refund);
    ASSERT_EQ(Automata::State::WAIT, a.getState());
}
