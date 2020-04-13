#ifndef Kunde_h
#define Kunde_h

#include <string>
#include <vector>
#include <fstream>
#include "Enum.h"


/**
 *  Kunde (med kundenummer, telefonnummer, navn, gate, postadresse, mailadresse, boligtype og interesserte soner).
 */
class Kunde  {
    private:
        int kundeNr,
            telefonNr;
        std::string navn,
                    gateadresse,
                    postadresse,
                    mail;
        Boligtype boligtype;
        std::vector <int> soneNr;
    public:
        Kunde(int tlf, int kundeNummer, std::ifstream & inn);
        Kunde(int kundeNummer);
        void skrivHovedData();
        void skrivAllData();
        void endreData();
        int returKundeNr();
        void leggTilSone(int soneNummer);
        void skrivOversiktTilFil();
        void skrivTilFil(std::ofstream & ut);

};

#endif
