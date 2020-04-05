#ifndef Enebolig_h
#define Enebolig_h

#include "Bolig.h"

class Enebolig : public Bolig {
    private:
        int areal;
        bool selveiet;
    public:
        Enebolig(int soneNummer);

};

#endif
