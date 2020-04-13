 /**
 *   @file     Kunder.cpp
 *   @author   J�rgen Eriksen
 */

#include <iostream>
#include <string>
#include "LesData3.h"
#include "Kunder.h"
#include "Kunde.h"
using namespace std;

/**
 *  Leser datamedlemmer fra fil
 *
 *  @param   inn - filen det leses inn fra
 */
void Kunder :: leggTil(int kNr, ifstream & inn){
    sisteNr = kNr;
    Kunde* nyKunde = new Kunde(sisteNr, inn);
    kunde.push_back(nyKunde);
}

/**
 *  Leser inn datamedlemmer
 */
void Kunder :: leggTil(){
    sisteNr++;
    cout << "\nlegger til ny kunde med kundenummer " <<  sisteNr;
    Kunde* nyKunde = new Kunde(sisteNr);
    kunde.push_back(nyKunde);
}

/**
 *  viser alle datamedlemmer til alle kunder (10 om gangen)
 */
void Kunder :: visAlle(){
    int counter = 0;
    for (const auto& person : kunde){
        person->skrivHovedData();
        counter++;
        if(counter > 9){   // hvis det er vist 10 kunder p� rad
            cout << "\n\nPress ENTER for A fortsette";
            cin.ignore();  // ignorerer input
            counter = 0;   // resetter counter
        }
    }
}

/**
 *  Viser data til en enkelt kunde
 *
 *  @param   kNr - kundenummer
 */
void Kunder :: visEnKunde(int kNr){
    bool fantKunde = false;
    for (const auto & val : kunde){          // looper igjennom listen kunde
        if(val->returKundeNr() == kNr){      // hvis kundenummeret er likt innskrevet tall
            fantKunde = true;                // registerer at kunden ble funnet s� den hopper over "if(!fantKunde)" under
            val->skrivAllData();             // skriver ut all data p� kunden via skrivAllData()
        }
    }

    if(!fantKunde){                          // om kundenummer ikke eksisterer
        cout << "\nugyldig kundenummer!";
    }
}

/**
 *  Endrer datamedlemmer til kunde
 *
 *  @param   kNr - kundenummer
 */
void Kunder :: endreKunde(int kNr){
    bool fantKunde = false;
    for (const auto & val : kunde){          // looper igjennom listen kunde
        if(val->returKundeNr() == kNr){      // hvis kundenummeret er likt innskrevet tall
            fantKunde = true;                // registerer at kunden ble funnet s� den hopper over "if(!fantKunde)" under
            val->skrivAllData();             // skriver ut all data p� kunden via skrivAllData()
            val->endreData();                // endrer data via endreData()
        }
    }

    if(!fantKunde){                          // om kundenummer ikke eksisterer
        cout << "\nugyldig kundenummer!";
    }
}

/**
 *  Sletter enkelt kunde
 *
 *  @param   kNr - kundenummer
 */
void Kunder :: slettKunde(int kNr){
    Kunde* sKunde;
    bool fantKunde = false;

    for(const auto & val : kunde){         // looper igjennom kunde
        if(val->returKundeNr() == kNr) {   // om kundenummer finnes
            sKunde = val;                  // lagrer kunden s� den kan bli slettet utenfor loopen
            fantKunde = true;              // registrerer at kundenummeret fins
        }
    }

    if(fantKunde){                         // om kunde er blit funnet
        char svar = lesChar("Er du sikker p� at du vil slette denne kunden? (Y/N)");
        switch(svar){
            case 'Y':
                kunde.remove(sKunde);               // sletter kunden
                cout << "\nKunden er slettet!"; break;
            default:                                // om ikke Y blir inskrevet
                cout << "\nAvbryter sletting av kunde";
        }
    } else {                    // om kundenummer ikke eksisterer
        cout << "\nugyldig kundenummer!";
    }

}

/**
 *  Skriver ut all data om kunde og interreserte soner til unik fil
 *
 *  @param   kNr - kundenummer
 */
void Kunder :: skrivOversiktTilFil(int kNr){
    bool fantKunde = false;
    for (const auto & val : kunde){          // looper igjennom listen kunde
        if(val->returKundeNr() == kNr){      // hvis kundenummeret er likt innskrevet tall
            fantKunde = true;                // registerer at kunden ble funnet s� den hopper over "if(!fantKunde)" under
            val->skrivOversiktTilFil();
        }
    }

    if(!fantKunde){
        cout << "\nugyldig kundenummer!";
    }
}

/**
 *  Skriver alle datamedlemmer til fil
 *
 *  @param   ut - filen det skrives til
 */
void Kunder :: skriTilFil(ofstream & ut){
    for (const auto & val : kunde){
        val->skrivTilFil(ut);
    }
}
