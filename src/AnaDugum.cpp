/** 
* @file anaDugum.cpp
* @description şekilleri tutan bağlı listeyi tutam iki yönlü bağlı listenin düğüm yapısını oluşturuyor.
* @course 1.öğretim b grubu
* @assignment 1.ödev
* @date 04.11.2025
* @author elif uzunoğlu elif.uzunoglu1@ogr.sakarya.edu.tr
*/
#include "AnaDugum.hpp"
#include "SekilListesi.hpp"

AnaDugum::AnaDugum(int numara) {
    this->DugumNumarasi = numara;        
    this->sekilListesi = new SekilListesi();  
    this->onceki = nullptr;              
    this->sonraki = nullptr;             
}

AnaDugum::~AnaDugum(){
    if(sekilListesi != nullptr){
        delete sekilListesi;
        sekilListesi = nullptr;
    }

}