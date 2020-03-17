project(glad VERSION 1.0.0)

file(GLOB all_SRCS
    "${PROJECT_SOURCE_DIR}/src/*.c"
    "${PROJECT_SOURCE_DIR}/src/*.h"
    )

add_library(glad STATIC ${all_SRCS})

target_include_directories(glad PUBLIC "${PROJECT_SOURCE_DIR}/include")