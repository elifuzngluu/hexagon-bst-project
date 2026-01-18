#ifndef ANALİSTE_HPP
#define ANALİSTE_HPP
#include "AnaDugum.hpp"

class AnaListe{
private:
    AnaDugum* bas;
    AnaDugum* son;
    AnaDugum* simdiki;
    int dugumSayisi;

public:
    AnaListe();

    ~AnaListe();

    void dugumEkle();

    void dugumSil(int dugumNumarasi);

    AnaDugum* getDugum(int dugumNumarasi) const;

    AnaDugum* getSimdiki() const;

    bool sonrakiDugum();

    bool oncekiDugum();

    void ilkDugumeGit();

    void sonDugumeGit();
    
    int getDugumSayisi() const;

    bool bosMu() const; 
    
    AnaDugum* getBas() const; //ilk düğümü döndürecek
    AnaDugum* getSon() const; // son düğümü döndürecek

};
#endif