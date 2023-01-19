target_sources(orion_math
        INTERFACE
        FILE_SET orion_math_headers
        TYPE HEADERS
        FILES
        abs.h
        sqrt.h
        )

add_subdirectory(vector)
