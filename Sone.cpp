#include <iostream>
#include <string>
#include <map>

#include "Sone.h"
#include "Bolig.h"
#include "Enebolig.h"

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

void Sone :: nyLeilighet(int sisteNr){
    Bolig* nyBolig = new Bolig(sisteNr);
    bolig.push_back(nyBolig);
}

void Sone :: nyEnebolig(int sisteNr){
    // Bolig* nyBolig = new Enebolig(sisteNr);
    // bolig.push_back(nyBolig);
}
