/**
 *
 *
 *
 *   @file     main.cpp
 *   @author   Jørgen Eriksen
 */


#include <iostream>

#include "Kunder.h"
#include "Soner.h"
#include "Funksjoner.h"
#include "LesData3.h"

using namespace std;

Kunder* gKunder;
Soner* gSoner;

int main(){

    char kommando;

    gKunder = new Kunder;
    gSoner = new Soner;

    // cin >> aar >> ant;
    // cin.ignore();

    kommando = lesChar("\nKommando");

    while (kommando != 'Q') {
        switch (kommando) {
            case 'A':   nyKunde(); break;
            case 'B':   visEnkeltKunde(); break;
            case 'C':   visAlleKunder(); break;
            case 'D':   endreKunde(); break;
            case 'E':   slettKunde(); break;
            case 'F':   kundeOversikt(); break;

            case 'G':   nySone(); break;
            case 'H':   visEnkeltSoner(); break;
            case 'I':   visAlleSoner(); break;

            case 'J':   nyttOppdrag(); break;
            case 'K':   visEnkeltOppdrag(); break;
            case 'L':   slettOppdrag(); break;
            default:    skrivMeny();
        }
        kommando = lesChar("\nKommando");
    }


}
