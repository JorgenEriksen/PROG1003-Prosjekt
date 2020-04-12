#ifndef Soner_h
#define Soner_h

#include <map>
#include <fstream>
#include "Sone.h"

/**
 *  Soner (med sist registrert sonenummer/ID, og soner).
 */
class Soner  {
    private:
        int sisteNr = 0; //siste oppdragsnummer
        std::map <int, Sone*> sone;
    public:
        void leggTil(int soneNr, std::ifstream & inn);
        void leggTil(int soneNr);
        void visEnSone(int soneNr);
        void visAlle();
        bool omSoneEksisterer(int soneNr);
        void leggTilOppdrag(int soneNr, std::ifstream & inn);
        void leggTilOppdrag(int soneNr);
        void visOppdrag(int boligNr);
        void slettOppdrag(int boligNr);
        void skrivOversiktTilFil(int soneNr, std::ofstream & ut);
        void skrivTilFil(std::ofstream & ut);
};

#endif
