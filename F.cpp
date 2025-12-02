//
// Created by kosti on 02.12.2025.
//
#include "F.h"
void printinfo(Konteiner<AEROFLOT> konteiner) {
    for (int i = 0; i < konteiner.getsize(); i++) {
        cout <<i+1<<endl;
        cout<<konteiner[i]<<endl;
    }
}

int countTypeAircraft(Konteiner<AEROFLOT> konteiner, AircraftType aircraft) {
    int count = 0;
    for (int i = 0; i < konteiner.getsize(); i++) {
        if (konteiner[i].getAircraftType() == aircraft) {
            count++;
        }
    }
    return count;
}

void printByTypeAircraft(Konteiner<AEROFLOT> konteiner, AircraftType aircraft) {
    if (countTypeAircraft(konteiner, aircraft) >0) {
        for (int i = 0; i < konteiner.getsize(); i++) {
            if (konteiner[i].getAircraftType() == aircraft) {cout<<konteiner[i]<<endl;}
        }
    }
    else {
        cout<<"No aircraft with  this type"<<endl;
    }
}

void WorkWithAircraft(AEROFLOT &aeroflot) {
    while (true) {
        cout<<"Edit Aircraft"<<endl;
        cout<<aeroflot;
        cout<<"1.Edit destination"<<endl;
        cout<<"2.Edit flightNumber"<<endl;
        cout<<"3.Edit aircraftType"<<endl;
        cout<<"4.Edit exit"<<endl;
        int choice;
        cin>>choice;
        system("cls");
        switch (choice) {
            case 1: {
                cout<<"destination:"<<aeroflot.getDestination()<<endl;
                cout<<"Enter new destination:";
                string destination;
                cin>>destination;
                aeroflot.setDestination(destination);
                cout<<"Destination changed"<<endl;
                system("pause");
                system("cls");
                break;
            }
            case 2: {
                cout<<"flightNumber:"<<aeroflot.getFlightNumber()<<endl;
                cout<<"Enter new flightNumber:";
                long flightNumber;
                cin>>flightNumber;
                aeroflot.setFlightNumber(flightNumber);
                cout<<"flightNumber changed"<<endl;
                system("pause");
                system("cls");
                break;
            }
            case 3: {
                cout<<"aircraftType:"<<aeroflot.getAircraftType()<<endl;
                cout<<"Enter new aircraftType:";
                AircraftType aircraftType;
                int aiercraft;
                cin>>aiercraft;
                aircraftType=static_cast<AircraftType>(aiercraft);
                aeroflot.setAircraftType(aircraftType);
                cout<<"Aircraft type changed"<<endl;
                system("pause");
                system("cls");
                break;
            }
            case 4: {
                cout<<"Exit"<<endl;
                system("cls");
                system("pause");
                return;
            }
        }
    }
}



void WorkWithAeroFlot() {
    Konteiner<AEROFLOT> konteiner;
    AircraftType aircraft;
    while (true) {
        cout << "Work with Aeroflot"<<endl;
        int choice;
        cout<<"1.Add aircraft"<<endl;
        cout<<"2.Delete aircraft"<<endl;
        cout<<"3.Print all aircraft"<<endl;
        cout<<"4.Print aircraft with type"<<endl;
        cout<<"5.Edit aircraft"<<endl;
        cout<<"6.Exit"<<endl;
        cin>>choice;
        system("cls");
        switch (choice) {
            case 1: {
                AEROFLOT aeroflot;
                cin>>aeroflot;
                konteiner.push_back(aeroflot);
                cout<<"Aircraft added"<<endl;
                system("pause");
                system("cls");
                break;
            }
            case 2: {
                printinfo(konteiner);
                int aicraft;
                cout<<"Enter Aircraft number"<<endl;
                cin>>aicraft;
                konteiner.erase(aicraft);
                cout<<"Aircraft deleted"<<endl;
                system("pause");
                system("cls");
                break;
            }
            case 3: {
                printinfo(konteiner);
                system("pause");
                system("cls");
                break;
            }
            case 4: {
                cout << "Enter aircraft type (0-PassengerJet, 1-PassengerTurboprop, 2-Cargo, 3-BusinessJet, 4-Regional, 5-GeneralAviation, 6-Helicopter, 7-MilitaryFighter, 8-MilitaryTransport, 9-UAV, 10-NONE): ";
                int aircraft;
                cin>>aircraft;
                AircraftType aircraftType;
                aircraftType=static_cast<AircraftType>(aircraft);
                printByTypeAircraft(konteiner, aircraftType);
                system("pause");
                system("cls");
                break;
            }
            case 5: {
                printinfo(konteiner);
                int aicraft;
                cout<<"Enter Aircraft number"<<endl;
                cin>>aicraft;
                system("cls");
                WorkWithAircraft(konteiner[aicraft-1]);
                break;
            }
            case 6: {
                cout<<"Exit"<<endl;
                system("pause");
                system("cls");
                return;
            }
        }
    }
}

void fileandstringstream() {
    ifstream file("1.txt");
    cout << "File open"<<endl;;
    stringstream ss;
    ss<<file.rdbuf();
    string text = ss.str();
    cout << "File read"<<endl;
    file.close();
    size_t start = 0;
    size_t end = 0;
    int sentenceCount = 0;
    Konteiner<string> sentences;
    string currentSentence;
    for (char c : text) {
        cout <<c;
    }
    for (char c : text) {
        currentSentence += c;
        if (c == '.' || c == '!' || c == '?') {
            size_t firstNonSpace = currentSentence.find_first_not_of(" \t\n\r");
            if (firstNonSpace != string::npos) {
                currentSentence = currentSentence.substr(firstNonSpace);
            }
            if (!currentSentence.empty()) {
                sentences.push_back(currentSentence);
            }
            currentSentence.clear();
            if (sentences.getsize() >= 3) {
                break;
            }
        }
    }
    cout << "Sentences divided"<<endl;
    ofstream file2("1.txt");
    for (int i = sentences.getsize()-1; i>=0; i--) {
        file2<<sentences[i]<<endl;
    }
    cout<<"Sentences write n the reverse order"<<endl;
}