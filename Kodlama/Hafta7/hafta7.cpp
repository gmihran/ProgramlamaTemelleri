#include <iostream>
#include <locale.h>
using namespace std;
int main() {
  setlocale(LC_ALL,"Turkish");
  //Girilen iki sayıdan büyük olanının karesini ekrana yazdıralım. Eğer sayılar birbirine eşitse sayılardan herhangi birini alıp, karesini yazdırabiliriz.
  //Ör:Klavyeden 10 5 sayıları girilirse; 100 çıktısını verecek
  //Ör:Klavyeden 10 10 sayıları girilirse; 100 çıktısını verecek 
  int sayi1,sayi2;
  
  cout << "2 sayı girin:";
  cin >> sayi1 >> sayi2;
  if (sayi1>sayi2)
    cout << "Karesi:" << sayi1*sayi1;
  else
    cout << "Karesi:" << sayi2*sayi2;
  cout << endl;
  //Girilen iki sayıdan büyük olanının karesini ekrana yazdıralım. Eğer sayılar birbirine eşitse sayılardan birinin küpünü alalım.
  //Ör:Klavyeden 10 5 sayıları girilirse; 100 çıktısını verecek
  //Ör:Klavyeden 10 10 sayıları girilirse; 1000 çıktısını verecek 
  //int sayi1,sayi2;
  cout << "İki sayı girin:";
  cin >> sayi1 >> sayi2;
  if (sayi1>sayi2)
    cout << "Karesi:" << sayi1*sayi1;
  else if (sayi2>sayi1)
    cout << "Karesi:" << sayi2*sayi2;
  else
    cout << "Küpü:" << sayi1*sayi1*sayi1;
    //cout << "Küpü:" << sayi2*sayi2*sayi2;
  cout << endl;

  //Klavyeden girilen 5 sayıdan en büyük sayıyı ve sayının 2'ye bölümünden kalanını ekrana yazdıralım.
  //Not: Bu problem çözümünde girilen değerler bir değişkende tutulup, bu değerler for döngüsünün içerisinde alınacak ve en büyük sayı yine for döngüsünün içerisinde hesaplanacak
  int sayi,i,mak;
  
  for (i=1;i<=5;i++)
  {
    cout << i << ".sayıyı giriniz:";
    cin >> sayi;
    if (i==1)
    //Eğer girilen ilk sayı ise i değeri 1'e eşittir ve bu adım çalışarak mak değerin içinde ilk girilen sayıyı tutar.
      mak=sayi;
    else if (sayi>mak)
    //Eğer girilen sayı ilk sayı değilse girilen sayı ile mak değeri karşılaştırır
      mak=sayi;
  }
  cout << "Mak:" << mak << endl;
  cout << mak << " mod 2:" << mak % 2 << endl;
  
  //1 ile 100 arasındaki 2 veya 7 sayılarına tam bölünebilen sayıları aralarında boşluk bırakarak yan yana ekrana yazdıralım
  //2 4 6 7 8 10 12 ..... 90 91 92 94 96 98 100 
  //int i;
  
  for (i=1;i<=100;i++)
    if (i%2==0 || i%7==0)
      cout << i << " ";
  cout << endl;

  //1 ile 100 arasındaki 2'ye tam bölünebilen ve 7 sayısına tam bölünemeyen sayıları aralarında boşluk bırakarak yan yana ekrana yazdıralım
  //int i;
  for (i=1;i<=100;i++)
    if (i%2==0 && i%7!=0)
      cout << i << " ";
  cout << endl;
  
  //1'den kullanıcının girdiği sayıya kadar olan sayıların toplamını ekrana yazdıralım
  //int sayi;
  int toplam=0;
  
  cout << "Sayı:";
  cin >> sayi;
  for (i=1;i<=sayi;i++)
    toplam+=i;
  cout << "Toplam:" << toplam << endl;
  
  //Kullanıcının girdiği 2 sayı arasındaki 3'e tam bölünen sayıların ve 5'e tam bölünen sayıların ayrı ayrı toplamını yazdıralım
  //Ör: Kullanıcı 10 20 değerlerini girerse;
  //3'e tam bölünenlerin toplamı: 45 (12+15+18)
  //5'e tam bölünenlerin toplamı: 45 (10+15+20)
  //int sayi, sayi1, sayi2;
  int toplam3=0,toplam5=0;
  cout << "2 sayı girin:";
  cin >> sayi1 >> sayi2;
  for (sayi=sayi1;sayi<=sayi2;sayi++)
  {
    if (sayi%3==0)
      toplam3+=sayi; //toplam3=toplam3+sayi;
    if (sayi%5==0)
      toplam5+=sayi; //toplam5=toplam5+sayi;
  }
  cout << "3'e tam bölünenlerin toplamı:" << toplam3 << endl;
  cout << "5'e tam bölünenlerin toplamı:" << toplam5 << endl;
}