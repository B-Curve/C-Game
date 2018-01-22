//
//  block.cpp
//  gl
//
//  Created by Brandon Kervin on 1/20/18.
//  Copyright © 2018 Brandon Kervin. All rights reserved.
//

#include "block.hpp"

void Block::draw(Camera &camera, const glm::vec3 &position, std::vector<Light> lights, bool isFirst){
    shader->bind();
    shader->setInt("material.diffuse", 0);
    shader->setInt("material.bump", 1);
    std::vector<glm::vec3> lightPositions;
    std::vector<glm::vec3> lightColors;
    std::vector<LIGHT_STRENGTH> lightStrengths;
    for(unsigned int i = 0 ; i < lights.size() ; i++){
        lightPositions.push_back(lights[i].position);
        lightColors.push_back(lights[i].color);
        lightStrengths.push_back(lights[i].lightStrength);
    }
    shader->updateLitElement(camera, lightPositions, lightColors, lightStrengths);
    if(isFirst){
        primary->bind(0);
        bump->bind(1);
    }
    shader->setPosition(position);
    mesh->draw();
}

void Block::draw(Camera &camera, const glm::vec3 &position, bool isFirst){
    if(isFirst){
        shader->bind();
        shader->update(camera);
        shader->setInt("material.diffuse", 0);
        shader->setInt("material.bump", 1);
        primary->bind(0);
        bump->bind(1);
    }
    shader->setPosition(position);
    mesh->draw();
}

void Light::draw(Camera &camera){
    shader->bind();
    shader->setLampColor(color);
    shader->updateLight(camera, position);
    mesh->draw();
}
