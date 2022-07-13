#include "orion-math/common.h"

#include <gtest/gtest.h>

namespace {
    TEST(ConstexprSqrt, Integral)
    {
        /*
         * Testing: constexpr sqrt with an integral value
         */


        EXPECT_DOUBLE_EQ(1.4142135623730950488, orion::sqrt(2));
    }

    TEST(ConstexprSqrt, IntegerResult)
    {
        /*
         * Testing:: constexpr sqrt when the result is an integer
         */

        EXPECT_EQ(4, orion::sqrt(16));
    }

    TEST(ConstexprSqrt, Zero)
    {
        /*
         * Testing:: constexpr sqrt with input 0
         */

        EXPECT_EQ(0, orion::sqrt(0));
    }
}
