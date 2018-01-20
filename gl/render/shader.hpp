//
//  shader.hpp
//  gl
//
//  Created by Brandon Kervin on 1/18/18.
//  Copyright © 2018 Brandon Kervin. All rights reserved.
//

#ifndef shader_hpp
#define shader_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include <fstream>
#include <OpenGL/gl3.h>
#include <glm/glm.hpp>
#include "camera.hpp"

enum TYPE {
    FLASHLIGHT,
    LAMP,
    LAMP_INHERIT,
    SKYBOX
};

class Shader {
public:
    Shader(const std::string& file);
    Shader(TYPE type);
    void bind();
    void setPosition(const glm::vec3 &position);
    void update(Camera& cam);
    void updateLight(Camera& cam, glm::vec3 lightPos);
    void updateLitElement(Camera &cam, std::vector<glm::vec3> lightPositions);
    void addLamp();
    void setLampColor(const glm::vec3 &color);
    void setBool(const std::string &name, bool value) const;
    void setInt(const std::string &name, int value) const;
    void setFloat(const std::string &name, float value) const;
    void setVec3(const std::string &name, const glm::vec3 &value) const;
    void setMat4(const std::string &name, const glm::mat4 &value) const;
private:
    Shader(const Shader& other){}
    void operator = (const Shader& other){}
    void init(const std::string &file);
    GLuint program;
    TYPE type;
};

#endif /* shader_hpp */
