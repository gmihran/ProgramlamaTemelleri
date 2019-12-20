#include "pch.h"
#include <iostream>
#include <locale.h>
#include <string>
#include <random>
#include <time.h>

using namespace std;

void arttir5(int sayi);
void arttir5(int *p);
void kat(int *ptr);
int * rastgele();
void neg_poz(int *s, int *ptoplam, int *ntoplam);
void random();

void tersine(string *p);

int main() {
	setlocale(LC_ALL, "turkish");
	srand(time(NULL));
	int sayi = 10;
	int *p = &sayi;
	
	cout << "sayi:" << sayi << endl;
	cout << "&sayi:"<< &sayi << endl;//deðerin tutulduðu adres deðerini yazdýrýr

	cout << "p:" << p << endl; //içinde tuttuðu adresi yazdýrýr
	cout << "*p:" << *p << endl; //içinde tuttuðu adresteki deðeri yazdýrýr
	
	arttir5(sayi);
	cout <<"arttir5(sayi) fonksiyonu çalýþtý..: " << sayi << endl;

	arttir5(&sayi);
	cout << "arttir5(&sayi) fonksiyonu çalýþtý..: " << sayi << endl;
	
	kat(&sayi); //sayýnýn iþaret ettiði adres (iþaretçi/pointer) bilgisini  kat fonksiyonuna parametre olarak gönderdik
	cout << "sayi:" << sayi << endl;

	string kelime;
	cout << "Kelime:";
	cin >> kelime;
	//getline(cin, kelime);
	//Birden fazla kelimeyi deðiþken içinde tutmayý saðlar.
	tersine(&kelime);
	cout << "kelime:" << kelime << endl;
	

	int toplam = * rastgele();
	cout << "Toplam:" << toplam << endl;

	//Kullanýcý 0 girene kadar girdiði deðerlerin pozitif olanlarýný ve negatif olanlarýný bir deðiþkende tutup bu deðerleri main içerisinde yazdýralým
	int s, ptoplam=0, ntoplam=0;
	cout << endl << "Burada girdiðiniz pozitif ve negatif sayýlarýn toplamý hesaplanacaktýr." << endl;
	cout << "Çýkmak için 0 deðerini giriniz..." << endl;
	do
	{
		cout << "Sayý:";
		cin >> s;
		neg_poz(&s, &ptoplam, &ntoplam);
	} while (s!=0);
	cout << "Pozitif Toplam:" << ptoplam << endl;
	cout << "Negatif Toplam:" << ntoplam << endl;
	
	random();

	system("pause");

	return 1;
}
void arttir5(int sayi) {
	//kendisine gönderilen sayi deðiþkeninin kopyasýný oluþturdu.
	//Bu sebeple gönderilen fonksiyon içerisindeki bu deðer deðiþmedi.
	sayi += 5;
}

//Kendisine gönderilen bellek adresinin içinde saklanan deðeri 5 arttýran fonksiyon:
void arttir5(int *p) {
	cout << "p:" << p << endl;
	*p += 5; // *p = *p + 5;
	cout << "*p:" << *p << endl; //
	cout << "&p:" << &p << endl; //p adresi
}

//Problem: Kullanýcýdan alýnan deðeri fonksiyon parametre olarak alsýn ve 
//bu deðeri fonksiyon içerisinde kullanýcýnýn girdiði kata eþitlesin
//Ör:main içinde 4 girilirse, fonksiyonda 5 girilirse, mainden gelen 4 deðeri 20 olacak
void kat(int *ptr) {
	int kat;
	cout << "Kat deðeri:";
	cin >> kat;
	*ptr = *ptr * kat; // *ptr *= kat;
	//*ptr pointer'ýn tuttuðu adresteki veriye gitti ve bu deðeri kat deðeriyle çarpýp yeni deðeri yaptý.
}

//Kendisine gönderilen kelimenin adresini (pointer) tutan fonksiyon tanýmlayalým. Bu kelimeyi fonksiyon içinde tersine dönüþtürelim.
//ÖR: kendisine "kedi" kelimesi geldiðinde, kelime "idek" olacak.
void tersine(string *p) {
	string ters = "";
	int uzunluk = (*p).length();
	for (int i = uzunluk-1; i >=0; i--)
		//uzunluk kelimenin karakter sayýsýný tutuyor. Ýndis deðerimiz sýfýrdan baþladýðý için 1 eksiðini aldýk.
	{
		ters += (*p)[i];
	}
	*p = ters;
}

//random ile oluþturulan 1-10 arasýndaki 10 sayýnýn toplamýnýn tutulduðu adresi çaðrýldýðý fonksiyona gönderen fonksiyonu yazalým.
int * rastgele() {
	int sayi, toplam = 0;
	for (int i = 1; i <= 10; i++)
	{
		sayi = rand() % 10 + 1;
		cout << sayi << " ";
		toplam += sayi;
	}
	cout << endl;
	cout << "Toplam:" << toplam << endl;
	return &toplam;
}

void neg_poz(int *s, int *ptoplam, int *ntoplam) {
	if (*s > 0)
		*ptoplam += *s;
	else if (*s < 0)
		*ntoplam += *s;
}

//10 tane 0-100 arasýnda rastgele üretilen sayýyý bir dizide tutarak bu deðerleri adres deðerleri ile yazdýralým
void random() {
	int sayilar[10];
	for (int i = 0; i < 10; i++){
		sayilar[i] = rand() % 101+0;
		cout << sayilar[i] << " ";
	}
	cout << endl;
	int *p = sayilar;
	cout << "p:" << p << endl;
	cout << "p+1:" << p + 1 << endl;
	cout << "*p:" << *p << endl;
	cout << "*(p+1):" << *(p + 1) << endl;
	//p+1 adresinde tutulan deðeri getirir
	cout << "*p+1:" << *p + 1 << endl;
	//p adresinde tutulan deðerin 1 fazlasýný getirir
	cout << "Deðerler:" << endl;
	for (int i = 0; i < 10; i++){
		cout << *(p+i) << " ";
	}
	cout << endl;
	cout << "Adresler:" << endl;
	for (int i = 0; i < 10; i++) {
		cout << p + i << endl;
	}
	cout << endl;
	cout << "Adresler:\tDeðerler:\n";
	for (int i = 0; i < 10; i++) {
		cout << p + i << "\t" << *(p + i) << endl;
	}
}