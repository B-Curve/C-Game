//
//  text.cpp
//  MinecraftClone
//
//  Created by Brandon Kervin on 1/30/18.
//  Copyright © 2018 Brandon Kervin. All rights reserved.
//

#include "text.hpp"
#include <iostream>

Text::Text(){
    
    shader = new Shader("text");
    
    if (FT_Init_FreeType(&ft))
        std::cout << "Freetype Error: Could not start the FreeType Library" << std::endl;
    
    if (FT_New_Face(ft, "./fonts/oswald/Oswald-Bold.ttf", 0, &face))
        std::cout << "Freetype Error: Failed to load font" << std::endl;
    
    FT_Set_Pixel_Sizes(face, 0, 48);
    
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    
    for (GLubyte c = 0; c < 128; c++){
        
        if (FT_Load_Char(face, c, FT_LOAD_RENDER)){
            std::cout << "Freetype Error: Failed to load Glyph -> " << c << std::endl;
            continue;
        }
        
        GLuint texture;
        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture);
        glTexImage2D(
                     GL_TEXTURE_2D,
                     0,
                     GL_RED,
                     face->glyph->bitmap.width,
                     face->glyph->bitmap.rows,
                     0,
                     GL_RED,
                     GL_UNSIGNED_BYTE,
                     face->glyph->bitmap.buffer
                     );
        
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        
        Character character = {
            texture,
            glm::ivec2(face->glyph->bitmap.width, face->glyph->bitmap.rows),
            glm::ivec2(face->glyph->bitmap_left, face->glyph->bitmap_top),
            static_cast<GLuint>(face->glyph->advance.x)
        };
        characters.insert(std::pair<GLchar, Character>(c, character));
    }
    
    vao = gen_vao();
    vbo = gen_dynamic_buffer(sizeof(GLfloat) * 6 * 4);
    
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), 0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    
    FT_Done_Face(face);
    FT_Done_FreeType(ft);
    
}

void Text::render(std::string text, GLfloat x, GLfloat y, GLfloat scale, glm::vec3 color){
    shader->bind();
    shader->setVec3("textColor", color);
    shader->setMat4("projection", glm::ortho(0.0f, 800.0f, 0.0f, 600.0f));
    glActiveTexture(GL_TEXTURE0);
    glBindVertexArray(vao);
    
    glDepthFunc(GL_ALWAYS);
    
    std::string::const_iterator c;
    for (c = text.begin(); c != text.end(); c++){
        Character ch = characters[*c];
        
        GLfloat xpos = x + ch.Bearing.x * scale;
        GLfloat ypos = y - (ch.Size.y - ch.Bearing.y) * scale;
        
        GLfloat w = ch.Size.x * scale;
        GLfloat h = ch.Size.y * scale;
        
        GLfloat vertices[6][4] = {
            { xpos,     ypos + h,   0.0, 0.0 },
            { xpos,     ypos,       0.0, 1.0 },
            { xpos + w, ypos,       1.0, 1.0 },
            
            { xpos,     ypos + h,   0.0, 0.0 },
            { xpos + w, ypos,       1.0, 1.0 },
            { xpos + w, ypos + h,   1.0, 0.0 }
        };
        
        glBindTexture(GL_TEXTURE_2D, ch.TextureID);
        
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        
        glDrawArrays(GL_TRIANGLES, 0, 6);
        
        x += (ch.Advance >> 6) * scale;
    }
    glBindVertexArray(0);
    glBindTexture(GL_TEXTURE_2D, 0);
    
    glDepthFunc(GL_LESS);
}





