cmake_minimum_required(VERSION 3.15)
project(OpenGLTutorial)

set(CMAKE_CXX_STANDARD 20)

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(glfw3 3.3 REQUIRED)

add_executable(OpenGLTutorial main.cpp)

target_link_libraries(OpenGLTutorial glfw)
target_link_libraries(OpenGLTutorial OpenGL::GL)
target_link_libraries(OpenGLTutorial GLEW)
