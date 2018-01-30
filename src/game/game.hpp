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
#ifndef utils_hpp
#include "../utils.hpp"
#endif

class Game {
public:
    Game();
private:
    View *window;
    Camera *camera;
    FPS *fps;
    Text *text;
    bool isRunning = true;
};

#endif /* game_hpp */
