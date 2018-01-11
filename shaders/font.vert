#version 410 core

layout (location = 0) in vec3 pos;
layout (location = 1) in vec2 uvCoords;

out vec2 uv;

uniform vec2 offset;

void main(){
    gl_Position = vec4(pos.x + offset.x, pos.y + offset.y, pos.z, 1.0);
    uv = uvCoords;
}
