#include "param.hpp"
#include "gtest/gtest.h"

Param *param;

TEST(PARAM, constructor)
{
    param = new Param("a", "b", "c", "d");
    
    EXPECT_NE(param, nullptr);
}

TEST(PARAM, getMethods1)
{
    EXPECT_EQ(param->GetParam1(), "a");
}

TEST(PARAM, getMethods2)
{
    EXPECT_EQ(param->GetParam2(), "b");
}

TEST(PARAM, getMethods3)
{
    EXPECT_EQ(param->GetParam3(), "c");
}

TEST(PARAM, getMethods4)
{
    EXPECT_EQ(param->GetParam1(), "d");
}