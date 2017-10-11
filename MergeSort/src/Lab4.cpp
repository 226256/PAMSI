/*
 * Lab3.cpp
 *
 *  Created on: Apr 4, 2017
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

#include "../inc/Stoper.hpp"
#include "../inc/Wykonawcze/Kierownik.hpp"
int main(int argc, char *argv[]){
  try{
    Kierownik::kieruj(argc, argv);
  } catch (const PustaStruktura &e){
    std::cerr << e.what() << std::endl;
  } catch (const PozaZasiegStruktury &e){
    std::cerr << e.what() << std::endl;
  } catch (const NiewlasciwaStruktura &e){
    std::cerr << e.what() << std::endl;
  } catch (const BrakOpcjiDoFlagi &e){
    std::cerr << e.what() << std::endl;
  } catch (const NieznanaFlaga &e){
    std::cerr << e.what() << std::endl;
  } catch (const NieznanaOpcja &e){
    std::cerr << e.what() << std::endl;
  } catch (...){
    std::cerr << "Nieznany error" << std::endl;
  }
//    Wektor wek;
//    wek.wypelnij_losowo(100, 0, 100, 0);
//    wek.wypisz();
//    wek.sortprzezscalanie();
//    wek.wypisz();


}
