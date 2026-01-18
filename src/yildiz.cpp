/** 
* @file yildiz.cpp
* @description Yıldız şeklinin yapısını oluşturuyor
* @course 1.öğretim b grubu
* @assignment 1.ödev
* @date 01.11.2025
* @author Elif Uzunoğlu  elif.uzunoglu1@ogr.sakarya.edu.tr
*/

#include "yildiz.hpp"

Yildiz::Yildiz(int x, int y, int boyut, char karakter, int z)
    :Sekil(x,y,boyut,boyut,karakter,z){

    }

    Yildiz::~Yildiz(){

    }

    void Yildiz::ciz(char** ekranDizisi, int ekranYukseklik, int ekranGenislik){
        int merkezX= x+ genislik/2;
        int merkezY = y+ yukseklik/2;
    
        for(int satir=0; satir<yukseklik; satir++){
            int ekranY = y+ satir;
            
            if(ekranY >=0 && ekranY< ekranYukseklik){
                if(merkezX >=0 && merkezX < ekranGenislik){
                   ekranDizisi[ekranY][merkezX] = cizimKarakteri; 
                }
            }
        }
   
         for (int sutun = 0; sutun < genislik; sutun++) {
        int ekranX = x + sutun;
            
            if(ekranX >=0 && ekranX < ekranGenislik){
                 if(merkezY >=0 && merkezY< ekranYukseklik){
                ekranDizisi[merkezY][ekranX] = cizimKarakteri;
        
            }
            }
           
        }
    };

    const char* Yildiz::getTip() const {
    return "YILDIZ";
}
