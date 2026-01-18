#ifndef YİLDİZ_HPP
#define YİLDİZ_HPP
#include "sekil.hpp"

class Yildiz: public Sekil{
    public:
    Yildiz(int x, int y, int boyut, char karakter, int z);
    ~Yildiz();

    void ciz(char** ekranDizisi, int ekranYukseklik, int ekranGenislik);

    const char* getTip() const;
};

#endif