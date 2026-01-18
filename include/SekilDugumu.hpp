#ifndef SEKILDUGUMU_HPP
#define SEKILDUGUMU_HPP

#include "Sekil.hpp"

class SekilDugumu{
public:
    Sekil* sekil;
    SekilDugumu* sonraki;

    SekilDugumu(Sekil* sekil);

    ~SekilDugumu();

};
#endif