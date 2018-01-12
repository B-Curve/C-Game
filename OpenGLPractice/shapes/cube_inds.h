//
//  cube_inds.h
//  OpenGLPractice
//
//  Created by Brandon Kervin on 1/10/18.
//  Copyright © 2018 Brandon Kervin. All rights reserved.
//

#ifndef cube_inds_h
#define cube_inds_h

namespace cube_i {
    static float vertices[] = {
        -0.5f, -0.5f, -0.5f,//front bottom-left 0
        0.5f, -0.5f, -0.5f,//front bottom-right 1
        0.5f, 0.5f, -0.5f,//front top right 2
        -0.5f, 0.5f, -0.5f,//front top left 3
        -0.5f, -0.5f, 0.5f,//back bottom left 4
        0.5f, -0.5f, 0.5f,//back bottom right 5
        0.5f, 0.5f, 0.5f,//back top right 6
        -0.5f, 0.5f, 0.5f,//back top left 7
    };
    static unsigned int vertTotal = sizeof(vertices)/sizeof(vertices[0]);
    static unsigned int indices[] = {
        0,1,2,//front
        2,3,0,
        4,5,6,//back
        6,7,4,
        4,0,3,//left
        3,7,4,
        1,5,6,//right
        6,2,1,
        3,2,6,//top
        6,7,3,
        0,1,5,//bottom
        5,4,0
    };
    static unsigned int indexTotal = sizeof(indices)/sizeof(indices[0]);
    static float uv[] = {
        //front
        -0.5f, -0.5f,
        0.5f, -0.5f,
        0.5f, 0.5f,
        0.5f, 0.5f,
        -0.5f, 0.5f,
        -0.5f, -0.5f,
        //back
        -0.5f, -0.5f,
        0.5f, -0.5f,
        0.5f, 0.5f,
        0.5f, 0.5f,
        -0.5f, 0.5f,
        -0.5f, -0.5f,
        //left
        -0.5f, -0.5f,
        0.5f, -0.5f,
        0.5f, 0.5f,
        0.5f, 0.5f,
        -0.5f, 0.5f,
        -0.5f, -0.5f,
        //right
        -0.5f, -0.5f,
        0.5f, -0.5f,
        0.5f, 0.5f,
        0.5f, 0.5f,
        -0.5f, 0.5f,
        -0.5f, -0.5f,
        //top
        -0.5f, -0.5f,
        0.5f, -0.5f,
        0.5f, 0.5f,
        0.5f, 0.5f,
        -0.5f, 0.5f,
        -0.5f, -0.5f,
        //bottom
        -0.5f, -0.5f,
        0.5f, -0.5f,
        0.5f, 0.5f,
        0.5f, 0.5f,
        -0.5f, 0.5f,
        -0.5f, -0.5f,
    };
    static unsigned int uvTotal = sizeof(uv)/sizeof(uv[0]);
}

#endif /* cube_inds_h */
