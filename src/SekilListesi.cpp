/** 
* @file sekilListesi.cpp
* @description şekillere ait bağlı listeyi oluşturuyor.
* @course 1.öğretim b grubu
* @assignment 1.ödev
* @date 03.11.2025
* @author  Elif Uzunoğlu  elif.uzunoglu1@ogr.sakarya.edu.tr
*/

#include "SekilListesi.hpp"
#include <iostream>
using namespace std;

SekilListesi::SekilListesi(){
    bas= nullptr; // ilk düğüm hiçbir şeyi göstermesin
    elemanSayisi = 0;
}

SekilListesi::~SekilListesi(){
    SekilDugumu* simdiki = bas; //liste başından başla

    while( simdiki != nullptr){ //son düğüme gelmediği sürece
        SekilDugumu* silinecek = simdiki;
        simdiki= simdiki->sonraki;
        delete silinecek;
    }
    bas= nullptr;
    elemanSayisi=0;
}

void SekilListesi::ekle(Sekil* sekil){

    SekilDugumu* yeniDugum= new SekilDugumu(sekil); // yeni düğüm oluştur

    if( bas == nullptr ){ // baştaki düğüm pointerı hiçbir şeyi göstermiyorsa
        bas= yeniDugum;   // artık yeni düğümü göstersin
    }

    else{ // en az bir düğğüm varsa yeni düğümü sona ekle
        SekilDugumu* sonDugum = bas;
         
        while( sonDugum->sonraki != nullptr){ //son düğüme gelene kadar döngü dönecek
            sonDugum = sonDugum->sonraki; 
        }

        sonDugum->sonraki = yeniDugum; //artık son düğümün sonraki null değil yeni düğümü gösteriyor.
    }
    elemanSayisi++;
}


void SekilListesi::sil(int index){

    if(index<0 || index >= elemanSayisi ){
        cout<< "geçersiz indeks girildi"<< endl;
        return;
    }

    else if(index == 0){
        SekilDugumu* silinecek= bas;
        bas= bas->sonraki;
        delete silinecek;
        elemanSayisi--;
        return;
    }

    else{
        SekilDugumu* onceki= bas;

        for(int i=0 ; i<index-1 ; i++ ){
            onceki= onceki->sonraki;
        }

        SekilDugumu* silinecek= onceki->sonraki;
        onceki->sonraki = silinecek->sonraki;

        delete silinecek;
        elemanSayisi--;
    }
}



Sekil* SekilListesi::getSekil(int index) const {

    SekilDugumu* dugum = getDugum(index);

     if(dugum != nullptr){
        return dugum->sekil;
        }
    
return nullptr;
    }



SekilDugumu* SekilListesi::getDugum(int index) const{

    if(index<0 || index>= elemanSayisi){
        return nullptr;
    }

    SekilDugumu* simdiki = bas;

    for(int i=0; i< index; i++){
        simdiki= simdiki->sonraki;
    }

    return simdiki;
}



int SekilListesi::getElemanSayisi() const{
    return elemanSayisi;
}


bool SekilListesi::bosMu() const{
    return ( bas == nullptr);
}

SekilDugumu* SekilListesi::getBas() const {
    return bas;
}
