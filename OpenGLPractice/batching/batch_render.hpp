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

struct Vertex {
    float x, y, z; //position
    float u, v; //texCoords
};

struct Triangle {
    int a, b, c; //index points
};

struct DrawElements {
    GLuint vertexCount;
    GLuint indexCount;
    GLuint instanceCount;
};

class BatchRender {
public:
    BatchRender();
    virtual ~BatchRender();
    void draw();
private:
    void init();
    GLuint m_vao;
    GLuint m_vbo;
    GLuint m_tbo;
    GLuint m_ibo;
    std::vector<Vertex> * verticies;
    std::vector<Triangle> * indices;
};

#endif /* batch_render_hpp */
