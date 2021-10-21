cmake_minimum_required(VERSION 3.17)
project(deeperdecay)


find_package(OpenGL REQUIRED)

if (WIN32)

    find_library( GLUT NAMES glut glut32 freeglut
        PATHS
        lib
        ${OPENGL_LIBRARY_DIR}
        ${GLUT_ROOT_PATH}/Release
    )
    find_library( GLEW NAMES glew32
        PATHS
        lib
    )
    find_library( GLFW NAMES glfw3
        PATHS
        lib
    )
    include_directories(${CMAKE_SOURCE_DIR}/lib)
    link_directories(${CMAKE_SOURCE_DIR}/lib)
else ()
    find_package(GLUT REQUIRED)
    find_package(GLEW REQUIRED)
    find_package(glm CONFIG REQUIRED)
    find_package(glfw3 CONFIG REQUIRED)

endif (WIN32)
set(ALL_LIBS
        ${OPENGL_LIBRARY}
        glfw
        GLEW_1130
        )

set(CMAKE_CXX_STANDARD 14)

add_executable(deeperdecay src/deeperdecay/main/main.cpp src/deeperdecay/rendering/Window.cpp src/deeperdecay/rendering/Window.h src/deeperdecay/rendering/initialization.cpp src/deeperdecay/rendering/rendering.h src/deeperdecay/util/logging.cpp src/deeperdecay/util/logging.h src/deeperdecay/util/timeutil.h src/deeperdecay/util/timeutil.cpp src/deeperdecay/rendering/Shader.cpp src/deeperdecay/rendering/Shader.h src/deeperdecay/rendering/textures/Texture.cpp src/deeperdecay/rendering/textures/Texture.h src/deeperdecay/util/strutil.cpp src/deeperdecay/util/strutil.h src/deeperdecay/rendering/renderloop.cpp src/deeperdecay/rendering/RenderState.cpp src/deeperdecay/rendering/primitives.h src/deeperdecay/rendering/primitives.cpp)

include_directories(${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS})
include_directories(src)

if (WIN32)
    target_link_libraries(deeperdecay PRIVATE
            ${OPENGL_LIBRARY} # filled by "find_package(OpenGL REQUIRED)"
            ${GLFW_LIBRARY}
            ${GLEW_LIBRARY} OpenGL::GL glfw3 glew32 glut)
else ()
    target_link_libraries(deeperdecay PRIVATE
        ${OPENGL_LIBRARY} # filled by "find_package(OpenGL REQUIRED)"
        ${GLFW_LIBRARY}
        ${GLEW_LIBRARY} OpenGL::GL glfw GLEW::GLEW GLUT::GLUT)
endif()
