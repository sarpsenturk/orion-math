#ifndef ORION_MATH_COMMON_H
#define ORION_MATH_COMMON_H

#include <cassert>
#include <type_traits>

namespace orion
{
    namespace detail
    {
        template<typename T>
        constexpr std::enable_if_t<std::is_floating_point_v<T>, T> sqrt_impl(T value) noexcept
        {
            assert(value >= 0);
            if (value == T{0})
                return T{0};
            auto initial = value / 2;
            auto current = (initial + value / initial) / 2;
            while (initial != current) {
                initial = current;
                current = (initial + value / initial) / 2;
            }
            return current;
        }
    } // namespace detail

    template<typename FloatingPoint, typename = std::enable_if_t<std::is_floating_point_v<FloatingPoint>>>
    constexpr auto sqrt(FloatingPoint value) noexcept
    {
        return detail::sqrt_impl(value);
    }

    template<typename Integral, typename = std::enable_if_t<std::is_integral_v<Integral>>>
    constexpr double sqrt(Integral value) noexcept
    {
        return detail::sqrt_impl(static_cast<double>(value));
    }
} // namespace orion

#endif // ORION_MATH_COMMON_H
