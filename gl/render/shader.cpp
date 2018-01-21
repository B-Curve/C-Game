//
//  shader.cpp
//  gl
//
//  Created by Brandon Kervin on 1/18/18.
//  Copyright © 2018 Brandon Kervin. All rights reserved.
//

#include "shader.hpp"

static void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage);
static std::string LoadShader(const std::string& filename);
static GLuint CreateShader(const std::string& text, GLenum shaderType);

Shader::Shader(const std::string& file){
    init(file);
}

Shader::Shader(LIGHT_TYPE type){
    this->type = type;
    if(type == FLASHLIGHT){
        init("./shaders/shader");
    }
    if(type == LAMP){
        init("./shaders/lamp");
    }
    if(type == SKYBOX){
        init("./shaders/sky");
    }
    if(type == LAMP_INHERIT){
        init("./shaders/lamp_inherit");
    }
}

void Shader::init(const std::string &file){
    program = glCreateProgram();
    unsigned int vShader = CreateShader(LoadShader(file + ".vert"), GL_VERTEX_SHADER);
    unsigned int fShader = CreateShader(LoadShader(file + ".frag"), GL_FRAGMENT_SHADER);
    glAttachShader(program, vShader);
    glAttachShader(program, fShader);
    glLinkProgram(program);
    glValidateProgram(program);
    glUseProgram(program);
    glDeleteShader(vShader);
    glDeleteShader(fShader);
}

void Shader::bind(){
    glUseProgram(program);
}

void Shader::setPosition(const glm::vec3 &position){
    this->setVec3("position", position);
}

void Shader::update(Camera& cam){
    if(type == FLASHLIGHT){
        this->setMat4("model", cam.getModel());
        this->setMat4("view", cam.getView());
        this->setMat4("projection", cam.getProjection());
        this->setVec3("light.position", cam.getPos());
        this->setVec3("camPos", cam.getPos());
        this->setVec3("light.direction", cam.getFront());
        this->setFloat("light.cutOff", glm::cos(glm::radians(12.5f)));
        this->setFloat("light.outerCutOff", glm::cos(glm::radians(17.5f)));
        this->setVec3("light.ambient", glm::vec3(0.4f, 0.4f, 0.4f));
        this->setVec3("light.diffuse", glm::vec3(0.8f, 0.8f, 0.8f));
        this->setVec3("light.specular", glm::vec3(1.0f, 1.0f, 1.0f));
        this->setFloat("light.constant", 1.0f);
        this->setFloat("light.linear", 0.09f);
        this->setFloat("light.quadratic", 0.032f);
        this->setFloat("material.shininess", 32.0f);
    }
    if(type == SKYBOX){
        this->setInt("skybox", 0);
        this->setMat4("view", glm::mat3(cam.getView()));
        this->setMat4("projection", cam.getProjection());
    }
}

void Shader::updateLight(Camera &cam, glm::vec3 lightPos){
    if(type == LAMP){
        glm::mat4 model = cam.getModel();
        model = glm::translate(model, lightPos);
        model = glm::scale(model, glm::vec3(0.2f));
        this->setMat4("model", model);
        this->setMat4("view", cam.getView());
        this->setMat4("projection", cam.getProjection());
    }
}

void Shader::updateLitElement(Camera &cam, std::vector<glm::vec3> lampPositions, std::vector<glm::vec3> lampColors, std::vector<LIGHT_STRENGTH> lightStrengths){
    if(type == LAMP_INHERIT){
        this->setMat4("model", cam.getModel());
        this->setMat4("view", cam.getView());
        this->setMat4("projection", cam.getProjection());
        this->setVec3("camPos", cam.getPos());
        for(int i = 0 ; i < lampPositions.size() ; i++){
            this->setVec3("lights[" + std::to_string(i) + "].position", lampPositions[i]);
            this->setVec3("lights[" + std::to_string(i) + "].ambient", glm::vec3(0.2f, 0.2f, 0.2f));
            this->setVec3("lights[" + std::to_string(i) + "].diffuse", glm::vec3(0.8f, 0.8f, 0.8f));
            this->setVec3("lights[" + std::to_string(i) + "].specular", glm::vec3(1.0f, 1.0f, 1.0f));
            this->setVec3("lights[" + std::to_string(i) + "].color", lampColors[i]);
            this->setLightType(lightStrengths[i], i);
        }
        this->setFloat("material.shininess", 32.0f);
    }
}

void Shader::setLightType(LIGHT_STRENGTH type, unsigned int index){
    float constant = 1.0f, linear = 0.7f, quadratic = 1.8f;
    switch (type) {
        case DIM:
            linear = 0.7f; quadratic = 1.8f;
            break;
        case MILD:
            linear = 0.22f; quadratic = 0.20f;
            break;
        case BRIGHT:
            linear = 0.07f; quadratic = 0.017f;
            break;
        case SUPER_BRIGHT:
            linear = 0.022f; quadratic = 0.0019f;
            break;
        case COLOSSAL:
            linear = 0.007f; quadratic = 0.0002f;
            break;
        case SUN:
            linear = 0.0014f; quadratic = 0.000007f;
            break;
        default:
            linear = 0.7f; quadratic = 1.8f; //shouldn't default, but just in case!
            break;
    }
    this->setFloat("lights[" + std::to_string(index) + "].constant", constant);
    this->setFloat("lights[" + std::to_string(index) + "].linear", linear);
    this->setFloat("lights[" + std::to_string(index) + "].quadratic", quadratic);
}

void Shader::setLampColor(const glm::vec3 &color){
    this->setVec3("lightColor", color);
}

void Shader::setBool(const std::string &name, bool value) const {
    glUniform1i(glGetUniformLocation(program, name.c_str()), (int)value);
}

void Shader::setInt(const std::string &name, int value) const {
    glUniform1i(glGetUniformLocation(program, name.c_str()), value);
}

void Shader::setFloat(const std::string &name, float value) const {
    glUniform1f(glGetUniformLocation(program, name.c_str()), value);
}

void Shader::setVec3(const std::string &name, const glm::vec3 &value) const {
    glUniform3fv(glGetUniformLocation(program, name.c_str()), 1, &value[0]);
}

void Shader::setMat4(const std::string &name, const glm::mat4 &value) const {
    glUniformMatrix4fv(glGetUniformLocation(program, name.c_str()), 1, GL_FALSE, &value[0][0]);
}

static GLuint CreateShader(const std::string& text, GLenum shaderType){
    GLuint shader = glCreateShader(shaderType);
    
    if(shader == 0){
        fprintf(stderr, "Error: Shader Creation Failed.\n");
    }
    
    const GLchar* shaderSourceStrings[1];
    GLint shaderSourceStringLength[1];
    shaderSourceStrings[0] = text.c_str();
    shaderSourceStringLength[0] = text.length();
    
    glShaderSource(shader, 1, shaderSourceStrings, shaderSourceStringLength);
    glCompileShader(shader);
    
    CheckShaderError(shader, GL_COMPILE_STATUS, false, "ERROR: Shader Compilation Failed: \n");
    
    return shader;
}

static std::string LoadShader(const std::string& filename){
    std::ifstream file;
    file.open((filename).c_str());
    
    std::string output;
    std::string line;
    
    if(file.is_open()){
        while(file.good()){
            getline(file, line);
            output.append(line + "\n");
        }
    }else{
        fprintf(stderr, "Unable to load shader: %s", filename.c_str());
    }
    
    return output;
}

static void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage){
    GLint success = 0;
    GLchar error[1024] = {0};
    
    if(isProgram){
        glGetProgramiv(shader, flag, &success);
    }else{
        glGetShaderiv(shader, flag, &success);
    }
    
    if(success == GL_FALSE){
        if(isProgram){
            glGetProgramInfoLog(shader, sizeof(error), NULL, error);
        }else{
            glGetShaderInfoLog(shader, sizeof(error), NULL, error);
        }
        fprintf(stderr, "%s: '%s'", errorMessage.c_str(), error);
    }
}
