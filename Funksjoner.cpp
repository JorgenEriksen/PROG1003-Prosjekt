 /**
 *   @file     Funksjoner.cpp
 *   @author   Jørgen Eriksen
 */

#include <iostream>
#include <string>
#include <fstream>  //   ifstream, ofstream
#include <sstream>  //   istringstream
#include "Kunder.h"
#include "Soner.h"
#include "Funksjoner.h"
#include "Const.h"
using namespace std;

extern Kunder* gKunder;
extern Soner* gSoner;

/**
 *  leser inn data fra KUNDER.DTA og SONER.DTA
 *
 * @see Kunder::leggTil(...)
 * @see Kunder::leggTilOppdrag(...)
 */
void lesFraFil(){
    // sjekker ikke et feil format/data i DTA, da det er kontrolert at det som blir lagret i DTA er feilfritt.
    int soneNr;
    string tegn;
    ifstream innfilSoner("SONER.DTA");
    ifstream innfilKunder("KUNDER.DTA");

    if(innfilSoner){                            //  ifstream, ofstream // om SONER.DTA ble funnet
        innfilSoner >> tegn;                     // leser første tegn i filen
        innfilSoner.ignore();                    // ignorerer mellomrom.
        while(!innfilSoner.eof()){
            istringstream(tegn) >> soneNr;        // leser sonenummer
            gSoner->leggTil(soneNr, innfilSoner); // legger til ny sone
            innfilSoner >> tegn;                  // leser inn tegn
            while(tegn == "b" && !innfilSoner.eof()){ // hvis tegn er 'b' (altså bolig) og mer data igjen i SONER.DTA
                gSoner->leggTilOppdrag(soneNr, innfilSoner); // legger til bolig/oppdrag
                innfilSoner >> tegn;                         // leser inn tegn
                innfilSoner.ignore();                        // ignorerer mellomrom.
            }
        }
    } else {                                      // om SONER.DTA IKKE ble funnet
        cout << "\nFANT IKKE SONER.DTA!";
    }

    if(innfilKunder){                             // om KUNDER.DTA ble funnet
       while(!innfilKunder.eof()){                // så lenge det er mer data igjen i KUNDER.DTA
            gKunder->leggTil(innfilKunder);       // legger til ny kunde
       }
    } else {                                      // om KUNDER.DTA IKKE ble funnet
        cout << "\nFANT IKKE KUNDER.DTA!";
    }
}


/**
 *  kjører funksjoner for kunder etter hvilke kommando(er) brukeren har skrevet
 *
 *  @param   kommando - tegn som bestemmer hvilken funksjon som skal kjøres
 *  @param   nr - kundenummer
 *  @see     Kunder::leggTil()
 *  @see     Kunder::visEnKunde(...)
 *  @see     Kunder::visAlle()
 *  @see     Kunder::endreKunde(...)
 *  @see     Kunder::slettKunde(...)
 *  @see     Kunder::skrivOversiktTilFil(...)
 *  @see     skrivMeny()
 */
void kunde(char kommando, int nr){
    switch(kommando){
        case 'N': gKunder->leggTil();               break;
        case '1': gKunder->visEnKunde(nr);          break;
        case 'A': gKunder->visAlle();               break;
        case 'E': gKunder->endreKunde(nr);          break;
        case 'S': gKunder->slettKunde(nr);          break;
        case 'O': gKunder->skrivOversiktTilFil(nr); break;
        default: skrivMeny();
    }

}

/**
 *  kjører funksjoner for soner etter hvilke kommando(er) brukeren har skrevet
 *
 *  @param   kommando - tegn som bestemmer hvilken funksjon som skal kjøres
 *  @param   nr - sonenummer
 *  @see     Soner::leggTil(...)
 *  @see     Soner::visEnSone(...)
 *  @see     Soner::visAlle()
 *  @see     skrivMeny()
 */
void sone(char kommando, int nr){
    switch(kommando){
        case 'N':
            if(nr <= MAXSONER && nr > 0) gSoner->leggTil(nr);  // om
            else cout << "\nsonenummer må være fra 1 til og med " << MAXSONER;
            break;
        case '1':
            if(nr <= MAXSONER && nr > 0) gSoner->visEnSone(nr);
            else cout << "\nsonenummer må være fra 1 til og med " << MAXSONER;
            break;
        case 'A': gSoner->visAlle(); break;
        default: skrivMeny();
    }

}

/**
 *  kjører funksjoner for boliger/oppdrag etter hvilke kommando(er) brukeren har skrevet
 *
 *  @param   kommando - tegn som bestemmer hvilken funksjon som skal kjøres
 *  @param   nr - soneenummer evt oppdragsnummer
 *  @see     Soner::leggTilOppdrag(...)
 *  @see     Soner::visOppdrag(...)
 *  @see     Soner::slettOppdrag(..)
 *  @see     skrivMeny()
 */
void oppdrag(char kommando, int nr){
    switch(kommando){
        case 'N':
            if(nr <= MAXSONER && nr > 0) gSoner->leggTilOppdrag(nr);
            else cout << "\nsonenummer må være fra 1 til og med " << MAXSONER;
            break;
        case '1':
            if(nr <= MAXOPPDRAG && nr > 0) gSoner->visOppdrag(nr);
            else cout << "\nsonenummer må være fra 1 til og med " << MAXOPPDRAG;
            break;
        case 'S':
            if(nr <= MAXOPPDRAG && nr > 0) gSoner->slettOppdrag(nr);
            else cout << "\nsonenummer må være fra 1 til og med " << MAXOPPDRAG;
            break;
        default: skrivMeny();
    }
}

/**
 *  skriver ut data til KUNDER.DTA og SONER.DTA
 *
 *  @see     Soner::skrivTilFil(...)
 *  @see     Kunder::skrivTilFil(...)
 */
void skrivTilFil(){
    ofstream utfilSoner("SONER.DTA");
    ofstream utfilKunder("KUNDER.DTA");
    gSoner->skrivTilFil(utfilSoner);
    gKunder->skriTilFil(utfilKunder);
}

/**
 *  Skriver ut programmets menyvalg/muligheter
 */
void skrivMeny(){
    cout << "\nalle kommandoer";
    cout << "\nK N \t\t-> oppretter ny kunde";
    cout << "\nK 1 <knr> \t-> skriver ut all data fra kunde <knr> ";
    cout << "\nK A \t\t-> skriver ut alle kunder";
    cout << "\nK E <knr> \t-> endrer kunde <knr>";
    cout << "\nK S <knr> \t-> sletter kunde <knr>";
    cout << "\nK O <knr> \t-> lagrer all kunde data fra kunde <knr> i fil K<knr>.DTA";

    cout << "\nS N <snr> \t-> oppretter ny sone";
    cout << "\nS 1 <snr> \t-> skriver ut alle info om alle oppdrag på sone <snr>";
    cout << "\nS A \t\t-> skriver ut alle soner";

    cout << "\nO N <snr> \t-> oppretter nytt oppdrag knyttet til sone <snr>";
    cout << "\nO 1 <onr> \t-> skriver ut all info om oppdrag <onr>";
    cout << "\nO S <onr> \t-> sletter oppdrag <onr>";
}

