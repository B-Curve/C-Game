//
//  shader.cpp
//  MinecraftClone
//
//  Created by Brandon Kervin on 1/30/18.
//  Copyright © 2018 Brandon Kervin. All rights reserved.
//

#include "shader.hpp"

static GLuint loadShader(std::string filename, GLenum type);
static void checkShaderError(GLuint shader);

Shader::Shader(const std::string &file){
    GLuint vShader = loadShader(("./shaders/" + file + ".vert"), GL_VERTEX_SHADER);
    GLuint fShader = loadShader(("./shaders/" + file + ".frag"), GL_FRAGMENT_SHADER);
    program = glCreateProgram();
    glAttachShader(program, vShader);
    glAttachShader(program, fShader);
    glLinkProgram(program);
    glValidateProgram(program);
    glUseProgram(program);
    glDetachShader(program, vShader);
    glDetachShader(program, fShader);
    glDeleteShader(vShader);
    glDeleteShader(fShader);
}

void Shader::bind(){
    glUseProgram(program);
}

void Shader::setMat4(std::string name, glm::mat4 value){
    glUniformMatrix4fv(glGetUniformLocation(program, name.c_str()), 1, GL_FALSE, &value[0][0]);
}

void Shader::setVec3(std::string name, glm::vec3 value){
    glUniform3fv(glGetUniformLocation(program, name.c_str()), 1, &value[0]);
}

static GLuint loadShader(std::string filename, GLenum type){
    std::ifstream file;
    file.open(filename.c_str());
    
    std::string out;
    std::string line;
    
    if(file.is_open()){
        while(file.good()){
            getline(file, line);
            out.append(line + "\n");
        }
    }else{
        fprintf(stderr, "Failed to open file: %s", filename.c_str());
    }
    
    GLuint shader = glCreateShader(type);
    
    const GLchar* shaderSourceStrings[1];
    GLint shaderSourceStringSize[1];
    shaderSourceStrings[0] = out.c_str();
    shaderSourceStringSize[0] = (GLint) out.length();
    
    glShaderSource(shader, 1, shaderSourceStrings, shaderSourceStringSize);
    glCompileShader(shader);
    
    checkShaderError(shader);
    
    return shader;
}

static void checkShaderError(GLuint shader){
    GLint success = 0;
    GLchar error[1024] = {0};
    
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    
    if(success == GL_FALSE){
        glGetShaderInfoLog(shader, sizeof(error), nullptr, error);
        fprintf(stderr, "Shader Error: %s", error);
    }
}







