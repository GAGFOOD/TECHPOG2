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

    string getAircraftTypeString() const {
        switch (this->aircraftType) {
            case AircraftType::PassengerJet:
                return "PassengerJet";
            case AircraftType::PassengerTurboprop:
                return "PassengerTurboprop";
            case AircraftType::Cargo:
                return "Cargo";
            case AircraftType::BusinessJet:
                return "BusinessJet";
            case AircraftType::Regional:
                return "Regional";
            case AircraftType::GeneralAviation:
                return "GeneralAviation";
            case AircraftType::Helicopter:
                return "Helicopter";
            case AircraftType::MilitaryFighter:
                return "MilitaryFighter";
            case AircraftType::MilitaryTransport:
                return "MilitaryTransport";
            case AircraftType::UAV:
                return "UAV";
            case AircraftType::NONE:
                return "NONE";
            default:
                return "Unknown";
        }
    }
    bool operator<(const AEROFLOT& other) const {
        return destination < other.destination;
    }

    bool operator>(const AEROFLOT& other) const {
        return destination > other.destination;
    }

    bool operator==(const AEROFLOT& other) const {
        return destination == other.destination;
    }

    friend ostream& operator<<(ostream& os, const AEROFLOT& flight);
    friend istream& operator>>(istream& is, AEROFLOT& flight);
};

inline ostream& operator<<(ostream& os, const AEROFLOT& flight) {
    os << "Destination: " << flight.destination
    << ", Flight: " << flight.flightNumber
    << ", Aircraft: " << flight.getAircraftTypeString();
    return os;
}

// Реализация оператора ввода
inline istream& operator>>(istream& is, AEROFLOT& flight) {
    cout << "Enter destination:";
    is >> flight.destination;

    cout << "Enter flight number:";
    is >> flight.flightNumber;

    cout << "Enter aircraft type \n0-PassengerJet\n1-PassengerTurbopropn\n2-Cargon\n3-BusinessJet/n4-Regional\n5-GeneralAviation\n6-Helicopter\n7-MilitaryFighter\n8-MilitaryTransport\n9-UAV\n10-NONE\n>";
    int type;
    is >> type;
    flight.aircraftType = static_cast<AircraftType>(type);

    return is;
}

#endif //АЕRОFLОТ_H
