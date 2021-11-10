#include <gtest/gtest.h>

#include "main.hpp"

TEST(test1, ok) { EXPECT_EQ(is_unique("hoge"), true); }
TEST(test1, ng) { EXPECT_EQ(is_unique("hopo"), false); }

TEST(test2, ok) { EXPECT_EQ(is_sorting_words("hoge", "oghe"), true); }
TEST(test2, ng) { EXPECT_EQ(is_sorting_words("hoge", "fuga"), false); }

TEST(test3, ok) { EXPECT_EQ(replace_space("hoge"), "hoge"); }
TEST(test3, ng) { EXPECT_EQ(replace_space(" ho g e '"), "%20ho%20g%20e%20'"); }
