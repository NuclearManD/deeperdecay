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

add_executable(deeperdecay src/deeperdecay/main/main.cpp src/deeperdecay/rendering/Window.cpp src/deeperdecay/rendering/Window.h src/deeperdecay/rendering/initialization.cpp src/deeperdecay/rendering/rendering.h src/deeperdecay/util/logging.cpp src/deeperdecay/util/logging.h src/deeperdecay/util/timeutil.h src/deeperdecay/util/timeutil.cpp src/deeperdecay/rendering/Shader.cpp src/deeperdecay/rendering/Shader.h)

include_directories(${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS})
include_directories(src)

target_link_libraries(deeperdecay PRIVATE
        ${OPENGL_LIBRARY} # filled by "find_package(OpenGL REQUIRED)"
        ${GLFW_LIBRARY}
        ${GLEW_LIBRARY} OpenGL::GL glfw glm GLEW::GLEW GLUT::GLUT)
