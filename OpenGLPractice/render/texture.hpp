//
//  texture.hpp
//  OpenGLPractice
//
//  Created by Brandon Kervin on 1/9/18.
//  Copyright © 2018 Brandon Kervin. All rights reserved.
//

#ifndef texture_hpp
#define texture_hpp

#include <stdio.h>
#include <string>
#include <OpenGL/gl3.h>

class Texture {
public:
    Texture(const std::string& file);
    void bind(unsigned int offset);
    virtual ~Texture();
private:
    GLuint texture;
};

#endif /* texture_hpp */
