//
//  block.hpp
//  gl
//
//  Created by Brandon Kervin on 1/20/18.
//  Copyright © 2018 Brandon Kervin. All rights reserved.
//

#ifndef block_hpp
#define block_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <glm/glm.hpp>
#include <iostream>
#include "../render/texture.hpp"
#include "../render/shader.hpp"
#include "../render/mesh.hpp"
#include "../data/data_fetch.h"

static Mesh * staticMesh;
static Texture * staticPrimary;
static Texture * staticBump;
static Shader * staticShader;

enum BLOCK_TYPE {
    STONE = 0
};

enum TEXTURE_TYPE {
    BRICKS = 0,
    DIRT = 1,
    COBBLESTONE = 2,
    GRASS = 3
};

static std::string diffuseMap[] = {
    "./textures/bricks.png",
    "./textures/dirt.png",
    "./textures/cobblestone.png",
    "./textures/grass.png"
};

static std::string bumpMap[] = {
    "./textures/bricks_normal.png",
    "./textures/dirt_bump.png",
    "./textures/cobblestone_bump.png",
    "./textures/grass_bump.png"
};

class Light {
public:
    Light(const glm::vec3 &position, const glm::vec3 &color, LIGHT_STRENGTH type){
        this->position = position;
        this->color = color;
        this->lightStrength = type;
        shader = new Shader(LAMP);
        mesh = new Mesh("./models/box/box.obj");
    }
    glm::vec3 position;
    glm::vec3 color;
    LIGHT_STRENGTH lightStrength;
    void draw(Camera &camera);
private:
    Shader * shader;
    Mesh * mesh;
};

class Block {
public:
    Block(BLOCK_TYPE block, Data &data, LIGHT_TYPE type, TEXTURE_TYPE textureType){
        this->lightType = type;
        if(block == STONE){
            data.mesh_iterator = data.meshes.find(BOX);
            data.shader_iterator = data.shaders.find(type);
            data.diffuse_iterator = data.diffuse_maps.find(diffuseMap[textureType]);
            data.bump_iterator = data.bump_maps.find(bumpMap[textureType]);
            if(data.mesh_iterator == data.meshes.end()){
                mesh = new Mesh("./models/box/box.obj");
                data.meshes.insert(std::pair<MESH_TYPE,Mesh*>(BOX,mesh));
            }else{
                mesh = data.meshes.at(BOX);
            }
            if(data.shader_iterator == data.shaders.end()){
                shader = new Shader(type);
                data.shaders.insert(std::pair<LIGHT_TYPE,Shader*>(type, shader));
            }else{
                shader = data.shaders.at(type);
            }
            if(data.diffuse_iterator == data.diffuse_maps.end()){
                primary = new Texture(diffuseMap[textureType], false);
                data.diffuse_maps.insert(std::pair<std::string, Texture*>(diffuseMap[textureType], primary));
            }else{
                primary = data.diffuse_maps.at(diffuseMap[textureType]);
            }
            if(data.bump_iterator == data.bump_maps.end()){
                bump = new Texture(bumpMap[textureType], false);
                data.bump_maps.insert(std::pair<std::string, Texture*>(bumpMap[textureType], bump));
            }else{
                bump = data.bump_maps.at(bumpMap[textureType]);
            }
        }
    }
    void draw(Camera &camera, const glm::vec3 &position, std::vector<Light> lights);
    void draw(Camera &camera, const glm::vec3 &position);
    LIGHT_TYPE lightType;
private:
    Texture * primary;
    Texture * bump;
    Shader * shader;
    Mesh * mesh;
};

#endif /* block_hpp */
