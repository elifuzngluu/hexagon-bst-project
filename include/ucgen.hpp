#ifndef UCGEN_HPP
#define UCGEN_HPP
#include "sekil.hpp"

class Ucgen: public Sekil
{
    public:
    //kurucu fonksiyonu
    Ucgen(int x, int y, int boyut, char karakter, int z);

    //yıkıcı fonksiyonu
    ~Ucgen();

    void ciz(char** ekranDizisi, int ekranYukseklik, int ekranGenislik);

    //dosyaya kayıt için şeklin tipini döndürme işlemi
    const char* getTip() const;
};

#endif