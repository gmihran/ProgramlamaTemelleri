#include <stdio.h>
#include <locale.h>
int main(void) {
  setlocale(LC_ALL,"Turkish");
  //Klavyeden 0 girilene kadar girilen değerleri toplayan ve toplam değeri ekrana yazdıran program
  
  int sayi,toplam=0;
  printf("0 girilene kadar değerleri toplayan program:\n");
gitsayi:
  printf("Bir değer giriniz:");
  scanf("%d",&sayi);
  toplam=toplam+sayi;
  if (sayi!=0)
    goto gitsayi;
  printf("Toplam:%d\n",toplam);
  
  //Klavyeden girilen sınav notunu harf notuna çevirelim
  //0'dan küçükse veya 100'den büyükse; "Hatalı Değer" çıktısı verilip, tekrar not istenecek
  //if (sinav<0 || sinav>100)
  //80-100 AA 
  //if (sinav>=80 && sinav<=100)
  //Yukarıdaki if ifadesi sayı 0 ile 100 arasında olmaması durumu kontrol edilmezse kullanılmalıdır
  //if (sinav>=80)
  //Biz yukarıdaki if ifadesini kullanacağız
  //60-79 BB
  //40-59 CC
  //35-39 DD
  //0-34 FF
  //Bu değerler gerçeği yansıtmamaktadır.
  int sinav;
gitsinav:
  printf("Not giriniz:");
  scanf("%d",&sinav);
  if (sinav<0 || sinav>100)
  {
    printf("Geçersiz not!\n");
    goto gitsinav;
  }
  else if (sinav>=80)
    printf("AA");
  else if (sinav>=60)
    printf("BB");
  else if (sinav>=40)
    printf("CC");
  else if (sinav>=35)
    printf("DD");
  else
    printf("FF");
  printf("\n");
  //Girilen iki sayıdan hangisinin büyük olduğunu veya eşitse eşit olduklarını ekrana yazdıralım
  //Örn: 30 40 girerse; 40 büyüktür
  //Örn: 35 30 girerse; 35 büyüktür
  //Örn: 30 30 girerse; 30 eşittir
  

  //Kullanıcıdan haftanın kaçıncı günü bilgisini alalım
  //Günü ekrana getirelim. (Pazartesi haftanın 1.günü)
  //Ör. 7 dediğinde Pazar, 3 dediğinde Çarşamba ekrana yazdırılacak
  //Eğer 7’den daha büyük bir sayı girerse 7’ye göre mod alınarak gün hesaplanacak
  //Örn. 8 girildiğinde Pazartesi, 10 girildiğinde Çarşamba ekrana yazdırılacak
  //Negatif sayı veya nötr(0) girilmiş ise “hatalı değer” çıktısını verecek
  
  int gun;
  
  printf("Haftanın kaçıncı günü:");
  scanf("%d",&gun);
  
  if (gun<=0)
    printf("Hatalı değer");
  else
  {
    gun=gun%7;
    if (gun==1)
      printf("Pazartesi");
    else if (gun==2)
      printf("Salı");
    else if (gun==3)
      printf("Çarşamba");
    else if (gun==4)
      printf("Perşembe");
    else if (gun==5)
      printf("Cuma");
    else if (gun==6)
      printf("Cumartesi");
    else
      printf("Pazar");
  }
  printf("\n");
  
  //int gun;
gitgun:  
  printf("Haftanın kaçıncı günü:");
  scanf("%d",&gun);
  gun=gun%7;
  if (gun<=0)
    goto gitgun;
	switch(gun)
{
  case 0:
		printf("Pazar");
		break;
	case 1:
		printf("Pazartesi");
		break;
	case 2:
		printf("Salı");
		break;
	case 3:
		printf("Çarşamba");
		break;
	case 4:
		printf("Perşembe");
		break;
	case 5:
		printf("Cuma");
		break;
	case 6:
		printf("Cumartesi");
		break;
	default:
		printf("Hatalı değer");
		break;
}
  printf("\n");

  
  /*Örnek - 6.	Bir ürünün alış fiyatı, vergi oranı 
	ve kar oranına göre satış fiyatını hesaplatıp ekrana yazdırınız.
	a.Eğer kar oranı 0 ile 1 arasında bir değer değilse kar oranı tekrar istenecek
	b.Eğer vergi oranı 0 ile 1 arasında bir değer değilse vergi oranı tekrar istenecek
	c.Kar eklenmiş fiyat = alış fiyatı + alış fiyatı * kar oranı
	d.Satış fiyatı = kar eklenmiş fiyat + kar eklenmiş fiyat * vergi oranı
  */
  float alis,vergi,kar,satis;
  printf("Alış fiyatını giriniz:");
  scanf("%f",&alis);
  gitkar:
  printf("Kar oranını giriniz(0-1 arasında):");
  scanf("%f",&kar);
  if (kar<0 || kar>1)
      goto gitkar;
  satis=alis+alis*kar;
  gitvergi:
  printf("Vergi oranını giriniz(0-1 arasında):");
  scanf("%f",&vergi);
  if (vergi<0 || vergi>1)
      goto gitvergi;
  satis=satis+satis*vergi;
  printf("Satış fiyatı:%.1f",satis);
  printf("\n");
  
  //Girilen ay bilgisine göre mevsimleri ekrana getiren program
  //12-1-2 Kış
  //3-4-5 İlkbahar
  //6-7-8 Yaz
  //9-10-11 Sonbahar
  int ay;
  printf("Ay (1-12):");
  scanf("%d",&ay);
  if (ay==12 || ay==1 || ay==2)
    printf("Kış");
  else if (ay>=3 && ay<=5)
    printf("İlkbahar");
  else if (ay>=6 && ay<=8)
    printf("Yaz");
  else if (ay>=9 && ay<=11)
    printf("Sonbahar");
  else
    printf("Hatalı değer");
  
  //Ödev: Bu örnek switch case ile çözülebilir.
  /*
  case 3:
  case 4:
  case 5:
    printf("İlkbahar");
    break;
  */
}