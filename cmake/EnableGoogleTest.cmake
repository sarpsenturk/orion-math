set(googletest_commit_id "4219e7254cb8c473f57f6065bd13d1520d7b708f")

macro(EnableGoogleTest project_name)
    option(${project_name}_BUILD_TESTS "Build tests for ${project_name}" OFF)
    if (${project_name}_BUILD_TESTS)
        # Include googletest - Taken from https://google.github.io/googletest/quickstart-cmake.html#set-up-a-project
        include(FetchContent)
        FetchContent_Declare(
                googletest
                URL https://github.com/google/googletest/archive/${googletest_commit_id}.zip
        )
        # For Windows: Prevent overriding the parent project's compiler/linker settings
        set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
        FetchContent_MakeAvailable(googletest)

        enable_testing()
        include(GoogleTest)
        add_subdirectory(tests)
    endif ()
endmacro()