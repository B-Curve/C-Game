#version 410 core

in vec2 texCoord;
in vec3 color0;
in vec3 normal0;
in vec3 torchPos;

out vec4 color;

uniform vec3 lightColor;

void main(){
    color = vec4(lightColor, 1.0);
}

