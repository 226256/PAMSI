//
// Created by mkajdak on 09.10.17.
//

#ifndef UNTITLED_GAME_H
#define UNTITLED_GAME_H

#include "Includes.h"
#include "Snake.h"

class Game{
public:
    static int Play(unsigned int& fps){

        //
        sf::RenderWindow window(sf::VideoMode(1024, 780), "SFML works!");
        window.setFramerateLimit(fps);
        std::unique_ptr<Snake> s{new Snake()};


        while (window.isOpen())
        {
            sf::Event event{};
            while (window.pollEvent(event)){
                if(event.type == sf::Event::Closed){
                    window.close();
                }
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
                window.close();
            }


            window.clear(sf::Color(128,128,128));
            s->Move();
            s->Draw(window);
            window.display();
        }
        return 0;
    }

};


#endif //UNTITLED_GAME_H
