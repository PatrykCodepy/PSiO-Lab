#include <iostream>
#include <string>
#include <conio.h>
#include "Header.h"

using namespace std;

int main()
{
    int end = 1;

    for(;;){
        Klasa objekt;
        objekt.opcje();
        objekt.metoda();

        _getch();
        system("cls");

    }
};