//
//  skybox.hpp
//  OpenGLPractice
//
//  Created by Brandon Kervin on 1/11/18.
//  Copyright © 2018 Brandon Kervin. All rights reserved.
//

#ifndef skybox_hpp
#define skybox_hpp

#include <stdio.h>
#include <string>
#include <OpenGL/gl3.h>
#include "../render/shader.hpp"

class Skybox {
public:
    Skybox();
    void render(Camera& cam);
private:
    void init();
    GLuint texture_id;
    GLuint skybox_vao;
    GLuint skybox_vbo;
    Shader * shader;
};

#endif /* skybox_hpp */
