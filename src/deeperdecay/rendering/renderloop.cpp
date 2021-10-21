//
// Created by nuclaer on 10/20/21.
//

#include <stdbool.h>
#include <deeperdecay/rendering/textures/Texture.h>

#include "rendering.h"


bool renderLoop(render_conf_t* renderConf) {
    RenderState& state = renderConf->renderState;
    Window& window = renderConf->window;
    ShaderProgram* shader = renderConf->shader;

    Texture& texture = loadTexture("atom2.bmp");

    GLuint VertexArrayID;
    glGenVertexArrays(1, &VertexArrayID);
    glBindVertexArray(VertexArrayID);

    // An array of 6 vectors which represents 6 vertices (2x tRiAnGlkee yyeeee)
    static const GLfloat g_vertex_buffer_data[] = {
            -1.0f, -1.0f, 0.0f,
            1.0f, -1.0f, 0.0f,
            -1.0f,  1.0f, 0.0f,

            1.0f, 1.0f, 0.0f,
            1.0f, -1.0f, 0.0f,
            -1.0f,  1.0f, 0.0f,
    };
    static const GLfloat g_uv_buffer_data[] = {
            0.0f, 0.0f,
            1.0f, 0.0f,
            0.0f, 1.0f,

            1.0f, 1.0f,
            1.0f, 0.0f,
            0.0f, 1.0f,
    };

    // This will identify our vertex buffer
    GLuint vertexbuffer;
    // Generate 1 buffer, put the resulting identifier in vertexbuffer
    glGenBuffers(1, &vertexbuffer);
    // The following commands will talk about our 'vertexbuffer' buffer
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    // Give our vertices to OpenGL.
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

    // This will identify our uv buffer
    GLuint uvbuffer;
    // Generate 1 buffer, put the resulting identifier in vertexbuffer
    glGenBuffers(1, &uvbuffer);
    // The following commands will talk about our 'vertexbuffer' buffer
    glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
    // Give our vertices to OpenGL.
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_uv_buffer_data), g_uv_buffer_data, GL_STATIC_DRAW);

    while (!state.shouldExit()) {
        // Clear screen
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Enable our shader
        shader->enable();
        shader->setTextureSelected(texture);

        // 1st attribute buffer : vertices
        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
        glVertexAttribPointer(
                0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
                3,                  // size
                GL_FLOAT,           // type
                GL_FALSE,           // normalized?
                0,                  // stride
                nullptr             // array buffer offset
        );
        glEnableVertexAttribArray(1);
        glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
        glVertexAttribPointer(
                1,                  // attribute 1
                2,                  // size
                GL_FLOAT,           // type
                GL_FALSE,           // normalized?
                0,                  // stride
                nullptr             // array buffer offset
        );
        // Draw the triangle
        glDrawArrays(GL_TRIANGLES, 0, 6); // Starting from vertex 0; 3 vertices total -> 1 triangle
        glDisableVertexAttribArray(0);
        glDisableVertexAttribArray(1);

        // Swap buffers
        window.swapBuffers();
        glfwPollEvents();
    }
}

