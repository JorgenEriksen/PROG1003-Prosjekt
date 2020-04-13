 /**
 *   @file     Sone.cpp
 *   @author   Jørgen Eriksen
 */

#include <iostream>
#include <string>
#include <map>
#include "LesData3.h"
#include "Sone.h"
#include "Bolig.h"
#include "Enebolig.h"
using namespace std;

/**
 *  Leser inne alle datamedlemmer fra fil
 *
 *  @param   soneNr - sonens unike kundenummer
 *  @param   inn - filen det leses inn fra
 */
Sone :: Sone(int soneNr, ifstream & inn){
    idNummer = soneNr;
    getline(inn, beskrivelse);

};

/**
 *  Leser inne alle datamedlemmer
 *
 *  @param   soneNummer - sonens unike kundenummer
 */
Sone :: Sone(int soneNummer){
    idNummer = soneNummer;
    cout << "\nSkriv inn en beskrivelse for sone " << idNummer << ": ";
    getline(cin, beskrivelse);
};

/**
 *  Skriver ut sonenummer og beskrivelse
 */
void Sone :: skrivHovedData(){
    cout << "\nSone " << idNummer << ":";
    cout << "\nBeskrivelse: " << beskrivelse;
};


/**
 *  Leser inn datamedlemmer til bolig fra fil
 *
 *  @param   inn - filen det leses inn fra
 */
void Sone :: nyBolig(ifstream & inn){
    char boligType;
    Bolig* nyBolig;

    inn >> boligType;
    switch(boligType){
        case 'L': nyBolig = new Bolig(inn);      break;     // leilighet
        case 'E': nyBolig = new Enebolig(inn);   break;     // enebolig
    }
    bolig.push_back(nyBolig);
}

/**
 *  Leser inn datamedlemmer til bolig/oppdrag
 *
 *  @param   sisteNr - boligens/oppdragets unike nummer
 */
void Sone :: nyBolig(int sisteNr){
    char svar;
    //sisteNr++;
    Bolig* nyBolig;
    do{
        svar = lesChar("Opprette leilighet eller enebolig? (L/E)");
    } while (svar != 'L' && svar != 'E');

    switch(svar){
        case 'L': nyBolig = new Bolig(sisteNr);      break;     // leilighet
        case 'E': nyBolig = new Enebolig(sisteNr);   break;     // enebolig
    }

    bolig.push_back(nyBolig);  // legger boligen inn bakerst i vectoren
}

/**
 *  Skriver ut all data om sonen og boliger på sonen
 */
void Sone :: visAlleBoliger(){
    skrivHovedData();
    cout << "\nAlle oppdrag: ";
    for(int i=0; i<bolig.size(); i++){
        cout << "\n";
        bolig[i]->skrivData();
    }
    cout << "\n";
}


/**
 *  Skriver ut all data om enkelt bolig
 *
 *  @param   boligNr - boligens/oppdragets unike nummer
 */
bool Sone :: visBolig(int boligNr){
    for(int i=0; i<bolig.size(); i++){
        if(bolig[i]->returBoligNr() == boligNr){
            bolig[i]->skrivData();
            return true;
        }
    }
    return false;
}

/**
 *  sletter bolig
 *
 *  @return true om den fantes og ble slettet, false hvis ikke
 */
bool Sone :: slettBolig(int boligNr){
    for(int i=0; i<bolig.size(); i++){
        if(bolig[i]->returBoligNr() == boligNr){
            bolig.erase(bolig.begin()+i);         //    sletter boligen
            return true;                          //    returnerer true da boligen er slettet
        }
    }
    return false;
}

/**
 *  Skriver alle datamedlemmer til unik fil
 *
 *  @param   ut - filen det skrives til
 */
void Sone :: skrivOversiktTilFil(ofstream & ut){
    ut << "\n\nsone/område " << idNummer << " - " << beskrivelse;
    for (Bolig* val : bolig){
        val->skrivOversiktTilFil(ut);
    }
}

/**
 *  Skriver alle datamedlemmer til fil
 *
 *  @param   ut - filen det skrives til
 */
void Sone :: skrivTilFil(ofstream & ut){
    ut << idNummer << ' ' << beskrivelse << '\n';
    for(int i=0; i<bolig.size(); i++){
        ut << 'b' << '\n';
        bolig[i]->skrivTilFil(ut);
    }
}

