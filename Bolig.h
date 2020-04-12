#ifndef Bolig_h
#define Bolig_h

#include <string>
#include <fstream>
#include "Enum.h"

/**
 *  bolig (med bolignummer, dato, byggeår, bruttoareal, antall soverom, pris,
 *  navn på saksbehandler, eier, gate, postadresse, beskrivelse og boligtype).
 */
class Bolig {
    private:
        int boligNr,
            dato,               // AAAAMMDD
            byggear,
            bruttoAreal,
            antallSoverom,
            pris;
        std::string saksbehandler,
               eier,
               gateadresse,   // gate+nr
               postadresse,   // nr+sted
               beskrivelse;
        Boligtype boligtype;
    public:
        Bolig(std::ifstream & inn);
        Bolig(int soneNummer);
        void setSomEnebolig();
        virtual int returBoligNr();
        virtual void skrivData();
        virtual void skrivOversiktTilFil(std::ofstream & ut);
        virtual void skrivTilFil(std::ofstream & ut);
};


#endif
