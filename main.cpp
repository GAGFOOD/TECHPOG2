#include <iostream>
#include "Konteiner.h"
#include "АЕRОFLОТ.h"
#include <fstream>
#include <sstream>

void printinfo(Konteiner<AEROFLOT> konteiner) {
    for (int i = 0; i < konteiner.getsize(); i++) {
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
            cout<<konteiner[i]<<endl;
        }
    }
    else {
        cout<<"No aircraft with  this type"<<endl;
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
        currentSentence += c;
        if (c == '.' || c == '!' || c == '?') {
            // Удаляем начальные пробелы
            size_t firstNonSpace = currentSentence.find_first_not_of(" \t\n\r");
            if (firstNonSpace != string::npos) {
                currentSentence = currentSentence.substr(firstNonSpace);
            }
            // Добавляем предложение в вектор, если оно не пустое
            if (!currentSentence.empty()) {
                sentences.push_back(currentSentence);
            }
            currentSentence.clear();
            // Если уже набрали три предложения - выходим
            if (sentences.getsize() >= 3) {
                break;
            }
        }
    }
    cout << "Sentences divided"<<endl;
    ofstream file2("1.txt");
    for (int i = sentences.getsize()-1; i>0; i--) {
        file2<<sentences[i]<<endl;
    }
    cout<<"Sentences write n the reverse order"<<endl;
}


int main() {

    return 0;
}