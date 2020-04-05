#ifndef Bolig_H
#define Bolig_H

#include <string>
#include "Const.h" // skal denne bort?

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
        Boligtype bolig;
    public:
        Bolig(int soneNummer);


};


#endif
