#include <iostream>
#include "F.h"

int main() {
    while (true) {
        cout<<"Aeroflot or  File/string stream\n(1-Aeroflot,2-FSstream,3-exit):";
        int choice;
        cin>>choice;
        system("cls");
        if (choice == 1) {
            WorkWithAeroFlot();
            system("cls");
        }
        else if (choice == 2) {
            fileandstringstream();
            system("pause");
            system("cls");
        }
        else if (choice == 3) {
            cout<<"Exit"<<endl;
            system("pause");
            system("cls");
            break;
        }
    }
    system("pause");
    return 0;
}