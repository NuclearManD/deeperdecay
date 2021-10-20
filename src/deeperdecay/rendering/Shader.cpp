//
// Created by nuclaer on 10/15/21.
//

#include <GL/glew.h>
#include <GL/gl.h>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

#include "Shader.h"
#include "deeperdecay/util/logging.h"

Shader::Shader(const char* path, GLuint type) {
    GLint Result = GL_FALSE;
    int InfoLogLength;

    shaderId = glCreateShader(type);

    // Read the shader code from the file
    std::string shaderSource;
    std::ifstream fileStream(path, std::ios::in);
    if (fileStream.is_open()) {
        std::stringstream sstr;
        sstr << fileStream.rdbuf();
        shaderSource = sstr.str();
        fileStream.close();
    } else {
        log_printf("Can't open shader '%s'.", ERROR, path);
        return;
    }

    // Compile shader
    log_printf("Compiling shader : %s", DEBUG, path);
    char const *srcPtr = shaderSource.c_str();
    glShaderSource(shaderId, 1, &srcPtr, NULL);
    glCompileShader(shaderId);

    // Check shader
    glGetShaderiv(shaderId, GL_COMPILE_STATUS, &Result);
    glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &InfoLogLength);
    if (InfoLogLength > 0) {
        std::vector<char> VertexShaderErrorMessage(InfoLogLength + 1);
        glGetShaderInfoLog(shaderId, InfoLogLength, NULL, &VertexShaderErrorMessage[0]);
        log_printf("%s", ERROR, &VertexShaderErrorMessage[0]);
    }

    isInitialized = true;
}

GLuint Shader::getId() {
    return shaderId;
}

Shader::~Shader() {
    if (isInitialized)
        glDeleteShader(shaderId);
}

ShaderProgram::ShaderProgram() {
    programId = glCreateProgram();
}

void ShaderProgram::attachShader(Shader &shader) {
    glAttachShader(programId, shader.getId());
}

void ShaderProgram::detachShader(Shader &shader) {
    glDetachShader(programId, shader.getId());
}

int ShaderProgram::link() {
    GLint result = GL_FALSE;
    int linkLogLen;

    glLinkProgram(programId);

    // Check the program
    glGetProgramiv(programId, GL_LINK_STATUS, &result);
    glGetProgramiv(programId, GL_INFO_LOG_LENGTH, &linkLogLen);
    if (linkLogLen > 0 ){
        std::vector<char> ProgramErrorMessage(linkLogLen + 1);
        glGetProgramInfoLog(programId, linkLogLen, nullptr, &ProgramErrorMessage[0]);
        printf("%s\n", &ProgramErrorMessage[0]);
    }
}

void ShaderProgram::enable() {
    glUseProgram(programId);
}

GLuint ShaderProgram::getUniformId(const char* s) {
    return glGetUniformLocation(programId, s);
}
