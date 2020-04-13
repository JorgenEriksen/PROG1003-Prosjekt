 /**
 *   @file     Soner.cpp
 *   @author   Jørgen Eriksen
 */

#include <iostream>
#include "LesData3.h"
#include "Soner.h"
#include "Sone.h"
using namespace std;

/**
 *  Leser datamedlemmer fra fil
 *
 *  @param   soneNr - sonenummer
 *  @param   inn - filen det leses inn fra
 */
void Soner :: leggTil(int soneNr, ifstream & inn){
    Sone* nySone = new Sone(soneNr, inn);
    sone.insert(pair <int, Sone*>(soneNr, nySone));
}

/**
 *  Leser datamedlemmer
 *
 *  @param   soneNr - sonenummer
 */
void Soner :: leggTil(int soneNr){
    auto it = sone.find(soneNr);
    if(it != sone.end()){                               // om sonen eksisterer allerede
        cout << "\ndenne sonen eksisterer allerede";
    } else {                                            // om sonen IKKE eksisterer allerede
        Sone* nySone = new Sone(soneNr);                // oppretter ny sone
        sone.insert(pair <int, Sone*>(soneNr, nySone)); // legger soneNr og sonen inn i map 'sone'
    }

};

/**
 *  viser alle boliger/oppdrag på sonen
 *
 *  @param   soneNr - sonenummer
 */
void Soner :: visEnSone(int soneNr){
    auto it = sone.find(soneNr);

    if(it != sone.end()){
        for (const auto & val : sone){
            if(val.first == soneNr){
                (val.second)->visAlleBoliger();
            }
        }
    } else { // om den ikke fant sonen
        cout << "\nfant ingen soner med sonenummer " << soneNr;
    }

}

/**
 *  skriver ut all soner
 */
void Soner :: visAlle(){
    for (const auto & val : sone){
        (val.second)->skrivHovedData();
    }
}


/**
 *  sjekker om sone eksisterer
 *
 * @param  soneNr - sonenummer
 * @return true om sone eksisterer
 */
bool Soner :: omSoneEksisterer(int soneNr){
    auto it = sone.find(soneNr);
    if(it != sone.end()){
        return true;
    }
    return false;
}


/**
 *  Skriver alle datamedlemmer til fil
 *
 *  @param   ut - filen det skrives til
 */
void Soner :: leggTilOppdrag(int soneNr, ifstream & inn){
    auto it = sone.find(soneNr);
    sisteNr++;
    (it->second)->nyBolig(inn);

}


/**
 *  registrerer og leser inn datamedlemmer til bolig/oppdrag
 *
 *  @param   soneNr - sonenummer
 */
void Soner :: leggTilOppdrag(int soneNr){
    auto it = sone.find(soneNr);
    if(it != sone.end()){
        for (const auto & val : sone){
            if(val.first == soneNr){
                sisteNr++;
                (val.second)->nyBolig(sisteNr);

            }
        }
    } else {
        cout << "\nsone " << soneNr << " eksisterer ikke";
    }
}


/**
 *  skriver ut datamedlemmer til bolig/oppdrag
 *
 *  @param   boligNr - bolignummer/oppdragsnummer
 */
void Soner :: visOppdrag(int boligNr){
    bool boligFunnet = false;
    for (const auto & val : sone){
        if((val.second)->visBolig(boligNr)){
            boligFunnet = true;
        }
    }

    if(!boligFunnet){  // vis bolignummer/oppdragsnummer ikke eksisterer
        cout << "\nFant ikke oppdrag med oppdragsnummer " << boligNr;
    }

}

/**
 *  skriver ut datamedlemmer til bolig/oppdrag
 *
 *  @param   boligNr - bolignummer
 */
void Soner :: slettOppdrag(int boligNr){
    char svar = lesChar("er du sikker på at du vil slette denne? (Y/N)");
    if(svar == 'Y'){
        bool boligFunnet = false; // denne blir endret om boligen blir funnet;
        for (const auto & val : sone){
            if((val.second)->slettBolig(boligNr)){ // vis den fant og slettet boligen/oppdraget
                boligFunnet = true;
                cout << "\nOppdrag " << boligNr << " er slettet!";
            }
        }

        if(!boligFunnet){  // vis bolignummer/oppdragsnummer ikke eksisterer
            cout << "\nFant ikke oppdrag med oppdragsnummer " << boligNr;
        }
    } else {
        cout << "\navbryter sletting!";
    }
}

/**
 *  skriver ut datamedlemmer til sone med alle bolig/oppdrag til unik fil
 *
 *  @param   soneNr - sonenummer
 *  @param   ut - filen det skrives til
 */
void Soner :: skrivOversiktTilFil(int soneNr, ofstream & ut){
    for (const auto & val : sone){
        if(val.first == soneNr){
            (val.second)->skrivOversiktTilFil(ut);
        }
    }
}

/**
 *  skriver ut datamedlemmer til alle soner med bolig/oppdrag til fil
 *
 *  @param   ut - filen det skrives til
 */
void Soner :: skrivTilFil(ofstream & ut){
    for (const auto & val : sone){
        (val.second)->skrivTilFil(ut);
    }
}


