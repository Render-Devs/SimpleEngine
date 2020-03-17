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

add_library(stb STATIC ${all_SRCS} )
target_include_directories(stb PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/stb")

target_link_libraries(Engine PRIVATE stb)

# OPENGL
find_package(OpenGL REQUIRED)
target_link_libraries(Engine PRIVATE ${OPENGL_gl_LIBRARY})

# GLFW
add_subdirectory(glfw)
target_link_libraries(Engine PRIVATE glfw)

#GLAD
add_subdirectory(glad)
target_link_libraries(Engine PRIVATE glad)

# GLM
add_subdirectory(glm)
target_link_libraries(Engine PRIVATE glm)

# ASSIMP
add_subdirectory(assimp)
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