#version 410 core

in vec3 position;
in vec2 uv;

out vec4 frag_color;

uniform sampler2D texSampler;

void main(){
    if(position.z == -0.5f || position.z == 0.5f){
        if(position.x > -0.495f && position.x < 0.495f && position.y > -0.495f && position.y < 0.495f){
            frag_color = texture( texSampler, uv );
        }else{
            frag_color = vec4(0,0,0,1.0);
        }
    }else if(position.x == -0.5f || position.x == 0.5f){
        if(position.z > -0.495f && position.z < 0.495f && position.y > -0.495f && position.y < 0.495f){
            frag_color = texture( texSampler, uv );
        }else{
            frag_color = vec4(0,0,0,1.0);
        }
    }else if(position.y == -0.5f || position.y == 0.5f){
        if(position.z > -0.495f && position.z < 0.495f && position.x > -0.495f && position.x < 0.495f){
            frag_color = texture( texSampler, uv );
        }else{
            frag_color = vec4(0,0,0,1.0);
        }
    }else{
        frag_color = texture( texSampler, uv );
    }
}
