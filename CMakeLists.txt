cmake_minimum_required(VERSION 3.23)

project(ORION_MATH_PROJECT
        VERSION 0.1.0
        DESCRIPTION "Math library for the Orion game engine"
        LANGUAGES CXX)

if (NOT DEFINED ORION_MATH_TOP_LEVEL)
    set(ORION_MATH_TOP_LEVEL OFF)
    if (CMAKE_CURRENT_SRC_DIR STREQUAL CMAKE_SOURCE_DIR)
        set(ORION_MATH_TOP_LEVEL ON)
    endif ()
endif ()


include(GNUInstallDirs)

option(ORION_MATH_TEST "Generate test targets orion-math" ${ORION_MATH_TOP_LEVEL})
option(ORION_MATH_INSTALL "Generate install target" ON)

# Add our CMake modules
list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

# Dependencies
find_package(fmt REQUIRED)

# Application library
add_library(orion_math INTERFACE "")
target_compile_features(orion_math INTERFACE cxx_std_20)
target_include_directories(orion_math INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
        )
target_link_libraries(orion_math INTERFACE fmt::fmt)

# Create file set
target_sources(
        orion_math
        INTERFACE
        FILE_SET orion_math_headers
        TYPE HEADERS
        BASE_DIRS
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

# Add sources
add_subdirectory(include/orion-math)

# Create alias
add_library(orion::math ALIAS orion_math)

# Enable/disable tests
if (ORION_MATH_BUILD_TESTS)
    enable_testing()
    find_package(GTest REQUIRED)
    add_subdirectory(tests)
endif ()

# Install targets
if (ORION_MATH_INSTALL)
    include(CMakePackageConfigHelpers)

    # Create version config file
    write_basic_package_version_file(
            "${CMAKE_CURRENT_BINARY_DIR}/OrionMathConfigVersion.cmake"
            VERSION ${PROJECT_VERSION}
            COMPATIBILITY SameMajorVersion
    )

    install(
            TARGETS orion_math
            EXPORT OrionMathTargets
            ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
            LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
            RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
            FILE_SET orion_math_headers DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    )

    configure_package_config_file(
            ${CMAKE_CURRENT_SOURCE_DIR}/cmake/OrionMathConfig.cmake.in
            ${PROJECT_BINARY_DIR}/OrionMathConfig.cmake
            INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/orion-math
    )

    install(EXPORT OrionMathTargets DESTINATION ${CMAKE_INSTALL_LIBDIR}/orion-math)
    install(FILES
            "${CMAKE_CURRENT_BINARY_DIR}/OrionMathConfig.cmake"
            "${CMAKE_CURRENT_BINARY_DIR}/OrionMathConfigVersion.cmake"
            DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/orion-math)
endif ()
