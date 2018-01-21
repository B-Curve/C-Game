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
#include <glm/glm.hpp>
#include "block.hpp"
#include "../data/data_fetch.h"

class Chunk {
public:
    Chunk(const glm::vec3 &position, Data &data, LIGHT_TYPE type, std::vector<TEXTURE_TYPE> textures){
        for(int x = position.x ; x < position.x + CHUNK_SIZE ; x++){
            for(int z = position.z ; z < position.z + CHUNK_SIZE ; z++){
                int random = rand() % textures.size() + 0;
                Block block(STONE, data, type, textures[random]);
                blocks.push_back(block);
                positions.push_back(glm::vec3(x*2, position.y, z*2));
            }
        }
    }
    void update(Camera &camera, std::vector<Light> lights);
private:
    std::vector<Block> blocks;
    std::vector<glm::vec3> positions;
};

#endif /* chunk_hpp */
