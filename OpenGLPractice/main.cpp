//
//  main.cpp
//  OpenGLPractice
//
//  Created by Brandon Kervin on 1/9/18.
//  Copyright © 2018 Brandon Kervin. All rights reserved.
//

#include <iostream>
#include <OpenGL/gl3.h>
#include <string>
#include <chrono>
#include <vector>
#include "window.hpp"
#include "render/shader.hpp"
#include "render/buffer.hpp"
#include "render/camera.hpp"
#include "render/texture.hpp"
#include "shapes/pyramid.h"
#include "shapes/cube.h"
#include "render/transform.h"
#include "gen/chunk.hpp"
#include "gen/text.hpp"

int main() {
    Window window;
    Camera cam(glm::vec3(0,0,5), window.getWindow());
    
    Chunk100x1x100 chunk(0, -4, 10);
    Chunk100x1x100 chunk2(-100, -4, 10);
    Text text;
    
    clock_t current_ticks, delta_ticks;
    clock_t fps = 0;
    
    glm::vec4 clip;
    while(window.isOpen()){
        current_ticks = clock();
        window.clear(0.7f, 0.7f, 0.7f, 1.0f);
        cam.update();
        chunk.update(cam);
        chunk2.update(cam);
        delta_ticks = clock() - current_ticks;
        if(delta_ticks > 0)
            fps = CLOCKS_PER_SEC / delta_ticks;
        text.draw("fps " + std::to_string(fps));
        window.update();
    }
}
