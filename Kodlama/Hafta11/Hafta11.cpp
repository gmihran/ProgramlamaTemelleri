//Bu örneği Visual Studio 2017 C++ ile oluşturduk

#include "pch.h"
#include <iostream>
#include <locale.h>
#include <random>
#include <time.h>

//#include <bits/stdc++.h> //Visual studio'da bu kütüphanenin eklenmesine gerek yoktur.
//https://repl.it/ üzerinden çalıştırmak için ekledik.

using namespace std;
int main() {
	setlocale(LC_ALL, "turkish");
	srand(time(NULL));
	int matris[2][3];
	//matris[satir][sutun];
	//Matrisin içine 1 ile 6 arasındaki sayıları atayalım
	matris[0][0] = 1;
	matris[0][1] = 2;
	matris[0][2] = 3;
	cout << matris[0][0] << endl;
	cout << matris[0][1] << endl;
	cout << matris[0][2] << endl;
	cout << matris[1][0] << endl;
	cout << matris[1][2] << endl;
	int sayac = 1, satir, sutun;
	//int matris[2][3];
	for (satir = 0; satir < 2; satir++) {
		for (sutun = 0; sutun < 3; sutun++) {
			matris[satir][sutun] = sayac;
			sayac = sayac + 1;
			//matris[satir][sutun]=sayac++;
			cout << matris[satir][sutun];
		}
	}
	cout << endl;
	//3*2 bir matrise rastgele 1-20 arasında değerler atayıp ekrana yazdıralım
	int matris2[3][2];
	//int satir,sutun;
	for (satir = 0; satir < 3; satir++) {
		for (sutun = 0; sutun < 2; sutun++) {
			matris2[satir][sutun] = rand() % 10 + 1;
			cout << matris2[satir][sutun] << "\t";
		}
		cout << endl;
	}

	//Bu matristeki en büyük değeri bulup ekrana yazdıralım
	int mak = 1;
	//mak=INT_MIN;
	//cout << mak << endl;
	for (satir = 0; satir < 3; satir++) {
		for (sutun = 0; sutun < 2; sutun++) {
			if (matris2[satir][sutun] > mak)
				mak = matris2[satir][sutun];
		}
	}
	cout << "Mak:" << mak << endl;
	int mak2 = 1; //mak2=INT_MIN;
	//2.en büyük değeri bulalım.
	for (satir = 0; satir < 3; satir++) {
		for (sutun = 0; sutun < 2; sutun++) {
			if (matris2[satir][sutun] >= mak2 && matris2[satir][sutun] != mak)
				mak2 = matris2[satir][sutun];
		}
	}
	cout << "2.Mak:" << mak2 << endl;

	//Aynı döngü içerisinde mak ve mak2 değerlerini bulalım
	mak = 1; mak2 = 1;
	for (satir = 0; satir < 3; satir++) {
		for (sutun = 0; sutun < 2; sutun++) {
			if (mak < matris2[satir][sutun])
			{
				mak2 = mak;
				mak = matris2[satir][sutun];
			}
			else if (mak2 < matris2[satir][sutun] && matris2[satir][sutun] != mak)
				mak2 = matris2[satir][sutun];
		}
	}
	cout << "Mak:" << mak << endl;
	cout << "2.Mak:" << mak2 << endl;


	//Matrisin en büyük elemanının bulunduğu sütunda yer alan en küçük elemanı bulalım
	//matris2[3][2]
	mak = 1;
	int maksutun;
	for (satir = 0; satir < 3; satir++) {
		for (sutun = 0; sutun < 2; sutun++) {
			if (mak < matris2[satir][sutun]) {
				mak = matris2[satir][sutun];
				maksutun = sutun;
			}
		}
	}
	cout << "Mak:" << mak << endl;
	int min = 20;
	for (satir = 0; satir < 3; satir++) {
		if (min > matris2[satir][maksutun])
			min = matris2[satir][maksutun];
	}
	cout << "Mak değerin olduğu sütun:" << maksutun + 1 << endl;
	cout << "Mak değerin olduğu sütundaki min değeri:" << min << endl;

	//4*4'lük içerisinde -20 ile 50 arasında rastgele değer tutan matriste yer alan 
	//satırlardaki ve sütunlardaki değerlerden en büyük ve en küçük değerleri ekrana yazdıralım
	int rastgele[4][4], i, j;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			rastgele[i][j] = rand() % 71 - 20;
			//Son değer 71+(-20)-1=50
			cout << rastgele[i][j] << "\t";
		}
		cout << endl;
	}
	//Değerlerimiz -20 ile 50 arasında olduğu için aşağıdaki atamaları yapıyoruz. 
	//Min değerine alabileceği maksimum değeri, mak değerine alabileceği minimum değeri atıyoruz
	int min_satir[4] = { 50,50,50,50 }, mak_satir[4] = { -20,-20,-20,-20 };
	int min_sutun[4] = { 50,50,50,50 }, mak_sutun[4] = { -20,-20,-20,-20 };
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (rastgele[i][j] < min_satir[i])
				min_satir[i] = rastgele[i][j];

			if (rastgele[i][j] > mak_satir[i])
				mak_satir[i] = rastgele[i][j];

			if (rastgele[j][i] < min_sutun[i])
				min_sutun[i] = rastgele[j][i];

			if (rastgele[j][i] > mak_sutun[i])
				mak_sutun[i] = rastgele[j][i];
		}
	}
	for (i = 0; i < 4; i++)
	{
		cout << i + 1 << ".satırdaki mak:" << mak_satir[i] << endl;
		cout << i + 1 << ".satırdaki min:" << min_satir[i] << endl;
		cout << i + 1 << ".sütundaki mak:" << mak_sutun[i] << endl;
		cout << i + 1 << ".sütundaki min:" << min_sutun[i] << endl;
	}

	char harfler[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','r','q','s','t','u','v','x','w','y','z' };
	//Random 25 kelime 6 harfli 2 boyutlu dizide tutulacak
	char kelime[25][6];
	int random;
	for (i = 0; i < 25; i++ ) {
		for (j = 0; j < 6; j++) {
			random = rand() % 26 + 0; //0 ile 25 arasında değer üretir
			kelime[i][j] = harfler[random];
			cout << kelime[i][j];
		}
		cout << endl;
	}
	
	//sessiz sesli sessiz sesli sessiz sesli
	cout << "-------------------------------" << endl;
	char sesli[5] = { 'a','e','i','o','u' };
	char sessiz[21] = {'b','c','d','f','g','h','j','k','l','m','n','p','r','q','s','t','v','x','w','y','z' };
	for (i = 0; i < 25; i++) {
		for (j = 0; j < 6; j++) {
			if (j % 2 == 0) {
				random = rand() % 21 + 0; //0 ile 20 arasında değer üretir
				kelime[i][j] = sessiz[random];
			}
			else {
				random = rand() % 5 + 0; //0 ile 4 arasında değer üretir
				kelime[i][j] = sesli[random];
			}
			cout << kelime[i][j];
		}
		cout << endl;
	}
	
	cout << "-------------------------------" << endl;
	/*
	sessiz sesli sessiz sessiz sesli sessiz
	sayac%2==1 
	1 =sessiz
	2 =sesli
	3 =sessiz
	4 =sessiz ->1
	5 =sesli  ->2
	6 =sessiz ->3
	
	if (sayac==3)
	sayac=1;
	
	sayac++;
	//Bu yöntem dışında farklı yollarla da çözülebilir.
	*/
	sayac = 1;
	for (i = 0; i < 25; i++) {
		for (j = 0; j < 6; j++) {
			//if (sayac==1 || sayac==3 || sayac==4 || sayac==6) bu şekilde kontrol edilirse; 
			//if (sayac == 3) sayac = 1; else 
			//adımlarına gerek kalmaz
			if (sayac%2==1) {
				random = rand() % 21 + 0; //0 ile 20 arasında değer üretir
				kelime[i][j] = sessiz[random];
			}
			else {
				random = rand() % 5 + 0; //0 ile 4 arasında değer üretir
				kelime[i][j] = sesli[random];
			}
			if (sayac == 3)
				sayac = 1;
			else
				sayac++;			
			cout << kelime[i][j];
		}
		cout << endl;
	}

	system("pause");
}
