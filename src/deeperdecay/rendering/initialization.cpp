
// Include standard headers
#include <stdio.h>
#include <stdlib.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>


int graphicsSystemPreinit() {
    // Needed for core profile (what does this do exactly????)
    glewExperimental = true;

    // Initialise GLFW, so we can easily create windows and manage OpenGL
    if (!glfwInit()) {
        fprintf(stderr, "Failed to initialize GLFW\n");
        return -1;
    }

    // 4x antialiasing, so our stuff looks prettier
    glfwWindowHint(GLFW_SAMPLES, 4);

    // We want OpenGL 3.3 (GL33 in LWJGL)
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    // To make MacOS happy; should not be needed
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    // We don't want the old OpenGL
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    return 0;
}
