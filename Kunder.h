#ifndef Kunder_h
#define Kunder_h

#include <list>
#include "Kunde.h"

class Kunder  {
    private:
        int sisteNr = 0;
        std::list <Kunde*> kunde;

    public:
        Kunder();
        void leggTil();
        void visAlle();
        void visEnKunde(int tall);
};



#endif

