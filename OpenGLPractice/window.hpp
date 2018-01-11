//
//  window.hpp
//  OpenGLPractice
//
//  Created by Brandon Kervin on 1/9/18.
//  Copyright © 2018 Brandon Kervin. All rights reserved.
//

#ifndef window_hpp
#define window_hpp

#include <stdio.h>
#include <GLFW/glfw3.h>
#include <OpenGL/gl3.h>

class Window {
public:
    Window();
    void update();
    void clear(float r, float g, float b, float a);
    GLFWwindow* getWindow(){return window;}
    bool isOpen(){return open;}
private:
    GLFWwindow* window;
    bool open = true;
};

#endif /* window_hpp */
