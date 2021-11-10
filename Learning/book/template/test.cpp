#include <gtest/gtest.h>

#include "main.hpp"

TEST(test, ok)
{
    EXPECT_EQ(is_unique("hoge"), true);
}

TEST(test, ng)
{
    EXPECT_EQ(is_unique("hopo"), false);
}