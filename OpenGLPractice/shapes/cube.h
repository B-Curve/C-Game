//
//  cube.h
//  OpenGLPractice
//
//  Created by Brandon Kervin on 1/9/18.
//  Copyright © 2018 Brandon Kervin. All rights reserved.
//

#ifndef cube_h
#define cube_h

namespace cube {
    static float vertices[] = {
        //front face
        -0.5f, -0.5f, -0.5f,
        0.5f, -0.5f, -0.5f,
        0.5f, 0.5f, -0.5f,
        0.5f, 0.5f, -0.5f,
        -0.5f, 0.5f, -0.5f,
        -0.5f, -0.5f, -0.5f,
        //back face
        -0.5f, -0.5f, 0.5f,
        0.5f, -0.5f, 0.5f,
        0.5f, 0.5f, 0.5f,
        0.5f, 0.5f, 0.5f,
        -0.5f, 0.5f, 0.5f,
        -0.5f, -0.5f, 0.5f,
        //left face
        -0.5f, -0.5f, 0.5f,
        -0.5f, -0.5f, -0.5f,
        -0.5f, 0.5f, -0.5f,
        -0.5f, 0.5f, -0.5f,
        -0.5f, 0.5f, 0.5f,
        -0.5f, -0.5f, 0.5f,
        //right face
        0.5f, -0.5f, -0.5f,
        0.5f, -0.5f, 0.5f,
        0.5f, 0.5f, 0.5f,
        0.5f, 0.5f, 0.5f,
        0.5f, 0.5f, -0.5f,
        0.5f, -0.5f, -0.5f,
        //bottom face
        -0.5f, -0.5f, -0.5f,
        0.5f, -0.5f, -0.5f,
        0.5f, -0.5f, 0.5f,
        0.5f, -0.5f, 0.5f,
        -0.5f, -0.5f, 0.5f,
        -0.5f, -0.5f, -0.5f,
        //top face
        -0.5f, 0.5f, -0.5f,
        0.5f, 0.5f, -0.5f,
        0.5f, 0.5f, 0.5f,
        0.5f, 0.5f, 0.5f,
        -0.5f, 0.5f, 0.5f,
        -0.5f, 0.5f, -0.5f,
    };
    static unsigned int vertTotal = sizeof(vertices)/sizeof(vertices[0]);
    static float uv[] = {
        0, 0,
        1, 0,
        1, 1,
        1, 1,
        0, 1,
        0, 0,
        0, 0,
        1, 0,
        1, 1,
        1, 1,
        0, 1,
        0, 0,
        0, 0,
        1, 0,
        1, 1,
        1, 1,
        0, 1,
        0, 0,
        0, 0,
        1, 0,
        1, 1,
        1, 1,
        0, 1,
        0, 0,
        0, 0,
        1, 0,
        1, 1,
        1, 1,
        0, 1,
        0, 0,
        0, 0,
        1, 0,
        1, 1,
        1, 1,
        0, 1,
        0, 0,
    };
    static unsigned int uvTotal = sizeof(uv)/sizeof(uv[0]);
}

#endif /* cube_h */
