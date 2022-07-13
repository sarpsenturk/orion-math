cmake_minimum_required(VERSION 3.8)

project(orion-math
        DESCRIPTION "Math library for the Orion game engine"
        VERSION 0.1.0)

add_library(orion-math INTERFACE
        include/orion-math/constants.h
        include/orion-math/common.h
        include/orion-math/vector/vector.h
        include/orion-math/vector/vector2.h
        include/orion-math/vector/vector3.h
        include/orion-math/vector/vector4.h
        include/orion-math/vector/_define_component.h

        include/orion-math/matrix/matrix.h
        )
target_compile_features(orion-math INTERFACE cxx_std_17)
target_include_directories(orion-math INTERFACE include/)


list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
message(${CMAKE_MODULE_PATH})
include(EnableGoogleTest)
EnableGoogleTest(ORION-MATH)

