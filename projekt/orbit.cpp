#include "orbit.hpp"
#include <iostream>
#include <armadillo>

void Velocity(double Standard_Gravitational_Parameter, double Distance, double Semi_xx_Axis) {
    double Velocity;
    Velocity = std::pow(Standard_Gravitational_Parameter * ((2 / Distance) - (1 / Semi_xx_Axis)), 0.5);
    std::cout << "Velocity: " << Velocity << " km/s\n";
}

void Distance(std::string name, double Distance, double Distance_AU) {
    std::cout << name << ": \n";
    std::cout << "Distance between the star (Sun) and Object: " << Distance << " km = " << Distance_AU << " a.u."<< std::endl;
}

Orbit::Orbit(double Semi_Major_Axis, double Eccentricity, double Mass) {

    double Semi_Minor_Axis_AU, Semi_Minor_Axis; //a.u., km
    double Distance_In_Apoapsis_AU, Distance_In_Apoapsis; //a.u., km
    double Distance_In_Perapsis_AU, Distance_In_Perapsis; //a.u., km
    double Mass_of_Sun = 1.989E30; //kg
    double Standard_Gravitational_Parameter;  // km ^ 3 / s^2
    double Gravitational_Constant = 6.674E-11; //m^3 /kg * s^2
    
    double Semi_Major_Axis_AU = Semi_Major_Axis/149597871; //a.u.
    

    Semi_Minor_Axis_AU = Semi_Major_Axis_AU * std::pow(1 - (Eccentricity * Eccentricity), 0.5); //a.u.
    Semi_Minor_Axis = Semi_Major_Axis_AU * 149597871; //km
    Standard_Gravitational_Parameter = Gravitational_Constant * (Mass + Mass_of_Sun) * 1E-9; 

    std::cout << "Semi major axis: " << Semi_Major_Axis << " km = " << Semi_Major_Axis_AU << " a.u.\n"
        <<"Semi minor axis: " << Semi_Minor_Axis_AU * 149597871  << " km = " << Semi_Minor_Axis_AU << " a.u.\n" 
        << "Eccentricity: " << Eccentricity << std::endl
        << "Standard gravitational parameter: " << Standard_Gravitational_Parameter << " km^3/s^2\n" << std::endl;
    
    Distance_In_Perapsis_AU = Semi_Major_Axis_AU - std::pow(Semi_Major_Axis_AU * Semi_Major_Axis_AU - Semi_Minor_Axis_AU * Semi_Minor_Axis_AU, 0.5);
    Distance_In_Perapsis = Distance_In_Perapsis_AU * 149597871;
    Distance("Perapsis", Distance_In_Perapsis, Distance_In_Perapsis_AU);
    Velocity(Standard_Gravitational_Parameter, Distance_In_Perapsis, Semi_Minor_Axis);
       
    Distance_In_Apoapsis_AU = Semi_Major_Axis_AU + std::pow(Semi_Major_Axis_AU * Semi_Major_Axis_AU - Semi_Minor_Axis_AU * Semi_Minor_Axis_AU, 0.5);
    Distance_In_Apoapsis = Distance_In_Apoapsis_AU * 149597871;
    Distance("Apoapsis", Distance_In_Apoapsis, Distance_In_Apoapsis_AU);
    Velocity(Standard_Gravitational_Parameter, Distance_In_Apoapsis, Semi_Major_Axis);
    
};
