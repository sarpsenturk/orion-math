#include "orion-math/vector/vector.h"

#include <gtest/gtest.h>

namespace
{
    TEST(Vector, ComponentType)
    {
        /*
         * This a simple type check. We can use std::is_same for this
         */

        using ExpectedType = float;
        const bool is_same =
            std::is_same_v<ExpectedType,
                           orion::Vector<ExpectedType, 2>::Component_t>;
        EXPECT_TRUE(is_same);
    }

    TEST(Vector, DefaultConstructor)
    {
        /*
         * Testing: Default construction of Vector
         * Description:
         *  A default constructed Vector should still initialize its
         *  components array.
         */

        const std::array expected{0, 0, 0};
        const orion::Vector<int, 3> vector;
        EXPECT_EQ(expected, vector.components);
    }

    TEST(Vector, BraceInitialization)
    {
        /*
         * Testing: Brace initialization of Vector
         * Description:
         *  We can directly pass in the components of the vector
         *  since C++ recursively passes the aggregate initialization
         *  parameters to any members than can use it.
         *
         *  We check for equality using std::array since we want to check for
         *  value equality, not pointer.
         */

        const std::array expected{1.0f, 2.0f, 3.0f};
        const orion::Vector<float, 3> vector{1.0f, 2.0f, 3.0f};
        EXPECT_EQ(expected, vector.components);
    }

    TEST(Vector, OperatorSubcript)
    {
        /*
         * Testing:  Subscript ('[]') operator of Vector
         * Description:
         *  This allows us to access each component by index directly as
         *  if we were accessing the underlying array directly.
         */

        const orion::Vector<float, 2> vector{5.f, 10.f};
        EXPECT_EQ(10.f, vector[1]);
    }

    TEST(Vector, OperatorEqualEqual)
    {
        /*
         * Testing: Operator equal-equal ('==') of Vector
         * Description:
         *  Comparison is done by comparing the underlying std::vector
         *  which will do a value comparison for each component.
         */

        const orion::Vector<float, 2> first{1.f, 2.f};
        const orion::Vector<float, 2> second{1.f, 2.f};
        EXPECT_EQ(first, second);
    }

    TEST(Vector, OperatorNotEqual)
    {
        /*
         * Testing: Operator not-equal ('!=') of Vector
         * Description:
         *  This is implemented using operator== as expected.
         */

        const orion::Vector<float, 2> first{0.f, 0.f};
        const orion::Vector<float, 2> second{0.f, 1.f};
        EXPECT_NE(first, second);
    }

    TEST(Vector, OperatorPlus)
    {
        /*
         * Testing: Operator + ('+') of Vector
         * Description:
         *  This is a simple vector addition. Every component is added with
         *  the corresponding component from the rhs Vector.
         */

        const orion::Vector<float, 3> lhs{1.f, 2.f, 3.f};
        const orion::Vector<float, 3> rhs{2.f, 3.f, 4.f};
        const auto expected = orion::Vector<float, 3>{3.f, 5.f, 7.f};
        EXPECT_EQ(expected, lhs + rhs);
    }

    TEST(Vector, OperatorMinus)
    {
        /*
         * Testing: Operator - ('-') of Vector
         * Description:
         *  This is a simple vector subtraction. Every component is subtracted
         * with the corresponding component from the rhs Vector.
         */

        const orion::Vector<float, 3> lhs{1.f, 2.f, 3.f};
        const orion::Vector<float, 3> rhs{2.f, 3.f, 4.f};
        const auto expected = orion::Vector<float, 3>{-1.f, -1.f, -1.f};
        EXPECT_EQ(expected, lhs - rhs);
    }

    TEST(Vector, OperatorStarVector)
    {
        /*
         * Testing: Operator - ('*') of Vector
         * Description:
         * This is a dot product operation. Each component is multiplied with
         * the corresponding component in the other Vector and put into the
         * corresponding component in the new Vector.
         */

        const orion::Vector<float, 3> lhs{1.f, 2.f, 3.f};
        const orion::Vector<float, 3> rhs{2.f, 3.f, 4.f};
        const auto expected = orion::Vector<float, 3>{2.f, 6.f, 12.f};
        EXPECT_EQ(expected, lhs * rhs);
    }

    TEST(Vector, OperatorStarScalar)
    {
        /*
         * Testing: Operator - ('*') of Vector
         * Description:
         * This is a dot product operation. Each component is multiplied with
         * the corresponding component in the other Vector and put into the
         * corresponding component in the new Vector.
         */

        const orion::Vector<float, 3> lhs{1.f, 2.f, 3.f};
        const float rhs = 5.f;
        const auto expected = orion::Vector<float, 3>{5.f, 10.f, 15.f};
        EXPECT_EQ(expected, lhs * rhs);
    }

    TEST(Vector, SqrMagnitude)
    {
        /*
         * Testing: Square magnitude member function
         * Description:
         *  Vector::sqr_magnitude() returns the squared magnitude of the vector.
         *  This might be preferable to use in situations when you only need
         *  to compare magnitudes rather than needing the specific value
         *  since a square root operation can be costly.
         */

        const orion::Vector<float, 3> vector{2.f, 4.f, 6.f};
        EXPECT_EQ(56.f, vector.sqr_magnitude());
    }

    TEST(Vector, Magnitude)
    {
        /*
         * Testing: magnitude member function
         * Description:
         *  Vector::magnitude() returns the magnitude of the function
         *  using sqrt(sqr_magnitude()). This is more costly therefore should
         *  be used only when needed.
         */

        const orion::Vector<float, 3> vector{1.f, 2.f, 2.f};
        EXPECT_EQ(0.f, vector.magnitude() - 3.f);
    }
} // namespace
