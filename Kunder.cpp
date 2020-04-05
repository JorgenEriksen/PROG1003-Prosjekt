#include <iostream>
#include <string>
#include "LesData3.h"
#include "Kunder.h"
#include "Kunde.h"


using namespace std;

Kunder :: Kunder(){

}

void Kunder :: leggTil(){
    sisteNr++;
    cout << "\nlegger til ny kunde med kundenummer " <<  sisteNr;
    Kunde* nyKunde = new Kunde(sisteNr);
    kunde.push_back(nyKunde);
}

void Kunder :: visAlle(){
    int counter = 0;
    char enter;
    for (const auto& person : kunde){
        person->skrivHovedData();
        counter++;
        if(counter > 9){
            cout << "\n\nPress ENTER for A fortsette";
            cin.ignore();
            counter = 0;
        }
    }
}

void Kunder :: visEnKunde(int tall){
    bool fantKunde = false;
    for (const auto & val : kunde){          // looper igjennom listen kunde
        if(val->returKundeNr() == tall){     // hvis kundenummeret er likt innskrevet tall
            fantKunde = true;                // registerer at kunden ble funnet så den hopper over "if(!fantKunde)" under
            val->skrivAllData();             // skriver ut all data på kunden via skrivAllData()
        }
    }

    if(!fantKunde){
        cout << "\nfant ingen kunder med kundenummer " << tall;
    }

}

void Kunder :: endreKunde(int nr){
    bool fantKunde = false;
    for (const auto & val : kunde){          // looper igjennom listen kunde
        if(val->returKundeNr() == nr){     // hvis kundenummeret er likt innskrevet tall
            fantKunde = true;                // registerer at kunden ble funnet så den hopper over "if(!fantKunde)" under
            val->skrivAllData();             // skriver ut all data på kunden via skrivAllData()
            val->endreData();                // endrer data via endreData()
        }
    }

    if(!fantKunde){
        cout << "\nfant ingen kunder med kundenummer " << nr;
    }
}

void Kunder :: slettKunde(int kNr){
    Kunde* sKunde;
    bool fantKunde = false;

    for(const auto & val : kunde){
        if(val->returKundeNr() == kNr) {
            sKunde = val;               // lagrer kunden så den kan bli slettet utenfor loopen
            fantKunde = true;

        }
    }
    if(fantKunde){
        char svar = lesChar("Er du sikker på at du vil slette denne kunden? (Y/N)");
        switch(svar){
            case 'Y':
                kunde.remove(sKunde);           // sletter kunden
                kunde.sort();                       // sorterer kunde listen
                cout << "\nKunden er slettet!";
                break;
            default:                            // om ikke Y blir tastet
                cout << "\nAvbryter sletting av kunde";
        }
    } else {                    // om inntastet kundenummer ikke eksisterer
        cout << "\nFinner ingen kunder med kundenummer " << kNr;
    }





}
