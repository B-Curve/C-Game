//
//  main.cpp
//  gl
//
//  Created by Brandon Kervin on 1/18/18.
//  Copyright © 2018 Brandon Kervin. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "window.hpp"
#include "render/shader.hpp"
#include "render/texture.hpp"
#include "render/camera.hpp"
#include "render/mesh.hpp"
#include "data/data_fetch.h"
#include "generation/chunk.hpp"
#include "render/text.hpp"

static double last_time = 0;
static int ticks = 0;
static int fps = 0;
static void framerate();

int main() {
    std::vector<Light> lights;
    Data data;
    Window window;
    Camera camera(glm::vec3(0,3,5), window.getWindow());
    Text text;
    
    CubeMap skybox;
    
    std::vector<TEXTURE_TYPE> textures{ DIRT_TEXTURE, STONE_TEXTURE, GRASS_TEXTURE };
    
    Chunk chunk(glm::vec3(0,0,0), data, FLASHLIGHT, textures);
    
    glm::vec3 lampColors[] = {
        glm::vec3(1.0f, 1.0f, 0.7f),
        glm::vec3(0.8f, 0.8f, 0.8f),
        glm::vec3(0.8f, 0.8f, 0.8f),
        glm::vec3(0.8f, 0.8f, 0.8f),
        glm::vec3(0.8f, 0.8f, 0.8f),
    };
    
    Light lightGroup[] = {
        Light(glm::vec3(16,30,16), lampColors[0], SUN),
        Light(glm::vec3(0,30,32), lampColors[1], COLOSSAL),
        Light(glm::vec3(32,30,0), lampColors[2], COLOSSAL),
        Light(glm::vec3(32,30,32), lampColors[3], COLOSSAL),
        Light(glm::vec3(0,30,0), lampColors[4], COLOSSAL),
    };
    
    for(int i = 0 ; i < sizeof(lightGroup)/sizeof(lightGroup[0]) ; i++){
        lights.push_back(lightGroup[i]);
    }
    
//    glfwSwapInterval(0);
    
    while(window.isOpen()){
        framerate();
        window.clear(0.2f, 0.2f, 0.2f, 1.0f);
        camera.update(window.getWindow());
        
        chunk.update(camera, lights);
        
        for(int i = 0 ; i < lights.size() ; i++){
            lights[i].draw(camera);
        }
        
        skybox.draw(camera);
        
        text.draw("Hello", 20, 20, 1, glm::vec3(0.0,1.0,0.0));
        
        window.update();
    }
    
    window.~Window();
}

static void framerate(){
    if(last_time == 0) last_time = glfwGetTime();
    if(glfwGetTime() - last_time <= 1.0){
        ticks++;
    }else{
        fps = ticks;
        ticks = 0;
        last_time = glfwGetTime();
        std::cout << "FPS: " << fps << std::endl;
    }
}
