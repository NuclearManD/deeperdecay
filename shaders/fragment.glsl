#version 330 core

// Interpolated values from the vertex shaders
in vec2 texturePos;

// Ouput data
out vec4 color;

// Values that stay constant for the whole mesh.
uniform sampler2D textureId;

void main(){
    // Output color = color of the texture at the specified position
    color = texture(textureId, texturePos).rgba;
    if(color.a < 0.05)
        discard;
}
