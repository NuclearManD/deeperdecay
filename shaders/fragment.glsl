#version 330 core

// Interpolated values from the vertex shaders
in vec2 texturePos;

// Ouput data
out vec3 color;

// Values that stay constant for the whole mesh.
uniform sampler2D textureId;

void main(){
    // Output color = color of the texture at the specified position
    color = vec3(0.5, 0.5, 0.5);//texture(textureId, texturePos).rgb;
}
