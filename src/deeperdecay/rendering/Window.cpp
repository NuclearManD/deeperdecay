//
// Created by nuclaer on 10/12/21.
//

#include "Window.h"

#include <deeperdecay/util/logging.h>


Window::Window() {
    window = glfwCreateWindow(1024, 768, "Deeperdecay", NULL, NULL);

    if (window == nullptr) {
        log_printf("Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible.\n", ERROR);
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(window);
	glfwSwapInterval(1);

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


void Window::updateScales(ShaderProgram *shader) {
	int w, h;
	glfwGetFramebufferSize(window, &w, &h);

	// Update the viewport
	glViewport(0, 0, w, h);

	// Fix the window scale
	if (w > h) {
		float sx = (float)w/(float)h;
		shader->setWindowScale(sx * worldScale, worldScale);
	} else {
		float sy = (float)h/(float)w;
		shader->setWindowScale(worldScale, sy * worldScale);
	}
}


int Window::getKey(int key) {
	return glfwGetKey(window, key);
}
