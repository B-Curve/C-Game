//
//  camera.hpp
//  MinecraftClone
//
//  Created by Brandon Kervin on 1/30/18.
//  Copyright © 2018 Brandon Kervin. All rights reserved.
//

#ifndef camera_hpp
#define camera_hpp


#ifndef glm_hpp
    #include <glm/glm.hpp>
#endif

#include <glm/gtx/transform.hpp>

#ifndef glfw3_h
    #include <GLFW/glfw3.h>
#endif

#define HEIGHT 0.75f
#define MC_FORWARD 'W'
#define MC_BACKWARD 'S'
#define MC_PAN_LEFT 'A'
#define MC_PAN_RIGHT 'D'
#define MC_FLY GLFW_KEY_TAB
#define MC_DEBUG '`'


class Camera {
public:
    Camera(const glm::vec3 &pos){
        position = pos;
        direction = glm::vec3(0,0,-1);
        right = glm::normalize(glm::cross(direction, worldUp));
        up = glm::normalize(glm::cross(direction, right));
        view = glm::lookAt(position, position + direction, worldUp);
    }
    inline glm::mat4 getView() const {
        return view;
    }
    void update(GLFWwindow *window, double delta);
    void updateMouse(float xOffset, float yOffset);
    inline bool isDebug(){return debugMode;}
private:
    inline void updateView() { view = glm::lookAt(position + glm::vec3(0,HEIGHT,0), position + glm::vec3(0,HEIGHT,0) + direction, worldUp); };
    glm::vec3 position;
    glm::vec3 direction;
    glm::vec3 right;
    glm::vec3 up;
    glm::vec3 worldUp = glm::vec3(0,1,0);
    glm::mat4 model = glm::mat4(1.0f);
    glm::mat4 view;
    
    float pitch = 0, yaw = 0, sensitivity = 0.06f;
    double last_tab = 0, last_debug = 0;
    bool flyMode = false;
    bool debugMode = false;
};

#endif /* camera_hpp */
