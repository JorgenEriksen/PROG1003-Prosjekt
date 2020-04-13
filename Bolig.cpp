 /**
 *   @file     Bolig.cpp
 *   @author   Jørgen Eriksen
 */

#include <iostream>
#include "Bolig.h"
#include "LesData3.h"
using namespace std;


/**
 *  Leser inne alle datamedlemmer fra fil
 *
 *  @param   inn - filen det leses inn fra
 */
Bolig :: Bolig(ifstream & inn){
    boligtype = Leilighet; // denne vil bli overskrevet om den blir opprettet fra subklassen Enebolig (via setSomEnebolig())
    inn >> boligNr >> dato >> byggear >> bruttoAreal >> antallSoverom >> pris;
    inn.ignore();                //fjerner '\n'
    getline(inn, saksbehandler);
    getline(inn, eier);
    getline(inn, gateadresse);
    getline(inn, postadresse);
    getline(inn, beskrivelse);
}

/**
 *  leser inn data for boligen
 *
 *  @param   bolignummer - unikt bolignummer
 */
Bolig :: Bolig(int bolignummer){
    boligNr = bolignummer;
    // boligtypoe vil bli overskrevet om den blir opprettet fra subklassen Enebolig (via setSomEnebolig())
    boligtype = Leilighet;
    cout << "\noppretter oppdrag med oppdragsnummer " << boligNr << "\n";
    dato = lesInt("dato i AAAAMMDD format", 20000101, 20401231);
    byggear = lesInt("byggeAr", 1900, 2030);
    bruttoAreal = lesInt("bruttoareal i meter", 0, 9999);
    antallSoverom = lesInt("antall soverom", 0, 20);
    pris = lesInt("pris i kr", 0, 99999999);
    cout << "navn på saksbehandler: ";
    getline(cin, saksbehandler);
    cout << "navn på eier: ";
    getline(cin, eier);
    cout << "gateadressen: ";
    getline(cin, gateadresse);
    cout << "postadressen: ";
    getline(cin, postadresse);
    cout << "beskrivelse: " ;
    getline(cin, beskrivelse);
}

/**
 *  Setter boligtype til EBolig (enebolig)
 */
void Bolig :: setSomEnebolig(){
    boligtype = EBolig;
}

/**
 *  returnerer bolignummer
 *
 *  @return boligens unike bolignummer
 */
int Bolig ::returBoligNr(){
    return boligNr;
}

/**
 *  Skriver ut all data om boligen
 */
void Bolig :: skrivData(){
    cout << "\noppdragsnummer: "    << boligNr;
    cout << "\ndato: "              << dato;
    cout << "\nboligtype: ";
    if(boligtype == Leilighet)
        cout << "leilighet";
    else
        cout << "enebolig";
    cout << "\nbyggeår: "           << byggear;
    cout << "\nbrutto areal: "      << bruttoAreal;
    cout << "\nantall soverom: "    << antallSoverom;
    cout << "\npris: "              << pris;
    cout << "\nsaksbehandler: "     << saksbehandler;
    cout << "\neier: "              << eier;
    cout << "\ngateadresse: "       << gateadresse;
    cout << "\npostadresse: "       << postadresse;
    cout << "\nbeskrivelse: "       << beskrivelse;
}

/**
 *  Skriver alle datamedlemmer til fil i et leselig oppsett
 *
 *  @param   ut - filen det skrives til
 */
void Bolig :: skrivOversiktTilFil(ofstream & ut){
    ut << "\n\toppdrag " << boligNr;
    ut << "\n\t\tdato: " << dato;
    ut << "\n\t\tboligtype: ";
    if(boligtype == Leilighet)
        ut << "leilighet";
    else
        ut << "enebolig";
    ut << "\n\t\tbyggear: " << byggear;
    ut << "\n\t\tbruttoareal: " << bruttoAreal;
    ut << "\n\t\tantall soverom: " << antallSoverom;
    ut << "\n\t\tpris: " << pris;
    ut << "\n\t\tsaksbehandler: " << saksbehandler;
    ut << "\n\t\teier: " << eier;
    ut << "\n\t\tgateadresse: " << gateadresse;
    ut << "\n\t\tpostadresse: " << postadresse;
    ut << "\n\t\tbeskrivelse: " << beskrivelse;
}

/**
 *  Skriver alle datamedlemmer til fil
 *
 *  @param   ut - filen det skrives til
 */
void Bolig :: skrivTilFil(ofstream & ut){
    if(boligtype == Leilighet) ut << 'L';
    else ut << 'E';
    ut << ' ' << boligNr << ' ' << dato << ' ' << byggear << ' ' << bruttoAreal << ' ' << antallSoverom << ' ' << pris << '\n';
    ut << saksbehandler << '\n';
    ut << eier << '\n';
    ut << gateadresse << '\n';
    ut << postadresse << '\n';
    ut << beskrivelse << '\n';
}
