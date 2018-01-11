//
//  camera.cpp
//  OpenGLPractice
//
//  Created by Brandon Kervin on 1/9/18.
//  Copyright © 2018 Brandon Kervin. All rights reserved.
//

#include "camera.hpp"

void mouse_callback(GLFWwindow* window, double xpos, double ypos);

void Camera::init(){
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSetWindowUserPointer(window, this);
    glfwSetCursorPosCallback(window, mouse_callback);
}

void Camera::update(){
    if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS){
        position.z -= movementSpeed * cos(glm::radians(yaw));
        position.x += movementSpeed * sin(glm::radians(yaw));
    }
    if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS){
        position.z += movementSpeed * cos(glm::radians(yaw));
        position.x -= movementSpeed * sin(glm::radians(yaw));
    }
    if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS){
        position -= glm::normalize(glm::cross(direction, up)) * movementSpeed;
    }
    if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS){
        position += glm::normalize(glm::cross(direction, up)) * movementSpeed;
    }
    view = glm::lookAt(position, position + direction, up);
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
    cam->direction = glm::normalize(front);
}
