project(Engine VERSION 0.0.1)

file(GLOB all_SRCS
    "${PROJECT_SOURCE_DIR}/src/*.cpp"
    "${PROJECT_SOURCE_DIR}/src/*.h"
    "${PROJECT_SOURCE_DIR}/src/SimpleEngine/RenderSpecific/*.cpp"
    "${PROJECT_SOURCE_DIR}/src/SimpleEngine/RenderSpecific/*.h"
    "${PROJECT_SOURCE_DIR}/src/SimpleEngine/RenderSpecific/OpenGL/Window/*.cpp"
    "${PROJECT_SOURCE_DIR}/src/SimpleEngine/RenderSpecific/OpenGL/Window/*.h"
    "${PROJECT_SOURCE_DIR}/src/SimpleEngine/Window/*.cpp"
    "${PROJECT_SOURCE_DIR}/src/SimpleEngine/Window/*.h"
    "${PROJECT_SOURCE_DIR}/src/SimpleEngine/Core/*.cpp"
    "${PROJECT_SOURCE_DIR}/src/SimpleEngine/Core/*.h"
    "${PROJECT_SOURCE_DIR}/src/SimpleEngine/Core/Memory/*.h"
    "${PROJECT_SOURCE_DIR}/src/SimpleEngine/Core/Memory/*.cpp"
    )

add_library(Engine SHARED ${all_SRCS})
target_compile_definitions(Engine PUBLIC SE_BUILD_DLL)

add_subdirectory(vendor)

target_include_directories(Engine PUBLIC "${PROJECT_SOURCE_DIR}/src")
