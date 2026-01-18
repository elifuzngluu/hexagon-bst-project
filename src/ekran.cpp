/** 
* @file ekran.cpp
* @description konsolda ekranla ilgili tüm işlemleri yapıyor.
* @course 1.öğretim b grubu
* @assignment 1.ödev
* @date 20.11.2025
* @author elif uzunoğlu elif.uzunoglu1@ogr.sakarya.edu.tr
*/
#include "ekran.hpp"
#include "SekilListesi.hpp"
#include "SekilDugumu.hpp"
#include <iostream>
#include <cstdlib> // syystem(cls) için
using namespace std;


Ekran::Ekran(){

    ekranDizisi= new char*[YUKSEKLIK];
    for(int i=0 ; i<YUKSEKLIK ; i++){
        ekranDizisi[i] =new char[GENISLIK];
    }


    zDegeri= new int*[YUKSEKLIK];
    for(int i=0 ; i<YUKSEKLIK; i++){
        zDegeri[i] = new int[GENISLIK];
    }

    ekraniTemizle();
    zDegeriTemizle();
}


Ekran::~Ekran(){

    for(int i=0; i<YUKSEKLIK; i++){
        delete[] ekranDizisi[i];
    }
    delete[] ekranDizisi;

    for(int i=0; i<YUKSEKLIK; i++){
        delete[] zDegeri[i];
    }
    delete[] zDegeri;
}

void Ekran::ekraniTemizle() {
    for(int y = 0; y < YUKSEKLIK; y++) {
        for(int x = 0; x < GENISLIK; x++) {
            ekranDizisi[y][x] = ' ';  
        }
    }
}

void Ekran::zDegeriTemizle() {
    for(int y = 0; y < YUKSEKLIK; y++) {
        for(int x = 0; x < GENISLIK; x++) {
            zDegeri[y][x] = -9999;  // Cok dusuk z degeri (en arkada)
        }
    }
}

void Ekran::ciz(AnaListe* anaListe) {
    
    ekraniTemizle();
    zDegeriTemizle();
    
    if(anaListe->bosMu()) {
        return;
    }

    AnaDugum* dugumItr = anaListe->getBas();

    while (dugumItr != nullptr) {
        
        if(dugumItr->sekilListesi != nullptr) {
            SekilDugumu* sekilItr = dugumItr->sekilListesi->getBas();

            while (sekilItr != nullptr) {
                
                Sekil* sekil = sekilItr->sekil;

                if(sekil != nullptr) {
                    int z = sekil->getZ();  
                    
                    // Geçici ekran oluştur
                    char** tempEkran = new char*[YUKSEKLIK];
                    for(int i = 0; i < YUKSEKLIK; i++) {
                        tempEkran[i] = new char[GENISLIK];
                        for(int j = 0; j < GENISLIK; j++) {
                            tempEkran[i][j] = ' ';
                        }
                    }
                    
                    // Şekli geçici ekrana çiz
                    sekil->ciz(tempEkran, YUKSEKLIK, GENISLIK);
                    
                    // Geçici ekrandan gerçek ekrana kopyala 
                    for(int tempY = 0; tempY < YUKSEKLIK; tempY++) {
                        for(int tempX = 0; tempX < GENISLIK; tempX++) {
                            if(tempEkran[tempY][tempX] != ' ') {
                                if(z > zDegeri[tempY][tempX]) {
                                    ekranDizisi[tempY][tempX] = tempEkran[tempY][tempX];
                                    zDegeri[tempY][tempX] = z;
                                }
                            }
                        }
                    }
                    
                    // Geçici ekranı temizle
                    for(int i = 0; i < YUKSEKLIK; i++) {
                        delete[] tempEkran[i];
                    }
                    delete[] tempEkran;
                }
                
                sekilItr = sekilItr->sonraki;
            }
        }
        
        dugumItr = dugumItr->sonraki;
    }
}



void Ekran::simdikiDugumuCiz( AnaListe* anaListe ){

    ekraniTemizle();
    zDegeriTemizle();

    AnaDugum* simdikiDugum = anaListe->getSimdiki();
    if( simdikiDugum == nullptr || simdikiDugum->sekilListesi == nullptr ) 
        return;
    
    SekilDugumu* sekilItr = simdikiDugum->sekilListesi->getBas();

    while (sekilItr != nullptr)
    {
        Sekil* sekil = sekilItr->sekil;

        if(sekil != nullptr){
            int z= sekil->getZ();

            //geçici ekranoluşturma
            char** tempEkran = new char*[YUKSEKLIK];
            for(int i = 0; i < YUKSEKLIK; i++) {
                tempEkran[i] = new char[GENISLIK];
                for(int j = 0; j < GENISLIK; j++) {
                    tempEkran[i][j] = ' ';
                }
            }
        
         sekil->ciz(tempEkran, YUKSEKLIK,GENISLIK);   

         //şekli geçici ekrana çizdir
          for(int tempY = 0; tempY < YUKSEKLIK; tempY++) {
                for(int tempX = 0; tempX < GENISLIK; tempX++) {
                    if(tempEkran[tempY][tempX] != ' ') {
                        if(z > zDegeri[tempY][tempX]) {
                            ekranDizisi[tempY][tempX] = tempEkran[tempY][tempX];
                            zDegeri[tempY][tempX] = z;
                        }
                    }
                }
            }


        for(int i=0 ;i< YUKSEKLIK; i++){
            delete[] tempEkran[i];
        }
        delete[] tempEkran;
        }

        sekilItr = sekilItr->sonraki;
    }
    
}


// Ekrani konsola yazdirir
void Ekran::ekraniGoster() {
    // Ekrani temizle (Windows icin)
    system("cls");
    
    // Ust cerceve
    cout << "+";
    for(int i = 0; i < GENISLIK; i++) {
        cout << "-";
    }
    cout << "+" << endl;
    
    // Ekran icerigini yazdir
    for(int y = 0; y < YUKSEKLIK; y++) {
        cout << "|";  // Sol cerceve
        for(int x = 0; x < GENISLIK; x++) {
            cout << ekranDizisi[y][x];
        }
        cout << "|" << endl;  // Sag cerceve
    }
    
    // Alt cerceve
    cout << "+";
    for(int i = 0; i < GENISLIK; i++) {
        cout << "-";
    }
    cout << "+" << endl;
}

// Ekran yuksekligini dondurur
int Ekran::getYukseklik() const {
    return YUKSEKLIK;
}

// Ekran genisligini dondurur
int Ekran::getGenislik() const {
    return GENISLIK;
}
