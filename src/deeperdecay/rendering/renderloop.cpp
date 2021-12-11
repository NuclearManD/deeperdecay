//
// Created by nuclaer on 10/20/21.
//

#include <deeperdecay/rendering/textures/Texture.h>
#include <deeperdecay/util/timeutil.h>

#include "rendering.h"


bool renderLoop(render_conf_t* renderConf) {
    RenderState& state = renderConf->renderState;
    Window& window = renderConf->window;
    ShaderProgram* shader = renderConf->shader;
    auto& universe = renderConf->universe;

    double last_time = unixtime();

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

        // Later we'll move this to it's own thread, it really doesn't belong here
        double time = unixtime();
        universe.update(time - last_time);
        last_time = time;
    }

    return true;
}

