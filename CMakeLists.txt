cmake_minimum_required(VERSION 3.12)

project(Game VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(Library/glfw)
add_subdirectory(Library/glm)

add_library(glad Library/glad/src/glad.c)

include_directories(Library/glfw/include
                    Library/glad/include
                    Library/glm/include
                    Library/stb/include)

add_definitions(-DProjectDirectory=\"${PROJECT_SOURCE_DIR}\"
                -DGLM_ENABLE_EXPERIMENTAL)

add_executable(Game "Source/Game.cpp" "Source/App.h" "Source/App.cpp" "Source/Window/Window.h" "Source/Window/Window.cpp" "Source/World/World.h" "Source/World/World.cpp" "Source/World/Light.h" "Source/World/Light.cpp" "Source/World/Mesh.h" "Source/World/Mesh.cpp" "Source/Shader/Shader.h" "Source/Shader/Shader.cpp" "Source/Shader/VAO.h" "Source/Shader/VAO.cpp" "Source/Shader/VBO.h" "Source/Shader/VBO.cpp" "Source/Shader/EBO.h" "Source/Shader/EBO.cpp" "Source/Texture/Texture.h" "Source/Texture/Texture.cpp" "Source/Texture/stb.cpp" "Source/Camera/Camera.h" "Source/Camera/Camera.cpp")

target_link_libraries(Game glfw glad glm)
