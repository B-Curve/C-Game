//
//  shader.cpp
//  OpenGLPractice
//
//  Created by Brandon Kervin on 1/9/18.
//  Copyright © 2018 Brandon Kervin. All rights reserved.
//

#include <iostream>
#include "shader.hpp"

static std::string LoadShader(const std::string& filename);
static unsigned int CreateShader(const std::string& text, GLenum shaderType);

Shader::Shader(const std::string& file){
    program = glCreateProgram();
    GLuint vShader = CreateShader(LoadShader(file + ".vert"), GL_VERTEX_SHADER);
    int success;
    char infoLog[512];
    glGetShaderiv(vShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    GLuint fShader = CreateShader(LoadShader(file + ".frag"), GL_FRAGMENT_SHADER);
    glGetShaderiv(fShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    glAttachShader(program, vShader);
    glAttachShader(program, fShader);
    glLinkProgram(program);
    glValidateProgram(program);
    glUseProgram(program);
    glDeleteShader(vShader);
    glDeleteShader(fShader);
    transformMatrix = glGetUniformLocation(program, "MVP");
    offset = glGetUniformLocation(program, "offset");
    view = glGetUniformLocation(program, "view");
    projection = glGetUniformLocation(program, "projection");
}

void Shader::bind(){
    glUseProgram(program);
}

void Shader::update(Camera& cam){
    glm::mat4 mvp = cam.getMVP();
    glUniformMatrix4fv(transformMatrix, 1, GL_FALSE, &mvp[0][0]);
}

void Shader::updateSkybox(Camera& cam){
    glm::mat4 camView = glm::mat4(glm::mat3(cam.getView()));
    glm::mat4 camProj = cam.getProjection();
    glUniformMatrix4fv(view, 1, GL_FALSE, &camView[0][0]);
    glUniformMatrix4fv(projection, 1, GL_FALSE, &camProj[0][0]);
}

void Shader::textOffset(float xOff, float yOff){
    glUniform2f(offset, xOff, yOff);
}

static unsigned int CreateShader(const std::string& text, GLenum shaderType){
    unsigned int shader = glCreateShader(shaderType);
    
    if(shader == 0){
        fprintf(stderr, "Error: Shader Creation Failed.\n");
    }
    
    const char* shaderSourceStrings[1];
    int shaderSourceStringLength[1];
    shaderSourceStrings[0] = text.c_str();
    shaderSourceStringLength[0] = text.length();
    
    glShaderSource(shader, 1, shaderSourceStrings, shaderSourceStringLength);
    glCompileShader(shader);
    
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
