#version 410 core

layout (location = 0) in vec3 pos;
layout (location = 1) in vec2 tCoord;
layout (location = 2) in vec3 normal;

out vec2 texCoord;
out vec3 normal0;
out vec3 pos0;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform vec3 position;

void main(){
    pos0 = vec3(model * vec4(pos + position, 1.0));
    texCoord = tCoord;
    normal0 = mat3(transpose(inverse(model))) * normal;
    gl_Position = projection * view * vec4(pos0, 1.0);
}

