#include <cstdio>
#include "gtest/gtest.h"
#include "ThisDir.h"

GTEST_TEST(Test1, AlwaysTrue)
{
    puts(ABSOLUTE_TEST_DIRECTORY);
    puts(TestFile("inp.ans"));
    EXPECT_EQ(1, 1);
}

GTEST_TEST(Test1, AlwaysFalse)
{
    EXPECT_NE(1, 0);
}
