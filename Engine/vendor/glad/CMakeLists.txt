project(glad VERSION 1.0.0)

file(GLOB all_SRCS
    "${PROJECT_SOURCE_DIR}/src/*.c"
    "${PROJECT_SOURCE_DIR}/src/*.h"
    )

add_library(glad SHARED ${all_SRCS})

target_compile_definitions(glad PUBLIC GLAD_GLAPI_EXPORT PRIVATE GLAD_GLAPI_EXPORT_BUILD)
target_include_directories(glad PUBLIC "${PROJECT_SOURCE_DIR}/include")