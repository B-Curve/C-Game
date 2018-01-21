//
//  chunk.cpp
//  gl
//
//  Created by Brandon Kervin on 1/20/18.
//  Copyright © 2018 Brandon Kervin. All rights reserved.
//

#include "chunk.hpp"

void Chunk::update(Camera &camera, std::vector<Light> lights){
    for(unsigned int i = 0 ; i < blocks.size() ; i++){
        glm::vec4 clip = camera.getMVP() * glm::vec4(positions[i], 1.0);
        if(clip.x > -clip.w - 4.0f && clip.x < clip.w + 4.0f && clip.y > -clip.w - 4.0f && clip.y < clip.w + 4.0f && clip.z > -clip.w - 4.0f && clip.z < clip.w + 4.0f){
            if(blocks[i].lightType != FLASHLIGHT){
                blocks[i].draw(camera, positions[i], lights);
            }else{
                blocks[i].draw(camera, positions[i]);
            }
        }
    }
}
