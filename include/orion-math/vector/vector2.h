#ifndef ORION_MATH_VECTOR2_H
#define ORION_MATH_VECTOR2_H

#include "vector.h"
#include "_define_component.h"

namespace orion
{
    template<typename T>
    struct Vector2_t : public Vector<T, 2> {
        using Vector_t = Vector<T, 2>;

        Vector2_t() noexcept = default;
        explicit Vector2_t(T initializer) noexcept
            : Vector_t{initializer, initializer}
        {
        }
        Vector2_t(T x, T y) noexcept
            : Vector_t{x, y}
        {
        }

        DEFINE_COMPONENT(x, 0);
        DEFINE_COMPONENT(y, 1);
    };

    using Vector2_f = Vector2_t<float>;
    using Vector2_d = Vector2_t<double>;
    using Vector2_i = Vector2_t<int>;
    using Vector2 = Vector2_f;
} // namespace orion

#undef DEFINE_COMPONENT

#endif // ORION_MATH_VECTOR2_H
