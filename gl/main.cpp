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

static double last_time = 0;
static int ticks = 0;
static int fps = 0;
static void framerate();

int main() {
    Window window;
    glm::vec3 lightPos = glm::vec3(0.0f, 4.0f, 0.0f);
    glm::vec3 lightPos2 = glm::vec3(16.0f, 4.0f, 16.0f);
    glm::vec3 lightPos3 = glm::vec3(0.0f, 4.0f, 16.0f);
    glm::vec3 lightPos4 = glm::vec3(16.0f, 4.0f, 0.0f);
    std::vector<glm::vec3> lights{
        lightPos,
        lightPos2,
        lightPos3,
        lightPos4
    };
    Camera camera(glm::vec3(0,3,5), window.getWindow());
    Shader * lamp = new Shader(LAMP);
    Shader * lamp2 = new Shader(LAMP);
    Shader * lamp3 = new Shader(LAMP);
    Shader * lamp4 = new Shader(LAMP);
    Shader * shader = new Shader(LAMP_INHERIT);
    Texture texture("./textures/bricks.png", false);
    Texture t2("./textures/bricks_normal.png", false);
    
    Mesh mesh("./models/box/box.obj");
    
    CubeMap skybox;
    
//    glfwSwapInterval(0);
    
    while(window.isOpen()){
        framerate();
        window.clear(0.2f, 0.2f, 0.2f, 1.0f);
        camera.update(window.getWindow());
        shader->bind();
        shader->setInt("material.diffuse", 0);
        shader->setInt("material.bump", 1);
        shader->updateLitElement(camera, lights);
        texture.bind(0);
        t2.bind(1);
        for(unsigned int x = 0 ; x < 16 ; x++){
            for(unsigned int z = 0 ; z < 16 ; z++){
                shader->setPosition(glm::vec3(x*2, 0, z*2));
                mesh.draw();
            }
        }
        
        lamp->bind();
        lamp->setLampColor(glm::vec3(1.0f, 1.0f, 0.0f));
        lamp->updateLight(camera, lightPos);
        mesh.draw();
        
        lamp2->bind();
        lamp2->setLampColor(glm::vec3(1.0f, 0.0f, 0.0f));
        lamp2->updateLight(camera, lightPos2);
        mesh.draw();
        
        lamp3->bind();
        lamp3->setLampColor(glm::vec3(1.0f, 0.0f, 1.0f));
        lamp3->updateLight(camera, lightPos3);
        mesh.draw();
        
        lamp4->bind();
        lamp4->setLampColor(glm::vec3(0.0f, 0.0f, 1.0f));
        lamp4->updateLight(camera, lightPos4);
        mesh.draw();
        
        skybox.draw(camera);
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
