project(imgui VERSION 1.0.0)

file(GLOB all_SRCS
    "${PROJECT_SOURCE_DIR}/vendor/imgui/*.cpp"
    "${PROJECT_SOURCE_DIR}/vendor/imgui/*.h"
    )

add_library(imgui STATIC ${all_SRCS})
target_include_directories(imgui PUBLIC "${PROJECT_SOURCE_DIR}/vendor/imgui")

project(Engine VERSION 0.0.1)

file(GLOB all_SRCS
    "${PROJECT_SOURCE_DIR}/src/*.cpp"
    "${PROJECT_SOURCE_DIR}/src/*.h"
    )

add_library(Engine SHARED ${all_SRCS})

find_package(OpenGL REQUIRED)
target_link_libraries(Engine PRIVATE ${OPENGL_gl_LIBRARY})

add_subdirectory(Vendor/glfw)
target_link_libraries(Engine PRIVATE glfw)

add_subdirectory(Vendor/glad)
target_link_libraries(Engine PRIVATE glad)

add_subdirectory(Vendor/glm)
target_link_libraries(Engine PRIVATE glm)

target_link_libraries(Engine PRIVATE imgui)

target_include_directories(Engine PUBLIC "${PROJECT_SOURCE_DIR}/src")