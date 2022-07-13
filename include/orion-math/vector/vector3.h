#ifndef ORION_MATH_VECTOR3_H
#define ORION_MATH_VECTOR3_H

#include "vector.h"
#include "_define_component.h"

namespace orion
{
    template<typename T>
    struct Vector3_t : public Vector<T, 3> {
        using Vector_t = Vector<T, 3>;

        Vector3_t() noexcept = default;
        explicit Vector3_t(T initializer) noexcept
            : Vector_t{initializer, initializer, initializer}
        {
        }
        Vector3_t(T x, T y, T z) noexcept
            : Vector_t{x, y, z}
        {
        }

        DEFINE_COMPONENT(x, 0);
        DEFINE_COMPONENT(y, 1);
        DEFINE_COMPONENT(z, 2);
    };

    using Vector3_f = Vector3_t<float>;
    using Vector3_d = Vector3_t<double>;
    using Vector3_i = Vector3_t<int>;
    using Vector3 = Vector3_f;
} // namespace orion

#undef DEFINE_COMPONENT

#endif // ORION_MATH_VECTOR3_H
