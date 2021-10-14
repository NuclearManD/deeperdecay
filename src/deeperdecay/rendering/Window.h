//
// Created by nuclaer on 10/12/21.
//

#ifndef DEEPERDECAY_WINDOW_H
#define DEEPERDECAY_WINDOW_H

#include <GLFW/glfw3.h>


class Window {
public:
    Window();

    inline explicit operator bool() {
        return window != nullptr;
    }

    inline bool shouldClose() {
        return glfwWindowShouldClose(window);
    }

    inline void swapBuffers() {
        glfwSwapBuffers(window);
    }

    inline bool checkKey(int key) {
        return glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS;
    }

private:
    GLFWwindow *window;
};


#endif //DEEPERDECAY_WINDOW_H
