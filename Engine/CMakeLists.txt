project(Engine VERSION 0.0.1)

file(GLOB all_SRCS
    "${PROJECT_SOURCE_DIR}/src/*.cpp"
    "${PROJECT_SOURCE_DIR}/src/*.h"
    )

add_library(Engine SHARED ${all_SRCS})

add_subdirectory(Vendor/glfw)
target_link_libraries(Engine PRIVATE glfw)

find_package(OpenGL REQUIRED)

target_link_libraries(Engine PRIVATE ${OPENGL_gl_LIBRARY})

target_include_directories(Engine PUBLIC "${PROJECT_SOURCE_DIR}/src")
target_include_directories(Engine PRIVATE "${PROJECT_SOURCE_DIR}/vendor/glfw/include")