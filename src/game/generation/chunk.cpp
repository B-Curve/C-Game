//
//  chunk.cpp
//  MinecraftClone
//
//  Created by Brandon Kervin on 1/30/18.
//  Copyright © 2018 Brandon Kervin. All rights reserved.
//

#include "chunk.hpp"

void ChunkList::update(Camera *camera){
    glm::vec4 clip;
    for(int i = 0 ; i < chunks.size() ; i++){
        for(int j = 0 ; j < chunks[i]->vaos.size() ; j++){
            int fails = 0;
            for(int d = 0 ; d < chunks[i]->corners.size() ; d++){
                clip = camera->getView() * glm::vec4(chunks[i]->corners[d], 1.0f);
//                if(clip.x < -clip.w || clip)
                //TODO - FIGURE OUT IF CHUNK IS ON SCREEN, BUT NOT BY CORNERS. WHAT IF YOU AREN'T LOOKING AT THE CORNERS, BUT CENTER?
            }
            glBindVertexArray(chunks[i]->vaos[j]);
            glDrawArraysInstanced(GL_TRIANGLES, 0, 36, chunks[i]->vaoSizes[j]);
        }
    }
}
