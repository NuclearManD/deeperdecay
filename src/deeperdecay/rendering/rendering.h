//
// Created by nuclaer on 10/14/21.
//

#ifndef DEEPERDECAY_RENDERING_H
#define DEEPERDECAY_RENDERING_H

#include <deeperdecay/framework/Level.h>
#include <deeperdecay/objects/Player.h>
#include "Shader.h"
#include "Window.h"

/*
** initialization.cpp
*/
int graphicsSystemPreinit();
int graphicsSystemInit();
ShaderProgram* loadShader();

/*
** renderLoop.cpp
*/

// An instance of this class keeps track of the rendering state.  It will
// facilitate inter-thread tracking of what the rendering system is doing.
// For now, it just keeps track of weather the window should close.
class RenderState {
public:
    RenderState(Window& window);

    bool shouldExit();

    void sendExitSignal();
private:
    Window& window;
    bool doExit;
};

// This compresses some function arguments into a single
// pointer.  See the comment below for explanation.
typedef struct {
    Window& window;

    // TODO: should we change all ShaderProgram pointers to references?
    // It probably doesn't matter...
    ShaderProgram* shader;
    RenderState& renderState;
    Level& universe;
    Player& player;
} render_conf_t;

// We encoded the function arguments into a struct so we only have one
// pointer argument.  The reason I did this is so we can make this
// function its own thread - threads must have exactly one argument.
bool renderLoop(render_conf_t* renderConf);

#endif //DEEPERDECAY_RENDERING_H
