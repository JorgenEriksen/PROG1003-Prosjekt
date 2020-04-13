 /**
 *   @file     Kunde.cpp
 *   @author   Jørgen Eriksen
 */

#include <iostream>
#include <string>
#include "Kunde.h"
#include "Soner.h"
#include "LesData3.h"
#include "Const.h"
using namespace std;

extern Soner* gSoner;

/**
 *  Leser inne alle datamedlemmer fra fil
 *
 *  @param   kundeNummer - kundens unike kundenummer
 *  @param   inn - filen det leses inn fra
 */
Kunde :: Kunde(int tlf, int kundeNummer, ifstream & inn){
    char bolig;
    int antallSoner;
    int sone;

    telefonNr = tlf;
    kundeNr = kundeNummer;
    // inn.ignore();
    getline(inn, navn);
    getline(inn, gateadresse);
    getline(inn, postadresse);
    getline(inn, mail);
    inn >> bolig;
    switch(bolig){
        case 'L': boligtype = Leilighet; break;
        case 'E': boligtype = EBolig; break;
    }
    inn >> antallSoner;
    for(int i = 0; i<antallSoner; i++){
        inn >> sone;
        soneNr.push_back(sone);
    }

}

/**
 *  Leser inne alle datamedlemmer
 *
 *  @param   kundeNummer - kundens unike kundenummer
 */
Kunde :: Kunde(int kundeNummer){
    int soneNummer;
    char bolig;

    kundeNr = kundeNummer;
    cout << "\nnavn: ";
    getline(cin, navn);
    telefonNr = lesInt("telefonnummer: ", 20000000, 99999999);
    cout << "gateadresse: ";
    getline(cin, gateadresse);
    cout << "postadresse: ";
    getline(cin, postadresse);
    cout << "emailadresse: ";
    getline(cin, mail);
    do{
        bolig = lesChar("Interresert i leilighet eller enebolig (L/E)?");
    } while(bolig != 'L' && bolig != 'E');

    switch(bolig){
        case 'L': boligtype = Leilighet; break;
        case 'E': boligtype = EBolig; break;
    }

    do{
        soneNummer = lesInt("Sonenummer kunden er interessert i", 1, MAXSONER);
        if(gSoner->omSoneEksisterer(soneNummer)){
            leggTilSone(soneNummer);
        } else {
            cout << "\nsone " << soneNummer << " eksisterer ikke";
        }
    } while(lesChar("\nlegg til ny/annen sone? (y/n)") == 'Y');

}

/**
 *  Skriver ut kundenummer og navn
 */
void Kunde :: skrivHovedData(){
    cout << "\nKundenummer: " << kundeNr;
    cout << "\nnavn: " << navn;
}

/**
 *  Skriver ut all data om kunde
 */
void Kunde :: skrivAllData(){
    skrivHovedData();
    cout << "\ntelefonnummer: " << telefonNr;
    cout << "\ngateadresse: " << gateadresse;
    cout << "\npostadresse: " << postadresse;
    cout << "\nmail: " << mail;
    cout << "\ninterresert i boligtype: ";
    if(boligtype == Leilighet)
        cout << "leilighet";
    else
        cout << "enebolig";
    cout << "\nantall soner interresert i: " <<soneNr.size();
    cout << "\nsoner interresert i: ";
    for(int val : soneNr){
        cout << val << " ";
    }
}

/**
 *  Legger til eller fjerner soner på kunden
 */
void Kunde :: endreData(){
    int soneNummer;
    char valg;

    do{
        valg = lesChar("\nvil du legge til eller slette sone (L/S)?");
    } while(valg != 'L' && valg != 'S');

    switch(valg){
    case 'L':
        soneNummer = lesInt("Legg til sonenummer kunden er interessert i", 1, MAXSONER);
        if(gSoner->omSoneEksisterer(soneNummer)){
            leggTilSone(soneNummer);
        } else {
            cout << "\nsone " << soneNummer << " eksisterer ikke\n";
        }
        break;
    case 'S':
        soneNummer = lesInt("Sone du vil fjerne fra kunden", 1, MAXSONER);
        if(gSoner->omSoneEksisterer(soneNummer)){
            for(int i=0; i<soneNr.size(); i++){
                if(soneNr[i] == soneNummer){
                    soneNr.erase(soneNr.begin()+i);  // fjerner sonenummeret.
                }
            }
            cout << "Sone " << soneNummer << " fjernet fra kunden!";
        } else {
            cout << "\nIngen soner har dette nummeret";
        }
        break;
    }

}

/**
 *  returnerer kundenummer
 *
 *  @return kundens unike nummer/ID
 */
int Kunde :: returKundeNr(){
    return kundeNr;
}


/**
 *  Legger til ny sone på kunden i sortert rekkefølge
 *
 *  @param   soneNummer - sonenummer som skal legges til
 */
void Kunde :: leggTilSone(int soneNummer){
    bool leggTilBak = true;                          // soneNummer skal legges bakerst om denne holder seg true etter loopen
    for(int i = 0; i<soneNr.size(); i++){
        if(soneNr[i] > soneNummer && leggTilBak){    // denne vil maks være true en gang pga leggTilBak
            auto itPos = soneNr.begin()+i;           // finner posisjonen sonenummeret skal legges inn i
            soneNr.insert(itPos, soneNummer);        // legges inn (i sortert rekkefølge)
            leggTilBak = false;
            cout << "\nSone " << soneNummer << " lagt på kunden!";
        } else if (soneNr[i] == soneNummer){
            cout << "\nKunden er allerede interresert i sone " << soneNummer << " fra før";
            leggTilBak = false;
        }
    }

    if(leggTilBak){ // sonenummer skal legges inn bakerst
        soneNr.push_back(soneNummer);
    }

}

/**
 *  Skriver alle datamedlemmer (både kunde og soner) til fil
 *
 *  @see Soner::skrivOversiktTilFil(...)
 */
void Kunde :: skrivOversiktTilFil(){
    string filnavn = "K";
    filnavn.append(to_string(kundeNr) + ".DTA");
    ofstream utfil(filnavn);
    utfil << "*********************";
    utfil << "\nOversikt for kunde " << kundeNr;
    utfil << "\n*********************";
    utfil << "\n\nnavn: " << navn;
    utfil << "\ntelefonnummer: " << telefonNr;
    utfil << "\nmail: " << mail;
    utfil << "\n\ngateadresse: " << gateadresse;
    utfil << "\npostadresse: " << postadresse;
    utfil << "\n\ninteressert i ";
    if(boligtype == Leilighet)
        utfil << "leilighet";
    else
        utfil << "enebolig";
    if(soneNr.size() < 1) utfil << "\n\ningen interesserte soner/områder registrert foreløpig";
    else utfil << " i følgende soner/områder: ";
    for(int val : soneNr){
        gSoner->skrivOversiktTilFil(val, utfil);
    }

    cout << "\noversikt over kunde " << kundeNr << " er lagret i " << filnavn;

}

/**
 *  Skriver alle datamedlemmer til fil
 *
 *  @param   ut - filen det skrives til
 */
void Kunde :: skrivTilFil(ofstream & ut){
    // trenger ikke å skrive kundenummer til fil, da det blir lagt inn riktig ved innlesning pga. sortering
    if(kundeNr != 1) ut << '\n'; // en av flere mulige løsninger for å hindre at det blir et linjeskift formye i starten/slutten.
    ut << telefonNr << ' ' << navn << '\n';
    ut << gateadresse << '\n';
    ut << postadresse << '\n';
    ut << mail << '\n';
    if(boligtype == Leilighet)
        ut << 'L';
    else
        ut << 'E';
    ut << ' ' << soneNr.size();
    for(int val : soneNr){
        ut << ' ' << val;
    }

}
