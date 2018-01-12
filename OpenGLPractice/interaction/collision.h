//
//  collision.h
//  OpenGLPractice
//
//  Created by Brandon Kervin on 1/11/18.
//  Copyright © 2018 Brandon Kervin. All rights reserved.
//

#ifndef collision_h
#define collision_h

#include <glm/glm.hpp>
#include <vector>

struct Collision {
    std::vector<glm::vec3> collisionPoints;
};

#endif /* collision_h */
