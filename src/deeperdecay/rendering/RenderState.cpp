//
// Created by nuclaer on 10/20/21.
//

#include "Window.h"
#include "rendering.h"

RenderState::RenderState(Window &window) : window(window) {
    doExit = false;
}

bool RenderState::shouldExit() {
    return doExit || window.checkKey(GLFW_KEY_ESCAPE) || window.shouldClose();
}

void RenderState::sendExitSignal() {
    doExit = true;
}


