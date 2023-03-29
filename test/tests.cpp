// Copyright 2022 GHA Test Team
#include <gtest/gtest.h>
#include "Automata.h"

TEST(AutomataTest, On) {
    Automata a;
    a.on();
    ASSERT_EQ(ON, a.getState());
}
TEST(AutomataTest, CancelAfterCoin)
{
    Automata a;
    a.on();
    a.coin(50);
    a.cancel();
    EXPECT_EQ(a.getState(), WAIT);
    EXPECT_EQ(a.cash, 0);
}

TEST(AutomataTest, CheckWithNoChoice)
{
    Automata a;
    a.on();
    a.coin(10);
    a.check();
    EXPECT_EQ(a.getState(), WAIT);
    EXPECT_EQ(a.cash, 10);
}

TEST(AutomataTest, CheckWithEnoughMoney)
{
    Automata a;
    a.on();
    a.coin(50);
    a.choice(0);
    a.check();
    EXPECT_EQ(a.getState(), COOK);
}

TEST(AutomataTest, CheckWithNotEnoughMoney)
{
    Automata a;
    a.on();
    a.coin(10);
    a.choice(0);
    a.check();
    EXPECT_EQ(a.getState(), WAIT);
}

TEST(AutomataTest, Cook)
{
    Automata a;
    a.on();
    a.coin(50);
    a.choice(0);
    a.check();
    a.cook();
    EXPECT_EQ(a.getState(), WAIT);
    EXPECT_EQ(a.cash, 40);
}

TEST(AutomataTest, Finish)
{
    Automata a;
    a.on();
    a.coin(50);
    a.choice(0);
    a.check();
    a.cook();
    a.finish();
    EXPECT_EQ(a.getState(), WAIT);
    EXPECT_EQ(a.cash, 0);
}
