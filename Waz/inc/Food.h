//
// Created by mkajdak on 09.10.17.
//

#ifndef UNTITLED_FOOD_H
#define UNTITLED_FOOD_H


#include "Includes.h"



class Food {
private:
    std::list<std::pair<int,int>>* food;
    int screenx,screeny;

public:
    Food(int& x,int& y);

    void Draw(sf::RenderWindow&);

};


#endif //UNTITLED_FOOD_H
