#ifndef Kunder_h
#define Kunder_h

#include <list>
#include "Kunde.h"

/**
 *  Kunder (med sist registrerte kundenummer og en liste med kunder)
 */
class Kunder  {
    private:
        int sisteNr = 0;
        std::list <Kunde*> kunde;
    public:
        void leggTil(int kNr, std::ifstream & inn);
        void leggTil();
        void visAlle();
        void visEnKunde(int kNr);
        void endreKunde(int kNr);
        void slettKunde(int kNr);
        void skrivOversiktTilFil(int kNr);
        void skriTilFil(std::ofstream & ut);
};

#endif

