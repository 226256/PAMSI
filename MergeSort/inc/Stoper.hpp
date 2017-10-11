/*
 * Stoper.hpp
 *
 *  Created on: Mar 19, 2017
 *      Author: arr
 */

#ifndef INC_STOPER_HPP_
#define INC_STOPER_HPP_
#include "Wykonawcze/Iwykonaj.hpp"
#include "Includy.hpp"

class Stoper {
public:
    Stoper() = delete;
    Stoper(const Stoper &) = delete;
    Stoper(const Stoper &&) = delete;

    static void wypisz_czas(std::chrono::duration<double> &&czas){
        std::cout.precision(9);
        std::cout << std::fixed << czas.count() << std::endl;
    }

    static void zmierz_czas(unsigned int dane_wejsciowe, Iwykonaj &wyk,int opcjap=0,int opcjaw=0){
        auto t2 = std::chrono::high_resolution_clock::now();
        wyk.przygotuj(dane_wejsciowe,opcjap);
        auto t1 = std::chrono::high_resolution_clock::now();
        wyk.wykonaj(dane_wejsciowe,opcjaw);
        t2 = std::chrono::high_resolution_clock::now();
        wypisz_czas(
                std::chrono::duration_cast<std::chrono::duration<double>>(
                        t2 - t1));
    }
};

#endif /* INC_STOPER_HPP_ */
