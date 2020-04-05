#ifndef Kunde_h
#define Kunde_h

#include <string>
#include <vector>
#include "Const.h"


class Kunde  {
    private:
        int kundeNr,
            telefon;
        std::string navn,
                    gateadresse,
                    postadresse,
                    mail;
        Boligtype boligtype;
        std::vector <int> soneNr;
    public:
        Kunde();
        Kunde(int kundeNummer);
        void skrivHovedData();
        void skrivAllData();
        void endreData();
        int returKundeNr();
        void leggTilSone(int soneNummer);

};

#endif
