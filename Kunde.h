#ifndef Kunde_h
#define Kunde_h

#include <string>
#include <vector>

class Kunde  {
    private:
        int kundeNr,
            telefon;
        std::string navn,
                    gateadresse,
                    postadresse,
                    mail;
        enum boligtye {Leilighet, Enebolig};
        std::vector <int> soneNr;
    public:
        Kunde();
        Kunde(int kundeNummer);
        void skrivHovedData();
        void skrivAllData();
        int returKundeNr();

};

#endif
