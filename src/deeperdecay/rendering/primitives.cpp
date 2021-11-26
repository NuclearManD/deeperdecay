//
// Created by nuclaer on 10/20/21.
//

#include <GL/glew.h>
#include <GLFW/glfw3.h>


static GLuint getSquareVAO() {
    static GLuint VertexArrayID;
    static bool is_loaded = false;

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

    if (is_loaded) return VertexArrayID;

    // Create a VAO
    glGenVertexArrays(1, &VertexArrayID);
    glBindVertexArray(VertexArrayID);

    // Create the vertex VBO
    GLuint vertexbuffer;
    glGenBuffers(1, &vertexbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
    // Configure for 3 floats per point (3D position)
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

    // Create the texture VBO (stores texture coordinates)
    GLuint uvbuffer;
    glGenBuffers(1, &uvbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_uv_buffer_data), g_uv_buffer_data, GL_STATIC_DRAW);
    // Configure for 2 floats per point (2D texture)
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, nullptr);

    // Unbind the VBOs and VAO
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    is_loaded = true;

    return VertexArrayID;
}

static void drawVAO(GLuint id, int size) {
    glBindVertexArray(id);
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);
    glDrawArrays(GL_TRIANGLES, 0, size);
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glDisableVertexAttribArray(2);
    glBindVertexArray(0);
}


void drawSquare() {
    drawVAO(getSquareVAO(), 6);
}
