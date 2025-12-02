//
// Created by kosti on 25.11.2025.
//
#ifndef АЕRОFLОТ_H
#define АЕRОFLОТ_H
#include <string>
#include <iostream>
using namespace std;

enum AircraftType {
    PassengerJet,      // Пассажирский реактивный самолет
    PassengerTurboprop,// Пассажирский турбовинтовой самолет
    Cargo,             // Грузовой самолет
    BusinessJet,       // Бизнес-джет
    Regional,          // Региональный самолет
    GeneralAviation,   // Самолет общей авиации
    Helicopter,        // Вертолет
    MilitaryFighter,   // Военный истребитель
    MilitaryTransport, // Военный транспортник
    UAV,               // Беспилотный летательный аппарат
    NONE
};

class AEROFLOT {
private:
    string destination;
    long flightNumber;
    AircraftType aircraftType;
public:
    void setAircraftType(int type);
    void setDestination(string destination);
    void setFlightNumber(long flightNumber);
    string getDestination();
    long getFlightNumber();
    AircraftType getAircraftType();
    string getAircraftTypeString() const;
    bool operator<(const AEROFLOT& other) const;
    bool operator>(const AEROFLOT& other) const;
    bool operator==(const AEROFLOT& other) const;
    friend ostream& operator<<(ostream& os, const AEROFLOT& flight);
    friend istream& operator>>(istream& is, AEROFLOT& flight);
};



#endif //АЕRОFLОТ_H
