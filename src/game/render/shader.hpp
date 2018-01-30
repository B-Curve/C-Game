//
//  shader.hpp
//  MinecraftClone
//
//  Created by Brandon Kervin on 1/30/18.
//  Copyright © 2018 Brandon Kervin. All rights reserved.
//

#ifndef shader_hpp
#define shader_hpp

#include <string>
#include <fstream>

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

class Shader {
public:
    Shader(const std::string &file);
    void bind();
    void setMat4(std::string name, glm::mat4 value);
    void setVec3(std::string name, glm::vec3 value);
private:
    GLuint program;
};

#endif /* shader_hpp */
