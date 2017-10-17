//
// Created by mkajdak on 01.10.17.
//

#include "../inc/Snake.h"

typedef sf::Keyboard key;

//std::ostream &operator<<(std::ostream &StrmWy, const Directions &Arg) {
//    if (Arg == Up) { return StrmWy << "Up"; }
//    else if (Arg == Down) { return StrmWy << "Down"; }
//    else if (Arg == Right) { return StrmWy << "Right"; }
//    else if (Arg == Left) { return StrmWy << "Left"; }
//    return StrmWy << "";
//}


Snake::Snake() {
    try {
        this->snake = new std::list<std::pair<int, int>>;
    }
    catch (std::bad_alloc){
        throw own::NotCreated("List Snake not created. Problem with memory.");
    }

    try {
        this->dir = new std::list<Directions>;
    }
    catch(std::bad_alloc){
        throw own::NotCreated("List Directions not created. Problem with memory.");
    }

    for (int i = 50; i >20; i-=10) {
        this->snake->push_back(std::pair<int,int>(i,100));
    }


    for(int i = 0; i < 3; ++i){
        this->dir->push_back(Right);
    }

}

void Snake::Draw( sf::RenderWindow &surface) {
    this->update();
    sf::RectangleShape shape(sf::Vector2f(10,10));
    shape.setFillColor(sf::Color::Green);
    for(auto i = this->snake->begin(); i != this->snake->end(); ++i){
        shape.setPosition(i.operator*().first,i.operator*().second);
        surface.draw(shape);

    }

}

Snake::~Snake() {
    delete(this->snake);
    delete(this->dir);
}

void Snake::Move() {


    auto it = this->dir->end();
    auto next = this->dir->end();
    --next;

    while (it != this->dir->begin()){
        if(it.operator*() != next.operator*()){
            it.operator*() = next.operator*();
        }

        --it;
        --next;
    }


    it = this->dir->begin();
    if ((key::isKeyPressed(key::W) || key::isKeyPressed(key::Up)) &&
        (this->dir->begin().operator*()!=Down)) {
            it.operator*() = Up;
    }
    else if ((key::isKeyPressed(key::S) || key::isKeyPressed(key::Down)) && (this->dir->begin().operator*() != Up)) {
        it.operator*() = Down;

    }
    else if ((key::isKeyPressed(key::A) || key::isKeyPressed(key::Left)) && (this->dir->begin().operator*() != Right)) {
        it.operator*() = Left;
    }
    else if ((key::isKeyPressed(key::D) || key::isKeyPressed(key::Right)) && (this->dir->begin().operator*() != Left)) {
        it.operator*() = Right;
    }
}

void Snake::update() {
    auto isnake = this->snake->begin();
    for (auto &idir : *this->dir) {
        if(idir == Up){
            isnake.operator*().second-=10;
        }
        else if(idir == Down){
            isnake.operator*().second+=10;
        }
        else if(idir == Left){
            isnake.operator*().first-=10;
        }
        else{
            isnake.operator*().first+=10;
        }
        ++isnake;
    }

}


