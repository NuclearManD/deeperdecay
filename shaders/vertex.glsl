#version 330 core

layout(location = 0) in vec3 vertexPosition;
layout(location = 1) in vec2 texturePosIn;

out vec2 texturePos;

uniform vec3 meshScale;
uniform vec3 meshPosition;
uniform vec2 origin;
uniform vec2 windowScale;

void main() {
    vec3 worldPos = vertexPosition * meshScale + meshPosition;
    gl_Position.xy = (worldPos.xy - origin) * windowScale;
    // We negatate this so that z values 1 and above are not discarded.  This also means that
    // the depth test operator is inverted (Would be GL_GREATER if not for this change)
    gl_Position.z = -worldPos.z;
    gl_Position.w = 1.0;

    texturePos = texturePosIn;
}
