#include <iostream>
#include <string>

#include "Kunder.h"
#include "Soner.h"
#include "Funksjoner.h"
#include "Const.h"
#include "LesData3.h"   // muligens denne må fjernes når jeg er ferdig med denne filen

using namespace std;

extern Kunder* gKunder;
extern Soner* gSoner;

// K N
void nyKunde()  {
    gKunder->leggTil();
}

// K 1 <knr>
void visEnkeltKunde(){
    cout << "\nviser informasjon om enkeltkunde";
    int num = lesInt("\nvelg kunde", 1, MAXKUNDER);
    gKunder->visEnKunde(num);
}

// K A
void visAlleKunder(){
    gKunder->visAlle();
}

// K E <knr>
void endreKunde(){
    int num = lesInt("skriv kundenummeret på kunden du vil endre", 1, MAXKUNDER);
    gKunder->endreKunde(num);

}

// K S <knr>
void slettKunde(){
    int num = lesInt("skriv kundenummeret på kunden du vil slette", 1, MAXKUNDER);
    gKunder->slettKunde(num);
}

// K O <knr>
void kundeOversikt(){

}

// S N <snr>
void nySone(){
    int num = lesInt("sonenummer", 0, MAXSONER);
    gSoner->leggTil(num);
}

// S A
void visAlleSoner(){
    gSoner->visAlle();
}

// S 1 <snr>
void visEnkeltSoner(){

}

// O N <snr>
void nyttOppdrag(){
    gSoner->visSoneNummer();
    cout << "\n";
    int sone = lesInt("velg sone",0, MAXSONER);
    gSoner->leggTilOppdrag(sone);
}

// O N <snr>
void visEnkeltOppdrag(){

}

// O 1 <onr>
void slettOppdrag(){

}

// O S <onr>
void skrivMeny(){

}

