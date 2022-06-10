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
        end = 0;
        break;
    default:
        cout << "Nie ma takiej pozycji\n\n";
        break;
    };
}