/**
 *   Prosjekt oppgave i PROG1003
 *
 *   Programmet fungerer som et program for eiendomsmeglere,
 *   hvor man kan registrere kunder, boligomr�der, og oppdrag/boliger.
 *
 *   @file     main.cpp
 *   @date     13.04.2020
 *   @author   J�rgen Eriksen
 */

#include <iostream>      // cout
#include <string>        // string
#include<bits/stdc++.h>  // stringstream
#include "Kunder.h"
#include "Soner.h"
#include "Funksjoner.h"
#include "LesData3.h"

using namespace std;

Kunder* gKunder;
Soner* gSoner;

/**
 *  Hovedprogrammet
 */
int main(){
    string input;
    char forsteKommando;
    char andreKommando;
    int nummer;

    gKunder = new Kunder;
    gSoner = new Soner;

    lesFraFil();

    cout << "\nKommando: ";
    getline(cin, input);
    stringstream kommando(input);
    kommando >> forsteKommando;   // f�rste tegn
    kommando >> andreKommando;    // andre tegn
    kommando >> nummer;           // evt. tredje tegn
    forsteKommando = toupper(forsteKommando);
    andreKommando = toupper(andreKommando);

    while (forsteKommando != 'Q') {
        switch (forsteKommando) {
            case 'K':   kunde(andreKommando, nummer);    break;
            case 'S':   sone(andreKommando, nummer);     break;
            case 'O':   oppdrag(andreKommando, nummer);  break;
            default:    skrivMeny();
        }

        // gj�r kommandoene blank, s� verdien ikke henger igjen om brukeren bare trykker enter f.eks.
        forsteKommando = ' ';
        andreKommando = ' ';
        nummer = 0;

        cout << "\nKommando: ";
        getline(cin, input);
        stringstream kommando(input);
        kommando >> forsteKommando;  // f�rste tegn
        kommando >> andreKommando;   // andre tegn
        kommando >> nummer;          // evt. tredje tegn
        forsteKommando = toupper(forsteKommando);
        andreKommando = toupper(andreKommando);
    }

    skrivTilFil(); // skriver ut data til KUNDER-DTA og SONER.DTA
}
