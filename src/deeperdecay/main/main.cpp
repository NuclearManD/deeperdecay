#include <iostream>
#include <deeperdecay/rendering/Window.h>

#include "deeperdecay/util/logging.h"
#include "deeperdecay/rendering/rendering.h"
#include "deeperdecay/rendering/Shader.h"
#include "deeperdecay/rendering/textures/Texture.h"


int main() {
	if (graphicsSystemPreinit() < 0) {
        log_critical("Failed graphics system preinit");
        return -1;
    }
    Window window;
    if (!window) {
        log_critical("Failed to open window");
        return -1;
    }

    ShaderProgram* shader = loadShader();
    if (shader == nullptr) {
        log_critical("Error loading shader!");
        return -1;
    }

    RenderState renderState(window);
    render_conf_t renderConf = {
            window,
            shader,
            renderState
    };

    renderLoop(&renderConf);

    log_printf("Goodbye.", INFO);
	return 0;
}
