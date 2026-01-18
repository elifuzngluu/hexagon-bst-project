#ifndef SEKİL_HPP
#define SEKİL_HPP

class Sekil{
    protected:
     int x;  
     int y;
     int genislik;
     int yukseklik;
     char cizimKarakteri;
     int z;  // çizim önceliği hangisi önde görünecek
    
     public:
      Sekil(int x, int y, int genislik,int yukseklik,char karakter,int z); //kurucu fonksiyon
      
      virtual ~Sekil(); // yıkıcı
      virtual void ciz(char** EkranDizisi, int ekranYukseklik, int ekranGenislik)=0; //sanal fonksiyon, gövdesi yok
    
    // private verilere erişmek için get fonksiyonu kullandık.
    int getX() const;
    int getY() const;
    int getGenislik() const;
    int getYukseklik() const;
    char getCizimKarakteri() const;
    int getZ() const;

    void setX(int yeniX);
    void setY(int yeniY);
    
    //dosyaya kaydetmek için şeklin tipini string dondurur
    virtual const char* getTip() const=0;

};
#endif