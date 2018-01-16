//
//  batch_render.hpp
//  OpenGLPractice
//
//  Created by Brandon Kervin on 1/11/18.
//  Copyright © 2018 Brandon Kervin. All rights reserved.
//

#ifndef batch_render_hpp
#define batch_render_hpp

#define MAX_BUFFER_SIZE 10000

#include <stdio.h>
#include <vector>
#include <OpenGL/gl3.h>

typedef struct {
    GLuint count;
    GLuint instanceCount;
    GLuint firstIndex;
    GLuint baseVertex;
    GLuint baseInstance;
} DrawArraysIndirectCommand;

class BatchRender {
public:
    BatchRender(unsigned int NUM_DRAWS);
    virtual ~BatchRender();
    void draw();
private:
    void init(unsigned int NUM_DRAWS);
    GLuint indirect_buffer;
    DrawArraysIndirectCommand * command;
};

#endif /* batch_render_hpp */
