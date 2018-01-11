#version 410 core

in vec2 uv;

out vec4 frag_color;

uniform sampler2D texSampler;

void main(){
    frag_color = texture( texSampler, uv ).rgba;
}
