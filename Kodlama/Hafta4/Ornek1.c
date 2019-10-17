#include <stdio.h>
#include <locale.h>
//locale.h kütüphanesini projemize dahil ettik
//setlocale fonksiyonunu kullanmak için tanımladık

 //Bu bir açıklama satırıdır
 
  /*
  Bu
  bir
  açıklama
  bloğudur.
  */
int main(void) {
  setlocale(LC_ALL, "Turkish");
  //Türkçe karakterleri çıktı vermemizi sağlar
  //İ,ı,ö,ü,ğ,ş,ç vb. karakterler

  printf("Merhaba Dünya\n");
  printf("Hello World\n");
  //printf ekrana çıktı verir.
  int x,y,toplam; //int tamsayı veri türüdür.
  printf("1.sayı:");
  scanf("%d",&x);
  //scanf klavyeden değer okumak için kullanılır
  //"%d" int değer okuyacağımızı belirtir
  //scanf işlemlerinde & değişkenin önüne koyulmalıdır.
  printf("2.sayı:");
  scanf("%d",&y);
  toplam=x+y;
  printf("Toplam:%d\n",toplam);
  //"\n" ifadesi alt satıra geçmemizi sağlar

  //Girilen iki sayının karelerini ekrana yazdıralım
  //Sayının karesi = sayi*sayi
  //Örn; 5 3 girilirse; 
  //Çıktı:
  //5 karesi 25
  //3 karesi 9
  printf("%d karesi %d\n",x,x*x);
  printf("%d karesi %d\n",y,y*y);
  
  //Klavyeden girilen iki ondalıklı sayının ortalamasını hesaplayan program
  float sayi1,sayi2,ortalama;
  //float reel sayıları tutan değişken türüdür
  printf("İki sayı giriniz:");
  scanf("%f%f",&sayi1,&sayi2);
  //"%f" float veri türüdür
  ortalama=(sayi1+sayi2)/2;
  printf("Ortalamaları=%.1f\n",ortalama);
  //"%.1f" float sayı 1 ondalıklı olacak şekilde sayıyı yuvarlar 

  //Klavyeden girilen sınav notuna göre ekrana "Geçti" veya "Kaldı" yazdıralım
  //Sınav notu 0-100 arasında değilse "Hatalı not girildi" yazdıralım
  //Girilen not : 50 ve üstü ise "Geçti"
  //Girilen not : 50 altı ise "Kaldı"
  
  float sinavnotu;
git:
  printf("Sınav notunu giriniz:");
  scanf("%f",&sinavnotu);
  if (sinavnotu<0 || sinavnotu>100)
  // || sembolü için Altgr + <> tuşlarına basınız
  // || sembolleri veya anlamı taşır
  {
    //{} arasındaki alan if bloğudur
    //{} kullanmazsak sadece kendinden sonra gelen kod satırını çalıştırır
    printf("Hatalı not girildi.\n");
    goto git;
  }
  if (sinavnotu>=50)
    printf("Geçti\n");
  if (sinavnotu<50)
    printf("Kaldı\n");
  //if tek tek kontrol edilir. Şartın doğru olduğu durumlar çalışır.

  if (sinavnotu>=50)
    printf("Geçti\n");
  else
    printf("Kaldı\n");
  //if şartı doğru olduğu takdirde else bloğu ile ilgili bir kontrol gerçekleştirmez
  //Program daha hızlı çalışır


//Klavyeden girilen sayının tek veya çift olduğunu ekrana yazdıralım
//mod alma (iki sayının birbirine bölümünden kalanını bulma) işlemi % işareti ile yapılır. Örn: sayi%2 
//5%2 işleminin sonucu 1, 4%2 işleminin sonucu 0 'dır.
int sayi;
printf("Bir sayı giriniz:");
scanf("%d",&sayi);
if (sayi%2==0)
  printf("Çifttir\n");
else 
  printf("Tektir\n");

//Klavyeden girilen sayının pozitif, negatif veya nötr olduğunu ekrana yazdıralım
int sayi3;
printf("Bir sayı giriniz:");
scanf("%d",&sayi3);
if (sayi3>0)
  printf("Pozitif");
else if (sayi3==0)
  printf("Nötr");
else 
  printf("Negatif");

//Klavyeden 0 girilene kadar girilen değerleri toplayan ve toplam değeri ekrana yazdıran program
//Gelecek hafta çözeceğiz.
    
  return 0;
}