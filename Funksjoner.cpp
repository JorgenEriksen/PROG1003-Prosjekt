#include <iostream>
#include <string>

#include "Kunder.h"
#include "Soner.h"
#include "Funksjoner.h"

using namespace std;

extern Kunder* gKunder;
extern Soner* gSoner;

// K N
void nyKunde()  {
    cout << "\nlegger til ny kunde";
    gKunder->leggTil();
}

// K A
void visAlleKunder(){
    gKunder->visAlle();
}

// K 1 <knr>
void visEnkeltKunde(){
    gKunder->visEnKunde(1);
}

// S N <snr>
void nySone(){
    gSoner->leggTil();
}

// S A
void visAlleSoner(){
    gSoner->visAlle();
}

// S 1 <snr>
void visEnkeltSoner(){

}
