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

typedef struct {
    GLuint count;
    GLuint instanceCount;
    GLuint first;
    GLuint baseInstance;
} DrawArraysIndirectCommand;

class Buffer {
public:
    Buffer(float* verticies, unsigned int vertCount);
    Buffer(float* verticies, unsigned int vertCount, float* texCoords, unsigned int tCoordCount, std::vector<Transform> transforms, unsigned int transformCount);
    Buffer(float* verticies, unsigned int vertCount, float* texCoords, unsigned int tCoordCount, glm::vec3* normals, unsigned int normalsCount);
    Buffer(float* verticies, unsigned int vertCount, float* texCoords, unsigned int tCoordCount);
    Buffer();
    //DO NOT USE
    Buffer(float* verticies, unsigned int vertCount, float* texCoords, unsigned int tCoordCount, std::vector<glm::vec3> positions, unsigned int positionCount);
    void draw(unsigned int instances);
    void drawWithoutIndices(unsigned int instances);
    void drawBatchCube(unsigned int instances);
    inline void updateModels(std::vector<glm::mat4> models){
        this->models = models;
        updateTransforms();
    }
    void testClear();
private:
    void updateTransforms();
    unsigned int indCount;
    unsigned int vertCount;
    GLuint vbo;
    GLuint vao;
    GLuint ibo;
    GLuint tbo;
    GLuint nbo;
    GLuint transBO;
    std::vector<glm::mat4> models;
    std::vector<glm::mat3x4> positions2;
    std::vector<glm::vec3> positions;
};

#endif /* buffer_hpp */
