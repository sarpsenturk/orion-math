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
        const Matrix<T, 1, 4> vector_matrix{vector[0], vector[1], vector[2], T{1}};
        const auto result = vector_matrix * transform;
        return {result[0][0], result[0][1], result[0][2]};
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
            1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 1, 0,
            x, y, z, 1};
    }

    template<typename T = float>
    [[nodiscard]] constexpr Matrix4_t<T> rotation_x(Radians radians)
    {
        const auto cos_x = cos<T>(radians);
        const auto sin_x = sin<T>(radians);
        return {
            1, 0, 0, 0,
            0, cos_x, sin_x, 0,
            0, -sin_x, cos_x, 0,
            0, 0, 0, 1};
    }

    template<typename T = float>
    [[nodiscard]] constexpr Matrix4_t<T> rotation_y(Radians radians)
    {
        const auto cos_x = cos<T>(radians);
        const auto sin_x = sin<T>(radians);
        return {
            cos_x, 0, -sin_x, 0,
            0, 1, 0, 0,
            sin_x, 0, cos_x, 0,
            0, 0, 0, 1};
    }

    template<typename T = float>
    [[nodiscard]] constexpr Matrix4_t<T> rotation_z(Radians radians)
    {
        const auto cos_x = cos<T>(radians);
        const auto sin_x = sin<T>(radians);
        return {
            cos_x, sin_x, 0, 0,
            -sin_x, cos_x, 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1};
    }

    template<typename T>
    [[nodiscard]] constexpr Matrix4_t<T> lookat_rh(const Vector3_t<T>& eye, const Vector3_t<T>& target, const Vector3_t<T>& up)
    {
        const auto zaxis = (eye - target).normalize();
        const auto xaxis = cross(up, zaxis).normalize();
        const auto yaxis = cross(zaxis, xaxis);
        return {
            xaxis.x(), yaxis.x(), zaxis.x(), 0,
            xaxis.y(), yaxis.y(), zaxis.z(), 0,
            xaxis.z(), yaxis.z(), zaxis.z(), 0,
            -dot(xaxis, eye), -dot(yaxis, eye), -dot(zaxis, eye), 1};
    }

    template<typename T>
    [[nodiscard]] constexpr Matrix4_t<T> lookat_lh(const Vector3_t<T>& eye, const Vector3_t<T>& target, const Vector3_t<T>& up)
    {
        const auto zaxis = (target - eye).normalize();
        const auto xaxis = cross(up, zaxis).normalize();
        const auto yaxis = cross(zaxis, xaxis);
        return {
            xaxis.x(), yaxis.x(), zaxis.x(), 0,
            xaxis.y(), yaxis.y(), zaxis.z(), 0,
            xaxis.z(), yaxis.z(), zaxis.z(), 0,
            -dot(xaxis, eye), -dot(yaxis, eye), -dot(zaxis, eye), 1};
    }
} // namespace orion::math
