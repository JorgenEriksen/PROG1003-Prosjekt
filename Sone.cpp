#include <iostream>
#include <string>
#include <map>

#include "Sone.h"

using namespace std;

Sone :: Sone(int soneNummer){
    idNummer = soneNummer;
    cout << "\nSkriv inn en beskrivelse for sone " << idNummer << ": ";
    getline(cin, beskrivelse);
};

void Sone :: skrivHovedData(){
    cout << "\nSone " << idNummer << ":";
    cout << "\nBeskrivelse: " << beskrivelse;
};

void Sone :: skrivAllData(){
    skrivHovedData();
};
