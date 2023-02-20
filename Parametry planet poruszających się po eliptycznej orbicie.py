import math as mt

gravitational_constant = 6.674 * 10 ** (-11) #m^3 /kg * s^2
mass_of_sun = 1.9893 * 10 ** 30 #kg


class Orbit:
    def __init__(self, semi_major_axis, eccentricity):
        self.semi_major_axis = semi_major_axis #km
        self.semi_major_axis_AU = semi_major_axis / 149597871
        self.eccentricity = eccentricity
        self.standard_gravitational_parameter = gravitational_constant * mass_of_sun * 10 ** (-9) #km ^ 3 / s^2
        self.semi_minor_axis = semi_major_axis * mt.sqrt(1 - (eccentricity * eccentricity)) #km
        self.semi_minor_axis_AU = semi_major_axis / 149597871
        self.distance_at_periapsis = semi_major_axis - mt.sqrt(semi_major_axis * semi_major_axis - self.semi_minor_axis * self.semi_minor_axis) #km
        self.distance_at_apoapsis = semi_major_axis + mt.sqrt(semi_major_axis * semi_major_axis - self.semi_minor_axis * self.semi_minor_axis) #km
        self.distance_at_periapsis_AU = self.distance_at_periapsis / 149597871
        self.distance_at_apoapsis_AU = self.distance_at_apoapsis / 149597871
        self.velocity_at_periapsis = mt.sqrt(self.standard_gravitational_parameter * ((2 / self.distance_at_periapsis) - (1 / self.semi_minor_axis))) #km/s
        self.velocity_at_apoapsis = mt.sqrt(self.standard_gravitational_parameter * ((2 / self.distance_at_apoapsis) - (1 / self.semi_major_axis))) #km/s

    def __str__(self):
        return f"Standard gravitational parameter = {self.standard_gravitational_parameter} km ^ 3 / s^2\n" \
               f"Semi major axis = {self.semi_major_axis} km = {self.semi_major_axis_AU} AU\n " \
               f"Semi minor axis = {self.semi_minor_axis} km = {self.semi_minor_axis_AU} AU\n " \
               f"Eccentricity is {self.eccentricity}\n" \
               f"Distance between the star (Sun) and Object at Periapsis = {self.distance_at_periapsis} km = {self.distance_at_periapsis_AU} AU\n" \
               f"Distance between the star (Sun) and Object at Apoapsis = {self.distance_at_apoapsis} km = {self.distance_at_apoapsis_AU} AU\n " \
               f"Velocity at Periapsis = {self.velocity_at_periapsis} km/s\n" \
               f"Velocity at Apoapsis = {self.velocity_at_apoapsis} km/s"

    def __repr__(self):
        return f"Orbit(standard_gravitational_parameter={self.standard_gravitational_parameter}," \
               f"semi_major_axis={self.semi_major_axis}, " \
               f"semi_major_axis_AU={self.semi_major_axis_AU}, " \
               f"semi_minor_axis={self.semi_minor_axis}, " \
               f"semi_minor_axis_AU={self.semi_minor_axis_AU}, " \
               f"eccentricity={self.eccentricity}" \
               f"distance_at_periapsis={self.distance_at_periapsis}," \
               f"distance_at_periapsis_AU={self.distance_at_periapsis_AU}," \
               f"distance_at_apoapsis={self.distance_at_apoapsis}," \
               f"distance_at_apoapsis_AU={self.distance_at_apoapsis_AU}," \
               f"velocity_at_periapsis={self.velocity_at_periapsis}," \
               f"velocity_at_apoapsis={self.velocity_at_apoapsis})" \


print("Options: \n"
      "m - Mercury\n"
      "v - Venus\n"
      "e - Earth\n"
      "a - Mars\n"
      "j - Jupiter\n"
      "s - Saturn\n"
      "u - Uranus\n"
      "n - Neptune\n"
      "p - Pluto \n")

option = str(input("Choose your option:"))

if option == 'm': #Merkury
    print(Orbit(57894376, 0.2056))

elif option == 'v': #Venus
    print(Orbit(108159260, 0.0068))

elif option == 'e': #Earth
    print(Orbit(149597871, 0.0167))

elif option == 'a': #Mars
    print(Orbit(227987155, 0.0934))

elif option == 'j': #Jupiter
    print(Orbit(778357722, 0.0484))

elif option == 's': #Saturn
    print(Orbit(1426714896, 0.0542))

elif option == 'u': #Uranus
    print(Orbit(2870932742, 0.0472))

elif option == 'n': #Neptune
    print(Orbit(4498258383, 0.0086))

elif option == 'p': #Pluto
    print(Orbit(5906423143, 0.2488))

else:
    print("nieznana operacja")
