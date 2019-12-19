#include "pch.h"
#include <iostream>
#include <locale.h>
#include <string>
#include <random>
#include <time.h>

using namespace std;

void topla();
void topla(int sayi1, int sayi2);
void topla(double sayi1, double sayi2);
void topla(int s1, int s2, int s3);
int toplam(int s1, int s2);
int rastgele();
void mukemmel_sayi();
bool asal(int sayi);
void asal_sayilar(int s1, int s2);
int asal_sayi(int sira);

char ilk_harf(string kelime);
//string tanýmlý fonksiyonlarda using namespace std; tanýmlamasý fonksiyon tanýmlamasýndan önce gelmelidir. Ya da bunun için bir kütüphane tanýmlamasý yapýlabilir.
string kelimenin_tersi(string kelime);

int main()
{
	int sayi1, sayi2,toplamlar;
	string kelime, cumle;

	setlocale(LC_ALL, "turkish");

	srand(time(NULL));

	/*
	topla();
	topla(2,4);
	sayi1 = 3;
	sayi2 = 7;
	topla(sayi1, sayi2);
	topla(5.3, 4.6);
	topla(double(5), 4.6);
	topla(5.0, 4.6);
	topla(2, 3, 4);
	cout << toplam(3, 6) << endl;
	toplamlar = toplam(3,6);
	cout << toplamlar << endl;
	*/

	//Birden fazla cümleyi klavyeden okutabilmek için getline fonksiyonu kullanýlýr.
	//cin >> kelime; okunan deðerin boþluða kadar olan kýsmýný deðiþkene atamayý gerçekleþtirir. Ama getline(cin,kelime) kodu enter'a basýncaya kadar olan tüm karakterleri string deðiþkende tutmamýzý saðlar.
	/*
	getline(cin, kelime);
	*/
	
	/*
	cout << ilk_harf("Beykoz") << endl;
	cout << "Kelime:";
	getline(cin, kelime);
	//cin >> kelime; //getline(cin, kelime);
	cout << "Cumle:";
	getline(cin, cumle);
	cout << cumle << endl;
	cout <<"Ýlk harf:" <<  ilk_harf(kelime) << endl;
	cout << "Kelimenin tersi:" << kelimenin_tersi(kelime) << endl;
	cout << "Cümlenin tersi:" << kelimenin_tersi(cumle) << endl;
	//kelimenin_tersi(kelime) dönen deðeri bir string deðerde saklayýp o deðeri de kullanabiliriz.
	if (kelimenin_tersi(kelime) == kelime) 
		cout << kelime << " kelimesinin tersi kendisine eþit" << endl;
	else
		cout << kelime << " kelimesinin tersi kendisine eþit deðil" << endl;

	cout << "Mak:" << rastgele() << endl;
	
	mukemmel_sayi();
	*/
	cout << "2 sayý giriniz..:";
	cin >> sayi1 >> sayi2;
	asal_sayilar(sayi1, sayi2);

	cout <<"4.sayi:" <<  asal_sayi(4) << endl;
	cout << "10.sayi:" << asal_sayi(10) << endl;
	system("pause");

	return 1;

	cout << "Deneme"; 
	//return ifadesinden sonraki hiçbir kod çalýþmaz. 
	//Bunun nedeni fonksiyonun return iþleminden sonra sona ermesidir.
}

/*
donus_deger_turu fonksiyon_adi(parametre(ler)){

fonksiyonun_icinde_yapilacak_islemler

}
*/

//Parametre: null (yok)
//Geri döndürdüðü deðer void (yok)
void topla() {
	cout << "void topla() fonksiyonu çalýþtý." << endl;
	int sayi1 = 3;
	int sayi2 = 5;
	cout << sayi1 + sayi2 << endl;
}

//Parametre: (int sayi1, int sayi2)
//Geri döndürdüðü deðer void (yok)
void topla(int sayi1, int sayi2) {
	cout << "void topla(int sayi1, int sayi2) fonksiyonu çalýþtý." << endl;
	cout << sayi1 + sayi2 << endl;
}

//Parametre: (double sayi1, double sayi2)
//Geri döndürdüðü deðer void (yok)
void topla(double sayi1, double sayi2) {
	cout << "void topla(double sayi1, double sayi2) fonksiyonu çalýþtý." << endl;
	cout << sayi1 + sayi2 << endl;
}

void topla(int s1, int s2, int s3) {
	cout << "topla(int s1, int s2, int s3)fonksiyonu çalýþtý." << endl;
	cout << s1 + s2 + s3 << endl;
}

//Kendisine gönderilen 2 tamsayýnýn toplamýný geri döndüren fonksiyon:
int toplam(int s1, int s2) {
	cout << "int toplam(int s1, int s2)fonksiyonu çalýþtý." << endl;
	return s1 + s2;
}

//Kendisine gönderilen kelimenin ilk harfini geri döndüren fonksiyon
//Parametre : string kelime
//Geri dönen deðer : char
char ilk_harf(string kelime) {
	return kelime[0];
}

//Kendisine gönderilen kelimeyi tersini geri döndüren fonksiyon
//Ör: kedi -> idek 
//Ör: ipek -> kepi
string kelimenin_tersi(string kelime) {
	int uzunluk = kelime.length();
	string tersi="";
	for (int i = uzunluk-1; i >= 0; i--)
	{
		tersi += kelime[i]; 
		//tersi=tersi+kelime[i];
	}
	return tersi;
}
//------PROBLEM:-----//
//Rastgele üretilen 20 ile 36 arasýndaki 6 sayýdan en büyük deðeri geri döndüren fonksiyonu yazýnýz.

//Parametre : null (yok)
//Geri döndürdüðü deðer : int
//Fonksiyon adý: rastgele

//int random=rand()%17+20; 
//Son deðer: 17+20-1=36

//min=20;

int rastgele() {
	int sayi, mak=20;
	for (int i = 1; i <= 6; i++) {
		sayi = rand() % 17 + 20;
		cout << sayi << " ";
		if (sayi > mak) //if (mak < sayi)
			mak = sayi;
	}
	cout << endl;
	return mak;
}


//------PROBLEM:-----//
//1-9000 arasýndaki mükemmel sayýlarý ekrana yazdýran fonksiyon
//Mükemmel sayý: Kendisi hariç pozitif bölenlerinin toplamlarý kendisine eþit olan sayýdýr.
//Fonksiyon adý: mukemmel_sayi
//Parametre: null (yok)
//Geri döndürdüðü deðer: void (yok)
void mukemmel_sayi() {
	int toplam;
	for (int sayi = 1; sayi <= 9000; sayi++)
	{
		toplam = 0;
		for (int bolen = 1; bolen < sayi; bolen++)
		{
			if (sayi%bolen == 0) {
				toplam += bolen;
			}
		}
		if (toplam == sayi) //Sayý mükemmel sayýdýr
			cout << sayi << endl;
	}
}


//------PROBLEM:-----//
//Fonksiyonu gelen (Kullanýcýnýn girdiði) iki deðer arasýndaki asal sayýlarý ekrana yazdýran fonksiyon
//Asal sayý, 1 ve kendisi hariç böleni olmayan sayýdýr
//Fonksiyon adý: asal_sayilar
//Parametre: int s1, int s2
//Geri döndürdüðü deðer: void (yok)
void asal_sayilar(int s1, int s2) {
	for (int sayi = s1; sayi <= s2; sayi++)
	{
		if (asal(sayi))
			cout << sayi << endl;
	}
}

bool asal(int sayi) {
	bool kontrol = true; //sayý asaldýr
	if (sayi <= 1)
		kontrol = false;
	else
		for (int i = 2; i <= sayi/2; i++)
		//Bir sayý kendisinin yarýsýndan daha büyük sayýlara bölünemez. 
		//Bu yüzden i <= sayi/2 koþulunu kullandýk.
		{
			if (sayi%i == 0) {
				kontrol = false; //sayý asal deðildir
				break;
			}
		}
	return kontrol;
}

//------PROBLEM:-----//
//Kullanýcýnýn girdiði sýradaki asal sayýyý geri döndüren fonksiyon
//Fonksiyon adý: asal_sayi
//Parametre: int s1
//Geri döndürdüðü deðer: int
int asal_sayi(int sira) {
	int sayi = 0, sayac=0;
	while(sira>=1)
	{
		sayi++;
		if (asal(sayi)) {
			sayac++;
		}
		if (sayac == sira) {
			//cout << sayi;
			break;
		}
	}
	return sayi;
}