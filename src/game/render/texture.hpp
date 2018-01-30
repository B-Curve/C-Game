//
//  texture.hpp
//  MinecraftClone
//
//  Created by Brandon Kervin on 1/30/18.
//  Copyright © 2018 Brandon Kervin. All rights reserved.
//

#ifndef texture_hpp
#define texture_hpp

#ifndef GLFW_INCLUDE_GLCOREARB
    #define GLFW_INCLUDE_GLCOREARB
#endif
#include <GLFW/glfw3.h>
#include <string>
#include <iostream>

class Texture {
public:
    Texture(const std::string &file);
    void bind(unsigned int unit);
private:
    GLuint texture;
};

#endif /* texture_hpp */
