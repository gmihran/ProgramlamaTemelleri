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
	cout << "&sayi:"<< &sayi << endl;//değerin tutulduğu adres değerini yazdırır

	cout << "p:" << p << endl; //içinde tuttuğu adresi yazdırır
	cout << "*p:" << *p << endl; //içinde tuttuğu adresteki değeri yazdırır
	
	arttir5(sayi);
	cout <<"arttir5(sayi) fonksiyonu çalıştı..: " << sayi << endl;

	arttir5(&sayi);
	cout << "arttir5(&sayi) fonksiyonu çalıştı..: " << sayi << endl;
	
	kat(&sayi); //sayının işaret ettiği adres (işaretçi/pointer) bilgisini  kat fonksiyonuna parametre olarak gönderdik
	cout << "sayi:" << sayi << endl;

	string kelime;
	cout << "Kelime:";
	cin >> kelime;
	//getline(cin, kelime);
	//Birden fazla kelimeyi değişken içinde tutmayı sağlar.
	tersine(&kelime);
	cout << "kelime:" << kelime << endl;
	

	int toplam = * rastgele();
	cout << "Toplam:" << toplam << endl;

	//Kullanıcı 0 girene kadar girdiği değerlerin pozitif olanlarını ve negatif olanlarını bir değişkende tutup 
	//bu değerleri main içerisinde yazdıralım
	int s, ptoplam=0, ntoplam=0;
	cout << endl << "Burada girdiğiniz pozitif ve negatif sayıların toplamı hesaplanacaktır." << endl;
	cout << "Çıkmak için 0 değerini giriniz..." << endl;
	do
	{
		cout << "Sayı:";
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
	//kendisine gönderilen sayi değişkeninin kopyasını oluşturdu.
	//Bu sebeple gönderilen fonksiyon içerisindeki bu değer değişmedi.
	sayi += 5;
}

//Kendisine gönderilen bellek adresinin içinde saklanan değeri 5 arttıran fonksiyon:
void arttir5(int *p) {
	cout << "p:" << p << endl;
	*p += 5; // *p = *p + 5;
	cout << "*p:" << *p << endl; //
	cout << "&p:" << &p << endl; //p adresi
}

//Problem: Kullanıcıdan alınan değeri fonksiyon parametre olarak alsın ve 
//bu değeri fonksiyon içerisinde kullanıcının girdiği kata eşitlesin
//Ör:main içinde 4 girilirse, fonksiyonda 5 girilirse, mainden gelen 4 değeri 20 olacak
void kat(int *ptr) {
	int kat;
	cout << "Kat değeri:";
	cin >> kat;
	*ptr = *ptr * kat; // *ptr *= kat;
	//*ptr pointer'ın tuttuğu adresteki veriye gitti ve bu değeri kat değeriyle çarpıp yeni değeri yaptı.
}

//Kendisine gönderilen kelimenin adresini (pointer) tutan fonksiyon tanımlayalım. Bu kelimeyi fonksiyon içinde tersine dönüştürelim.
//ÖR: kendisine "kedi" kelimesi geldiğinde, kelime "idek" olacak.
void tersine(string *p) {
	string ters = "";
	int uzunluk = (*p).length();
	for (int i = uzunluk-1; i >=0; i--)
		//uzunluk kelimenin karakter sayısını tutuyor. İndis değerimiz sıfırdan başladığı için 1 eksiğini aldık.
	{
		ters += (*p)[i];
	}
	*p = ters;
}

//random ile oluşturulan 1-10 arasındaki 10 sayının toplamının tutulduğu adresi çağrıldığı fonksiyona gönderen fonksiyonu yazalım.
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

//10 tane 0-100 arasında rastgele üretilen sayıyı bir dizide tutarak bu değerleri adres değerleri ile yazdıralım
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
	//p+1 adresinde tutulan değeri getirir
	cout << "*p+1:" << *p + 1 << endl;
	//p adresinde tutulan değerin 1 fazlasını getirir
	cout << "Değerler:" << endl;
	for (int i = 0; i < 10; i++){
		cout << *(p+i) << " ";
	}
	cout << endl;
	cout << "Adresler:" << endl;
	for (int i = 0; i < 10; i++) {
		cout << p + i << endl;
	}
	cout << endl;
	cout << "Adresler:\tDeğerler:\n";
	for (int i = 0; i < 10; i++) {
		cout << p + i << "\t" << *(p + i) << endl;
	}
}
