//
//  shader.hpp
//  OpenGLPractice
//
//  Created by Brandon Kervin on 1/9/18.
//  Copyright © 2018 Brandon Kervin. All rights reserved.
//

#ifndef shader_hpp
#define shader_hpp

#include <stdio.h>
#include <fstream>
#include <string>
#include <vector>
#include <OpenGL/gl3.h>
#include "camera.hpp"

class Shader {
public:
    Shader(const std::string& file);
    void bind();
    void update(Camera& cam);
    void update(Camera &cam, std::vector<glm::mat4> models, unsigned int size);
    void updateSkybox(Camera& cam);
    void textOffset(float xOff, float yOff);
    inline GLuint getProgram(){return program;}
private:
    GLuint program;
    GLuint transformMatrix;
    GLuint modelMatrix;
    GLuint offset;
    GLuint view;
    GLuint projection;
};

#endif /* shader_hpp */
