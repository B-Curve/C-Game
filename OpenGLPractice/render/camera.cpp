//
//  camera.cpp
//  OpenGLPractice
//
//  Created by Brandon Kervin on 1/9/18.
//  Copyright © 2018 Brandon Kervin. All rights reserved.
//

#include "camera.hpp"

static double last_time = 0;
static int jumps = 0;

void mouse_callback(GLFWwindow* window, double xpos, double ypos);

void Camera::init(){
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSetWindowUserPointer(window, this);
    glfwSetCursorPosCallback(window, mouse_callback);
}

void Camera::update(Collision& collision){
    double current_time = glfwGetTime();
    float lagBoost = (current_time - last_time) * TIME_OFFSET;
    if(glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS){
        if(sprinting && fov < 55.0f){
            fov += 0.5f;
        }else sprinting = true;
    }else{
        sprinting = false;
        fov = 45.0f;
    }
    sprintModifier = sprinting ? (current_time - last_time) * TIME_OFFSET : 1.0f;
    jumpHeight = (current_time - last_time) * TIME_OFFSET / 4;
    if(jumping == true && jumps < 20){
        position.y += jumpHeight;
        jumps++;
    }else{
        jumping = false;
        jumps = 0;
    }
    glm::vec3 savedPos = position;
    if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS){
        glm::vec3 savedPos = position;
        position.z -= lagBoost * movementSpeed * sprintModifier * cos(glm::radians(yaw));
        position.x += lagBoost * movementSpeed * sprintModifier * sin(glm::radians(yaw));
    }
    if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS){
        glm::vec3 savedPos = position;
        position.z += lagBoost * movementSpeed * cos(glm::radians(yaw));
        position.x -= lagBoost * movementSpeed * sin(glm::radians(yaw));
    }
    if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS){
        glm::vec3 savedPos = position;
        position -= glm::normalize(glm::cross(direction, up)) * lagBoost * movementSpeed;
    }
    if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS){
        glm::vec3 savedPos = position;
        position += glm::normalize(glm::cross(direction, up)) * lagBoost * movementSpeed;
    }
    testCollision(savedPos, collision);
    bool shouldDrop = true;
    for(unsigned int i = 0 ; i < collision.collisionPoints.size() ; i++){
        if(position.y + 0.5f > collision.collisionPoints[i].y - 0.6f && position.y - 0.5f < collision.collisionPoints[i].y + 0.6f && position.x < collision.collisionPoints[i].x + 0.5f &&
           position.x > collision.collisionPoints[i].x - 0.5f && position.z < collision.collisionPoints[i].z + 0.5f &&
           position.z > collision.collisionPoints[i].z - 0.5f){
            shouldDrop = false;
        }
    }
    if(shouldDrop)  position.y -= GRAVITY;
    if(glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS){
        if(!jumping && !shouldDrop) jumping = true;
    }
    glm::vec3 lookHeight = glm::vec3(position.x, position.y + height, position.z);
    view = glm::lookAt(lookHeight, lookHeight + direction, up);
    projection = glm::perspective(glm::radians(fov), (float)800/(float)600, 0.1f, 500.0f);
    last_time = glfwGetTime();
}

void Camera::testCollision(glm::vec3 savedPosition, Collision& collision){
    glm::vec3 testPostionX = glm::vec3(position.x, savedPosition.y, savedPosition.z);
    glm::vec3 testPostionY = glm::vec3(savedPosition.x, position.y, savedPosition.z);
    glm::vec3 testPostionZ = glm::vec3(savedPosition.x, savedPosition.y, position.z);
    bool failX = false, failY = false, failZ = false;
    for(unsigned int i = 0 ; i < collision.collisionPoints.size() ; i++){
        if(testPostionX.x > collision.collisionPoints[i].x - 0.6f && testPostionX.x < collision.collisionPoints[i].x + 0.6f && testPostionX.z > collision.collisionPoints[i].z - 0.6f && testPostionX.z < collision.collisionPoints[i].z + 0.6f && testPostionX.y > collision.collisionPoints[i].y - 0.6f - height && testPostionX.y < collision.collisionPoints[i].y + 0.6f){
            position.x = savedPosition.x;
        }
    }
    for(unsigned int i = 0 ; i < collision.collisionPoints.size() ; i++){
        if(testPostionY.x > collision.collisionPoints[i].x - 0.6f && testPostionY.x < collision.collisionPoints[i].x + 0.6f && testPostionY.z > collision.collisionPoints[i].z - 0.6f && testPostionY.z < collision.collisionPoints[i].z + 0.6f && testPostionY.y > collision.collisionPoints[i].y - 0.6f - height && testPostionY.y < collision.collisionPoints[i].y + 0.6f){
            position.y = savedPosition.y;
        }
    }
    for(unsigned int i = 0 ; i < collision.collisionPoints.size() ; i++){
        if(testPostionZ.x > collision.collisionPoints[i].x - 0.6f && testPostionZ.x < collision.collisionPoints[i].x + 0.6f && testPostionZ.z > collision.collisionPoints[i].z - 0.6f && testPostionZ.z < collision.collisionPoints[i].z + 0.6f && testPostionZ.y > collision.collisionPoints[i].y - 0.6f - height && testPostionZ.y < collision.collisionPoints[i].y + 0.6f){
            position.z = savedPosition.z;
        }
    }
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
