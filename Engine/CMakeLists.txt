project(imgui VERSION 1.0.0)

file(GLOB all_SRCS
    "${PROJECT_SOURCE_DIR}/vendor/imgui/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.h"
    )

add_library(imgui STATIC ${all_SRCS})
target_include_directories(imgui PUBLIC "${PROJECT_SOURCE_DIR}/vendor/imgui")

project(stb VERSION 1.0.0)

file(GLOB all_SRCS
    "${PROJECT_SOURCE_DIR}/vendor/stb/*.h"
    "${PROJECT_SOURCE_DIR}/vendor/stb/*.c"
    )

add_library(stb STATIC ${all_SRCS} )
target_include_directories(stb PUBLIC "${PROJECT_SOURCE_DIR}/vendor/stb")


project(Engine VERSION 0.0.1)

file(GLOB all_SRCS
    "${PROJECT_SOURCE_DIR}/src/*.cpp"
    "${PROJECT_SOURCE_DIR}/src/*.h"
    )

add_library(Engine SHARED ${all_SRCS})

find_package(OpenGL REQUIRED)
target_link_libraries(Engine PRIVATE ${OPENGL_gl_LIBRARY})

add_subdirectory(vendor/glfw)
target_link_libraries(Engine PRIVATE glfw)

add_subdirectory(vendor/glad)
target_link_libraries(Engine PRIVATE glad)

add_subdirectory(vendor/glm)
target_link_libraries(Engine PRIVATE glm)

target_link_libraries(Engine PRIVATE imgui)

target_link_libraries(Engine PRIVATE stb)

add_subdirectory(vendor/assimp)
set_target_properties(assimp PROPERTIES 
                      FOLDER "assimp")
set_target_properties(assimp_cmd PROPERTIES 
                      FOLDER "assimp")
set_target_properties(IrrXML PROPERTIES 
                      FOLDER "assimp")
set_target_properties(unit PROPERTIES
                      FOLDER "assimp")
set_target_properties(UpdateAssimpLibsDebugSymbolsAndDLLs PROPERTIES
                      FOLDER "assimp")
set_target_properties(zlib PROPERTIES
                      FOLDER "assimp")
set_target_properties(zlibstatic PROPERTIES
                      FOLDER "assimp")                         
target_link_libraries(Engine PRIVATE assimp)

target_include_directories(Engine PUBLIC "${PROJECT_SOURCE_DIR}/src")