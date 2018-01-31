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

#define MC_AIR 0
#define MC_DIRT 1

#include <vector>
#include <map>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <iostream>
#ifndef GLFW_INCLUDE_GLCOREARB
    #define GLFW_INCLUDE_GLCOREARB
#endif
#include <GLFW/glfw3.h>
#ifndef camera_hpp
    #include "../player/camera.hpp"
#endif
#ifndef utils_hpp
    #include "../../utils.hpp"
#endif

static GLfloat verts[] = {
    //front
    -1, -1, -1,
    1, -1, -1,
    1, 1, -1,
    1, 1, -1,
    -1, 1, -1,
    -1, -1, -1,
    //back
    -1, -1, 1,
    1, -1, 1,
    1, 1, 1,
    1, 1, 1,
    -1, 1, 1,
    -1, -1, 1,
    //left
    -1, -1, 1,
    -1, -1, -1,
    -1, 1, -1,
    -1, 1, -1,
    -1, 1, 1,
    -1, -1, 1,
    //right
    1, -1, -1,
    1, -1, 1,
    1, 1, 1,
    1, 1, 1,
    1, 1, -1,
    1, -1, -1,
    //top
    -1, 1, -1,
    1, 1, -1,
    1, 1, 1,
    1, 1, 1,
    -1, 1, 1,
    -1, 1, -1,
    //bottom
    -1, -1, -1,
    1, -1, -1,
    1, -1, 1,
    1, -1, 1,
    -1, -1, 1,
    -1, -1, -1,
};

static GLfloat texCoords[] = {
    -1,-1,  1,-1,   1,1,    1,1,    -1,1,   -1,-1,
    -1,-1,  1,-1,   1,1,    1,1,    -1,1,   -1,-1,
    -1,-1,  1,-1,   1,1,    1,1,    -1,1,   -1,-1,
    -1,-1,  1,-1,   1,1,    1,1,    -1,1,   -1,-1,
    -1,-1,  1,-1,   1,1,    1,1,    -1,1,   -1,-1,
    -1,-1,  1,-1,   1,1,    1,1,    -1,1,   -1,-1,
};

static GLfloat normals[] = {
    0,0,-1, 0,0,-1, 0,0,-1, 0,0,-1, 0,0,-1, 0,0,-1,
    0,0,1,  0,0,1,  0,0,1,  0,0,1,  0,0,1,  0,0,1,
    -1,0,0,  -1,0,0,  -1,0,0,  -1,0,0,  -1,0,0,  -1,0,0,
    1,0,0,  1,0,0,  1,0,0,  1,0,0,  1,0,0,  1,0,0,
    0,1,0,  0,1,0,  0,1,0,  0,1,0,  0,1,0,  0,1,0,
    0,-1,0, 0,-1,0, 0,-1,0, 0,-1,0, 0,-1,0, 0,-1,0,
};

struct Block {
    glm::vec3 position;
    unsigned int type;
};

class Chunk {
public:
    Chunk(const glm::vec3 &pos){
        corners = {glm::vec3(pos),
        glm::vec3(pos) + glm::vec3(CHUNK_SIZE,0,0),
        glm::vec3(pos) + glm::vec3(CHUNK_SIZE,CHUNK_SIZE,0),
        glm::vec3(pos) + glm::vec3(0,CHUNK_SIZE,0),
        glm::vec3(pos) + glm::vec3(0,CHUNK_SIZE,CHUNK_SIZE),
        glm::vec3(pos) + glm::vec3(0,0,CHUNK_SIZE),
        glm::vec3(pos) + glm::vec3(CHUNK_SIZE,0,CHUNK_SIZE),
        glm::vec3(pos) + glm::vec3(CHUNK_SIZE)};
        blocks = new Block[CHUNK_SIZE*CHUNK_SIZE*CHUNK_SIZE];
        int count = 0;
        for(int x = pos.x ; x < pos.x + CHUNK_SIZE ; x++){
            for(int z = pos.z ; z < pos.z + CHUNK_SIZE ; z++){
                for(int y = pos.y ; y < pos.y + CHUNK_SIZE ; y++){
                    blocks[count] = Block{glm::vec3(x,y,z), MC_DIRT};
                    count++;
                }
            }
        }
        std::vector<glm::vec3> positions;
        for(unsigned int i = 0 ; i < (CHUNK_SIZE*CHUNK_SIZE*CHUNK_SIZE) ; i++){
            positions.push_back(blocks[i].position);
        }
        GLuint vao = gen_vao();
        gen_buffer(sizeof(verts), verts);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
        gen_buffer(sizeof(texCoords), texCoords);
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);
        gen_buffer(sizeof(normals), normals);
        glEnableVertexAttribArray(2);
        glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, 0);
        gen_buffer(positions.size() * sizeof(positions[0]), positions);
        glEnableVertexAttribArray(3);
        glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 0, 0);
        glVertexAttribDivisor(3, 1);
        glBindVertexArray(0);
        vaos.push_back(vao);
        vaoSizes.push_back(positions.size());
    }
    inline virtual ~Chunk(){
        delete [] blocks;
        
    }
    std::vector<glm::vec3> corners;
    glm::vec3 a;
    glm::vec3 b;
    glm::vec3 c;
    glm::vec3 d;
    glm::vec3 e;
    glm::vec3 f;
    glm::vec3 g;
    glm::vec3 h;
//    std::map<int, int*> bufferObjects;
    std::vector<GLuint> vbos;
    std::vector<GLuint> vaos;
    std::vector<unsigned int> vaoSizes;
//    GLuint buffer, vao;
private:
    Block *blocks;
};

class ChunkList {
public:
    void update(Camera *camera);
    inline void addChunk(glm::vec3 position){
        Chunk *c = new Chunk(position);
        chunks.push_back(c);
    }
    inline void removeChunk(Chunk *c){
        delete c;
        c = NULL;
        chunks.erase(std::remove(chunks.begin(), chunks.end(), c), chunks.end());
    }
    std::vector<Chunk*> chunks;
};

#endif /* chunk_hpp */
