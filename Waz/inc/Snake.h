//
// Created by mkajdak on 01.10.17.
//

#ifndef UNTITLED_SNAKE_H
#define UNTITLED_SNAKE_H

#include "Includes.h"
#include "Drawable.h"


enum Directions {Up,Down,Left,Right};

class Snake : my::Drawable{
private:
    std::list<std::pair<int,int>> *snake;
/*
 *      Snake is a list of pairs [x,y]
 *      [x-20,y][x-10,y][x,y]
 *
 */
    std::list<Directions> *dir;
    void update();

public:
    Snake();

    virtual ~Snake();

    void Draw( sf::RenderWindow&);
    void Move();

};


#endif //UNTITLED_SNAKE_H
