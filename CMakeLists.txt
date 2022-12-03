cmake_minimum_required(VERSION 3.20)

project(CPP_STARTER_PROJECT
        VERSION 0.1.0
        DESCRIPTION "CPP_STARTER_PROJECT description"
        LANGUAGES CXX)

# Add our CMake modules
list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

# Dependencies
add_subdirectory(external/fmt)

# Application library
add_library(cpp_starter_lib STATIC "")
target_compile_features(cpp_starter_lib PUBLIC cxx_std_20)
target_include_directories(cpp_starter_lib PUBLIC include/)
target_link_libraries(cpp_starter_lib PUBLIC fmt::fmt)

add_subdirectory(include/cpp-starter)
add_subdirectory(src)

# Application executable
add_executable(cpp_starter_exe src/main.cpp)
target_link_libraries(cpp_starter_exe PRIVATE cpp_starter_lib)

add_library(cpp_starter::lib ALIAS cpp_starter_lib)
add_executable(cpp_starter ALIAS cpp_starter_exe)

# Enable/disable tests
option(CPP_STARTER_BUILD_TESTS "Build tests for cpp-starter" OFF)
if (CPP_STARTER_BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()
