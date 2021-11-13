#version 330 core

layout(location = 0) in vec3 vertexPosition;
layout(location = 1) in vec2 texturePosIn;

out vec2 texturePos;

uniform vec3 scale;
uniform vec3 position;

void main(){
    gl_Position.xyz = vertexPosition * scale + position;
    gl_Position.w = 1.0;

    texturePos = texturePosIn;
}
