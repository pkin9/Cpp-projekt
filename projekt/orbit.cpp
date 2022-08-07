#include "orbit.hpp"
#include <iostream>
#include <armadillo>

void Velocity(double Standard_Gravitational_Parameter, double Distance, double Semi_xx_Axis) {
    double Velocity;
    Velocity = std::pow(Standard_Gravitational_Parameter * ((2 / Distance) - (1 / Semi_xx_Axis)), 0.5);
    std::cout << "Velocity: " << Velocity << " km/s\n";
}

double Distance(std::string name, double Semi_Major_Axis_AU, double Semi_Minor_Axis_AU) {
        double Distance, Distance_AU;
        if (name == "Periapsis") {
            Distance_AU = Semi_Major_Axis_AU - std::pow(Semi_Major_Axis_AU * Semi_Major_Axis_AU - Semi_Minor_Axis_AU * Semi_Minor_Axis_AU, 0.5);
            Distance = Distance_AU * 149597871;
        }
        else if (name == "Apoapsis") {
            Distance_AU = Semi_Major_Axis_AU + std::pow(Semi_Major_Axis_AU * Semi_Major_Axis_AU - Semi_Minor_Axis_AU * Semi_Minor_Axis_AU, 0.5);
            Distance = Distance_AU * 149597871;
        }
    
    std::cout << name << ": \n";
    std::cout << "Distance between the star (Sun) and Object: " << Distance << " km = " << Distance_AU << " a.u."<< std::endl;
    
    return Distance;
}

Orbit::Orbit(double Semi_Major_Axis, double Eccentricity) {

    double Semi_Minor_Axis_AU, Semi_Minor_Axis; //a.u., km
    double Distance_In_Apoapsis_AU, Distance_In_Apoapsis; //a.u., km
    double Distance_In_Periapsis_AU, Distance_In_Periapsis; //a.u., km
    double Mass_of_Sun = 1.989E30; //kg
    double Gravitational_Constant = 6.674E-11; //m^3 /kg * s^2
    double Standard_Gravitational_Parameter = Gravitational_Constant * Mass_of_Sun * 1E-9;;  // km ^ 3 / s^2
    double Semi_Major_Axis_AU = Semi_Major_Axis/149597871; //a.u.
    
    Semi_Minor_Axis_AU = Semi_Major_Axis_AU * std::pow(1 - (Eccentricity * Eccentricity), 0.5); //a.u.
    Semi_Minor_Axis = Semi_Major_Axis_AU * 149597871; //km

    std::cout << "Semi major axis: " << Semi_Major_Axis << " km = " << Semi_Major_Axis_AU << " a.u.\n"
        <<"Semi minor axis: " << Semi_Minor_Axis_AU * 149597871  << " km = " << Semi_Minor_Axis_AU << " a.u.\n" 
        << "Eccentricity: " << Eccentricity << std::endl
        << "Standard gravitational parameter: " << Standard_Gravitational_Parameter << " km^3/s^2\n" << std::endl;
    
    Distance_In_Periapsis = Distance("Periapsis", Semi_Major_Axis_AU, Semi_Minor_Axis_AU);
    Velocity(Standard_Gravitational_Parameter, Distance_In_Periapsis, Semi_Minor_Axis);
       
    Distance_In_Apoapsis = Distance("Apoapsis", Semi_Major_Axis_AU, Semi_Minor_Axis_AU);
    Velocity(Standard_Gravitational_Parameter, Distance_In_Apoapsis, Semi_Major_Axis);
     
    
};
