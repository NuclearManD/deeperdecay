//
// Created by nuclaer on 10/12/21.
//

#ifndef DEEPERDECAY_WINDOW_H
#define DEEPERDECAY_WINDOW_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Shader.h"


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

    int getKey(int i);

	void updateScales(ShaderProgram *pProgram);

	void setWorldScale(float scale) { worldScale = scale; }

private:
    GLFWwindow *window;

    float worldScale = 16;
};


#endif //DEEPERDECAY_WINDOW_H
