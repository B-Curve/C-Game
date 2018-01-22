//
//  chunk.hpp
//  gl
//
//  Created by Brandon Kervin on 1/20/18.
//  Copyright © 2018 Brandon Kervin. All rights reserved.
//

#ifndef chunk_hpp
#define chunk_hpp

#define CHUNK_SIZE 16

#include <stdio.h>
#include <vector>
#include <map>
#include <glm/glm.hpp>
#include "block.hpp"
#include "../data/data_fetch.h"

class Chunk {
public:
    Chunk(const glm::vec3 &position, Data &data, LIGHT_TYPE type, std::vector<TEXTURE_TYPE> textures){
        for(int x = position.x ; x < position.x + CHUNK_SIZE ; x++){
            for(int z = position.z ; z < position.z + CHUNK_SIZE ; z++){
                int random = rand() % textures.size() + 0;
                Block * block = new Block(STONE, data, type, textures[random]);
                BlockInstance * instance = new BlockInstance;
                instance->block = block;
                instance->position = glm::vec3(x*2, position.y, z*2);
                it = blocksMapped.find(block->textureType);
                if(it == blocksMapped.end()){
                    blocksMapped.insert(std::pair<TEXTURE_TYPE, std::vector<BlockInstance*>>(block->textureType, std::vector<BlockInstance*>{instance}));
                    usedTextures.push_back(block->textureType);
                }else{
                    blocksMapped.at(block->textureType).push_back(instance);
                }
            }
        }
    }
    void update(Camera &camera, std::vector<Light> lights);
private:
    std::map<TEXTURE_TYPE, std::vector<BlockInstance*>> blocksMapped;
    std::map<TEXTURE_TYPE, std::vector<BlockInstance*>>::iterator it;
    std::vector<TEXTURE_TYPE> usedTextures;
};

#endif /* chunk_hpp */
