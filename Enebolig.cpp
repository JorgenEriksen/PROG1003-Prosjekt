 /**
 *   @file     Enebolig.cpp
 *   @author   Jørgen Eriksen
 */

#include <iostream>
#include "Enebolig.h"
#include "LesData3.h"
using namespace std;


/**
 *  Leser inne alle datamedlemmer fra fil
 *
 *  @param   inn - filen det leses inn fra
 */
Enebolig :: Enebolig(ifstream & inn) : Bolig(inn){
    char erSelveiet;
    inn >> areal >> erSelveiet;
    switch(erSelveiet){
        case 'Y': selveiet = true;      break;
        case 'N': selveiet = false;     break;
    }
    Bolig::setSomEnebolig();
}

/**
 *  leser inn data for sone
 *
 *  @param   soneNummer - unikt sonenummer
 */
Enebolig :: Enebolig(int soneNummer) : Bolig(soneNummer){
    char svar;
    areal = lesInt("tomtens areal i kvadratmeter", 0, 1000);

    do{
        svar = lesChar("Er den selveiet? (Y/N)");
    } while(svar != 'Y' && svar != 'N');

    switch(svar){
        case 'Y': selveiet = true;      break;
        case 'N': selveiet = false;     break;
    }
    Bolig::setSomEnebolig(); // setter enum boligtype i Bolig klassen som EBolig
};

/**
 *  returnerer bolignummer
 *
 *  @return boligens unike bolignummer
 */
int Enebolig :: returBoligNr(){
    return Bolig::returBoligNr();
}

/**
 *  Skriver ut all data om eneboligen
 */
void Enebolig :: skrivData(){
    Bolig::skrivData();
    cout << "\nareal: " << areal
         << "\nselveiet: ";
    if(selveiet) cout << "ja";
    else cout << "nei";


}

/**
 *  Skriver alle datamedlemmer til fil i et leselig oppsett
 *
 *  @param   ut - filen det skrives til
 */
void Enebolig :: skrivOversiktTilFil(ofstream & ut){
    Bolig::skrivOversiktTilFil(ut);
    ut << "\n\t\tareal: " << areal
       << "\n\t\tselveiet: ";
    if(selveiet) ut << "ja";
    else ut << "nei";

}

/**
 *  Skriver alle datamedlemmer til fil
 *
 *  @param   ut - filen det skrives til
 */
void Enebolig :: skrivTilFil(ofstream & ut){
    Bolig::skrivTilFil(ut);
    ut << areal << ' ';
    if(selveiet) ut << 'Y';
    else ut << 'N';
    ut << '\n';
}




