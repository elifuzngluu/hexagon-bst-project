/** 
* @file main.cpp
* @description şekillerle ilgili tüm işlmleri gerçekleştiren, iki yönlü ve tek yönlü bağlı listelerde işlem yapmayı sağlayan program
* @course 1.öğretim b grubu
* @assignment 1.ödev
* @date 15.11.2025 - 16.11.2025 - 19.11.2025
* @author elif uzunoğlu elif.uzunoglu1@ogr.sakarya.edu.tr
*/
#include "AnaListe.hpp"
#include "sekil.hpp"
#include "SekilListesi.hpp"
#include "ucgen.hpp"
#include "dikdortgen.hpp"
#include "yildiz.hpp"
#include "ekran.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <conio.h>
using namespace std;

void rastgeleOlustur(AnaListe* anaListe);
bool dosyadanYukle(AnaListe* anaListe, const string& dosyaAdi);
void dosyayaKaydet(AnaListe* anaListe, const string& dosyaAdi);
Sekil* rastgeleSekil(int ekranGenislik, int ekranYukseklik);
bool anaMenu(AnaListe* anaListe, Ekran* ekran);
void sekilMenusu(AnaListe* anaListe, Ekran* ekran);
void bilgiYazdir(AnaListe* anaListe);

int main(){

    srand(time(0));

    bool programDevam = true;
    
    while(programDevam){
        AnaListe* anaListe= new AnaListe();
        Ekran* ekran = new Ekran();

        string dosyaYolu = "veriler.txt";

        cout << "1. Sekilleri rastgele olustur" << endl;
        cout << "2. Dosyadan yukle" << endl;
        cout << "Seciminiz: ";

        int secim;
        cin >> secim;

         while(secim != 1 && secim != 2) {
            cout << "Gecersiz secim! Lutfen 1 veya 2 girin: ";
            cin >> secim;
        }

        if(secim == 1) {
            rastgeleOlustur(anaListe);
        } 

        else{
            bool dosyaBasarili = dosyadanYukle(anaListe ,dosyaYolu);
             if(!dosyaBasarili) {
                rastgeleOlustur(anaListe);
            }
        }
    programDevam = anaMenu(anaListe, ekran);
    dosyayaKaydet(anaListe, dosyaYolu);

    delete ekran;
    delete anaListe;

    if(programDevam){
        system("pause");
      }
    }
    return 0;
}

void rastgeleOlustur(AnaListe* anaListe){
    int dugumSayisi=20;

    for(int i=0 ; i<dugumSayisi; i++){
        anaListe->dugumEkle();

        AnaDugum* sonDugum = anaListe->getSon();
        int sekilSayisi = 2 + rand()%6; // 2-7 arası rastgele seçecek
        
        for(int j=0; j<sekilSayisi; j++){
            Sekil* yeniSekil = rastgeleSekil(80,25);
            sonDugum->sekilListesi->ekle(yeniSekil);
        }
    }
     anaListe->ilkDugumeGit();
}


Sekil* rastgeleSekil(int ekranGenislik, int ekranYukseklik){

    int sekilNo= rand()%3; // 0=Ucgen, 1=Dikdortgen, 2=Yildiz gibi...

    int maxBoyut= ekranYukseklik;
    int minBoyut=3;

    int boyut = minBoyut + rand() % (maxBoyut - minBoyut + 1); //3 ile 25 arası rastgele bir boyut

    int maxX, maxY;

    if(sekilNo==0){//yani üçgense
        maxX = ekranGenislik- (boyut * 2 -1);
        maxY = ekranYukseklik - boyut;
    } 

    else if(sekilNo == 1) {  // Dikdörtgense
        maxX = ekranGenislik - boyut;
        maxY = ekranYukseklik - boyut;
    }

    else {  // Yıldızsa
        maxX = ekranGenislik - boyut;
        maxY = ekranYukseklik - boyut;
    }

    //negatif bir konumsa x=0,y=0 'a ayarla
    if(maxX < 0) maxX = 0;
    if(maxY < 0) maxY = 0;

    int x= rand()% (maxX + 1);
    int y= rand()% (maxY + 1);

    char karakterler[]= {'*','#','@','+','X'}; 
    char karakter = karakterler[ rand() % 5 ];

    int z= rand() % 10;

    if(sekilNo == 0){
        return new Ucgen(x, y, boyut, karakter, z);
    }
    else if(sekilNo == 1){
        int genislik = boyut;
        int yukseklik = minBoyut + rand() % (boyut - minBoyut + 1);
        return new Dikdortgen(x, y, genislik, yukseklik, karakter, z);
    }

    else{
        return new Yildiz(x, y, boyut, karakter, z);
    }
}



bool dosyadanYukle(AnaListe* anaListe, const string& dosyaAdi) {
    ifstream dosya(dosyaAdi.c_str());
    
    if(!dosya.is_open()) {
        return false;
    }
    
    int dugumSayisi;
    dosya >> dugumSayisi;

    if(dosya.fail()){
        dosya.close();
        return false;
    }
    
    for(int i = 0; i < dugumSayisi; i++) {
        anaListe->dugumEkle();
        AnaDugum* sonDugum = anaListe->getSon();
        
        int sekilSayisi;
        dosya >> sekilSayisi;
        
        if(dosya.fail()){
        dosya.close();
        return false;
        }
        
        for(int j = 0; j < sekilSayisi; j++) {
            string tip;
            int x, y, genislik, yukseklik, z;
            char karakter;
            
            dosya >> tip >> x >> y >> genislik >> yukseklik >> karakter >> z;

            if(dosya.fail()){
                dosya.close();
                return false;
            }
            
            Sekil* yeniSekil = nullptr;
            
            if(tip == "UCGEN") {
                yeniSekil = new Ucgen(x, y, genislik, karakter, z);
            }
            else if(tip == "DIKDORTGEN") {
                yeniSekil = new Dikdortgen(x, y, genislik, yukseklik, karakter, z);
            }
            else if(tip == "YILDIZ") {
                yeniSekil = new Yildiz(x, y, genislik, karakter, z);
            }
            
            if(yeniSekil != nullptr) {
                sonDugum->sekilListesi->ekle(yeniSekil);
            } 
        }
    }
    dosya.close();
    anaListe->ilkDugumeGit();
    return true;   
}




void dosyayaKaydet(AnaListe* anaListe, const string& dosyaAdi) {
    ofstream dosya(dosyaAdi.c_str());
    
    if(!dosya.is_open()) {
        cout << "Hata: Dosya olusturulamadi!" << endl;
        return;
    }
    
    // Dugum sayisini yaz
    dosya << anaListe->getDugumSayisi() << endl;
    
    // Her dugumu dolas
    AnaDugum* dugumItr = anaListe->getBas();
    
    while(dugumItr != nullptr) {
        // Bu dugumun sekil sayisini yaz
        dosya << dugumItr->sekilListesi->getElemanSayisi() << endl;
        
        // Her sekli yaz
        SekilDugumu* sekilItr = dugumItr->sekilListesi->getBas();
        
        while(sekilItr != nullptr) {
            Sekil* sekil = sekilItr->sekil;
            
            // Format: TIP X Y GENISLIK YUKSEKLIK KARAKTER Z
            dosya << sekil->getTip() << " "
                  << sekil->getX() << " "
                  << sekil->getY() << " "
                  << sekil->getGenislik() << " "
                  << sekil->getYukseklik() << " "
                  << sekil->getCizimKarakteri() << " "
                  << sekil->getZ() << endl;
            
            sekilItr = sekilItr->sonraki;
        }
        
        dugumItr = dugumItr->sonraki;
    }
    
    dosya.close();
}




bool anaMenu(AnaListe* anaListe, Ekran* ekran) {
    bool devam = true;
    
    while(devam) {
        // Şu anki düğümü çiz
        ekran->simdikiDugumuCiz(anaListe);
        ekran->ekraniGoster();

        bilgiYazdir(anaListe);
        
        cout << "\n--- ANA MENU ---" << endl;
        cout << "W: Onceki dugum (yukari)" << endl;
        cout << "S: Sonraki dugum (asagi)" << endl;
        cout << "F: Dugumu sec (sekil menusu)" << endl;
        cout << "C: Dugumu sil" << endl;
        cout << "Q: Cikis" << endl;
        cout << "\nKomut: ";
        
        char komut = _getch();
        cout << komut << endl;
        
        switch(komut) {
            case 'w':
            case 'W':
                if(!anaListe->oncekiDugum()) {
                    cout << "Zaten ilk dugumdeyiz!" << endl;
                    _getch();
                }
                break;
                
            case 's':
            case 'S':
                if(!anaListe->sonrakiDugum()) {
                    cout << "Zaten son dugumdeyiz!" << endl;
                     _getch();
                }
                break;
                
            case 'f':
            case 'F':
                sekilMenusu(anaListe, ekran);
                break;
                
            case 'q':
            case 'Q':
                devam = false;
                break;

            case 'c':
            case 'C':
             if(anaListe->getDugumSayisi() > 1) {
                 AnaDugum* silinecekDugum = anaListe->getSimdiki();  // Şu anki düğümü al
                int dugumNo = silinecekDugum->DugumNumarasi;        // Numarasını kaydet
                anaListe->dugumSil(dugumNo);                        // Sil
                dosyayaKaydet(anaListe, "veriler.txt");                       
             }
             break;
                
            default:
                cout << "Gecersiz komut!" << endl;
                break;  
        }
    }
  return true;
}

void sekilMenusu(AnaListe* anaListe, Ekran* ekran) {
    AnaDugum* simdikiDugum = anaListe->getSimdiki();
    
    if(simdikiDugum == nullptr || simdikiDugum->sekilListesi->bosMu()) { 
        return;
    }
    
    int secilenSekilIndex = 0;
    bool sekilMenuDevam = true;
    
    while(sekilMenuDevam) {
        // Ekranı çiz
        ekran->simdikiDugumuCiz(anaListe);
        ekran->ekraniGoster();
        
        // Şekil bilgilerini göster
        cout << "\nSEKIL MENUSU -> " << simdikiDugum->DugumNumarasi << ". DUGUM" << endl;
        cout << "Toplam Sekil: " << simdikiDugum->sekilListesi->getElemanSayisi() << endl;
        cout << "\n--- KONTROLLER ---" << endl;
        cout << "Q: Onceki sekil" << endl;
        cout << "E: Sonraki sekil" << endl;
        cout << "W: Yukari hareket ettir" << endl;
        cout << "S: Asagi hareket ettir" << endl;
        cout << "A: Sola hareket ettir" << endl;
        cout << "D: Saga hareket ettir" << endl;
        cout << "C: Sekli sil" << endl;
        cout << "Z: Ana menuye don" << endl;
        cout << "\nKomut: ";
        
        char komut = _getch();
        cout << komut << endl;
        
        Sekil* secilenSekil = simdikiDugum->sekilListesi->getSekil(secilenSekilIndex);
        
        switch(komut) {
            case 'q':
            case 'Q':
                // Önceki şekil
                if(secilenSekilIndex > 0) {
                    secilenSekilIndex--;
                } 
                break;
                
            case 'e':
            case 'E':
                // Sonraki şekil
                if(secilenSekilIndex < simdikiDugum->sekilListesi->getElemanSayisi() - 1) {
                    secilenSekilIndex++;
                } 
                break;
                
            case 'w':
            case 'W':
                // Yukarı hareket
                if(secilenSekil != nullptr) {
                    int yeniY = secilenSekil->getY() - 1;
                    if(yeniY >= 0) {
                        secilenSekil->setY(yeniY);
                        dosyayaKaydet(anaListe, "veriler.txt");
                    } 
                      
                }
                break;
                
            case 's':
            case 'S':
                // Aşağı hareket
                if(secilenSekil != nullptr) {
                    int yeniY = secilenSekil->getY() + 1;
                    if(yeniY + secilenSekil->getYukseklik() <= ekran->getYukseklik()) {
                        secilenSekil->setY(yeniY);
                        dosyayaKaydet(anaListe, "veriler.txt");
                    }
                }
                break;
                
            case 'a':
            case 'A':
                // Sola hareket
                if(secilenSekil != nullptr) {
                    int yeniX = secilenSekil->getX() - 1;
                    if(yeniX >= 0) {
                        secilenSekil->setX(yeniX);
                        dosyayaKaydet(anaListe, "veriler.txt");
                    } 
                }
                break;
                
            case 'd':
            case 'D':
                // Sağa hareket
                if(secilenSekil != nullptr) {
                    int yeniX = secilenSekil->getX() + 1;
                    int genislik = secilenSekil->getGenislik();
                    if(secilenSekil->getTip() == string("UCGEN")) {
                        genislik = genislik * 2 - 1;
                    }
                    if(yeniX + genislik <= ekran->getGenislik()) {
                        secilenSekil->setX(yeniX);
                        dosyayaKaydet(anaListe, "veriler.txt");
                    } 
                }
                break;
                
            case 'c':
            case 'C':
                // Şekli sil
                simdikiDugum->sekilListesi->sil(secilenSekilIndex);
                dosyayaKaydet(anaListe, "veriler.txt");
                
                // Eğer liste boşaldıysa veya son şekil silindiyse
                if(simdikiDugum->sekilListesi->bosMu()) {  
                    sekilMenuDevam = false;
                } else {
                    // İndeksi ayarla
                    if(secilenSekilIndex >= simdikiDugum->sekilListesi->getElemanSayisi()) {
                        secilenSekilIndex = simdikiDugum->sekilListesi->getElemanSayisi() - 1;
                    }  
                }
                break;
                
            case 'z':
            case 'Z':
                // Ana menüye dön
                sekilMenuDevam = false;
                break;
                
            default:  
                break;
        }
    }
}

void bilgiYazdir(AnaListe* anaListe) {
    AnaDugum* simdiki = anaListe->getSimdiki();
    
    if(simdiki == nullptr) {
        cout << "Liste bos!" << endl;
        return;
    }
    
    cout << "\n--- DUGUM BILGISI ---" << endl;
    cout << "Dugum Numarasi: " << simdiki->DugumNumarasi << " / " << anaListe->getDugumSayisi() << endl;
    cout << "Sekil Sayisi: " << simdiki->sekilListesi->getElemanSayisi() << endl;
}
