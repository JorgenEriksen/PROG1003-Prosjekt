#ifndef Soner_h
#define Soner_h

#include <map>
#include "Sone.h"

class Soner  {
    private:
        int sisteNr = 0;
        std::map <int, Sone*> sone;
    public:
        void leggTil();
        void visAlle();
};

#endif
