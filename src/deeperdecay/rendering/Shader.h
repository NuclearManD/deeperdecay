//
// Created by nuclaer on 10/15/21.
//

#ifndef DEEPERDECAY_SHADER_H
#define DEEPERDECAY_SHADER_H

#include <stdbool.h>
#include <GL/gl.h>

#include "textures/Texture.h"


class Shader {
public:
    Shader(const char* path, GLuint type);

    inline explicit operator bool () const { return isInitialized; }

    // So we can do "delete shader;" and do all the work in the background automatically.
    ~Shader();

    GLuint getId();

private:
    GLuint shaderId;
    bool isInitialized;
};


class ShaderProgram {
public:
    ShaderProgram();

    void attachShader(Shader& shader);
    void detachShader(Shader& shader);

    int link();
    void enable();

    GLuint getUniformId(const char *string);

    void setTextureSelected(Texture &texture);

private:
    GLuint programId;
    GLuint textureUniform;
};


#endif //DEEPERDECAY_SHADER_H
