#include "pch.h"
#include <iostream>
#include <locale.h>
#include <random>
#include <time.h>
#include <string>

using namespace std;

int kare(int sayi1, int sayi2);
int kare2(int sayi1, int sayi2);
void kare_yazdir();
int faktoriyel(int sayi);
void faktoriyel_yazdir(int sayi);
void rastgele();
void rastgele2();
void rastgele3();
int rastgele_toplam(int miktar, int baslangic, int bitis);
void maks();
void farklar();
int hesap_giris();
bool hesap_giris2();

int main()
{
	setlocale(LC_ALL, "turkish");
	srand(time(NULL)); //Program her çalýþtýrýldýðýnda Random ile üretilen deðerlerin farklý deðerler olmasýný saðlar. 
	//Ama bu sayýnýn farklýlýklarýný ifade etmez. Yani 5 üretildiyse tekrar üretilebilir.
	
	cout << kare(1, 2) << endl;
	cout << kare(3, 2) << endl;
	cout << kare(3, 3) << endl;
	cout << kare2(1, 2) << endl;
	cout << kare2(3, 2) << endl;
	cout << kare2(3, 3) << endl;

	kare_yazdir();

	//Çýktý: Ör:5 girilirse; 5!=120
	int sayi = 5;
	cout << "faktoriyel() fonksiyonu çalýþýyor...\n";
	cout << sayi << "!=" << faktoriyel(sayi) << endl;
	sayi = 10;
	cout << sayi << "!=" << faktoriyel(sayi) << endl;
	sayi = 0;
	cout << sayi << "!=" << faktoriyel(sayi) << endl;
	sayi = -10;
	cout << faktoriyel(sayi) << endl;

	cout << "faktoriyel_yazdir() fonksiyonu çalýþýyor...\n";
	faktoriyel_yazdir(5);
	faktoriyel_yazdir(-2);
	faktoriyel_yazdir(0);


	rastgele();

	rastgele2();

	rastgele3();

	cout << "Toplam:" << rastgele_toplam(5, 20, 30) << endl;
	cout << "Toplam:" << rastgele_toplam(10, -50, -20) << endl;
	cout << "Toplam:" << rastgele_toplam(4, 20 , 23) << endl;
	maks();
	farklar();
	cout << "admin - nimda" << endl;
	cout <<"Hatalý giriþ sayýsý:" << hesap_giris() << endl;

	cout << "admin - nimda" << endl;
	if (hesap_giris2())
		cout << "Giriþ baþarýlý" << endl;
	else
		cout << "Giriþ baþarýsýz" << endl;
	system("pause");
	return 0;
}
//Örnek-1:
//Kendisine gönderilen iki tamsayý deðerinden büyük olanýn karesini, 
//sayýlar eþitse sayýlardan herhangi birini geri döndüren fonksiyonu yazýnýz.
//Parametre: int sayi1, int sayi2
//1.yöntem:
int kare(int sayi1,int sayi2) {
	if (sayi1 > sayi2)
		return sayi1 * sayi1;
	else if (sayi2 > sayi1)
		return sayi2 * sayi2;
	else
		return sayi1; //return sayi2;
}
//2.Yöntem:
int kare2(int sayi1, int sayi2) {
	int sonuc;
	if (sayi1 > sayi2)
		sonuc = sayi1 * sayi1;
	else if (sayi2 > sayi1)
		sonuc = sayi2 * sayi2;
	else
		sonuc = sayi1; //sonuc=sayi2;
	return sonuc;
}

//Örnek-2:
//Girilen iki tamsayý deðerini kare fonksiyonuna gönderip fonksiyondan gelen deðeri ekrana yazdýran fonksiyonu yazýnýz. 
//Parametre : yok (null)
//Gönderdiði deðer: yok (void)
void kare_yazdir() {
	//fonksiyonun içerisinde return yoksa fonksiyon void olarak tanýmlanýr.
	int s1, s2, sonuc;
	cout << "2 sayi giriniz:";
	cin >> s1 >> s2;

	sonuc = kare(s1, s2);
	cout << sonuc << endl;
	//cout << kare(s1, s2) << endl;
	
}


//Örnek-3:
//Kendisine gönderilen tamsayý deðerinin faktöriyelini geri döndüren fonksiyonu yazýnýz. 
//Eðer kendisine gönderilen sayý negatif ise 0 deðerini döndürelim.
//Not: 0!=1
//5!=1*2*3*4*5 5!=5*4*3*2*1
//Paremetre: int sayi
//Geri dönen deðer: int
int faktoriyel(int sayi) {
	int sonuc = 1; //Çarpmada 1 etkisiz eleman, 0 yutan eleman. Bu yüzden sonuc deðerine 1 verdik
	for (int i = 1; i <= sayi; i++)
	{
		sonuc *= i; //sonuc = sonuc * i;
	}
	if (sayi < 0)
		sonuc = 0;
	return sonuc;
	//if (sayi < 0)
	//	return 0;
	//else
	//	return sonuc;
}


//Örnek-4:
//Kendisine gönderilen sayýyý faktöriyel fonksiyonuna gönderip,
//faktöriyel fonksiyonundan gelen deðer 0 ise "... sayýsýnýn faktöriyeli yoktur.", 
//0 deðilse sayi!=sonuc Ör/5!=120 çýktýsýný versin
void faktoriyel_yazdir(int sayi) {
	int sonuc = faktoriyel(sayi);
	if (sonuc == 0)
		cout << sayi << " sayýsýnýn faktöriyeli yoktur.\n";
	else
		cout << sayi << "!=" << sonuc << endl;
}



//Örnek-5:
//Rastgele üretilen 1-100 arasýnda 5 sayýnýn toplamýný ekrana yazdýran fonksiyon
//Parametre (Bu fonksiyona gönderilen deðer) : YOK (NULL)
//Geri döndürdüðü deðer (Return deðeri) : YOK (void)
void rastgele() {
	int sayi, toplam=0;
	for (int i = 1; i <= 5; i++) {
		sayi = rand() % 100 + 1;
		cout << sayi << endl;
		//Ör: 20 ile 53 arasýnda deðer üretin deseydim;
		//sayi = rand() % 34 + 20;
		//Ör: -20 ile 53 arasýndaki deðer üretin deseydim;
		//sayi = rand() % 74 - 20;
		toplam += sayi; //toplam = toplam + sayi;
	}
	cout << "Toplam:" << toplam << endl;
}


//Örnek-6:
//Rastgele üretilen 1-100 arasýndaki 20 sayýdan tek olanlarý ve çift olanlarý ayrý ayrý ve alt alta ekrana yazdýran fonksiyon
//Not: Deðerler bir dizide tutulmak zorundadýr
//Parametre (Bu fonksiyona gönderilen deðer) : YOK (NULL)
//Geri döndürdüðü deðer (Return deðeri) : YOK (void)
void rastgele2() {
	int sayilar[20], i;
	for (i = 0; i < 20; i++) {
		sayilar[i] = rand() % 100 + 1;
	}
	cout << "Tek Sayýlar\n";
	for (i = 0; i < 20; i++){
		if (sayilar[i] % 2 == 1)
			cout << sayilar[i] << endl;
	}
	cout << "Çift Sayýlar\n";
	for (i = 0; i < 20; i++) {
		if (sayilar[i] % 2 == 0)
			cout << sayilar[i] << endl;
	}
}

//Örnek-7:
//Rastgele üretilen  1-100 arasýndaki 20 sayýdan tek olanlarý ve çift olanlarý ayrý ayrý ve alt alta ekrana yazdýran,
//tek ve çift sayýlarýn toplamlarýný ekrana yazdýran fonksiyon
//Not: Deðerler bir dizide tutulmak zorundadýr
//Parametre (Bu fonksiyona gönderilen deðer) : YOK (NULL)
//Geri döndürdüðü deðer (Return deðeri) : YOK (void)
void rastgele3() {
	int sayilar[20], i, tektoplam=0, cifttoplam=0;
	for (i = 0; i < 20; i++) {
		sayilar[i] = rand() % 100 + 1;
	}
	cout << "Tek Sayýlar\n";
	for (i = 0; i < 20; i++) {
		if (sayilar[i] % 2 == 1) {
			cout << sayilar[i] << endl;
			tektoplam += sayilar[i];
		}
	}
	cout << "Tek toplam:" << tektoplam << endl;
	cout << "Çift Sayýlar\n";
	for (i = 0; i < 20; i++) {
		if (sayilar[i] % 2 == 0) {
			cout << sayilar[i] << endl;
			cifttoplam += sayilar[i];
		}
	}
	cout << "Çift toplam:" << cifttoplam << endl;
}


//Örnek-8:
//Fonksiyona gelen sayý kadar, fonksiyona gelen sayý aralýðýnda deðer üreten ve bu sayýlarý ekrana yazdýrýp, sayýlarýn toplamýný geri döndüren fonksiyon
//Parametre (Bu fonksiyona gönderilen deðer) : int miktar, int baslangic, int bitis
//Geri döndürdüðü deðer (Return deðeri) : int (toplam)
int rastgele_toplam(int miktar, int baslangic, int bitis) {
	cout << miktar << " tane sayý üretiliyor...\n";
	int sayi, toplam = 0;
	for (int i = 1; i <= miktar; i++){
		sayi = rand() % (bitis-baslangic+1) + baslangic;
		cout << i << ".sayi:" << sayi << endl;
		toplam += sayi;
	}
	return toplam;
}

//Örnek-9:Kullanýcý 0 sayýsýný girene kadar sayý girmesini saðlayýp, bu sayýlarýn en büyüðünü (sýfýr sayýsýný dahil etmeden büyük sayý bulunmalýdýr) ekrana yazdýran fonksiyon
void maks() {
	int sayi, mak=INT_MIN;
	do
	{
		cout << "Sayý:";
		cin >> sayi;
		if (mak < sayi && sayi!=0) {
			//sýfýrý dahil etmememizin sebebi tüm sayýlarýn negatif girilmesi durumu içindir
			mak = sayi;
		}
	} while (sayi!=0);
	cout << "Maksimum deðer:" << mak << endl;
}

//Örnek-10:Kullanýcý 0 sayýsýný girene kadar sayý girmesini saðlayýp, bu sayýlarýn farklarýný ekrana yazdýran fonksiyon
//Ör: 3 4 girdiðinde Çýktý:-1, 6 girdiðinde Çýktý:-2, 0 girdiðinde Çýktý:6 program sonlanýr.
void farklar() {
	int ilksayi, sayi;
	cout << "Sayý:";
	cin >> ilksayi;
	do
	{
		cout << "Sayý:";
		cin >> sayi;
		cout <<"Fark:" << ilksayi-sayi << endl;
		ilksayi = sayi;
	} while (sayi != 0);
}

//Örnek-11:Kullanýcý adý ve parola giriþi doðru olana kadar kontrol edip, kullanýcý adý ve parola bilgisinin kaç kere yanlýþ girildiðini geri döndüren fonksiyon
int hesap_giris() {
	string k_adi, parola;
	int miktar = 0;
	do
	{
		cout << "Kullanýcý adý:";
		cin >> k_adi;
		cout << "Parola:";
		cin >> parola;
		if (k_adi == "admin" && parola == "nimda") {
			//yazýlým güvenliði söz konusu deðil. 
			//Kullanýcý adý ve þifre kontrol esnasýnda kodda olmamalý
			cout << "Giriþ baþarýlý\n";
			break;
		}
		else
			miktar++;
	} while (true);
	return miktar;
}

//Örnek-12:Kullanýcýdan kullanýcý adý ve parola giriþi alýp  kontrol edelim, 3 yanlýþ yapma hakký olsun. Giriþin baþarýlý bir þekilde olup olmadýðýný (bool deðer) döndürsün ve kaç hakký kaldýðýný ekrana yazdýrsýn
bool hesap_giris2() {
	string k_adi, parola;
	int hak = 3;
	bool durum = false;
	do
	{
		cout << "Kullanýcý adý:";
		cin >> k_adi;
		cout << "Parola:";
		cin >> parola;
		if (k_adi == "admin" && parola == "nimda") {
			//yazýlým güvenliði söz konusu deðil. 
			//Kullanýcý adý ve þifre kontrol esnasýnda kodda olmamalý
			durum = true;
			break;
		}
		else {
			hak--;
			cout << "Kalan hak:" << hak << endl;
		}
			
	} while (hak!=0);
	return durum;
}

