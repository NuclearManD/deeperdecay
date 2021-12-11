//
// Created by nuclaer on 10/15/21.
//

#ifndef DEEPERDECAY_SHADER_H
#define DEEPERDECAY_SHADER_H

#include <stdbool.h>
#include "textures/Texture.h"
#include <GL/gl.h>


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
    void disable();

    GLuint getUniformId(const char *string);

    void setTextureSelected(Texture &texture);
    void setMeshPosition(float x, float y, float z) const;
    void setMeshScale(float x, float y, float z) const;
	void setRenderOrigin(float x, float y) const;
	void setWindowScale(float xs, float ys) const;

private:
    GLuint programId;
    GLuint textureUniform;
    GLuint scaleUniform;
	GLuint positionUniform;
	GLuint originUniform;
	GLuint windowScaleUniform;
};


#endif //DEEPERDECAY_SHADER_H
