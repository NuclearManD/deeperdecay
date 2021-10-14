#include <iostream>
#include <deeperdecay/rendering/Window.h>

#include "deeperdecay/util/logging.h"
#include "deeperdecay/rendering/rendering.h"

int main() {
	if (graphicsSystemPreinit() < 0) {
        log_printf("Failed graphics system preinit", ERROR);
        return -1;
    }
    Window window;
    if (!window) {
        log_printf("Failed to open window", ERROR);
        return -1;
    }

    do {
        // Clear the screen. It's not mentioned before Tutorial 02, but it can cause flickering, so it's there nonetheless.
        glClear(GL_COLOR_BUFFER_BIT);

        // Draw nothing, see you in tutorial 2 !

        // Swap buffers
        window.swapBuffers();
        glfwPollEvents();

    } // Check if the ESC key was pressed or the window was closed
    while (!(window.checkKey(GLFW_KEY_ESCAPE) ||
           window.shouldClose()));

    log_printf("Goodbye.", INFO);
	return 0;
}
