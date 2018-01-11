//
//  chunk.cpp
//  OpenGLPractice
//
//  Created by Brandon Kervin on 1/10/18.
//  Copyright © 2018 Brandon Kervin. All rights reserved.
//

#include <iostream>
#include "chunk.hpp"

void Chunk16x16x16::update(Camera& cam){
    shader->bind();
    shader->update(cam);
    texture->bind(0);
    buffer->drawWithoutIndices(transforms.size());
}

void Chunk100x1x100::update(Camera& cam){
    shader->bind();
    shader->update(cam);
    texture->bind(0);
    buffer->drawWithoutIndices(transforms.size());
}

void Chunk1000x1x1000::update(Camera& cam){
    shader->bind();
    shader->update(cam);
    texture->bind(0);
    buffer->drawWithoutIndices(transforms.size());
}
