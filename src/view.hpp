//
//  view.hpp
//  MinecraftClone
//
//  Created by Brandon Kervin on 1/30/18.
//  Copyright © 2018 Brandon Kervin. All rights reserved.
//

#ifndef view_hpp
#define view_hpp

#include <iostream>
#define GLFW_INCLUDE_GLCOREARB
#include <GLFW/glfw3.h>

const GLint WIDTH = 1152, HEIGHT = 648;

class View {
public:
    View();
    virtual ~View();
    inline GLFWwindow* getWindow(){return window;}
    inline bool isOpen(){return open;}
    void update();
    void clear();
    int scrWidth, scrHeight;
private:
    GLFWwindow *window;
    bool open = true;
};

#endif /* view_hpp */
