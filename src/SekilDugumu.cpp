/** 
* @file sekilDugumu.cpp
* @description şekilleri tutacak düğüm yapısını oluşturur
* @course 1.öğretim b grubu
* @assignment 1.öğretim
* @date 02.11.2025
* @author elif uzunoğlu elif.uzunoglu1@ogr.sakarya.edu.tr
*/
#include "SekilDugumu.hpp"

SekilDugumu::SekilDugumu(Sekil* sekil){
    this->sekil= sekil;
    this->sonraki= nullptr;
}

SekilDugumu::~SekilDugumu(){
    if(sekil != nullptr){
        delete sekil;

        sekil= nullptr;
    }
}



