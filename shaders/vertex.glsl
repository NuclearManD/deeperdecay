#version 330 core

layout(location = 0) in vec3 vertexPosition;
layout(location = 1) in vec2 texturePosIn;

out vec2 texturePos;

uniform vec3 meshScale;
uniform vec3 meshPosition;
uniform vec3 origin;
uniform float windowScale;

void main(){
    gl_Position.xyz = (vertexPosition * meshScale + meshPosition - origin) * windowScale;
    gl_Position.w = 1.0;

    texturePos = texturePosIn;
}
