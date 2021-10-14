//
// Created by nuclaer on 10/12/21.
//

#include "Window.h"

// Include standard headers
#include <stdio.h>
#include <stdlib.h>

// Include GLEW. Always include it before gl.h and glfw3.h, since it's a bit magic.
#include <GL/glew.h>
// We decided to let GLFW handle the window and the keyboard, so let’s include it too :

// Include GLFW
#include <GLFW/glfw3.h>
// We don’t actually need this one right now, but this is a library for 3D mathematics. It will prove very useful soon. There is no magic in GLM, you can write your own if you want; it’s just handy. The “using namespace” is there to avoid typing “glm::vec3”, but “vec3” instead.

// Include GLM
#include <glm/glm.hpp>
#include <deeperdecay/util/logging.h>

using namespace glm;

Window::Window() {
    window = glfwCreateWindow(1024, 768, "Tutorial 01", NULL, NULL);

    if (window == nullptr) {
        log_printf("Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible.\n", ERROR);
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(window);

    // Needed in core profile (what???)
    glewExperimental = true;

    // Initialize GLEW
    if (glewInit() != GLEW_OK) {
        log_printf("Failed to initialize GLEW\n", ERROR);
        window = nullptr;
        return;
    }

    // Ensure we can capture the escape key being pressed below
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
}
