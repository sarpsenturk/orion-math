#include <cpp-starter/cpp-starter.h>
#include <gtest/gtest.h>

TEST(CppStarterTest, ReturnOk)
{
    EXPECT_EQ(cpp_starter::return_ok(), 0);
}
