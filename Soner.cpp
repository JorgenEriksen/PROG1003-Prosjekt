#include <iostream>
#include "LesData3.h"

#include "Soner.h"
#include "Sone.h"



using namespace std;

void Soner :: leggTil(int soneNr){
    auto it = sone.find(soneNr);
    if(it != sone.end()){                               // om sonen eksisterer allerede
        cout << "\ndenne sonen eksisterer allerede";
    } else {                                            // om sonen IKKE eksisterer allerede
        Sone* nySone = new Sone(soneNr);                // oppretter ny sone
        sone.insert(pair <int, Sone*>(soneNr, nySone)); // legger soneNr og sonen inn i map 'sone'
    }

};

void Soner :: visAlle(){
    for (const auto & val : sone){
        (val.second)->skrivHovedData();
    }
}

void Soner :: visSoneNummer(){
    cout << "\nalle registrerte soner: \n";
    for (const auto & val : sone){
        cout << val.first << "  ";
    }
}


bool Soner :: omSoneEksisterer(int soneNr){
    auto it = sone.find(soneNr);
    if(it != sone.end()){
        return true;
    }
    return false;
}




/**
* @param    soneNr  - tekst her
*
*/
void Soner :: leggTilOppdrag(int soneNr){
    char svar;
    auto it = sone.find(soneNr);
    if(it != sone.end()){
        for (const auto & val : sone){
            if(val.first == soneNr){
                do{
                    svar = lesChar("Opprette leilighet eller enebolig? (L/E)");
                } while (svar != 'L', svar != 'E');
                switch(svar){
                    case 'L': (val.second)->nyLeilighet(sisteNr);
                    case 'E': (val.second)->nyEnebolig(sisteNr);
                }

            }
        }

    } else {
        cout << "\nsone " << soneNr << " eksisterer ikke";
    }



}


