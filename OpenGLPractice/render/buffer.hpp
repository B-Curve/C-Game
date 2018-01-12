//
//  buffer.hpp
//  OpenGLPractice
//
//  Created by Brandon Kervin on 1/9/18.
//  Copyright © 2018 Brandon Kervin. All rights reserved.
//

#ifndef buffer_hpp
#define buffer_hpp

#define MAX_BUFFER_SIZE 50000 //max amount of verticies on one buffer

#include <stdio.h>
#include <vector>
#include <OpenGL/gl3.h>
#include <glm/glm.hpp>
#include "transform.h"

class Buffer {
public:
    Buffer(float* verticies, unsigned int vertCount);
    Buffer(float* verticies, unsigned int vertCount, float* texCoords, unsigned int tCoordCount, std::vector<Transform> transforms, unsigned int transformCount);
    Buffer(float* verticies, unsigned int vertCount, float* texCoords, unsigned int tCoordCount, glm::vec3* normals, unsigned int normalsCount);
    Buffer(float* verticies, unsigned int vertCount, unsigned int* indices, unsigned int indCount, float* texCoords, unsigned int tCoordCount, std::vector<Transform> transforms, unsigned int transformCount);
    Buffer();
    void draw(unsigned int instances);
    void drawWithoutIndices(unsigned int instances);
    void drawBatchCube(unsigned int instances);
    void setModels(std::vector<glm::mat4> models){this->models = models;}
private:
    unsigned int indCount;
    unsigned int vertCount;
    GLuint vbo;
    GLuint vao;
    GLuint ibo;
    GLuint tbo;
    GLuint nbo;
    GLuint transBO;
    std::vector<glm::mat4> models;
};

#endif /* buffer_hpp */
