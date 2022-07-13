#ifndef ORION_MATH_MATRIX_H
#define ORION_MATH_MATRIX_H

#include <algorithm>
#include <array>
#include <cstddef>
#include <numeric>

namespace orion
{
    template<typename T, std::size_t Rows, std::size_t Cols>
    struct Matrix {
        static constexpr auto NumRows = Rows;
        static constexpr auto NumCols = Cols;

        using Component_t = T;
        using RowArray_t = std::array<Component_t, NumCols>;
        using MatrixArray_t = std::array<RowArray_t, NumRows>;

        MatrixArray_t matrix{};

        [[nodiscard]] constexpr const RowArray_t& at(std::size_t idx) const { return matrix.at(idx); }
        [[nodiscard]] constexpr RowArray_t& at(std::size_t idx) { return matrix.at(idx); }
        [[nodiscard]] constexpr const RowArray_t& operator[](std::size_t idx) const noexcept { return matrix[idx]; }
        [[nodiscard]] constexpr RowArray_t& operator[](std::size_t idx) noexcept { return matrix[idx]; }

        [[nodiscard]] constexpr bool operator==(const Matrix& other) const noexcept { return matrix == other.matrix; }
        [[nodiscard]] constexpr bool operator!=(const Matrix& other) const noexcept { return !(matrix == other.matrix); }

        [[nodiscard]] constexpr Matrix operator+(const Matrix& other) const noexcept
        {
            return for_each(other, std::plus<>());
        }
        [[nodiscard]] constexpr Matrix operator-(const Matrix& other) const noexcept
        {
            return for_each(other, std::minus<>());
        }
        template<typename Scalar, typename = std::enable_if_t<std::is_arithmetic_v<Scalar>>>
        [[nodiscard]] constexpr Matrix operator*(Scalar scalar) const noexcept
        {
            return for_each([scalar](const Component_t& component) { return component * scalar; });
        }

        // TODO: We may want to switch to a more efficient algorithm like Strassen's matrix multiplication algorithm
        template<typename U, std::size_t N, std::size_t P, typename = std::enable_if_t<NumCols == N>>
        [[nodiscard]] constexpr auto operator*(const Matrix<U, N, P>& other) const noexcept
        {
            using NewComponent_t = std::common_type_t<Component_t, U>;
            using ReturnMatrix_t = Matrix<NewComponent_t, NumRows, P>;
            ReturnMatrix_t new_matrix{};
            for (std::size_t i = 0; i < NumRows; ++i) {
                for (std::size_t j = 0; j < P; ++j) {
                    NewComponent_t sum = 0;
                    for (std::size_t k = 0; k < NumCols; ++k)
                        sum += matrix[i][k] * other.matrix[k][j];
                    new_matrix[i][j] = sum;
                }
            }

            return new_matrix;
        }

    private:
        template<typename UnaryOp>
        Matrix for_each(const UnaryOp& operation) const
        {
            MatrixArray_t new_matrix;
            std::transform(matrix.begin(), matrix.end(), new_matrix.begin(),
                           [&operation](const RowArray_t& row) {
                               RowArray_t new_row;
                               std::transform(row.begin(), row.end(), new_row.begin(), operation);
                               return new_row;
                           });
            return {new_matrix};
        }

        template<typename BinaryOp>
        Matrix for_each(const Matrix& other, const BinaryOp& operation) const
        {
            MatrixArray_t new_matrix;
            std::transform(matrix.begin(), matrix.end(), other.matrix.begin(), new_matrix.begin(),
                           [&operation](const RowArray_t& row_self, const RowArray_t& row_other) {
                               RowArray_t new_row;
                               std::transform(row_self.begin(), row_self.end(), row_other.begin(), new_row.begin(), operation);
                               return new_row;
                           });
            return {new_matrix};
        }
    };
} // namespace orion

#endif // ORION_MATH_MATRIX_H
