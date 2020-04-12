#ifndef Sone_h
#define Sone_h

#include <string>
#include <vector>
#include <fstream>
#include "Bolig.h"

/**
 *  Sone (med sonenummer/ID, beskrivelse og boliger i sonen).
 */
class Sone {
    private:
        int idNummer;
        std::string beskrivelse;
        std::vector <Bolig*> bolig;
    public:
        Sone(int soneNr, std::ifstream & inn);
        Sone(int soneNummer);
        void skrivHovedData();
        void nyBolig(std::ifstream & inn);
        void nyBolig(int sisteNr);
        void visAlleBoliger();
        bool visBolig(int boligNr);
        bool slettBolig(int boligNr);
        void skrivOversiktTilFil(std::ofstream & ut);
        void skrivTilFil(std::ofstream & ut);
};

#endif
