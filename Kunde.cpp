#include <iostream>
#include <string>
#include "Kunde.h"

using namespace std;

Kunde :: Kunde(){
    cout << "\nher2";
}

Kunde :: Kunde(int kundeNummer){
    kundeNr = kundeNummer;

    cout << "\nnavn: ";
    getline(cin, navn);

    cout << "gateadresse: ";
    getline(cin, gateadresse);

    cout << "postadresse: ";
    getline(cin, postadresse);

    cout << "emailadresse: ";
    getline(cin, mail);

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
}

int Kunde :: returKundeNr(){
    return kundeNr;
}
