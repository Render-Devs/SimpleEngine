project(Engine VERSION 0.0.1)

file(GLOB all_SRCS
    "${PROJECT_SOURCE_DIR}/src/*.cpp"
    "${PROJECT_SOURCE_DIR}/src/*.h"
    )

add_library(Engine SHARED ${all_SRCS})

add_subdirectory(vendor)

target_include_directories(Engine PUBLIC "${PROJECT_SOURCE_DIR}/src")