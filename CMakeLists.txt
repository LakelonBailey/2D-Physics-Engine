cmake_minimum_required(VERSION 3.10)
project(2d-physics-engine)

find_package(glfw3 REQUIRED)
find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)

add_executable(2d-physics-engine src/main.cpp)
target_include_directories(2d-physics-engine PRIVATE ${GLEW_INCLUDE_DIRS})
target_link_libraries(2d-physics-engine glfw GLEW::GLEW OpenGL::GL)