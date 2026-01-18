/** 
* @file sekil.cpp
* @description şekilleri çizdirebilmek için özelliklerini tutuyor.
* @course 1.öğretim b grubu
* @assignment 1.öğretim
* @date 03.11.2025
* @author elif uzunoğlu elif.uzunoglu1@ogr.sakarya.edu.tr
*/
#include "sekil.hpp"

//kurucu fonksiyonun uygulanışı
Sekil::Sekil(int x,int y, int genislik, int yukseklik,char karakter, int z){
    this->x= x;
    this->y= y;
    this->z= z;
    this->genislik= genislik;
    this->yukseklik= yukseklik;
    this->cizimKarakteri=karakter;

}

// sanal yıkıcı fonksiyon
Sekil::~Sekil(){
}

//girilen değerleri aldı
int Sekil::getX() const {
    return x;
}

int Sekil::getY() const {
    return y;
}

int Sekil::getGenislik() const {
    return genislik;
}

int Sekil::getYukseklik() const {
    return yukseklik;
}

char Sekil::getCizimKarakteri() const {
    return cizimKarakteri;
}


//girilen değerleri değiştirme
int Sekil::getZ() const {
    return z;
}

void Sekil::setY(int yeniY) {
    y = yeniY;
}

void Sekil::setX(int yeniX){
    x = yeniX;
}


