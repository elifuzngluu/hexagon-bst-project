/** 
* @file dikdortgen.cpp
* @description dikdortgen şeklinin yapısını oluşturuyor.
* @course 1.öğretim b grubu
* @assignment 1.ödev
* @date 01.11.2025
* @author Elif Uzunoğlu  elif.uzunoglu1@ogr.sakarya.edu.tr
*/

#include "dikdortgen.hpp"
Dikdortgen::Dikdortgen(int x, int y,int genislik, int yukseklik , char karakter, int z)
    :Sekil(x,y,genislik,yukseklik,karakter,z){
        
    }
Dikdortgen::~Dikdortgen(){

}

void Dikdortgen::ciz(char** ekranDizisi, int ekranYukseklik,int ekranGenislik){
    for(int satir=0 ; satir<yukseklik ; satir++){
        int ekranY = y+ satir;
        if(ekranY <0 || ekranY >= ekranYukseklik){
            continue;
        }

        for(int sutun=0 ; sutun<genislik; sutun++){
            int ekranX= x+ sutun;
            if(ekranX >=0 && ekranX< ekranGenislik){
                ekranDizisi[ekranY][ekranX] = cizimKarakteri;
            }
        }

    }
}

const char*  Dikdortgen:: getTip() const {
    return "DIKDORTGEN";
}