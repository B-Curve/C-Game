//
//  text.cpp
//  OpenGLPractice
//
//  Created by Brandon Kervin on 1/10/18.
//  Copyright © 2018 Brandon Kervin. All rights reserved.
//


#include "text.hpp"

Text::Text(){
    generateText();
    
    float verts[] = {
        -0.05f, -0.05f, 0.05f,
        0.05f, -0.05f, 0.05f,
        0.05f, 0.05f, 0.05f,
        0.05f, 0.05f, 0.05f,
        -0.05f, 0.05f, 0.05f,
        -0.05f, -0.05f, 0.05f
    };
    
    float texCoords[] = {
        0, 0.9,
        1, 0.9,
        1, 0.1,
        1, 0.1,
        0, 0.1,
        0, 0.9
    };
    
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glGenBuffers(1, &tbo);
    
    glBindVertexArray(vao);
    
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    
    glBindBuffer(GL_ARRAY_BUFFER, tbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(texCoords), texCoords, GL_STATIC_DRAW);
    
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(1);
    
    glBindVertexArray(0);
    
}

void Text::draw(const std::string& text){
    shader->bind();
    const char * sequence = text.c_str();
    for(unsigned int i = 0 ; i < sizeof(sequence)/sizeof(sequence[0]) ; i++){
        it = letters.find(sequence[i]);
        if(it == letters.end()) continue;
        shader->textOffset(-0.95f + (i*0.1), 0.93f);
        letters.at(sequence[i])->bind(0);
        glBindVertexArray(vao);
        glDrawArrays(GL_TRIANGLES, 0, 6);
    }
}

void Text::generateText(){
    shader = new Shader("./shaders/font");
    letters.insert(std::pair<char, Texture*>('a', new Texture("./fonts/a.png")));
    letters.insert(std::pair<char, Texture*>('b', new Texture("./fonts/b.png")));
    letters.insert(std::pair<char, Texture*>('c', new Texture("./fonts/c.png")));
    letters.insert(std::pair<char, Texture*>('d', new Texture("./fonts/d.png")));
    letters.insert(std::pair<char, Texture*>('e', new Texture("./fonts/e.png")));
    letters.insert(std::pair<char, Texture*>('f', new Texture("./fonts/f.png")));
    letters.insert(std::pair<char, Texture*>('g', new Texture("./fonts/g.png")));
    letters.insert(std::pair<char, Texture*>('h', new Texture("./fonts/h.png")));
    letters.insert(std::pair<char, Texture*>('i', new Texture("./fonts/i.png")));
    letters.insert(std::pair<char, Texture*>('j', new Texture("./fonts/j.png")));
    letters.insert(std::pair<char, Texture*>('k', new Texture("./fonts/k.png")));
    letters.insert(std::pair<char, Texture*>('l', new Texture("./fonts/l.png")));
    letters.insert(std::pair<char, Texture*>('m', new Texture("./fonts/m.png")));
    letters.insert(std::pair<char, Texture*>('n', new Texture("./fonts/n.png")));
    letters.insert(std::pair<char, Texture*>('o', new Texture("./fonts/o.png")));
    letters.insert(std::pair<char, Texture*>('p', new Texture("./fonts/p.png")));
    letters.insert(std::pair<char, Texture*>('q', new Texture("./fonts/q.png")));
    letters.insert(std::pair<char, Texture*>('r', new Texture("./fonts/r.png")));
    letters.insert(std::pair<char, Texture*>('s', new Texture("./fonts/s.png")));
    letters.insert(std::pair<char, Texture*>('t', new Texture("./fonts/t.png")));
    letters.insert(std::pair<char, Texture*>('u', new Texture("./fonts/u.png")));
    letters.insert(std::pair<char, Texture*>('v', new Texture("./fonts/v.png")));
    letters.insert(std::pair<char, Texture*>('w', new Texture("./fonts/w.png")));
    letters.insert(std::pair<char, Texture*>('x', new Texture("./fonts/x.png")));
    letters.insert(std::pair<char, Texture*>('y', new Texture("./fonts/y.png")));
    letters.insert(std::pair<char, Texture*>('z', new Texture("./fonts/z.png")));
    letters.insert(std::pair<char, Texture*>('1', new Texture("./fonts/1.png")));
    letters.insert(std::pair<char, Texture*>('2', new Texture("./fonts/2.png")));
    letters.insert(std::pair<char, Texture*>('3', new Texture("./fonts/3.png")));
    letters.insert(std::pair<char, Texture*>('4', new Texture("./fonts/4.png")));
    letters.insert(std::pair<char, Texture*>('5', new Texture("./fonts/5.png")));
    letters.insert(std::pair<char, Texture*>('6', new Texture("./fonts/6.png")));
    letters.insert(std::pair<char, Texture*>('7', new Texture("./fonts/7.png")));
    letters.insert(std::pair<char, Texture*>('8', new Texture("./fonts/8.png")));
    letters.insert(std::pair<char, Texture*>('9', new Texture("./fonts/9.png")));
    letters.insert(std::pair<char, Texture*>('0', new Texture("./fonts/0.png")));
}











