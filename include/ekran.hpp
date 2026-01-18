#ifndef EKRAN_HPP
#define EKRAN_HPP
#include "AnaListe.hpp"

class Ekran{
private:
    static const int YUKSEKLIK = 25;
    static const int GENISLIK = 80;

    char** ekranDizisi;
    int** zDegeri;

    void ekraniTemizle();

    void zDegeriTemizle();

public:
    Ekran();

    ~Ekran();

    void ciz(AnaListe* anaListe);

    void simdikiDugumuCiz(AnaListe* anaListe);

    void ekraniGoster();

    int getYukseklik() const;
    int getGenislik() const;

};

#endif