//
//  chunk.cpp
//  gl
//
//  Created by Brandon Kervin on 1/20/18.
//  Copyright © 2018 Brandon Kervin. All rights reserved.
//

#include "chunk.hpp"

void Chunk::update(Camera &camera, std::vector<Light> lights){
    for(unsigned int i = 0 ; i < usedTextures.size() ; i++){
        int INITIAL_RENDER = -1;
        std::vector<BlockInstance*> instances = blocksMapped.at(usedTextures[i]);
        for(unsigned int j = 0 ; j < instances.size() ; j++){
            glm::vec4 clip = camera.getMVP() * glm::vec4(instances[j]->position, 1.0);
            if(clip.x > -clip.w - 4.0f && clip.x < clip.w + 4.0f && clip.y > -clip.w - 4.0f && clip.y < clip.w + 4.0f && clip.z > -clip.w - 4.0f && clip.z < clip.w + 4.0f){
                if(INITIAL_RENDER == -1){
                    INITIAL_RENDER = j;
                }
                if(instances[j]->block->lightType != FLASHLIGHT){
                    instances[j]->block->draw(camera, instances[j]->position, lights, j == INITIAL_RENDER);
                }else{
                    instances[j]->block->draw(camera, instances[j]->position, j == INITIAL_RENDER);
                }
            }
        }
    }
}
