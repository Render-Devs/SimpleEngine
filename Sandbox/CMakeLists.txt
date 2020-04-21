project(Sandbox VERSION 0.0.1)

file(GLOB all_SRCS
    "${PROJECT_SOURCE_DIR}/src/*.cpp"
    "${PROJECT_SOURCE_DIR}/src/*.h"
    )

add_executable(Sandbox ${all_SRCS})
include_directories("../Engine/vendor/glfw/include") #remove after implement Window Events
target_link_libraries(Sandbox PRIVATE Engine)