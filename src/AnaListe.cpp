/** 
* @file anaListe.cpp
* @description şekilleri tutan bağlı listeyi tutan iki yönlü bağlı listenin liste yapısını oluşturuyor.
* @course 1.öğretim b grubu
* @assignment 1.ödev
* @date 04.11.2025
* @author elif uzunoğlu elif.uzunoglu1@ogr.sakarya.edu.tr
*/
#include "AnaListe.hpp"
#include "SekilListesi.hpp"
#include  <iostream>
using namespace std;

AnaListe::AnaListe(){
    bas=nullptr;
    son=nullptr;
    simdiki=nullptr; //üstünde bulunduğum düğüm
    dugumSayisi=0;
}

AnaListe::~AnaListe(){
    AnaDugum* itr =bas; //baştaki düğümü kaybetmemek ve listeyi dolaşmak için itr

    while( itr != nullptr){ //tüm düğümleri sil
        AnaDugum* silinecek=itr;
        itr= itr->sonraki;
        delete silinecek;
    }

    bas= nullptr;
    son= nullptr;
    simdiki= nullptr;
    dugumSayisi=0;
}


//sona düğüm ekleme
void AnaListe::dugumEkle(){
    int yeniNumara = dugumSayisi + 1;

    AnaDugum* yeniDugum= new AnaDugum(yeniNumara);

    //eğer hiçbir düğüm yoksa yani baş pointerı hiçbir düğümü göstermiyorsa
    if(bas == nullptr){
        bas = yeniDugum;
        son = yeniDugum;
        simdiki = yeniDugum;
    }

    //en az bir düğüm varsa
    else{
        son->sonraki = yeniDugum;
        yeniDugum->onceki = son;
        son = yeniDugum;
    }

    dugumSayisi++;
}


void AnaListe::dugumSil(int dugumNumarasi){

    //hiçbir düğüm olmayabilir
    if(bas == nullptr){
        cout<<"silinecek bir düğüm yok"<<endl;
        return;
    }

    //silinecek düğümü bul
    AnaDugum* silinecek= getDugum(dugumNumarasi);

    //tek bir düğüm olabilir
    if(bas->sonraki == nullptr){
        bas=nullptr;
        son=nullptr;
        simdiki=nullptr;
        delete silinecek;
        dugumSayisi--;
    }

    //ilk düğüm silinmek isteniyorsa
    else if( silinecek == bas){
        bas = bas->sonraki;
        bas->onceki =nullptr;
        simdiki= bas;
        delete silinecek;
        dugumSayisi--;
    }

    //son düğüm silinmek isteniyorsa
    else if(silinecek == son){
        son = son->onceki;
        son->sonraki= nullptr;
        simdiki= son;
        delete silinecek;
        dugumSayisi--;
    }

    //aradaki bir düğüm silinmek isteniyorsa
    else{
        silinecek->onceki->sonraki = silinecek->sonraki;
        silinecek->sonraki->onceki = silinecek->onceki;

        simdiki= silinecek->sonraki;
        delete silinecek;
        dugumSayisi--;
    }

    //düğüm numaralarını düzenleme
    AnaDugum* itr = bas;
    int yeniNumara = 1;
    while(itr != nullptr){
        itr->DugumNumarasi = yeniNumara;
        yeniNumara++;
        itr = itr->sonraki;
    }
}





AnaDugum* AnaListe::getDugum(int dugumNumarasi) const {
    AnaDugum* itr = bas;
    while(itr != nullptr){
        if(itr->DugumNumarasi == dugumNumarasi){
            return itr;
        }
        itr = itr->sonraki;
    }
    return nullptr;
}

AnaDugum* AnaListe::getSimdiki() const {
    return simdiki;
}

bool AnaListe::sonrakiDugum(){
    if(simdiki != nullptr && simdiki->sonraki != nullptr){
        simdiki = simdiki->sonraki;
        return true;
    }
    return false;
}

bool AnaListe::oncekiDugum(){
    if(simdiki != nullptr && simdiki->onceki != nullptr){
        simdiki = simdiki->onceki;
        return true;
    }
    return false;
}

void AnaListe::ilkDugumeGit(){
    simdiki = bas;
}

void AnaListe::sonDugumeGit(){
    simdiki = son;
}

int AnaListe::getDugumSayisi() const {
    return dugumSayisi;
}

bool AnaListe::bosMu() const {
    return (bas == nullptr);
}

AnaDugum* AnaListe::getBas() const {
    return bas;
}

AnaDugum* AnaListe::getSon() const {
    return son;
}

