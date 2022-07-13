#include "orion-math/vector/vector3.h"

#include <gtest/gtest.h>

namespace
{
    TEST(Vector3, SingleArgumentCtor)
    {
        /*
         * Testing: Single argument explicit ctor of Vector3_t
         * Description:
         *  It is possible to initialize every component of a Vector
         *  by specifying a single initializer value.
         */

        const std::array expected{5, 5, 5};
        const orion::Vector3_t<int> vector(5);
        EXPECT_EQ(expected, vector.components);
    }

    TEST(Vector3, ThreeArgumentCtor)
    {
        /*
         * Testing: Two argument ctor of Vector3_t
         * Description:
         *  Constructing a Vector3_t by specifying all 3 components
         *  in the constructor
         */

        const std::array expected{42, 100, 21};
        const orion::Vector3_t<int> vector(42, 100, 21);
        EXPECT_EQ(expected, vector.components);
    }

    TEST(Vector3, ComponentXGet)
    {
        /*
         * Testing: Member function Vector3_t::x() as getter
         * Description:
         *  Member function x() returns reference to components[0]
         */

        const orion::Vector3_t<int> vector(42, 0, 0);
        EXPECT_EQ(42, vector.x());
    }

    TEST(Vector3, ComponentXSet)
    {
        /*
         * Testing: Member function Vector3_t::x() as setter
         * Description:
         *  Member function x() returns reference to components[0]
         *  which can be used as setter in non-const context
         */

        orion::Vector3_t<int> vector(0);
        vector.x() = 42;
        EXPECT_EQ(42, vector.x());
    }

    TEST(Vector3, ComponentYGet)
    {
        /*
         * Testing: Member function Vector3_t::y() as getter
         * Description:
         *  Member function y() returns reference to components[1]
         */

        const orion::Vector3_t<int> vector(0, 42, 0);
        EXPECT_EQ(42, vector.y());
    }

    TEST(Vector3, ComponentYSet)
    {
        /*
         * Testing: Member function Vector3_t::y() as setter
         * Description:
         *  Member function y() returns reference to components[1]
         *  which can be used as setter in non-const context
         */

        orion::Vector3_t<int> vector(0);
        vector.y() = 42;
        EXPECT_EQ(42, vector.y());
    }

    TEST(Vector3, ComponentZGet)
    {
        /*
         * Testing: Member function Vector3_t::z() as getter
         * Description:
         *  Member function z() returns reference to components[2]
         */

        const orion::Vector3_t<int> vector(0, 0, 42);
        EXPECT_EQ(42, vector.z());
    }

    TEST(Vector3, ComponentZSet)
    {
        /*
         * Testing: Member function Vector3_t::z() as setter
         * Description:
         *  Member function z() returns reference to components[2]
         *  which can be used as setter in non-const context
         */

        orion::Vector3_t<int> vector(0);
        vector.z() = 42;
        EXPECT_EQ(42, vector.z());
    }
} // namespace
