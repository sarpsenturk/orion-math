#pragma once

#include "matrix4.h"
#include "orion-math/angles.h"
#include "orion-math/trig.h"
#include "orion-math/vector/vector3.h"

namespace orion::math
{
    template<typename T>
    [[nodiscard]] constexpr Vector3_t<T> transform(const Vector3_t<T>& vector, const Matrix4_t<T>& transform)
    {
        const Matrix<T, 4, 1> vector_matrix{vector[0], vector[1], vector[2], T{1}};
        const auto result = transform * vector_matrix;
        return {result(0), result(1), result(2)};
    }

    template<typename T>
    [[nodiscard]] constexpr Matrix4_t<T> scaling(T x, T y, T z)
    {
        return {
            x, 0, 0, 0,
            0, y, 0, 0,
            0, 0, z, 0,
            0, 0, 0, 1};
    }

    template<typename T>
    [[nodiscard]] constexpr Matrix4_t<T> translation(T x, T y, T z)
    {
        return {
            1, 0, 0, x,
            0, 1, 0, y,
            0, 0, 1, z,
            0, 0, 0, 1};
    }

    template<typename T = float>
    [[nodiscard]] constexpr Matrix4_t<T> rotation_x(Radians radians)
    {
        const auto cos_x = cos<T>(radians);
        const auto sin_x = sin<T>(radians);
        return {
            1, 0, 0, 0,
            0, cos_x, -sin_x, 0,
            0, sin_x, cos_x, 0,
            0, 0, 0, 1};
    }

    template<typename T = float>
    [[nodiscard]] constexpr Matrix4_t<T> rotation_y(Radians radians)
    {
        const auto cos_x = cos<T>(radians);
        const auto sin_x = sin<T>(radians);
        return {
            cos_x, 0, sin_x, 0,
            0, 1, 0, 0,
            -sin_x, 0, cos_x, 0,
            0, 0, 0, 1};
    }

    template<typename T = float>
    [[nodiscard]] constexpr Matrix4_t<T> rotation_z(Radians radians)
    {
        const auto cos_x = cos<T>(radians);
        const auto sin_x = sin<T>(radians);
        return {
            cos_x, -sin_x, 0, 0,
            sin_x, cos_x, 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1};
    }

    template<typename T>
    [[nodiscard]] constexpr Matrix4_t<T> lookat_rh(const Vector3_t<T>& position, const Vector3_t<T>& target, const Vector3_t<T>& up)
    {
        const auto zaxis = (position - target).normalize();
        const auto xaxis = cross(zaxis, up).normalize();
        const auto yaxis = cross(xaxis, zaxis);
        return {
            xaxis[0], xaxis[1], xaxis[2], -dot(xaxis, position),
            yaxis[0], yaxis[1], yaxis[2], -dot(yaxis, position),
            zaxis[0], zaxis[1], zaxis[2], -dot(zaxis, position),
            0, 0, 0, 1};
    }

    template<typename T>
    [[nodiscard]] constexpr Matrix4_t<T> lookat_lh(const Vector3_t<T>& position, const Vector3_t<T>& target, const Vector3_t<T>& up)
    {
        const auto zaxis = (target - position).normalize();
        const auto xaxis = cross(zaxis, up).normalize();
        const auto yaxis = cross(xaxis, zaxis);
        return {
            xaxis[0], xaxis[1], xaxis[2], -dot(xaxis, position),
            yaxis[0], yaxis[1], yaxis[2], -dot(yaxis, position),
            zaxis[0], zaxis[1], zaxis[2], -dot(zaxis, position),
            0, 0, 0, 1};
    }
} // namespace orion::math
