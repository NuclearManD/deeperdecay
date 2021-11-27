//
// Created by nuclaer on 10/20/21.
//

#include <stdbool.h>
#include <deeperdecay/rendering/textures/Texture.h>

#include "rendering.h"
#include "primitives.h"


bool renderLoop(render_conf_t* renderConf) {
    RenderState& state = renderConf->renderState;
    Window& window = renderConf->window;
    ShaderProgram* shader = renderConf->shader;
    auto& universe = renderConf->universe;

    Texture& texture = loadTexture("atom2.bmp");

    while (!state.shouldExit()) {
        // Clear screen
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Render our level
        shader->enable();
        shader->setWindowScale(10);
		universe.render(shader);
        shader->disable();

        // Swap buffers
        window.swapBuffers();
        glfwPollEvents();
    }

    return true;
}

