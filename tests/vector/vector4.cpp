#include "orion-math/vector/vector4.h"

#include <gtest/gtest.h>

namespace
{
    TEST(Vector4, SingleArgumentCtor)
    {
        /*
         * Testing: Single argument explicit ctor of Vector4_t
         * Description:
         *  It is possible to initialize every component of a Vector
         *  by specifying a single initializer value.
         */

        const std::array expected{5, 5, 5, 5};
        const orion::Vector4_t<int> vector(5);
        EXPECT_EQ(expected, vector.components);
    }

    TEST(Vector4, ThreeArgumentCtor)
    {
        /*
         * Testing: Two argument ctor of Vector4_t
         * Description:
         *  Constructing a Vector4_t by specifying all 4 components
         *  in the constructor
         */

        const std::array expected{42, 100, 21, 10};
        const orion::Vector4_t<int> vector(42, 100, 21, 10);
        EXPECT_EQ(expected, vector.components);
    }

    TEST(Vector4, ComponentXGet)
    {
        /*
         * Testing: Member function Vector4_t::x() as getter
         * Description:
         *  Member function x() returns reference to components[0]
         */

        const orion::Vector4_t<int> vector(42, 0, 0, 0);
        EXPECT_EQ(42, vector.x());
    }

    TEST(Vector4, ComponentXSet)
    {
        /*
         * Testing: Member function Vector4_t::x() as setter
         * Description:
         *  Member function x() returns reference to components[0]
         *  which can be used as setter in non-const context
         */

        orion::Vector4_t<int> vector(0);
        vector.x() = 42;
        EXPECT_EQ(42, vector.x());
    }

    TEST(Vector4, ComponentYGet)
    {
        /*
         * Testing: Member function Vector4_t::y() as getter
         * Description:
         *  Member function y() returns reference to components[1]
         */

        const orion::Vector4_t<int> vector(0, 42, 0, 0);
        EXPECT_EQ(42, vector.y());
    }

    TEST(Vector4, ComponentYSet)
    {
        /*
         * Testing: Member function Vector4_t::y() as setter
         * Description:
         *  Member function y() returns reference to components[1]
         *  which can be used as setter in non-const context
         */

        orion::Vector4_t<int> vector(0);
        vector.y() = 42;
        EXPECT_EQ(42, vector.y());
    }

    TEST(Vector4, ComponentZGet)
    {
        /*
         * Testing: Member function Vector4_t::z() as getter
         * Description:
         *  Member function z() returns reference to components[2]
         */

        const orion::Vector4_t<int> vector(0, 0, 42, 0);
        EXPECT_EQ(42, vector.z());
    }

    TEST(Vector4, ComponentZSet)
    {
        /*
         * Testing: Member function Vector4_t::z() as setter
         * Description:
         *  Member function z() returns reference to components[2]
         *  which can be used as setter in non-const context
         */

        orion::Vector4_t<int> vector(0);
        vector.z() = 42;
        EXPECT_EQ(42, vector.z());
    }

    TEST(Vector4, ComponentWGet)
    {
        /*
         * Testing: Member function Vector4_t::w() as getter
         * Description:
         *  Member function w() returns reference to components[3]
         */

        const orion::Vector4_t<int> vector(0, 0, 0, 42);
        EXPECT_EQ(42, vector.w());
    }

    TEST(Vector4, ComponentWSet)
    {
        /*
         * Testing: Member function Vector4_t::w() as setter
         * Description:
         *  Member function w() returns reference to components[3]
         *  which can be used as setter in non-const context
         */

        orion::Vector4_t<int> vector(0);
        vector.w() = 42;
        EXPECT_EQ(42, vector.w());
    }
} // namespace
