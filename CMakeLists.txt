cmake_minimum_required(VERSION 3.17)
project(deeperdecay)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(GLEW REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)

set(ALL_LIBS
        ${OPENGL_LIBRARY}
        glfw
        GLEW_1130
        )

set(CMAKE_CXX_STANDARD 14)

add_executable(deeperdecay src/deeperdecay/main/main.cpp src/deeperdecay/rendering/Window.cpp src/deeperdecay/rendering/Window.h)

include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )

target_link_libraries(deeperdecay PRIVATE
        ${OPENGL_LIBRARY} # filled by "find_package(OpenGL REQUIRED)"
        ${GLFW_LIBRARY}
        ${GLEW_LIBRARY} OpenGL::GL glfw glm GLEW::GLEW GLUT::GLUT)
