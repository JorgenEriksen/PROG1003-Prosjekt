#ifndef Sone_h
#define Sone_h

#include <string>
#include <vector>

#include "Bolig.h"



class Sone {
    private:
        int idNummer;
        std::string beskrivelse;
        std::vector <Bolig*> bolig;
    public:
        Sone(int soneNummer);
        void skrivHovedData();
        void skrivAllData();
        void nyLeilighet(int sisteNr);
        void nyEnebolig(int sisteNr);


};

#endif
