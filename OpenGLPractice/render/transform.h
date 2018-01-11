//
//  transform.h
//  OpenGLPractice
//
//  Created by Brandon Kervin on 1/9/18.
//  Copyright © 2018 Brandon Kervin. All rights reserved.
//

#ifndef transform_h
#define transform_h

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

class Transform {
public:
    Transform(const glm::vec3& pos = glm::vec3(), const glm::vec3& rot = glm::vec3(), const glm::vec3& scale = glm::vec3(1.0f,1.0f,1.0f)) :
    pos(pos),
    rot(rot),
    scale(scale) {}
    inline glm::mat4 getModel() const {
        glm::mat4 posMatrix = glm::translate(pos);
        glm::mat4 rotXMatrix = glm::rotate(rot.x, glm::vec3(1,0,0));
        glm::mat4 rotYMatrix = glm::rotate(rot.y, glm::vec3(0,1,0));
        glm::mat4 rotZMatrix = glm::rotate(rot.z, glm::vec3(0,0,1));
        glm::mat4 scaleMatrix = glm::scale(scale);
        
        //ORDER IS SUPER IMPORTANT FOR MATRIX MULTIPLICATION
        glm::mat4 rotMatrix = rotZMatrix * rotYMatrix * rotXMatrix;
        return posMatrix * rotMatrix * scaleMatrix;
    }
    inline glm::vec3& getPos(){return pos;}
//    Transform& operator=(const Transform& other);
//        Transform(const Transform& other){}
private:
    glm::vec3 pos;
    glm::vec3 rot;
    glm::vec3 scale;
};


#endif /* transform_h */
