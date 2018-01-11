//
//  chunk.hpp
//  OpenGLPractice
//
//  Created by Brandon Kervin on 1/10/18.
//  Copyright © 2018 Brandon Kervin. All rights reserved.
//

#ifndef chunk_hpp
#define chunk_hpp

#include <stdio.h>
#include <vector>
#include "../render/transform.h"
#include "../render/shader.hpp"
#include "../render/texture.hpp"
#include "../render/buffer.hpp"
#include "../shapes/cube.h"

class Chunk16x16x16 {
public:
    Chunk16x16x16(int xPos, int yPos, int zPos){
        position = glm::vec4(xPos+0.01f, yPos+0.01f, zPos+0.01f, 1.0f);
        shader = new Shader("./shaders/shader");
        texture = new Texture("./textures/lowresgrass.jpg");
        for(int x = xPos ; x < xPos + 16 ; x++){
            for(int y = yPos ; y < yPos + 16 ; y++){
                for(int z = zPos ; z < zPos + 16 ; z++){
                    transforms.push_back(Transform(glm::vec3(x,y,z)));
                }
            }
        }
        buffer = new Buffer(cube::vertices, cube::vertTotal, cube::uv, cube::uvTotal, transforms, transforms.size());
    }
    void update(Camera& cam);
private:
    std::vector<Transform> transforms;
    std::vector<glm::mat4> activeModels;
    glm::vec4 position;
    //will be placed elsewhere eventually
    Shader * shader;
    Texture * texture;
    Buffer * buffer;
};

class Chunk100x1x100 {
public:
    Chunk100x1x100(int xPos, int yPos, int zPos){
        position = glm::vec4(xPos+0.01f, yPos+0.01f, zPos+0.01f, 1.0f);
        shader = new Shader("./shaders/shader");
        texture = new Texture("./textures/lowresgrass.jpg");
        for(int x = xPos ; x < xPos + 100 ; x++){
            for(int z = zPos ; z < zPos + 100 ; z++){
                transforms.push_back(Transform(glm::vec3(x,yPos,z)));
            }
        }
        buffer = new Buffer(cube::vertices, cube::vertTotal, cube::uv, cube::uvTotal, transforms, transforms.size());
    }
    void update(Camera& cam);
private:
    std::vector<Transform> transforms;
    std::vector<glm::mat4> activeModels;
    glm::vec4 position;
    //will be placed elsewhere eventually
    Shader * shader;
    Texture * texture;
    Buffer * buffer;
};

//DO NOT USE. NO OPTIMIZATION YET
class Chunk1000x1x1000 {
public:
    Chunk1000x1x1000(int xPos, int yPos, int zPos){
        position = glm::vec4(xPos+0.01f, yPos+0.01f, zPos+0.01f, 1.0f);
        shader = new Shader("./shaders/shader");
        texture = new Texture("./textures/lowresgrass.jpg");
        for(int x = xPos ; x < xPos + 1000 ; x++){
            for(int z = zPos ; z < zPos + 1000 ; z++){
                transforms.push_back(Transform(glm::vec3(x,yPos,z)));
            }
        }
        buffer = new Buffer(cube::vertices, cube::vertTotal, cube::uv, cube::uvTotal, transforms, transforms.size());
    }
    void update(Camera& cam);
private:
    std::vector<Transform> transforms;
    std::vector<glm::mat4> activeModels;
    glm::vec4 position;
    //will be placed elsewhere eventually
    Shader * shader;
    Texture * texture;
    Buffer * buffer;
};

#endif /* chunk_hpp */
