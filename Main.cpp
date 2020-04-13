/**
 *   Prosjekt oppgave i PROG1003
 *
 *   Programmet fungerer som et program for eiendomsmeglere,
 *   hvor man kan registrere kunder, boligomr�der, og oppdrag/boliger, og knytte de opp mot hverandre.
 *   Programmet lagrer ogs� all data i KUNDER.DTA og SONER.DTA n�r programmet avsluttes.
 *   Disse dataene blir automatisk lest inn n�r programmet starter opp igjen.
 *
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

    lesFraFil(); // henter data fra KUNDER.DTA og SONER.DTA

    cout << "\nKommando: ";
    getline(cin, input);          // leser inn kommando
    stringstream kommando(input); // endrer kommandoen fra string til stringstream
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
        getline(cin, input);          // leser inn kommando
        stringstream kommando(input); // endrer kommandoen fra string til stringstream
        kommando >> forsteKommando;   // f�rste tegn
        kommando >> andreKommando;    // andre tegn
        kommando >> nummer;           // evt. tredje tegn
        forsteKommando = toupper(forsteKommando);
        andreKommando = toupper(andreKommando);
    }

    skrivTilFil(); // skriver ut data til KUNDER.DTA og SONER.DTA
}
