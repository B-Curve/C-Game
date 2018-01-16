//
//  chunk.hpp
//  OpenGLPractice
//
//  Created by Brandon Kervin on 1/10/18.
//  Copyright © 2018 Brandon Kervin. All rights reserved.
//

#ifndef chunk_hpp
#define chunk_hpp

#define CHUNK_SIZE 16

#include <stdio.h>
#include <vector>
#include <cstdlib>
#include "../render/transform.h"
#include "../render/shader.hpp"
#include "../render/texture.hpp"
#include "../render/buffer.hpp"
#include "../shapes/cube.h"
#include "../shapes/cube_inds.h"
#include "../interaction/collision.h"

class Chunk {
public:
    Chunk(int xPos, int yPos, int zPos, Collision& collision){
        this->xPos = xPos; this->yPos = yPos; this->zPos = zPos;
        position = glm::vec4(xPos+0.01f, yPos+0.01f, zPos+0.01f, 1.0f);
        shader = new Shader("./shaders/shader");
        texture = new Texture("./textures/grass.jpg");
        int lastY = 0;
        for(int x = xPos ; x < xPos + CHUNK_SIZE ; x++){
            for(int z = zPos ; z < zPos + CHUNK_SIZE ; z++){
                int randY = rand() % 3 + lastY;
                lastY = randY;
                if(lastY > 3) lastY = 3;
                for(int y = yPos + randY ; y > yPos - CHUNK_SIZE ; y--){
                    
                    //TODO - Sort transforms based on player position so that culling can be evaluated much easier
                    transforms.push_back(Transform(glm::vec3(x,y,z)));
//                    positions.push_back(glm::vec3(x,y,z));
                    collision.collisionPoints.push_back(glm::vec3(x,y,z));
                }
            }
        }
        buffer = new Buffer(cube::vertices, cube::vertTotal, cube::uv, cube::uvTotal, transforms, transforms.size());
    }
    void update(Camera& cam);
private:
    int xPos, yPos, zPos;
    std::vector<Transform> transforms;
//    std::vector<glm::vec3> positions;
    std::vector<glm::mat4> activeModels;
    glm::vec4 position;
    //will be placed elsewhere eventually
    Shader * shader;
    Texture * texture;
    Buffer * buffer;
};

#endif /* chunk_hpp */
