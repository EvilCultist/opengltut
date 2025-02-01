#version 150 core

in vec3 position;
in vec3 color;
in vec2 texCord;

out vec3 Color;
out vec2 TexCord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main() {
    Color = color;
    TexCord = texCord;
    gl_Position = projection * view * model * vec4(position, 1.0);
}
