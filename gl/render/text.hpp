//
//  text.hpp
//  gl
//
//  Created by Brandon Kervin on 1/24/18.
//  Copyright © 2018 Brandon Kervin. All rights reserved.
//

#ifndef text_hpp
#define text_hpp

#include <stdio.h>
#include <map>
#include <ft2build.h>
#include <freetype/freetype.h>
#include <OpenGL/gl3.h>
#include <glm/glm.hpp>
#include "./shader.hpp"

struct Character {
    GLuint     TextureID;
    glm::ivec2 Size;
    glm::ivec2 Bearing;
    GLuint     Advance;
};

class Text {
public:
    Text();
    void draw(const std::string &text, float x, float y, float scale, glm::vec3 color);
private:
    FT_Library ft;
    FT_Face face;
    GLuint vao;
    GLuint vbo;
    std::map<GLchar, Character> characters;
    Shader * shader;
};

#endif /* text_hpp */
