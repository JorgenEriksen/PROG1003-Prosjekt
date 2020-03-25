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

    kommando = lesChar("\nKommando");

    while (kommando != 'Q') {
        switch (kommando) {
            case 'N':   nyKunde(); break;
            case 'A':   visAlleKunder(); break;
            case 'B':   visEnkeltKunde(); break;
            case 'C':   nySone(); break;
            case 'D':   visAlleSoner(); break;
            case 'E':   visEnkeltSoner(); break;
            case 'X':   break;
        }
        kommando = lesChar("\nKommando");
    }


}
