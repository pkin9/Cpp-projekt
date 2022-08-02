
class Orbit{
public:
    double semi_major_axis; //unit km
    double eccentricity; //unit km
    double mass; //mass of the object, unit kg

    Orbit(double semi_major_axis, double eccentricity, double mass);
    ~Orbit() = default;
    
};

