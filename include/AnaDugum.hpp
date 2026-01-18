#ifndef ANADUGUM_HPP
#define ANADUGUM_HPP

class SekilListesi;
class AnaDugum{
public:
    SekilListesi* sekilListesi;
    AnaDugum* onceki;
    AnaDugum* sonraki;
    int DugumNumarasi;

    AnaDugum(int numara);

    ~AnaDugum();
};
#endif