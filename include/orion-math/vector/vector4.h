#ifndef ORION_MATH_VECTOR3_H
#define ORION_MATH_VECTOR3_H

#include "vector.h"
#include "_define_component.h"

namespace orion
{
    template<typename T>
    struct Vector4_t : public Vector<T, 4> {
        using Vector_t = Vector<T, 4>;

        constexpr Vector4_t() noexcept = default;
        constexpr explicit Vector4_t(T initializer) noexcept
            : Vector_t{initializer, initializer, initializer, initializer}
        {
        }
        constexpr Vector4_t(T x, T y, T z, T w) noexcept
            : Vector_t{x, y, z, w}
        {
        }

        DEFINE_COMPONENT(x, 0);
        DEFINE_COMPONENT(y, 1);
        DEFINE_COMPONENT(z, 2);
        DEFINE_COMPONENT(w, 3);
    };

    using Vector4_f = Vector4_t<float>;
    using Vector4_d = Vector4_t<double>;
    using Vector4_i = Vector4_t<int>;
    using Vector4 = Vector4_f;
} // namespace orion

#undef DEFINE_COMPONENT

#endif // ORION_MATH_VECTOR3_H
