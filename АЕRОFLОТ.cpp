//
// Created by kosti on 25.11.2025.
//

#include "АЕRОFLОТ.h"



void AEROFLOT::setAircraftType(int type) {
    this->aircraftType = static_cast<AircraftType>(type);
}
void AEROFLOT::setDestination(string destination) {
    this->destination = destination;
}
void AEROFLOT::setFlightNumber(long flightNumber) {
    this->flightNumber = flightNumber;
}
string AEROFLOT::getDestination() {
    return this->destination;
}
long AEROFLOT::getFlightNumber() {
    return this->flightNumber;
}
AircraftType AEROFLOT::getAircraftType() {
    return this->aircraftType;
}

string AEROFLOT::getAircraftTypeString() const {
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
bool AEROFLOT::operator<(const AEROFLOT& other) const {
    return destination < other.destination;
}

bool AEROFLOT::operator>(const AEROFLOT& other) const {
    return destination > other.destination;
}

bool AEROFLOT::operator==(const AEROFLOT& other) const {
    return destination == other.destination;
}

ostream& operator<<(ostream& os, const AEROFLOT& flight) {
    os << "Destination: " << flight.destination
    << ", Flight: " << flight.flightNumber
    << ", Aircraft: " << flight.getAircraftTypeString();
    return os;
}

// Реализация оператора ввода
istream& operator>>(istream& is, AEROFLOT& flight) {
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