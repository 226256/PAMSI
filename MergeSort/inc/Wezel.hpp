/*
 * Wezel.hpp
 *
 *  Created on: Apr 2, 2017
 *      Author: 226332
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

//Węzeł do listy dwustronnej
#ifndef INC_WEZEL_HPP_
#define INC_WEZEL_HPP_

#include "Includy.hpp"

class Wezel {
//Nie bawię się w shared_ptr bo szkoda mi tracić na wydajności
//skoro i tak procesor długo liczy na zwykłych :/
    Wezel *kolejny;   //Kolejny węzeł
    Wezel *poprzedni; //Poprzedni węzeł
    int element;      //Przechowywany element

public:
    Wezel() :
            kolejny(nullptr), poprzedni(nullptr), element(0){
    }

    //dodatkowe argumenty(domyślne) pozwalają na wstawianie elementów między węzły
    //chyba nie musze tłumaczyć jak to działa
    Wezel(int elem, Wezel *pop = nullptr, Wezel *kol = nullptr) :
            kolejny(kol), poprzedni(pop), element(elem){
        if (poprzedni){
            poprzedni->kolejny = this;
        }
        if (kolejny){
            kolejny->poprzedni = this;
        }
    }

    int Getelement(){
        return element;
    }

    Wezel *Getpoprzedni(){
        return poprzedni;
    }

    Wezel *Getkolejny(){
        return kolejny;
    }

    void Setelement(int elem){
        element = elem;
    }

    ~Wezel(){
        if (poprzedni && kolejny){
            kolejny->poprzedni = poprzedni;
            poprzedni->kolejny = kolejny;
        } else if (poprzedni){
            poprzedni->kolejny = nullptr;
        } else if (kolejny){
            kolejny->poprzedni = nullptr;
        }
    }
};

#endif /* INC_WEZEL_HPP_ */
