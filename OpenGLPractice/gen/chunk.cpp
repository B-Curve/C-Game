//
//  chunk.cpp
//  OpenGLPractice
//
//  Created by Brandon Kervin on 1/10/18.
//  Copyright © 2018 Brandon Kervin. All rights reserved.
//

#include <iostream>
#include "chunk.hpp"

void Chunk::update(Camera& cam){
//    glm::mat4 mvp = cam.getMVP();
//    glm::vec4 f;
//    f = mvp * glm::vec4(xPos, yPos, zPos, 1.0);
//    std::cout << f.x << " : " << f.y << " : " << f.z << " : " << f[3] << std::endl;
//    if(f.x < -f[3] || f.x > f[3] || f.y < -f[3] || f.y > f[3] || f.z < -f[3] || f.z > f[3]){
//
//    }
    shader->bind();
    shader->update(cam);
    texture->bind(0);
    buffer->drawWithoutIndices(transforms.size());
}

