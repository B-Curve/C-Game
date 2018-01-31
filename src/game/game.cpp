//
//  game.cpp
//  MinecraftClone
//
//  Created by Brandon Kervin on 1/30/18.
//  Copyright © 2018 Brandon Kervin. All rights reserved.
//

#include "game.hpp"

bool firstMouse = true;
float lastX = 0, lastY = 0;
void mouse_callback(GLFWwindow* window, double xpos, double ypos);

Game::Game(){
    window = new View;
    camera = new Camera(glm::vec3(1,0,2));
    fps = new FPS;
    text = new Text;
    glfwSetWindowUserPointer(window->getWindow(), camera);
    glfwSetCursorPosCallback(window->getWindow(), mouse_callback);
}

void Game::start(){
    Shader shader("cube");
    Texture texture("dirt");
    
//    GLuint vao = gen_vao();
//    gen_buffer(sizeof(verts), verts);
//    glEnableVertexAttribArray(0);
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
//    gen_buffer(sizeof(texCoords), texCoords);
//    glEnableVertexAttribArray(1);
//    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);
//    gen_buffer(sizeof(normals), normals);
//    glEnableVertexAttribArray(2);
//    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, 0);
//    glBindVertexArray(0);
    
    list = new ChunkList;
    list->addChunk(glm::vec3(0.0f, 0.0f, 10.0f));
    list->addChunk(glm::vec3(20.0f, 0.0f, 10.0f));
    
    while(window->isOpen()){
        update_fps(fps);
        window->clear();
        
        camera->update(window->getWindow(), fps->delta);
        
//        glBindVertexArray(vao);
        
        shader.bind();
        shader.setMat4("model", glm::scale(glm::mat4(1.0f), glm::vec3(0.5f)));
        shader.setMat4("view", camera->getView());
        shader.setMat4("projection", glm::perspective(glm::radians(50.0f),
                                                      (float)window->scrWidth / (float)window->scrHeight, 0.1f, 100.0f));
//        shader.setVec3("objectColor", glm::vec3(1, 1, 0));
        texture.bind(0);
        
        list->update(camera);
        
//        glDrawArrays(GL_TRIANGLES, 0, 36);
        
        if(camera->isDebug()){
            text->render("FPS: " + std::to_string(fps->fps), 2, ((float)window->scrHeight/2) - 65, 0.3f, glm::vec3(1.0f));
        }
        
        window->update();
    }
    
    isRunning = false;
    
    window->~View();
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos){
    void* data = glfwGetWindowUserPointer(window);
    Camera * cam = static_cast<Camera *>(data);
    if (firstMouse){
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }
    
    float xOffset = xpos - lastX;
    float yOffset = lastY - ypos;
    
    lastX = xpos;
    lastY = ypos;
    
    cam->updateMouse(xOffset, yOffset);
}
