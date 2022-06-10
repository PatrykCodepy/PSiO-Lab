#include <iostream>
#include "Header.h"
#include <conio.h>
#include <string>
#include <cstring>

using namespace std;

void Klasa::metoda()
{
    cin >> select;
    switch (select)
    {
    case 1:
        system("start cmd.exe");
        cout << "WIERSZ POLECEN URUCHOMIONY";
        break;
    case 2:
        system("start regedit.exe");
        cout << "EDYTOR REJESTRU URUCHOMIONY";
        break;
    case 3:
    {
        string commend = "ping ";
        string addres;
        cout << "Podaj adres IP: ";
        cin >> addres;
        commend += addres;
        const char* com = commend.c_str();
        system(com);
        break;
    }
    case 4:
        system("start calc.exe");
        break;
    case 0:
        //system("start exit.exe");
        exit(1);
        break;
    default:
        cout << "Nie ma takiej pozycji\n\n";
        break;
    };
}

void Klasa::opcje()
{
    cout << "\t\t\t\tWitaj!\n\n";
    cout << "\t\tABY ZAKONCZYC WPISZ 0 I WCISNIJ ENTER\n\n";

    cout << "Wybierz co ma zrobic program\n\n";
    cout << "1. Uruchom WIERSZ POLECEN\t\t\t2. Uruchom EDYTOR REJESTRU\n";
    cout << "3. Uruchom PING\t\t\t4. Uruchom KALKURATOR\n";

    cout << "\n\n\n\n\n\n";
}