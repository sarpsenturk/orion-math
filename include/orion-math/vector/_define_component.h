#ifndef ORION_MATH__DEFINE_COMPONENT_H
#define ORION_MATH__DEFINE_COMPONENT_H

#define DEFINE_COMPONENT(name, index)        \
    constexpr T& name() noexcept             \
    {                                        \
        return this->components[index];      \
    }                                        \
    constexpr const T& name() const noexcept \
    {                                        \
        return this->components[index];      \
    }

#endif // ORION_MATH__DEFINE_COMPONENT_H
