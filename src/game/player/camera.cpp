//
//  camera.cpp
//  MinecraftClone
//
//  Created by Brandon Kervin on 1/30/18.
//  Copyright © 2018 Brandon Kervin. All rights reserved.
//

#include "camera.hpp"
#include <iostream>

void Camera::update(GLFWwindow *window, double delta){
    float movespeed = delta * (0.12f * 20);
    if(glfwGetKey(window, MC_FORWARD)){
        position -= (flyMode ? -direction : glm::normalize(glm::cross(right, worldUp))) * movespeed;
    }
    if(glfwGetKey(window, MC_BACKWARD)){
        position += (flyMode ? -direction : glm::normalize(glm::cross(right, worldUp))) * movespeed;
    }
    if(glfwGetKey(window, MC_PAN_LEFT)){
        position -= right * movespeed;
    }
    if(glfwGetKey(window, MC_PAN_RIGHT)){
        position += right * movespeed;
    }
    if(glfwGetKey(window, MC_FLY)){
        double now = glfwGetTime();
        if(now - last_tab > 0.3){
            last_tab = now;
            flyMode = !flyMode;
        }
    }
    if(glfwGetKey(window, MC_DEBUG)){
        double now = glfwGetTime();
        if(now - last_debug > 0.3){
            last_debug = now;
            debugMode = !debugMode;
        }
    }
    
    updateView();
}

void Camera::updateMouse(float xOffset, float yOffset){
    xOffset*= sensitivity;
    yOffset*= sensitivity;
    
    yaw+= xOffset;
    pitch+= yOffset;
    
    if (pitch > 89.0f) pitch = 89.0f;
    if (pitch < -89.0f) pitch = -89.0f;
    
    glm::vec3 front;
    front.x = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    front.y = sin(glm::radians(pitch));
    front.z = -cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    direction = glm::normalize(front);
    right = glm::normalize(glm::cross(direction, worldUp));
    up = glm::normalize(glm::cross(right, direction));
}







