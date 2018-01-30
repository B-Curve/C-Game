//
//  view.cpp
//  MinecraftClone
//
//  Created by Brandon Kervin on 1/30/18.
//  Copyright © 2018 Brandon Kervin. All rights reserved.
//

#include "view.hpp"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

View::View(){
    glfwInit();
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    
    window = glfwCreateWindow(WIDTH, HEIGHT, "OpenGL", nullptr, nullptr);
    
    glfwGetFramebufferSize(window, &scrWidth, &scrHeight);
    
    if(window == nullptr){
        glfwTerminate();
        std::cout << "Failed to load window." << std::endl;
        this->~View();
    }
    
    glfwMakeContextCurrent(window);
#ifndef __APPLE__
    glewExperimental = GL_TRUE;
    
    if(glewInit() != GLEW_OK){
        std::cout << "Failed to initialize GLEW." << std::endl;
        this->~View();
    }
#endif
    
    glfwSetInputMode(window, GLFW_STICKY_KEYS, 1);
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
}

void View::clear(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
}

void View::update(){
    glfwSwapBuffers(window);
    glfwPollEvents();
    if(glfwWindowShouldClose(window) || glfwGetKey(window, GLFW_KEY_ESCAPE) == GL_TRUE) open = false;
}

View::~View(){
    glfwTerminate();
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height){
    glViewport(0, 0, width, height);
}




