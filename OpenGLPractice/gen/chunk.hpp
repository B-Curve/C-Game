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
#include "../shapes/cube_inds.h"
#include "../interaction/collision.h"

class Chunk16x16x16 {
public:
    Chunk16x16x16(int xPos, int yPos, int zPos, Collision& collision){
        position = glm::vec4(xPos+0.01f, yPos+0.01f, zPos+0.01f, 1.0f);
        shader = new Shader("./shaders/shader");
        texture = new Texture("./textures/rock.jpg");
        for(int x = xPos ; x < xPos + 16 ; x++){
            for(int y = yPos ; y < yPos + 16 ; y++){
                for(int z = zPos ; z < zPos + 16 ; z++){
                    transforms.push_back(Transform(glm::vec3(x,y,z)));
                    collision.collisionPoints.push_back(glm::vec3(x,y,z));
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

class Chunk30x30x30_no_ind {
public:
    Chunk30x30x30_no_ind(int xPos, int yPos, int zPos, Collision& collision){
        position = glm::vec4(xPos+0.01f, yPos+0.01f, zPos+0.01f, 1.0f);
        shader = new Shader("./shaders/shader");
        texture = new Texture("./textures/rock.jpg");
        for(int x = xPos ; x < xPos + 30 ; x++){
            for(int y = yPos ; y < yPos + 30 ; y++){
                for(int z = zPos ; z < zPos + 30 ; z++){
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
    Chunk100x1x100(int xPos, int yPos, int zPos, Collision& collision){
        position = glm::vec4(xPos+0.01f, yPos+0.01f, zPos+0.01f, 1.0f);
        shader = new Shader("./shaders/shader");
        texture = new Texture("./textures/grass.jpg");
        for(int x = xPos ; x < xPos + 100 ; x++){
            for(int z = zPos ; z < zPos + 100 ; z++){
                transforms.push_back(Transform(glm::vec3(x,yPos,z)));
                collision.collisionPoints.push_back(glm::vec3(x,yPos,z));
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
class Chunk100x100x100 {
public:
    Chunk100x100x100(int xPos, int yPos, int zPos, Collision& collision){
        position = glm::vec4(xPos+0.01f, yPos+0.01f, zPos+0.01f, 1.0f);
        shader = new Shader("./shaders/shader");
        texture = new Texture("./textures/grass.jpg");
        for(int x = xPos ; x < xPos + 100 ; x++){
            for(int y = yPos ; y < yPos + 100 ; y++){
                for(int z = zPos ; z < zPos + 100 ; z++){
                    transforms.push_back(Transform(glm::vec3(x,yPos,z)));
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

#endif /* chunk_hpp */
