//
//  text.hpp
//  OpenGLPractice
//
//  Created by Brandon Kervin on 1/10/18.
//  Copyright © 2018 Brandon Kervin. All rights reserved.
//

#ifndef text_hpp
#define text_hpp

#include <iostream>
#include <map>
#include <string>
#include <stdio.h>
#include <OpenGL/gl3.h>
#include "../render/shader.hpp"
#include "../render/texture.hpp"

class Text {
public:
    Text();
    void draw(const std::string& text);
private:
    void generateText();
    GLuint vao;
    GLuint vbo;
    GLuint tbo;
    std::map<char, Texture*> letters;
    std::map<char, Texture*>::iterator it;
    Shader* shader;
};

#endif /* text_hpp */
