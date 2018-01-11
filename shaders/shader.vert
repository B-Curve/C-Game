#version 410 core

layout (location = 0) in vec3 pos;
layout (location = 1) in vec2 uvCoords;
layout (location = 2) in mat4 transform;

out vec3 position;
out vec2 uv;

uniform mat4 MVP;

void main(){
    gl_Position = MVP * transform * vec4(pos, 1.0);
    position = pos;
    uv = uvCoords;
}
