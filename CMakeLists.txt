cmake_minimum_required(VERSION 3.20)

project(ORION_MATH_PROJECT
        VERSION 0.1.0
        DESCRIPTION "Math library for the Orion game engine"
        LANGUAGES CXX)

# Add our CMake modules
list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

# Dependencies
find_package(fmt REQUIRED)

# Application library
add_library(orion_math_lib INTERFACE "")
target_compile_features(orion_math_lib INTERFACE cxx_std_20)
target_include_directories(orion_math_lib INTERFACE include/)
target_link_libraries(orion_math_lib INTERFACE fmt::fmt)

add_subdirectory(include/orion-math)

add_library(orion::math ALIAS orion_math_lib)

# Enable/disable tests
option(ORION_MATH_BUILD_TESTS "Build tests for orion-math" OFF)
if (ORION_MATH_BUILD_TESTS)
    enable_testing()
    find_package(GTest REQUIRED)
    add_subdirectory(tests)
endif()
