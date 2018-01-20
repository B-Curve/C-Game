#version 410 core

layout (location = 0) in vec3 pos;
layout (location = 1) in vec2 tCoord;
layout (location = 2) in vec3 normal;

out vec2 texCoord;
out vec3 normal0;
out vec3 torchPos;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main(){
    mat4 MVP = projection * view * model;
    texCoord = tCoord;
    normal0 = normal;
    torchPos = pos;
    gl_Position = MVP * vec4(pos, 1.0);
}
