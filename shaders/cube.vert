#version 410 core

layout (location = 0) in vec3 pos;
layout (location = 1) in vec2 texCoords;
layout (location = 2) in vec3 normals;

out vec2 texCoords0;
out vec3 normals0;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main(){
    texCoords0 = texCoords;
    normals0 = normals;
    gl_Position = projection * view * model * vec4(pos, 1.0f);
//    gl_Position = vec4(pos, 1.0f);
}
