//
//  batch_render.cpp
//  OpenGLPractice
//
//  Created by Brandon Kervin on 1/11/18.
//  Copyright © 2018 Brandon Kervin. All rights reserved.
//

#include "batch_render.hpp"

BatchRender::BatchRender(unsigned int NUM_DRAWS){
    init(NUM_DRAWS);
}

BatchRender::~BatchRender(){
    
}

void BatchRender::init(unsigned int NUM_DRAWS){
    
    glGenBuffers(1, &indirect_buffer);
    glBindBuffer(GL_DRAW_INDIRECT_BUFFER, indirect_buffer);
    glBufferData(GL_DRAW_INDIRECT_BUFFER, NUM_DRAWS * sizeof(DrawArraysIndirectCommand), NULL, GL_STATIC_DRAW);
    command =
    (DrawArraysIndirectCommand *)
    glMapBufferRange(GL_DRAW_INDIRECT_BUFFER,
                     0,
                     NUM_DRAWS * sizeof(DrawArraysIndirectCommand),
                     GL_MAP_WRITE_BIT | GL_MAP_INVALIDATE_BUFFER_BIT);
    for(int i = 0 ; i < NUM_DRAWS ; i++){
        
    }
    
    
}

void BatchRender::draw(){
    
}


