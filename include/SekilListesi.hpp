#ifndef SEKILLISTESİ_HPP
#define SEKILLISTESİ_HPP

#include "SekilDugumu.hpp"

class SekilListesi{
private:
    SekilDugumu* bas;
    int elemanSayisi;

public:
    SekilListesi(); //boş liste oluştursun
   
    ~SekilListesi();

    void ekle(Sekil* sekil);

    void sil(int index);

    Sekil* getSekil(int index) const;

    SekilDugumu* getDugum(int index) const;

    int getElemanSayisi() const;

    SekilDugumu* getBas() const;

    bool bosMu() const; 
};
#endif