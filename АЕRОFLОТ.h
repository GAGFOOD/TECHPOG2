//
// Created by kosti on 25.11.2025.
//
#ifndef АЕRОFLОТ_H
#define АЕRОFLОТ_H
#include <string>
#include <iostream>
using namespace std;

enum class AircraftType {
    PassengerJet,      // Пассажирский реактивный самолет
    PassengerTurboprop,// Пассажирский турбовинтовой самолет
    Cargo,             // Грузовой самолет
    BusinessJet,       // Бизнес-джет
    Regional,          // Региональный самолет
    GeneralAviation,   // Самолет общей авиации
    Helicopter,        // Вертолет
    MilitaryFighter,   // Военный истребитель
    MilitaryTransport, // Военный транспортник
    UAV                // Беспилотный летательный аппарат
};



class AEROFLOT {
private:
    string destination;
    long flightNumber;
    AircraftType aircraftType;
public:
    void setAircraftType(int type) {
        this->aircraftType = static_cast<AircraftType>(type);
    }
    void setDestination(string destination) {
        this->destination = destination;
    }
    void setFlightNumber(long flightNumber) {
        this->flightNumber = flightNumber;
    }
    string getDestination() {
        return this->destination;
    }
    long getFlightNumber() {
        return this->flightNumber;
    }
    AircraftType getAircraftType() {
        return this->aircraftType;
    }


    friend ostream& operator<<(ostream& os, const AEROFLOT& flight);
    friend istream& operator>>(istream& is, AEROFLOT& flight);
};
ostream& operator<<(ostream& os, const AEROFLOT& flight) {
    os << "Destination: " << flight.destination
       << ", Flight: " << flight.flightNumber
       << ", Aircraft: " << flight.getAircraftTypeString();
    return os;
}

// Реализация оператора ввода
istream& operator>>(istream& is, AEROFLOT& flight) {
    cout << "Enter destination: ";
    is >> flight.destination;

    cout << "Enter flight number: ";
    is >> flight.flightNumber;

    cout << "Enter aircraft type (0-Boeing737, 1-AirbusA320, 2-Boeing777, 3-AirbusA380, 4-SukhoiSuperjet): ";
    int type;
    is >> type;
    flight.setAircraftType(type);

    return is;
}

#endif //АЕRОFLОТ_H
