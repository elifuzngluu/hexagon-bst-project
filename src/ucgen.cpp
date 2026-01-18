/** 
* @file ucgen.cpp
* @description üçgen şeklinin yapısını oluşturur.
* @course 1.öğretim b grubu
* @assignment 1.ödev
* @date 01.11.2025
* @author Elif Uzunoğlu  elif.uzunoglu1@ogr.sakarya.edu.tr
*/

#include "ucgen.hpp"

Ucgen::Ucgen(int x, int y, int boyut, char karakter, int z) 
    : Sekil(x, y, boyut, boyut, karakter, z) { // eşkenar üçgen olduğu için boyut hem yükseklik hem de genişlik oldu

}

Ucgen::~Ucgen(){}

void Ucgen::ciz(char** ekranDizisi, int ekranYukseklik, int ekranGenislik){
    for (int satir = 0; satir < yukseklik; satir++){
        int ekranY = y + satir;

        //ekrandan taşma kontrolü
        if(ekranY <0 || ekranY >= ekranYukseklik){
            continue;
        }

         int karakterSayisi = 2 * satir + 1;
         int solBosluk = (genislik * 2 - 1 - karakterSayisi) / 2;

        // karakteri çizdirme
         for (int i = 0; i < karakterSayisi; i++){
            int ekranX = x + solBosluk + i;

            if(ekranX < ekranGenislik && ekranX >= 0){
            ekranDizisi[ekranY][ekranX] = cizimKarakteri;
            }
         }
    } 
}

//dosyaya "UCGEN" yazacak
const char* Ucgen::getTip() const {
    return "UCGEN";
}
