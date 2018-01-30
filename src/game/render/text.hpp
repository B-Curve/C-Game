//
//  text.hpp
//  MinecraftClone
//
//  Created by Brandon Kervin on 1/30/18.
//  Copyright © 2018 Brandon Kervin. All rights reserved.
//

#ifndef text_hpp
#define text_hpp

#ifndef GLFW_INCLUDE_GLCOREARB
    #define GLFW_INCLUDE_GLCOREARB
#endif
#ifndef utils_hpp
    #include "../../utils.hpp"
#endif
#include <glm/gtx/transform.hpp>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <map>
#include <ft2build.h>
#include <freetype/freetype.h>
#ifndef shader_hpp
#include "shader.hpp"
#endif

struct Character {
    GLuint TextureID;
    glm::ivec2 Size;
    glm::ivec2 Bearing;
    GLuint Advance;
};

class Text {
public:
    Text();
    void render(std::string text, GLfloat x, GLfloat y, GLfloat scale, glm::vec3 color);
private:
    FT_Library ft;
    FT_Face face;
    Shader *shader;
    std::map<GLchar, Character> characters;
    GLuint vao, vbo;
};

#endif /* text_hpp */
