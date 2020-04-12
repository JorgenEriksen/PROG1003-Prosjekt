#ifndef Enebolig_h
#define Enebolig_h

#include "Bolig.h"

/**
 *  Enebolig (med areal og true/false om den er selveiet).
 */
class Enebolig : public Bolig {
    private:
        int areal;
        bool selveiet;
    public:
        Enebolig(std::ifstream & inn);
        Enebolig(int soneNummer);
        int returBoligNr();
        virtual void skrivData();
        virtual void skrivOversiktTilFil(std::ofstream & ut);
        virtual void skrivTilFil(std::ofstream & ut);
};

#endif
