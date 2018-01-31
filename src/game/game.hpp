//
//  game.hpp
//  MinecraftClone
//
//  Created by Brandon Kervin on 1/30/18.
//  Copyright © 2018 Brandon Kervin. All rights reserved.
//

#ifndef game_hpp
#define game_hpp

#include "../view.hpp"
#include "player/camera.hpp"
#include "render/shader.hpp"
#include "render/text.hpp"
#include "render/texture.hpp"
#include "generation/chunk.hpp"
#ifndef utils_hpp
#include "../utils.hpp"
#endif

class Game {
public:
    Game();
    void start();
private:
    View *window;
    Camera *camera;
    FPS *fps;
    Text *text;
    ChunkList *list;
    bool isRunning = true;
};

//static GLfloat verts[] = {
//    //front
//    -1, -1, -1,
//    1, -1, -1,
//    1, 1, -1,
//    1, 1, -1,
//    -1, 1, -1,
//    -1, -1, -1,
//    //back
//    -1, -1, 1,
//    1, -1, 1,
//    1, 1, 1,
//    1, 1, 1,
//    -1, 1, 1,
//    -1, -1, 1,
//    //left
//    -1, -1, 1,
//    -1, -1, -1,
//    -1, 1, -1,
//    -1, 1, -1,
//    -1, 1, 1,
//    -1, -1, 1,
//    //right
//    1, -1, -1,
//    1, -1, 1,
//    1, 1, 1,
//    1, 1, 1,
//    1, 1, -1,
//    1, -1, -1,
//    //top
//    -1, 1, -1,
//    1, 1, -1,
//    1, 1, 1,
//    1, 1, 1,
//    -1, 1, 1,
//    -1, 1, -1,
//    //bottom
//    -1, -1, -1,
//    1, -1, -1,
//    1, -1, 1,
//    1, -1, 1,
//    -1, -1, 1,
//    -1, -1, -1,
//};
//
//static GLfloat texCoords[] = {
//    -1,-1,  1,-1,   1,1,    1,1,    -1,1,   -1,-1,
//    -1,-1,  1,-1,   1,1,    1,1,    -1,1,   -1,-1,
//    -1,-1,  1,-1,   1,1,    1,1,    -1,1,   -1,-1,
//    -1,-1,  1,-1,   1,1,    1,1,    -1,1,   -1,-1,
//    -1,-1,  1,-1,   1,1,    1,1,    -1,1,   -1,-1,
//    -1,-1,  1,-1,   1,1,    1,1,    -1,1,   -1,-1,
//};
//
//static GLfloat normals[] = {
//    0,0,-1, 0,0,-1, 0,0,-1, 0,0,-1, 0,0,-1, 0,0,-1,
//    0,0,1,  0,0,1,  0,0,1,  0,0,1,  0,0,1,  0,0,1,
//    -1,0,0,  -1,0,0,  -1,0,0,  -1,0,0,  -1,0,0,  -1,0,0,
//    1,0,0,  1,0,0,  1,0,0,  1,0,0,  1,0,0,  1,0,0,
//    0,1,0,  0,1,0,  0,1,0,  0,1,0,  0,1,0,  0,1,0,
//    0,-1,0, 0,-1,0, 0,-1,0, 0,-1,0, 0,-1,0, 0,-1,0,
//};

#endif /* game_hpp */
