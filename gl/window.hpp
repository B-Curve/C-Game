//
//  window.hpp
//  gl
//
//  Created by Brandon Kervin on 1/18/18.
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
    virtual ~Window();
    inline GLFWwindow* getWindow(){return window;}
    inline bool isOpen(){return open;}
    void clear(float r, float g, float b, float a);
    void update();
private:
    GLFWwindow * window;
    bool open = true;
};

#endif /* window_hpp */
