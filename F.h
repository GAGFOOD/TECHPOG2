//
// Created by kosti on 02.12.2025.
//

#ifndef F_H
#define F_H
#include <iostream>
#include "Konteiner.h"
#include "АЕRОFLОТ.h"
#include <fstream>
#include <sstream>
void printinfo(Konteiner<AEROFLOT> konteiner);
int countTypeAircraft(Konteiner<AEROFLOT> konteiner, AircraftType aircraft);
void printByTypeAircraft(Konteiner<AEROFLOT> konteiner, AircraftType aircraft);
void WorkWithAircraft(AEROFLOT &aeroflot);
void WorkWithAeroFlot();
void fileandstringstream();
#endif //F_H
