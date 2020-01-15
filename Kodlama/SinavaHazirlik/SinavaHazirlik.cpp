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
	srand(time(NULL)); //Program her çalıştırıldığında Random ile üretilen değerlerin farklı değerler olmasını sağlar. 
	//Ama bu sayının farklılıklarını ifade etmez. Yani 5 üretildiyse tekrar üretilebilir.
	
	cout << kare(1, 2) << endl;
	cout << kare(3, 2) << endl;
	cout << kare(3, 3) << endl;
	cout << kare2(1, 2) << endl;
	cout << kare2(3, 2) << endl;
	cout << kare2(3, 3) << endl;

	kare_yazdir();

	//Çıktı: Ör:5 girilirse; 5!=120
	int sayi = 5;
	cout << "faktoriyel() fonksiyonu çalışıyor...\n";
	cout << sayi << "!=" << faktoriyel(sayi) << endl;
	sayi = 10;
	cout << sayi << "!=" << faktoriyel(sayi) << endl;
	sayi = 0;
	cout << sayi << "!=" << faktoriyel(sayi) << endl;
	sayi = -10;
	cout << faktoriyel(sayi) << endl;

	cout << "faktoriyel_yazdir() fonksiyonu çalışıyor...\n";
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
	cout <<"Hatalı giriş sayısı:" << hesap_giris() << endl;

	cout << "admin - nimda" << endl;
	if (hesap_giris2())
		cout << "Giriş başarılı" << endl;
	else
		cout << "Giriş başarısız" << endl;
	system("pause");
	return 0;
}
//Örnek-1:
//Kendisine gönderilen iki tamsayı değerinden büyük olanın karesini, 
//sayılar eşitse sayılardan herhangi birini geri döndüren fonksiyonu yazınız.
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
//Girilen iki tamsayı değerini kare fonksiyonuna gönderip fonksiyondan gelen değeri ekrana yazdıran fonksiyonu yazınız. 
//Parametre : yok (null)
//Gönderdiği değer: yok (void)
void kare_yazdir() {
	//fonksiyonun içerisinde return yoksa fonksiyon void olarak tanımlanır.
	int s1, s2, sonuc;
	cout << "2 sayi giriniz:";
	cin >> s1 >> s2;

	sonuc = kare(s1, s2);
	cout << sonuc << endl;
	//cout << kare(s1, s2) << endl;
	
}


//Örnek-3:
//Kendisine gönderilen tamsayı değerinin faktöriyelini geri döndüren fonksiyonu yazınız. 
//Eğer kendisine gönderilen sayı negatif ise 0 değerini döndürelim.
//Not: 0!=1
//5!=1*2*3*4*5 5!=5*4*3*2*1
//Paremetre: int sayi
//Geri dönen değer: int
int faktoriyel(int sayi) {
	int sonuc = 1; //Çarpmada 1 etkisiz eleman, 0 yutan eleman. Bu yüzden sonuc değerine 1 verdik
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
//Kendisine gönderilen sayıyı faktöriyel fonksiyonuna gönderip,
//faktöriyel fonksiyonundan gelen değer 0 ise "... sayısının faktöriyeli yoktur.", 
//0 değilse sayi!=sonuc Ör/5!=120 çıktısını versin
void faktoriyel_yazdir(int sayi) {
	int sonuc = faktoriyel(sayi);
	if (sonuc == 0)
		cout << sayi << " sayısının faktöriyeli yoktur.\n";
	else
		cout << sayi << "!=" << sonuc << endl;
}



//Örnek-5:
//Rastgele üretilen 1-100 arasında 5 sayının toplamını ekrana yazdıran fonksiyon
//Parametre (Bu fonksiyona gönderilen değer) : YOK (NULL)
//Geri döndürdüğü değer (Return değeri) : YOK (void)
void rastgele() {
	int sayi, toplam=0;
	for (int i = 1; i <= 5; i++) {
		sayi = rand() % 100 + 1;
		cout << sayi << endl;
		//Ör: 20 ile 53 arasında değer üretin deseydim;
		//sayi = rand() % 34 + 20;
		//Ör: -20 ile 53 arasındaki değer üretin deseydim;
		//sayi = rand() % 74 - 20;
		toplam += sayi; //toplam = toplam + sayi;
	}
	cout << "Toplam:" << toplam << endl;
}


//Örnek-6:
//Rastgele üretilen 1-100 arasındaki 20 sayıdan tek olanları ve çift olanları ayrı ayrı ve alt alta ekrana yazdıran fonksiyon
//Not: Değerler bir dizide tutulmak zorundadır
//Parametre (Bu fonksiyona gönderilen değer) : YOK (NULL)
//Geri döndürdüğü değer (Return değeri) : YOK (void)
void rastgele2() {
	int sayilar[20], i;
	for (i = 0; i < 20; i++) {
		sayilar[i] = rand() % 100 + 1;
	}
	cout << "Tek Sayılar\n";
	for (i = 0; i < 20; i++){
		if (sayilar[i] % 2 == 1)
			cout << sayilar[i] << endl;
	}
	cout << "Çift Sayılar\n";
	for (i = 0; i < 20; i++) {
		if (sayilar[i] % 2 == 0)
			cout << sayilar[i] << endl;
	}
}

//Örnek-7:
//Rastgele üretilen  1-100 arasındaki 20 sayıdan tek olanları ve çift olanları ayrı ayrı ve alt alta ekrana yazdıran,
//tek ve çift sayıların toplamlarını ekrana yazdıran fonksiyon
//Not: Değerler bir dizide tutulmak zorundadır
//Parametre (Bu fonksiyona gönderilen değer) : YOK (NULL)
//Geri döndürdüğü değer (Return değeri) : YOK (void)
void rastgele3() {
	int sayilar[20], i, tektoplam=0, cifttoplam=0;
	for (i = 0; i < 20; i++) {
		sayilar[i] = rand() % 100 + 1;
	}
	cout << "Tek Sayılar\n";
	for (i = 0; i < 20; i++) {
		if (sayilar[i] % 2 == 1) {
			cout << sayilar[i] << endl;
			tektoplam += sayilar[i];
		}
	}
	cout << "Tek toplam:" << tektoplam << endl;
	cout << "Çift Sayılar\n";
	for (i = 0; i < 20; i++) {
		if (sayilar[i] % 2 == 0) {
			cout << sayilar[i] << endl;
			cifttoplam += sayilar[i];
		}
	}
	cout << "Çift toplam:" << cifttoplam << endl;
}


//Örnek-8:
//Fonksiyona gelen sayı kadar, fonksiyona gelen sayı aralığında değer üreten ve bu sayıları ekrana yazdırıp, 
//sayıların toplamını geri döndüren fonksiyon
//Parametre (Bu fonksiyona gönderilen değer) : int miktar, int baslangic, int bitis
//Geri döndürdüğü değer (Return değeri) : int (toplam)
int rastgele_toplam(int miktar, int baslangic, int bitis) {
	cout << miktar << " tane sayı üretiliyor...\n";
	int sayi, toplam = 0;
	for (int i = 1; i <= miktar; i++){
		sayi = rand() % (bitis-baslangic+1) + baslangic;
		cout << i << ".sayi:" << sayi << endl;
		toplam += sayi;
	}
	return toplam;
}

//Örnek-9:Kullanıcı 0 sayısını girene kadar sayı girmesini sağlayıp, bu sayıların en büyüğünü 
//(sıfır sayısını dahil etmeden büyük sayı bulunmalıdır) ekrana yazdıran fonksiyon
void maks() {
	int sayi, mak=INT_MIN;
	do
	{
		cout << "Sayı:";
		cin >> sayi;
		if (mak < sayi && sayi!=0) {
			//sıfırı dahil etmememizin sebebi tüm sayıların negatif girilmesi durumu içindir
			mak = sayi;
		}
	} while (sayi!=0);
	cout << "Maksimum değer:" << mak << endl;
}

//Örnek-10:Kullanıcı 0 sayısını girene kadar sayı girmesini sağlayıp, bu sayıların farklarını ekrana yazdıran fonksiyon
//Ör: 3 4 girdiğinde Çıktı:-1, 6 girdiğinde Çıktı:-2, 0 girdiğinde Çıktı:6 program sonlanır.
void farklar() {
	int ilksayi, sayi;
	cout << "Sayı:";
	cin >> ilksayi;
	do
	{
		cout << "Sayı:";
		cin >> sayi;
		cout <<"Fark:" << ilksayi-sayi << endl;
		ilksayi = sayi;
	} while (sayi != 0);
}

//Örnek-11:Kullanıcı adı ve parola girişi doğru olana kadar kontrol edip, kullanıcı adı ve parola bilgisinin 
//kaç kere yanlış girildiğini geri döndüren fonksiyon
int hesap_giris() {
	string k_adi, parola;
	int miktar = 0;
	do
	{
		cout << "Kullanıcı adı:";
		cin >> k_adi;
		cout << "Parola:";
		cin >> parola;
		if (k_adi == "admin" && parola == "nimda") {
			//yazılım güvenliği söz konusu değil. 
			//Kullanıcı adı ve şifre kontrol esnasında kodda olmamalı
			cout << "Giriş başarılı\n";
			break;
		}
		else
			miktar++;
	} while (true);
	return miktar;
}

//Örnek-12:Kullanıcıdan kullanıcı adı ve parola girişi alıp  kontrol edelim, 3 yanlış yapma hakkı olsun. 
//Girişin başarılı bir şekilde olup olmadığını (bool değer) döndürsün ve kaç hakkı kaldığını ekrana yazdırsın
bool hesap_giris2() {
	string k_adi, parola;
	int hak = 3;
	bool durum = false;
	do
	{
		cout << "Kullanıcı adı:";
		cin >> k_adi;
		cout << "Parola:";
		cin >> parola;
		if (k_adi == "admin" && parola == "nimda") {
			//yazılım güvenliği söz konusu değil. 
			//Kullanıcı adı ve şifre kontrol esnasında kodda olmamalı
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

