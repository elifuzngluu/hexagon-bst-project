#ifndef DIKDORTGEN_HPP
#define DIKDORTGEN_HPP
#include "sekil.hpp"

class Dikdortgen: public Sekil
{
public:
    Dikdortgen(int x, int y, int genislik, int yukseklik, char karakter, int z);
    ~Dikdortgen();

    void ciz(char** ekranDizisi, int ekranYukseklik, int ekranGenislik);

    const char* getTip() const;
};





#endif