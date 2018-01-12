//
//  batch_render.cpp
//  OpenGLPractice
//
//  Created by Brandon Kervin on 1/11/18.
//  Copyright © 2018 Brandon Kervin. All rights reserved.
//

#include "batch_render.hpp"

BatchRender::BatchRender(){
    init();
}

BatchRender::~BatchRender(){
    delete verticies;
    delete indices;
}

void BatchRender::init(){
    verticies = new std::vector<Vertex>;
    indices = new std::vector<Triangle>;
    
    glGenVertexArrays(1, &m_vao);
    glGenBuffers(1, &m_vbo);
    glGenBuffers(1, &m_ibo);
    glGenBuffers(1, &m_tbo);
    
    glBindBuffer(1, m_vbo);
    
    glBindVertexArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    
    glBindBuffer(1, m_ibo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, MAX_BUFFER_SIZE * sizeof(int), NULL, GL_DYNAMIC_DRAW);
    
    glBindBuffer(1, m_tbo);
//    glBufferSubData(GL_ARRAY_BUFFER, 3 * sizeof(float), sizeof(<#expression-or-type#>), <#const GLvoid *data#>)
    
    glBindVertexArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)(3*sizeof(float)));
    
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void BatchRender::draw(){
    
}


