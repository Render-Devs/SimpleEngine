# IMGUI
project(imgui VERSION 1.0.0)

file(GLOB all_SRCS
    "${CMAKE_CURRENT_SOURCE_DIR}/imgui/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/imgui/*.h"
    )

add_library(imgui STATIC ${all_SRCS})
target_include_directories(imgui PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/imgui")

target_link_libraries(Engine PRIVATE imgui)

# STB
project(stb VERSION 1.0.0)

file(GLOB all_SRCS
    "${CMAKE_CURRENT_SOURCE_DIR}/stb/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/stb/*.c"
    )

add_library(stb INTERFACE)
target_include_directories(stb INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/stb")

target_link_libraries(Engine PRIVATE stb)

# OPENGL
find_package(OpenGL REQUIRED)
target_link_libraries(Engine PRIVATE ${OPENGL_gl_LIBRARY})

# GLFW
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)
set(BUILD_SHARED_LIBS ON)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "Build the GLFW documentation")
set(GLFW_INSTALL OFF CACHE BOOL "Generate installation target")
add_subdirectory(glfw)
target_link_libraries(Engine PRIVATE glfw)

# GLAD
add_subdirectory(glad)
target_link_libraries(Engine PRIVATE glad)

# GLM
add_subdirectory(glm)
target_link_libraries(Engine PRIVATE glm)

# ASSIMP
set(ASSIMP_BUILD_ASSIMP_TOOLS OFF CACHE BOOL "If the supplementary tools for Assimp are built in addition to the library.")
set(ASSIMP_BUILD_TESTS OFF CACHE BOOL "If the test suite for Assimp is built in addition to the library.")
set(ASSIMP_INSTALL OFF CACHE BOOL "DIsable this if you want to use assimp as a submodule.")
add_subdirectory(assimp)
set_target_properties(assimp PROPERTIES 
                      FOLDER "Assimp"
                      ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
                      LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
                      RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    )
set_target_properties(IrrXML PROPERTIES 
                      FOLDER "Assimp"
                      ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
                      LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
                      RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    )
set_target_properties(UpdateAssimpLibsDebugSymbolsAndDLLs PROPERTIES
                      FOLDER "Assimp"
                      ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
                      LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
                      RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    )
set_target_properties(zlib PROPERTIES
                      FOLDER "Assimp"
                      ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
                      LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
                      RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    )
set_target_properties(zlibstatic PROPERTIES
                      FOLDER "Assimp"
                      ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
                      LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
                      RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    )     
set_target_properties(uninstall PROPERTIES
                      FOLDER "Assimp"
                      ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
                      LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
                      RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    )   
target_link_libraries(Engine PRIVATE assimp)