#version 410 core

in vec2 texCoords0;
in vec3 normals0;

out vec4 color;

uniform sampler2D tex;

void main(){
    color = texture(tex, texCoords0);
}
