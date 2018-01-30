//
//  utils.cpp
//  MinecraftClone
//
//  Created by Brandon Kervin on 1/30/18.
//  Copyright © 2018 Brandon Kervin. All rights reserved.
//

#include "utils.hpp"

GLuint gen_vao(){
    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    return vao;
}

GLuint gen_buffer(GLsizei size, GLfloat *data){
    GLuint buffer;
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
    return buffer;
}

GLuint gen_dynamic_buffer(GLsizei size){
    GLuint buffer;
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, size, NULL, GL_DYNAMIC_DRAW);
    return buffer;
}

unsigned int update_fps(FPS *fps){
    fps->frames++;
    double now = glfwGetTime();
    double elapsed = now - fps->since;
    if (elapsed >= 1) {
        fps->fps = fps->frames / elapsed;
        fps->frames = 0;
        fps->since = now;
    }
    fps->delta = now - fps->last_frame_time;
    fps->last_frame_time = now;
    return fps->fps;
}
