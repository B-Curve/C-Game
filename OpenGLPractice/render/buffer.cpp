//
//  buffer.cpp
//  OpenGLPractice
//
//  Created by Brandon Kervin on 1/9/18.
//  Copyright © 2018 Brandon Kervin. All rights reserved.
//

#include <iostream>
#include "buffer.hpp"

Buffer::Buffer(float* verticies, unsigned int vertCount){
    this->vertCount = vertCount;
    
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    
    glBindVertexArray(vao);
    
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, vertCount * sizeof(float), verticies, GL_STATIC_DRAW);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void Buffer::updateTransforms(){
    glDeleteBuffers(1, &transBO);
    glGenBuffers(1, &transBO);
    glBindBuffer(GL_ARRAY_BUFFER, transBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(models), &models[0], GL_STATIC_DRAW);
}

Buffer::Buffer(float* verticies, unsigned int vertCount, float* texCoords, unsigned int tCoordCount, glm::vec3* normals, unsigned int normalsCount){
    this->vertCount = vertCount;
    
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glGenBuffers(1, &tbo);
    glGenBuffers(1, &nbo);
    
    glBindVertexArray(vao);
    
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, vertCount * sizeof(float), verticies, GL_STATIC_DRAW);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    
    glBindBuffer(GL_ARRAY_BUFFER, tbo);
    glBufferData(GL_ARRAY_BUFFER, vertCount * sizeof(float), texCoords, GL_STATIC_DRAW);
    
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(1);
    
    glBindBuffer(GL_ARRAY_BUFFER, nbo);
    glBufferData(GL_ARRAY_BUFFER, normalsCount * sizeof(glm::vec3), &normals[0], GL_STATIC_DRAW);
    
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(2);
    
    glBindVertexArray(0);
}

Buffer::Buffer(float* verticies, unsigned int vertCount, float* texCoords, unsigned int tCoordCount){
    this->vertCount = vertCount;
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glGenBuffers(1, &tbo);
    
    glBindVertexArray(vao);
    
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, vertCount * sizeof(float), verticies, GL_STATIC_DRAW);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    
    glBindBuffer(GL_ARRAY_BUFFER, tbo);
    glBufferData(GL_ARRAY_BUFFER, tCoordCount * sizeof(float), texCoords, GL_STATIC_DRAW);
    
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(1);
    
    glBindVertexArray(0);
}

Buffer::Buffer(){
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glGenBuffers(1, &tbo);
    glGenBuffers(1, &ibo);
    
    
}

//DO NOT USE
Buffer::Buffer(float* verticies, unsigned int vertCount, float* texCoords, unsigned int tCoordCount, std::vector<glm::vec3> positions, unsigned int positionCount){
    this->vertCount = vertCount;
    this->positions = positions;
    
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glGenBuffers(1, &tbo);
    glGenBuffers(1, &transBO);
    
    glBindVertexArray(vao);
    
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, vertCount * sizeof(float), verticies, GL_STATIC_DRAW);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    
    glBindBuffer(GL_ARRAY_BUFFER, tbo);
    glBufferData(GL_ARRAY_BUFFER, vertCount * sizeof(float), texCoords, GL_STATIC_DRAW);
    
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(1);
    
    glBindBuffer(GL_ARRAY_BUFFER, transBO);
    glBufferData(GL_ARRAY_BUFFER, positionCount * sizeof(positions[0]), &positions[0], GL_STATIC_DRAW);
    
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), (void*)0);
    glEnableVertexAttribArray(2);
    glVertexAttribDivisor(2, 1);
    
//    glVertexAttribPointer(2, 4, GL_FLOAT, GL_FALSE, sizeof(glm::mat4), (void*)0);
//    glEnableVertexAttribArray(2);
//    glVertexAttribPointer(3, 4, GL_FLOAT, GL_FALSE, sizeof(glm::mat4), (void*)(sizeof(float) * 4));
//    glEnableVertexAttribArray(3);
//    glVertexAttribPointer(4, 4, GL_FLOAT, GL_FALSE, sizeof(glm::mat4), (void*)(sizeof(float) * 8));
//    glEnableVertexAttribArray(4);
//    glVertexAttribPointer(5, 4, GL_FLOAT, GL_FALSE, sizeof(glm::mat4), (void*)(sizeof(float) * 12));
//    glEnableVertexAttribArray(5);
//    glVertexAttribDivisor(2, 1);
//    glVertexAttribDivisor(3, 1);
//    glVertexAttribDivisor(4, 1);
//    glVertexAttribDivisor(5, 1);
    
    glBindVertexArray(0);
}

Buffer::Buffer(float* verticies, unsigned int vertCount, float* texCoords, unsigned int tCoordCount, std::vector<Transform> transforms, unsigned int transformCount){
    this->vertCount = vertCount;
    for(unsigned int i = 0 ; i < transformCount ; i++){
        models.push_back(transforms[i].getModel());
    }
    
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glGenBuffers(1, &tbo);
    glGenBuffers(1, &transBO);
    
    glBindVertexArray(vao);
    
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, vertCount * sizeof(float), verticies, GL_STATIC_DRAW);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    
    glBindBuffer(GL_ARRAY_BUFFER, tbo);
    glBufferData(GL_ARRAY_BUFFER, vertCount * sizeof(float), texCoords, GL_STATIC_DRAW);
    
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(1);
    
    glBindBuffer(GL_ARRAY_BUFFER, transBO);
    glBufferData(GL_ARRAY_BUFFER, transformCount * sizeof(models[0]), &models[0], GL_STATIC_DRAW);
    
    glVertexAttribPointer(2, 4, GL_FLOAT, GL_FALSE, sizeof(glm::mat4), (void*)0);
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(3, 4, GL_FLOAT, GL_FALSE, sizeof(glm::mat4), (void*)(sizeof(glm::vec4)));
    glEnableVertexAttribArray(3);
    glVertexAttribPointer(4, 4, GL_FLOAT, GL_FALSE, sizeof(glm::mat4), (void*)(sizeof(glm::vec4) * 2));
    glEnableVertexAttribArray(4);
    glVertexAttribPointer(5, 4, GL_FLOAT, GL_FALSE, sizeof(glm::mat4), (void*)(sizeof(glm::vec4) * 3));
    glEnableVertexAttribArray(5);
    glVertexAttribDivisor(2, 1);
    glVertexAttribDivisor(3, 1);
    glVertexAttribDivisor(4, 1);
    glVertexAttribDivisor(5, 1);
    
    glBindVertexArray(0);
}

void Buffer::draw(unsigned int instances){
    glBindVertexArray(vao);
    glDrawElementsInstanced(GL_TRIANGLES, indCount, GL_UNSIGNED_INT, 0, instances);
//    glDrawElements(GL_TRIANGLES, indCount, GL_UNSIGNED_INT, 0);
}

void Buffer::drawWithoutIndices(unsigned int instances){
    glBindVertexArray(vao);
    glDrawArraysInstanced(GL_TRIANGLES, 0, vertCount, instances);
//    glDrawArrays(GL_TRIANGLES, 0, vertCount);
    glBindVertexArray(0);
}

void Buffer::drawBatchCube(unsigned int instances){
    
}










