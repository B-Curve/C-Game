//
//  utils.hpp
//  MinecraftClone
//
//  Created by Brandon Kervin on 1/30/18.
//  Copyright © 2018 Brandon Kervin. All rights reserved.
//

#ifndef utils_hpp
#define utils_hpp

#ifndef GLFW_INCLUDE_GLCOREARB
    #define GLFW_INCLUDE_GLCOREARB
#endif
#include <GLFW/glfw3.h>
#include <iostream>

struct FPS {
    unsigned int fps;
    unsigned int frames;
    double since;
    double delta;
    double last_frame_time = 0;
};

GLuint gen_vao();
GLuint gen_buffer(GLsizei size, GLfloat *data);
GLuint gen_dynamic_buffer(GLsizei size);
unsigned int update_fps(FPS *fps);

#endif /* utils_hpp */
