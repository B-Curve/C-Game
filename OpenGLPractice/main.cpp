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
#include "interaction/collision.h"
#include "gen/skybox.hpp"

int main() {
    Window window;
    Camera cam(glm::vec3(30,0,40), window.getWindow());
    Collision collision;
    Skybox skybox;
    
    Chunk100x1x100 chunk(0, -4, 10, collision);
    Chunk16x16x16 c3(0,-1,20,collision);
//    Chunk16x16x16 c4(20,2,0);
//    Chunk16x16x16 c5(-20,2,0);
//    Chunk16x16x16 c6(0,2,-20);
    Text text;
    
    double previousTime = glfwGetTime();
    int frameCount = 0;
    int lastFrameCount = 0;
    
//    glfwSwapInterval(0);//disables v-sync
    
    glm::vec4 clip;
    while(window.isOpen()){
        double currentTime = glfwGetTime();
        frameCount++;
        if ( currentTime - previousTime >= 1.0 ){
            lastFrameCount = frameCount;
            frameCount = 0;
            previousTime += 1.0;
        }
        window.clear(0.2f, 0.2f, 0.2f, 1.0f);
        cam.update(collision);
        chunk.update(cam);
        c3.update(cam);
//        c4.update(cam);
//        c5.update(cam);
//        c6.update(cam);
        skybox.render(cam);
        text.draw("fps " + std::to_string(lastFrameCount));
        window.update();
    }
}
