#include <iostream>
#include <deeperdecay/rendering/Window.h>
#include <deeperdecay/framework/Level.h>
#include <deeperdecay/objects/TestObject.h>
#include <deeperdecay/objects/Player.h>
#include <deeperdecay/loader/objectRegistry.h>

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

	loadObjects();

    Level level0;
    Player player(window);
    level0.addGameObject(vec2d(0, 0), player);

	DynamicObjectDefinition* floorTileDefinition = getObjectDefinitionById("floortile0");
    for (int x = 1; x < 10; x++)
    	for (int y = 0; y < 10; y++) {
			level0.addGameObject(vec2d(x, y), *floorTileDefinition->instantiate());
		}

	level0.addGameObject(vec2d(0, 0), *instantiateObjectById("beaker_100ml"));

    RenderState renderState(window);
    render_conf_t renderConf = {
            window,
            shader,
            renderState,
			level0,
			player
    };

    renderLoop(&renderConf);

    log_printf("Goodbye.", INFO);
	return 0;
}
