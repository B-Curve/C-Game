//
//  camera.hpp
//  OpenGLPractice
//
//  Created by Brandon Kervin on 1/9/18.
//  Copyright © 2018 Brandon Kervin. All rights reserved.
//

#ifndef camera_hpp
#define camera_hpp

#define TIME_OFFSET 100.0f
#define GRAVITY 0.17f

#include <stdio.h>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <GLFW/glfw3.h>
#include "../interaction/collision.h"

class Camera {
public:
    Camera(const glm::vec3& position, GLFWwindow* window){
        this->position = position;
        this->window = window;
        projection = glm::perspective(glm::radians(45.0f), (float)800/(float)600, 0.1f, 500.0f);
        view = glm::lookAt(position, //position
                           position + glm::vec3(0,0,1), //view direction
                           glm::vec3(0,1,0)); //above direction
        model = glm::mat4(1.0f);
        mvp = projection * view * model;
        glm::vec3 front;
        front.x = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
        front.y = sin(glm::radians(pitch));
        front.z = -cos(glm::radians(yaw)) * cos(glm::radians(pitch));
        direction = glm::normalize(front);
        right = glm::vec3(sin(yaw),0,cos(pitch));
        up = glm::cross( right, direction );
        init();
    }
    inline glm::mat4 getMVP() const{
        return projection * view * model;
    }
    inline glm::mat4 getView() {
        return view;
    }
    inline glm::mat4 getProjection() {
        return projection;
    }
    void update(Collision& collision);
    bool firstMouseCall = true;
    float yaw = 180;
    float pitch = 0;
    float lastX;
    float lastY;
    float sensitivity = 0.08f;
    glm::vec3 direction;
private:
    void testCollision(glm::vec3 savedPosition, Collision& collision);
    void init();
    GLFWwindow* window;
    glm::vec3 right;
    glm::vec3 up;
    glm::vec3 position;
    glm::mat4 model;
    glm::mat4 view;
    glm::mat4 projection;
    glm::mat4 mvp;
    float height = 2.0f;
    float movementSpeed = 0.14f;
    bool jumping;
    float jumpHeight = 0.37f;
    float sprintModifier = .09f;
    bool sprinting;
    float fov = 45.0f;
};

#endif /* camera_hpp */
