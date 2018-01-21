//
//  data_fetch.h
//  gl
//
//  Created by Brandon Kervin on 1/20/18.
//  Copyright © 2018 Brandon Kervin. All rights reserved.
//

#ifndef data_fetch_h
#define data_fetch_h

#include <map>
#include <string>
#include "../render/texture.hpp"
#include "../render/shader.hpp"
#include "../render/mesh.hpp"

enum MESH_TYPE {
    BOX
};

struct Data {
    std::map<MESH_TYPE, Mesh*> meshes;
    std::map<MESH_TYPE, Mesh*>::iterator mesh_iterator;
    std::map<std::string, Texture*> diffuse_maps;
    std::map<std::string, Texture*> bump_maps;
    std::map<std::string, Texture*>::iterator diffuse_iterator;
    std::map<std::string, Texture*>::iterator bump_iterator;
    std::map<LIGHT_TYPE, Shader*> shaders;
    std::map<LIGHT_TYPE, Shader*>::iterator shader_iterator;
};


#endif /* data_fetch_h */
