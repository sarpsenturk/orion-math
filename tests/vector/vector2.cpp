#include "orion-math/vector/vector2.h"

#include <gtest/gtest.h>

namespace
{
    TEST(Vector2, SingleArgumentCtor)
    {
        /*
         * Testing: Single argument explicit ctor of Vector2_t
         * Description:
         *  It is possible to initialize every component of a Vector
         *  by specifying a single initializer value.
         */

        const std::array expected{5, 5};
        const orion::Vector2_t<int> vector(5);
        EXPECT_EQ(expected, vector.components);
    }

    TEST(Vector2, TwoArgumentCtor)
    {
        /*
         * Testing: Two argument ctor of Vector2_t
         * Description:
         *  Constructing a Vector2_t by specifying both components
         *  in the constructor
         */

        const std::array expected{42, 100};
        const orion::Vector2_t<int> vector(42, 100);
        EXPECT_EQ(expected, vector.components);
    }

    TEST(Vector2, ComponentXGet)
    {
        /*
         * Testing: Member function Vector2_t::x() as getter
         * Description:
         *  Member function x() returns reference to components[0]
         */

        const orion::Vector2_t<int> vector(42, 0);
        EXPECT_EQ(42, vector.x());
    }

    TEST(Vector2, ComponentXSet)
    {
        /*
         * Testing: Member function Vector2_t::x() as setter
         * Description:
         *  Member function x() returns reference to components[0]
         *  which can be used as setter in non-const context
         */

        orion::Vector2_t<int> vector(0);
        vector.x() = 42;
        EXPECT_EQ(42, vector.x());
    }

    TEST(Vector2, ComponentYGet)
    {
        /*
         * Testing: Member function Vector2_t::y() as getter
         * Description:
         *  Member function y() returns reference to components[1]
         */

        const orion::Vector2_t<int> vector(0, 42);
        EXPECT_EQ(42, vector.y());
    }

    TEST(Vector2, ComponentYSet)
    {
        /*
         * Testing: Member function Vector2_t::y() as setter
         * Description:
         *  Member function y() returns reference to components[1]
         *  which can be used as setter in non-const context
         */

        orion::Vector2_t<int> vector(0);
        vector.y() = 42;
        EXPECT_EQ(42, vector.y());
    }
} // namespace
