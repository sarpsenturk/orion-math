#include "orion-math/matrix/matrix.h"

#include "orion-math/vector/vector.h"

#include <gtest/gtest.h>

namespace
{
    TEST(Matrix, ComponentType)
    {
        /*
         * This a simple type check. We can use std::is_same for this
         */

        using ExpectedType = float;
        const bool is_same = std::is_same_v<ExpectedType, orion::Matrix<float, 1, 1>::Component_t>;
        EXPECT_TRUE(is_same);
    }

    TEST(Matrix, DefaultInitialization)
    {
        /*
         * Testing: Default initialization of Matrix
         * Description:
         *  Components of the matrix should be default initialized
         */

        const std::array<std::array<float, 2>, 2> expected{};
        const orion::Matrix<float, 2, 2> matrix;
        EXPECT_EQ(expected, matrix.matrix);
    }

    TEST(Matrix, BraceInitialization)
    {
        /*
         * Testing: Brace initialization of Matrix
         * Description:
         *  We can directly pass in the components of the matrix
         *  since C++ recursively passes the aggregate initialization
         *  parameters to any members than can use it.
         */

        const std::array<std::array<float, 2>, 2> expected{1.f, 2.f, 3.f, 4.f};
        const orion::Matrix<float, 2, 2> matrix{1.f, 2.f, 3.f, 4.f};
        EXPECT_EQ(expected, matrix.matrix);
    }

    TEST(Matrix, OperatorSubcript)
    {
        /*
         * Testing:  Subscript ('[]') operator of Matrix
         * Description:
         *  This allows us to access each component by index directly as
         *  if we were accessing the underlying array directly.
         */

        const std::array<float, 2> expected{42.f, 70.f};
        const orion::Matrix<float, 2, 2> matrix{5.f, 10.f, expected};
        EXPECT_EQ(expected, matrix[1]);
    }

    TEST(Matrix, OperatorEqualEqual)
    {
        /*
         * Testing: Operator equal-equal ('==') of Matrix
         * Description:
         *  Comparison is done by comparing the underlying std::array
         *  which will do a value comparison for each component.
         */

        const orion::Matrix<float, 2, 2> first{1.f, 2.f, 3.f, 4.f};
        const orion::Matrix<float, 2, 2> second{1.f, 2.f, 3.f, 4.f};
        EXPECT_EQ(first, second);
    }

    TEST(Matrix, OperatorNotEqual)
    {
        /*
         * Testing: Operator not-equal ('!=') of Matrix
         * Description:
         *  This is implemented using operator== as expected.
         */

        const orion::Matrix<float, 2, 2> first{1.f, 2.f, 3.f, 4.f};
        const orion::Matrix<float, 2, 2> second;
        EXPECT_NE(first, second);
    }

    TEST(Matrix, OperatorPlus)
    {
        /*
         * Testing: Operator + ('+') of Matrix>
         * Description:
         *  This will add every component of the matrix with the corresponding
         *  component of the rhs matrix. This operation requires both matrices to
         *  be of the same size.
         */

        const orion::Matrix<float, 2, 2> lhs{1.f, 2.f, 3.f, 4.f};
        const orion::Matrix<float, 2, 2> rhs{5.f, 6.f, 7.f, 8.f};
        const auto expected = orion::Matrix<float, 2, 2>{6.f, 8.f, 10.f, 12.f};
        EXPECT_EQ(expected, lhs + rhs);
    }

    TEST(Matrix, OperatorMinus)
    {
        /*
         * Testing: Operator - ('-') of Matrix>
         * Description:
         *  This will subtract every component of the matrix with the corresponding
         *  component of the rhs matrix. This operation requires both matrices to
         *  be of the same size.
         */

        const orion::Matrix<float, 2, 2> lhs{1.f, 2.f, 3.f, 4.f};
        const orion::Matrix<float, 2, 2> rhs{5.f, 6.f, 7.f, 8.f};
        const auto expected = orion::Matrix<float, 2, 2>{-4.f, -4.f, -4.f, -4.f};
        EXPECT_EQ(expected, lhs - rhs);
    }

    TEST(Matrix, OperatorStarScalar)
    {
        /*
         * Testing: Operator * ('*') of Matrix
         * Description:
         *  This is a scalar multiplication. Each component of the
         *  matrix is multiplied by the scalar input value
         */

        const orion::Matrix<float, 2, 2> matrix{1.f, 2.f, 3.f, 4.f};
        const auto expected = orion::Matrix<float, 2, 2>{2.f, 4.f, 6.f, 8.f};
        EXPECT_EQ(expected, matrix * 2);
    }

    TEST(Matrix, MulSqaureMatrix)
    {
        /*
         * Testing: Operator * ('*') of Matrix
         * Description:
         *  This is a matrix multiplication. It is only defined if the
         *  number of columns on the lhs is equal to the number of rows
         *  on the rhs. This is testing 2 equal order square matrices.
         */

        const orion::Matrix<float, 2, 2> lhs{1.f, 2.f, 3.f, 4.f};
        const orion::Matrix<float, 2, 2> rhs{5.f, 6.f, 7.f, 8.f};
        const orion::Matrix<float, 2, 2> expected{19.f, 22.f, 43.f, 50.f};
        const auto multiplied = lhs * rhs;
        EXPECT_EQ(expected, multiplied);
    }

    TEST(Matrix, MulColumnVector)
    {
        /*
         * Testing: Operator * ('*') of Matrix
         * Description:
         *  This is a matrix multiplication. It is only defined if the
         *  number of columns on the lhs is equal to the number of rows
         *  on the rhs. This is testing a square matrix and a column vector (nx1)
         */

        const orion::Matrix<float, 2, 2> lhs{1.f, 2.f, 3.f, 4.f};
        const orion::Matrix<float, 2, 1> rhs{5.f, 6.f};
        const orion::Matrix<float, 2, 1> expected{17.f, 39.f};
        EXPECT_EQ(expected, lhs * rhs);
    }

    TEST(Matrix, MulRowVector)
    {
        /*
         * Testing: Operator * ('*') of Matrix
         * Description:
         *  This is a matrix multiplication. It is only defined if the
         *  number of columns on the lhs is equal to the number of rows
         *  on the rhs. This is testing a square matrix and a row vector (1xn)
         */

        const orion::Matrix<float, 2, 1> lhs{1.f, 2.f};
        const orion::Matrix<float, 1, 2> rhs{3.f, 4.f};
        const orion::Matrix<float, 2, 2> expected{3.f, 4.f, 6.f, 8.f};
        EXPECT_EQ(expected, lhs * rhs);
    }
} // namespace
