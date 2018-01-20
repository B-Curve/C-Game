//
//  camera.cpp
//  gl
//
//  Created by Brandon Kervin on 1/18/18.
//  Copyright © 2018 Brandon Kervin. All rights reserved.
//

#include "camera.hpp"

#define TIME_OFFSET 7.5f

static long double last_time = 0;

void mouse_callback(GLFWwindow* window, double xpos, double ypos);

void Camera::init(GLFWwindow *window){
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSetWindowUserPointer(window, this);
    glfwSetCursorPosCallback(window, mouse_callback);
}

void Camera::update(GLFWwindow *window){
    long double current_time = glfwGetTime();
    float movespeed = (current_time - last_time) * TIME_OFFSET;
    if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS){
        cameraPos += movespeed * cameraTarget;
    }
    if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS){
        cameraPos -= movespeed * cameraTarget;
    }
    if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS){
        cameraPos -= glm::normalize(glm::cross(cameraTarget, cameraUp)) * movespeed;
    }
    if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS){
        cameraPos += glm::normalize(glm::cross(cameraTarget, cameraUp)) * movespeed;
    }
    view = glm::lookAt(cameraPos, cameraPos + cameraTarget, cameraUp);
    last_time = glfwGetTime();
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos){
    void* data = glfwGetWindowUserPointer(window);
    Camera * cam = static_cast<Camera *>(data);
    if(cam->firstMouseCall){
        cam->lastX = xpos;
        cam->lastY = ypos;
        cam->firstMouseCall = false;
    }
    
    float xOffset = xpos - cam->lastX;
    float yOffset = cam->lastY - ypos;
    cam->lastY = ypos;
    cam->lastX = xpos;
    
    xOffset *= cam->sensitivity;
    yOffset *= cam->sensitivity;
    
    cam->yaw += xOffset;
    cam->pitch += yOffset;
    
    if(cam->pitch > 89.0f) cam->pitch = 89.0f;
    if(cam->pitch < -89.0f) cam->pitch = -89.0f;
    glm::vec3 front;
    front.x = sin(glm::radians(cam->yaw)) * cos(glm::radians(cam->pitch));
    front.y = sin(glm::radians(cam->pitch));
    front.z = -cos(glm::radians(cam->yaw)) * cos(glm::radians(cam->pitch));
    cam->cameraTarget = glm::normalize(front);
    cam->cameraRight = glm::normalize(glm::cross(cam->cameraTarget, cam->up));
    cam->cameraUp = glm::normalize(glm::cross(cam->cameraRight, cam->cameraTarget));
}
