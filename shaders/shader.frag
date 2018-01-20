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
    vec3 direction;
    float cutOff;
    float outerCutOff;
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

void main(){
    vec3 normal1 = texture(material.bump, texCoord).rgb;
    normal1 = normalize(normal1 * 2.0 - 1.0);
    
    vec3 ambient = light.ambient * texture(material.diffuse, texCoord).rgb;
    
    vec3 norm = normalize(normal1);
    vec3 lightDir = normalize(light.position - pos0);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = light.diffuse * diff * texture(material.diffuse, texCoord).rgb;
    
    vec3 viewDir = normalize(camPos - pos0);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    vec3 specular = light.specular * spec * texture(material.diffuse, texCoord).rgb;
    
    float theta = dot(lightDir, normalize(-light.direction));
    float epsilon = (light.cutOff - light.outerCutOff);
    float intensity = clamp((theta - light.outerCutOff) / epsilon, 0.0, 1.0);
    diffuse*=intensity;
    specular*=intensity;
    
    float dist = length(light.position - pos0);
    float attenuation = 1.0 / (light.constant + light.linear * dist + light.quadratic * (dist*dist));
    
    ambient*=attenuation;
    diffuse*=attenuation;
    specular*=attenuation;
    
    vec3 result = ambient + diffuse + specular;
    color = vec4(result, 1.0);
}
