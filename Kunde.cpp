#include <iostream>
#include <string>

#include "Kunde.h"
#include "Soner.h"

#include "LesData3.h"
#include "Const.h"

using namespace std;

extern Soner* gSoner;

Kunde :: Kunde(){
    cout << "\nher2";
}

Kunde :: Kunde(int kundeNummer){
    int soneNummer;
    char bolig;

    kundeNr = kundeNummer;
    cout << "\nnavn: ";
    getline(cin, navn);
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
        case 'E': boligtype = Enebolig; break;
    }

    do{
        soneNummer = lesInt("Sonenummer kunden er interessert i", 1, MAXSONER);
        if(gSoner->omSoneEksisterer(soneNummer)){
            leggTilSone(soneNummer);
        } else {
            cout << "\nsone " << soneNummer << " eksisterer ikke";
        }
    } while(lesChar("\nlegg til ny sone? (y/n)") == 'Y');

}

void Kunde :: skrivHovedData(){
    cout << "\nKundenummer: " << kundeNr;
    cout << "\nnavn: " << navn;

}

void Kunde :: skrivAllData(){
    skrivHovedData();
    cout << "\ngateadresse: " << gateadresse;
    cout << "\npostadresse: " << postadresse;
    cout << "\nmail: " << mail;
    cout << "\nAntall soner interresert i: " <<soneNr.size();
    cout << "\nSoner interresert i: ";
    for(int i = 0; i<soneNr.size(); i++){
        cout << soneNr[i] << " ";
    }
}

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

int Kunde :: returKundeNr(){
    return kundeNr;
}

// sørger for at ny sone blir lagt inn i sortert rekkefølge
void Kunde :: leggTilSone(int soneNummer){
    bool leggTilBak = true;       // soneNummer skal legges bakerst om denne holder seg true etter loopen
    for(int i = 0; i<soneNr.size(); i++){
        if(soneNr[i] > soneNummer && leggTilBak){
            auto itPos = soneNr.begin()+i;
            soneNr.insert(itPos, soneNummer);
            leggTilBak = false;
            cout << "\nSone " << soneNummer << " lagt på kunden!";
        } else if (soneNr[i] == soneNummer){
            cout << "\nKunden er allerede interresert i sone " << soneNummer << " fra før";
            leggTilBak = false;
        }
    }

    if(leggTilBak){
        soneNr.push_back(soneNummer);
    }

}
