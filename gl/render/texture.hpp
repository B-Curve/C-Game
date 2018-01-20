//
//  texture.hpp
//  gl
//
//  Created by Brandon Kervin on 1/18/18.
//  Copyright © 2018 Brandon Kervin. All rights reserved.
//

#ifndef texture_hpp
#define texture_hpp

#include <stdio.h>
#include <string>
#include <OpenGL/gl3.h>
#include "./shader.hpp"

class CubeMap {
public:
    CubeMap();
    void draw(Camera &cam);
private:
    GLuint map;
    Shader * shader;
    GLuint vbo;
    GLuint vao;
};

class Texture{
public:
    Texture(const std::string& filename, bool flip);
    void bind(unsigned int unit);
    virtual ~Texture();
    Texture(const Texture& other){}
private:
    GLuint texture;
};

#endif /* texture_hpp */
