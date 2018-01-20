#version 410 core

in vec2 texCoord;
in vec3 normal0;
in vec3 pos0;

out vec4 color;

struct Material {
    sampler2D diffuse;
    sampler2D bump;
    float shininess;
};

struct Light {
    vec3 position;
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float constant;
    float linear;
    float quadratic;
};

uniform vec3 camPos;
uniform Material material;
uniform Light light;

#define LIGHT_COUNT 4
uniform Light lights[LIGHT_COUNT];

vec3 applyLight(vec3 _normal, Light light, vec3 _fragPos, vec2 _texCoord);

void main(){
    vec3 normal1 = texture(material.bump, texCoord).rgb;
    normal1 = normalize(normal1 * 2.0 - 1.0);
    
    vec3 norm = normalize(normal1);
    
    vec3 result = vec3(0.0, 0.0, 0.0);
    
    for(int i = 0 ; i < LIGHT_COUNT ; i++){
        result += applyLight(normal1, lights[i], pos0, texCoord);
    }
    
//    vec3 ambient = light.ambient * texture(material.diffuse, texCoord).rgb;
//    vec3 lightDir = normalize(light.position - pos0);
//    float diff = max(dot(norm, lightDir), 0.0);
//    vec3 diffuse = light.diffuse * diff * texture(material.diffuse, texCoord).rgb;
//    
//    vec3 viewDir = normalize(light.position - pos0);
//    vec3 reflectDir = reflect(-lightDir, norm);
//    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
//    vec3 specular = light.specular * spec * texture(material.diffuse, texCoord).rgb;
//    
//    float dist = length(light.position - pos0);
//    float attenuation = 1.0 / (light.constant + light.linear * dist + light.quadratic * (dist*dist));
//    
//    ambient*=attenuation;
//    diffuse*=attenuation;
//    specular*=attenuation;
//    
//    vec3 result = ambient + diffuse + specular;
    color = vec4(result, 1.0);
}

vec3 applyLight(vec3 _normal, Light light, vec3 _fragPos, vec2 _texCoord){
    vec3 ambient = light.ambient * texture(material.diffuse, _texCoord).rgb;
    
    vec3 lightDir = normalize(light.position - _fragPos);
    float diff = max(dot(_normal, lightDir), 0.0);
    vec3 diffuse = light.diffuse * diff * texture(material.diffuse, _texCoord).rgb;
    
    vec3 viewDir = normalize(light.position - _fragPos);
    vec3 reflectDir = reflect(-lightDir, _normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    vec3 specular = light.specular * spec * texture(material.diffuse, _texCoord).rgb;
    
    float dist = length(light.position - _fragPos);
    float attenuation = 1.0 / (light.constant + light.linear * dist + light.quadratic * (dist*dist));
    
    ambient*=attenuation;
    diffuse*=attenuation;
    specular*=attenuation;
    
    return (ambient + diffuse + specular);
}









