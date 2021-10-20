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

    ShaderProgram* shader = loadShader();
    if (shader == nullptr) {
        log_critical("Error loading shader!");
        return -1;
    }

    GLuint textureUniform = shader->getUniformId("myTextureSampler");

    Texture& texture = loadTexture("atom2.bmp");

    do {
        // Clear screen
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Enable our shader
        shader->enable();

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture.getTextureId());
        // Set our "textureId" shader uniform to use Texture Unit 0
        glUniform1i(textureUniform, 0);

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

    } // Check if the ESC key was pressed or the window was closed
    while (!(window.checkKey(GLFW_KEY_ESCAPE) ||
           window.shouldClose()));

    log_printf("Goodbye.", INFO);
	return 0;
}
