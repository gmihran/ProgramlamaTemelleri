#include <iostream>
#include <locale.h>
#include <random>
#include <time.h>
using namespace std;
int main() {
  setlocale(LC_ALL,"turkish");
  //Ödev- C++ 11 ile gelen yenilikleri araştırınız.
  //Word dökümanı olarak online.beykoz üzerinden yükleyiniz.
  //Son teslim tarihi:16.12.2019
  
  //Diziler/Arrays:
  int sayilar[5], i;
  sayilar[0]=20;
  sayilar[1]=10;
  sayilar[2]=5;
  cout << sayilar[0] << endl << sayilar[1] << endl;
  cout << "Sayı:";
  cin >> sayilar[3];
  cout << sayilar[3] << endl;
  cout << "Tüm değerler:\n";
  for (i=0;i<=4;i++)
    cout << sayilar[i] << endl;
  //C++ 11 ile gelen bir yenilik:
  cout << "Tüm değerler:\n";
  for (int deger:sayilar)
  {
    cout << deger << endl;
  }
  //Sayılardan sadece çift olanları alt alta ekrana yazdıralım
  cout << "Çift sayılar\n";
  for (int deger:sayilar)
    if (deger%2==0)
      cout << deger << endl;

  //Kullanıcının girdiği 4 değerden pozitif ve negatif değerleri ve toplamlarını ekrana yazdıralım
  int dizi[4],ptoplam=0,ntoplam=0;
  for (i=0;i<=3;i++)
  {
    cout << i+1 << ".sayı:";
    cin >> dizi[i];
  }
  cout << "Pozitif Sayılar\n";
  for (int deger:dizi)
  {
    if (deger>0){
      cout << deger << endl;
      ptoplam+=deger;
      }
  }
  cout << "Pozitif Toplam:" << ptoplam << endl;
  cout << "Negatif Sayılar\n";
  for (int deger:dizi)
  {
    if (deger<0)
    {
      cout << deger << endl;
      ntoplam+=deger;
    }
  }
  cout << "Negatif Toplam:" << ntoplam << endl;

  //Kullanıcıdan bir sayı isteyelim. Rastgele üretilen 1-100 arasındaki 10 sayı arasında kullanıcının girdiği sayı varsa "Tebrikler bildiniz", yoksa "Üzgünüm bilemediniz" çıktısı verilsin
  int tahmin, random[10];
  srand(time(NULL)); //Program her çalıştırıldığında rand fonksiyonun farklı değerler üretmesini sağlar.
  cout << "Tahmininiz:";
  cin >> tahmin;
  for (i=0;i<=9;i++)
  {
    random[i]=rand()%100+1;
    //Başlangıç değeri +1 ile ifade ettiğim 1'dir.
    //Bitiş değeri bu iki değerin toplamının 1 eksiğidir. 100+1-1=100
    //Ör: 20 ile 50 arasında rastgele sayı üreten fonksiyon nedir?
    //rand()%31+20
    cout << random[i] << " ";
  }
  cout << endl;
  bool kontrol=false;
  for (int deger:random)
    if (deger==tahmin)
      kontrol=true;
  
  if (kontrol)
    cout << "Tebrikler,bildiniz.\n";
  else
    cout << "Üzgünüm,bilemediniz\n";
  
  //İlk 100 asal sayıyı bir dizide tutarak bu diziyi ekrana yazdıralım
  int asal[100],sayi=2,miktar;
  bool asal_durum;
  for(miktar=0;miktar<100;)
  {
    asal_durum=true; //sayının asal olduğunu farzedelim
    for (i=2;i<sayi;i++)
      if (sayi%i==0)
      {
        asal_durum=false;
        //sayı asal değildir
        break;
      }
    if (asal_durum)
    {
      asal[miktar]=sayi;
      miktar++;
    }
    sayi++;    
  }
  for (int deger:asal)
    cout << deger << " ";
}