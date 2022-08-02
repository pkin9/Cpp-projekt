#include <iostream>

#include "orbit.hpp"

int main() {
    //Object sun("Sun", 1.989E30, 695510E3, 0, 0); 
    char option;

    std::cout << "Options: \nm - Mercury\nv - Venus\ne - Earth\na - Mars\nj - Jupiter\ns - Saturn\nu - Uranus\nn - Neptune\np - Pluto \n";
    std::cin >> option;

    switch (option) {
        case 'm': //Mercury
            Orbit(57894376, 0.2056, 3.30263E23);
            break;
        case 'v': //Venus
            Orbit(108159260, 0.0068, 4.86734E24);
            break;
        case 'e': //Earth
            Orbit(149597871, 0.0167, 5.9722E24);
            break;
        case 'a': //Mars
            Orbit(227987155, 0.0934, 6.39025E23);
            break; 
        case 'j': //Jupiter
            Orbit(778357722, 0.0484, 1.89814E27);
            break; 
        case 's': //Saturn
            Orbit(1426714896, 0.0542, 5.68309E26);
            break;
        case 'u': //Uranus
            Orbit(2870932742, 0.0472, 8.68119E25);
            break;
        case 'n': //Neptune
            Orbit(4498258383, 0.0086, 1.02405E26);
            break;
        case 'p': //Pluto
            Orbit(5906423143, 0.2488, 1.25416E22);
            break;
        default:
            std::cout << "nieznana operacja\n";
            return 1;
    }
     
     
     
    
    
     
 





}