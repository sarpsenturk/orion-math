#ifndef ORION_MATH_VECTOR_H
#define ORION_MATH_VECTOR_H

#include "orion-math/common.h"

#include <algorithm>
#include <array>
#include <functional>
#include <numeric>

namespace orion
{
    template<typename T, std::size_t Size>
    struct Vector {
        static_assert(Size > 1, "Vector expects 2 or more components");
        static constexpr auto ComponentCount = Size;

        using Component_t = T;
        using ComponentArray_t = std::array<Component_t, ComponentCount>;

        ComponentArray_t components{};

        [[nodiscard]] constexpr const Component_t& at(std::size_t idx) const { return components.at(idx); }
        [[nodiscard]] constexpr Component_t& at(std::size_t idx) { return components.at(idx); }

        [[nodiscard]] constexpr const Component_t& operator[](std::size_t idx) const noexcept { return components[idx]; }
        [[nodiscard]] constexpr Component_t& operator[](std::size_t idx) { return components[idx]; }

        [[nodiscard]] constexpr bool operator==(const Vector& other) const noexcept { return components == other.components; }
        [[nodiscard]] constexpr bool operator!=(const Vector& other) const noexcept { return !(*this == other); }

        [[nodiscard]] constexpr Vector operator+(const Vector& other) const noexcept
        {
            return for_each(other, std::plus<>());
        }
        [[nodiscard]] constexpr Vector operator-(const Vector& other) const noexcept
        {
            return for_each(other, std::minus<>());
        }
        // Dot (scalar) product
        [[nodiscard]] constexpr Vector operator*(const Vector& other) const noexcept
        {
            return for_each(other, std::multiplies<>());
        }

        template<typename Scalar>
        [[nodiscard]] constexpr std::enable_if_t<std::is_scalar_v<Scalar>, Vector> operator*(Scalar scalar) const noexcept
        {
            ComponentArray_t new_components;
            std::transform(
                components.cbegin(), components.cend(), new_components.begin(),
                [scalar](auto component) { return component * scalar; });
            return {new_components};
        }

        [[nodiscard]] constexpr auto sqr_magnitude() const noexcept
        {
            return std::accumulate(components.begin(), components.end(), 0, [](auto a, Component_t next) {
                return a + next * next;
            });
        }

        [[nodiscard]] constexpr auto magnitude() const noexcept { return sqrt(sqr_magnitude()); }

    private: // Internal helpers
        template<typename BinaryOperation>
        [[nodiscard]] constexpr Vector for_each(const Vector& other, BinaryOperation operation) const noexcept
        {
            ComponentArray_t new_components;
            std::transform(components.begin(), components.end(),
                           other.components.begin(), new_components.begin(),
                           operation);
            return {new_components};
        }
    };
} // namespace orion

#endif // ORION_MATH_VECTOR_H
