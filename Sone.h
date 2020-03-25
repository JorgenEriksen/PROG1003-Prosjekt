#ifndef Sone_h
#define Sone_h

#include <string>

class Sone {
    private:
        int idNummer;
        std::string beskrivelse;
        // vector <Bolig*>: bolig;
    public:
        Sone(int soneNummer);
        void skrivHovedData();
        void skrivAllData();

};

#endif
