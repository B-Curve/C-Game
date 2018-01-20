//
//  camera.hpp
//  gl
//
//  Created by Brandon Kervin on 1/18/18.
//  Copyright © 2018 Brandon Kervin. All rights reserved.
//

#ifndef camera_hpp
#define camera_hpp

#include <stdio.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <GLFW/glfw3.h>

class Camera {
public:
    Camera(glm::vec3 position, GLFWwindow *window){
        this->cameraPos = position;
        glm::vec3 front;
        front.x = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
        front.y = sin(glm::radians(pitch));
        front.z = -cos(glm::radians(yaw)) * cos(glm::radians(pitch));
        cameraTarget = glm::normalize(front);
        cameraUp = glm::vec3(0,1.0f,0);
        view = glm::lookAt(cameraPos, cameraPos + cameraTarget, cameraUp);
        projection = glm::perspective(glm::radians(50.0f), 800.0f/600.0f, 0.1f, 100.0f);
        model = glm::mat4(1.0f);
        init(window);
    }
    void update(GLFWwindow *window);
    inline glm::mat4 getMVP() const {
        return projection * view * model;
    }
    inline glm::mat4 getModel() const {
        return model;
    }
    inline glm::mat4 getView() const {
        return view;
    }
    inline glm::mat4 getProjection() const {
        return projection;
    }
    inline glm::vec3 getPos() const {
        return cameraPos;
    }
    inline glm::vec3 getFront() const {
        return cameraTarget;
    }
    bool firstMouseCall = true;
    float lastX = 0, lastY = 0;
    float sensitivity = 0.05f;
    float pitch = 0, yaw = 0;
    glm::vec3 cameraTarget;
    glm::vec3 cameraUp;
    glm::vec3 cameraRight;
    glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
private:
    void init(GLFWwindow *window);
    glm::vec3 cameraPos;
    glm::mat4 view;
    glm::mat4 projection;
    glm::mat4 model;
};

#endif /* camera_hpp */
