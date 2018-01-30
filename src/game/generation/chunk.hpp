//
//  chunk.hpp
//  MinecraftClone
//
//  Created by Brandon Kervin on 1/30/18.
//  Copyright © 2018 Brandon Kervin. All rights reserved.
//

#ifndef chunk_hpp
#define chunk_hpp

#define CHUNK_SIZE 16

#include <vector>
#include <glm/glm.hpp>
#ifndef camera_hpp
    #include "../player/camera.hpp"
#endif

class ChunkList {
public:
    void update(Camera &camera);
    std::vector<bool*> chunks;
};

class Chunk {
public:
    Chunk(const glm::vec3 &pos, ChunkList *ch){
        this->ch = ch;
        a = glm::vec3(pos);
        b = glm::vec3(pos) + glm::vec3(CHUNK_SIZE,0,0);
        c = glm::vec3(pos) + glm::vec3(CHUNK_SIZE,CHUNK_SIZE,0);
        d = glm::vec3(pos) + glm::vec3(0,CHUNK_SIZE,0);
        e = glm::vec3(pos) + glm::vec3(0,CHUNK_SIZE,CHUNK_SIZE);
        f = glm::vec3(pos) + glm::vec3(0,0,CHUNK_SIZE);
        g = glm::vec3(pos) + glm::vec3(CHUNK_SIZE,0,CHUNK_SIZE);
        h = glm::vec3(pos) + glm::vec3(CHUNK_SIZE);
        bool cs[CHUNK_SIZE*CHUNK_SIZE*CHUNK_SIZE];
        for(int x = pos.x ; x < pos.x + CHUNK_SIZE ; x++){
            for(int z = pos.z ; z < pos.z + CHUNK_SIZE ; z++){
                for(int y = pos.y ; y < pos.y + CHUNK_SIZE ; y++){
                    cs[x*y*z] = true;
                }
            }
        }
        memcpy(chunkSpaces, cs, sizeof(cs));
        ch->chunks.push_back(chunkSpaces);
    }
    inline virtual ~Chunk(){
        delete [] chunkSpaces;
        ch->chunks.erase(std::remove(ch->chunks.begin(), ch->chunks.end(), chunkSpaces), ch->chunks.end());
    }
private:
    bool *chunkSpaces;
    ChunkList *ch;
    //corners of chunk
    glm::vec3 a;
    glm::vec3 b;
    glm::vec3 c;
    glm::vec3 d;
    glm::vec3 e;
    glm::vec3 f;
    glm::vec3 g;
    glm::vec3 h;
};

#endif /* chunk_hpp */
