//
// Created by mkajdak on 09.10.17.
//

#ifndef UNTITLED_INCLUDES_H
#define UNTITLED_INCLUDES_H

#include <utility>
#include <list>
#include <SFML/Graphics.hpp>
#include <memory>
#include <iostream>
#include <exception>


namespace own {

    class NotCreated : std::exception {
        const char *err;
    public:
        explicit NotCreated(const char *arg) : err(arg) {
        }

        ~NotCreated() override {
            delete[](err);
        }

    private:
        const char *what() const throw() override {
            return this->err;
        }

    };

}
#endif //UNTITLED_INCLUDES_H

