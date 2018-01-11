//
//  pyramid.h
//  OpenGLPractice
//
//  Created by Brandon Kervin on 1/9/18.
//  Copyright © 2018 Brandon Kervin. All rights reserved.
//

#ifndef pyramid_h
#define pyramid_h
#include <glm/glm.hpp>

static glm::vec3 getNormals(glm::vec3 p1, glm::vec3 p2, glm::vec3 p3){
    glm::vec3 u = p2 - p1;
    glm::vec3 v = p3 - p1;
    
    float normalX = u.y*v.z - u.z*v.y;
    float normalY = u.z*v.x - u.x*v.z;
    float normalZ = u.x*v.y - u.y*v.x;
    return glm::vec3(normalX, normalY, normalZ);
}

namespace pyramid {
    static float vertices[] = {
        //t1
        -0.5f, -0.5f, -0.5f,
        0.5f, -0.5f, -0.5f,
        0.0f, 0.5f, 0.0f,
        
        //t2
        0.5f, -0.5f, -0.5f,
        0.5f, -0.5f, 0.5f,
        0.0f, 0.5f, 0.0f,
        
        //t3
        0.5f, -0.5f, 0.5f,
        -0.5f, -0.5f, 0.5f,
        0.0f, 0.5f, 0.0f,
        
        //t4
        -0.5f, -0.5f, 0.5f,
        -0.5f, -0.5f, -0.5f,
        0.0f, 0.5f, 0.0f,
        
        //bottom1
        -0.5f, -0.5f, -0.5f,
        0.5f, -0.5f, -0.5f,
        0.5f, -0.5f, 0.5f,
        
        //bottom2
        0.5f, -0.5f, 0.5f,
        -0.5f, -0.5f, 0.5f,
        -0.5f, -0.5f, -0.5f,
    };
    static unsigned int vertTotal = sizeof(vertices)/sizeof(vertices[0]);
    static float uv[] = {
        -1, 1,
        1, 1,
        0.0f, -1,
        -1, 1,
        1, 1,
        0.0f, -1,
        -1, 1,
        1, 1,
        0.0f, -1,
        -1, 1,
        1, 1,
        0.0f, -1,
        -1, -1,
        1, -1,
        1, 1,
        1, 1,
        -1, 1,
        -1, -1,
    };
    static unsigned int uvTotal = sizeof(uv)/sizeof(uv[0]);
    static glm::vec3 normals[] = {
        //normal 1
        getNormals(glm::vec3(vertices[0], vertices[1], vertices[2]),
                   glm::vec3(vertices[3], vertices[4], vertices[5]),
                   glm::vec3(vertices[6], vertices[7], vertices[8])),
        getNormals(glm::vec3(vertices[9], vertices[10], vertices[11]),
                   glm::vec3(vertices[12], vertices[13], vertices[14]),
                   glm::vec3(vertices[15], vertices[16], vertices[17])),
        getNormals(glm::vec3(vertices[18], vertices[19], vertices[20]),
                   glm::vec3(vertices[21], vertices[22], vertices[23]),
                   glm::vec3(vertices[24], vertices[25], vertices[26])),
        getNormals(glm::vec3(vertices[27], vertices[28], vertices[29]),
                   glm::vec3(vertices[30], vertices[31], vertices[32]),
                   glm::vec3(vertices[33], vertices[34], vertices[35])),
        getNormals(glm::vec3(vertices[36], vertices[37], vertices[38]),
                   glm::vec3(vertices[39], vertices[40], vertices[41]),
                   glm::vec3(vertices[42], vertices[43], vertices[44])),
        getNormals(glm::vec3(vertices[45], vertices[46], vertices[47]),
                   glm::vec3(vertices[48], vertices[49], vertices[50]),
                   glm::vec3(vertices[51], vertices[52], vertices[53]))
    };
    static unsigned int normalsTotal = sizeof(normals)/sizeof(normals[0]);
}


#endif /* pyramid_h */
