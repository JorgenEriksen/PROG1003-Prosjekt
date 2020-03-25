#include <iostream>

#include "Soner.h"
#include "Sone.h"

using namespace std;

void Soner :: leggTil(){
    sisteNr++;
    Sone* nySone = new Sone(sisteNr);
    sone.insert(pair <int, Sone*>(sisteNr, nySone));
};

void Soner :: visAlle(){
    for (const auto & val : sone){
        (val.second)->skrivHovedData();
    }

}


