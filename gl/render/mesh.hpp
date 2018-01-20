//
//  mesh.hpp
//  gl
//
//  Created by Brandon Kervin on 1/19/18.
//  Copyright © 2018 Brandon Kervin. All rights reserved.
//

#ifndef mesh_hpp
#define mesh_hpp

#include <stdio.h>
#include <string>
#include <glm/glm.hpp>
#include <OpenGL/gl3.h>
#include "obj_loader.hpp"

class Mesh {
public:
    Mesh(const std::string &file);
    void draw();
    void enableFrameBuffer();
    void disableFrameBuffer();
private:
    GLuint vao;
    GLuint vbo;
    GLuint tbo;
    GLuint nbo;
    GLuint ibo;
    GLuint fbo;
    IndexedModel model;
};

#endif /* mesh_hpp */
