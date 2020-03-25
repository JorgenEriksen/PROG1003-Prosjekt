#include <iostream>
#include <string>
#include "Kunder.h"
#include "Kunde.h"

using namespace std;

Kunder :: Kunder(){

}

void Kunder :: leggTil(){
    sisteNr++;
    Kunde* nyKunde = new Kunde(sisteNr);
    kunde.push_back(nyKunde);
}

void Kunder :: visAlle(){
    for (const auto& person : kunde){
        person->skrivHovedData();
    }
}

void Kunder :: visEnKunde(int tall){
    bool fantKunde = false;
    for (const auto & val : kunde){          // looper igjennom listen kunde
        if(val->returKundeNr() == tall){     // hvis kundenummeret er likt innskrevet tall
            fantKunde = true;                // registerer at kunden ble funnet så den hopper "if(!fantKunde)" under
            val->skrivAllData();             // skriver ut all data på kunden via skrivAllData()
        }
    }

    if(!fantKunde){
        cout << "\nfant ingen kunder med kundenummer " << tall;
    }


}
