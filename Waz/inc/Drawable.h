//
// Created by mkajdak on 17.10.17.
//

#ifndef WAZ_DRAWABLE_H
#define WAZ_DRAWABLE_H

#include <SFML/Graphics/RenderWindow.hpp>

namespace my {
    class Drawable {
    public:
        virtual Drawable() = 0;
        virtual ~Drawable() = default;

        virtual void Draw(sf::RenderWindow&) = 0;
    };
}

#endif //WAZ_DRAWABLE_H
