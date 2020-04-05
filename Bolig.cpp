#include <iostream>
#include "Bolig.h"
#include "LesData3.h"

using namespace std;

Bolig :: Bolig(int oppdragsNr){
    boligNr = oppdragsNr;
    dato = lesInt("dato(AAAAMMDD)", 19000101, 20303112);
    byggear = lesInt("byggeAr", 1900, 2020);
    bruttoAreal = lesInt("bruttoareal i meter", 0, 9999);
    antallSoverom = lesInt("antall soverom", 0, 20);
    pris = lesInt("pris i kr", 0, 99999999);
}
