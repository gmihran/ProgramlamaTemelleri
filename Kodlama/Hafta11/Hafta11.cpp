//Bu örneði Visual Studio 2017 C++ ile oluþturduk

#include "pch.h"
#include <iostream>
#include <locale.h>
#include <random>
#include <time.h>

//#include <bits/stdc++.h> //Visual studio'da bu kütüphanenin eklenmesine gerek yoktur.
//https://repl.it/ üzerinden çalýþtýrmak için ekledik.

using namespace std;
int main() {
	setlocale(LC_ALL, "turkish");
	srand(time(NULL));
	int matris[2][3];
	//matris[satir][sutun];
	//Matrisin içine 1 ile 6 arasýndaki sayýlarý atayalým
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
	//3*2 bir matrise rastgele 1-20 arasýnda deðerler atayýp ekrana yazdýralým
	int matris2[3][2];
	//int satir,sutun;
	for (satir = 0; satir < 3; satir++) {
		for (sutun = 0; sutun < 2; sutun++) {
			matris2[satir][sutun] = rand() % 10 + 1;
			cout << matris2[satir][sutun] << "\t";
		}
		cout << endl;
	}

	//Bu matristeki en büyük deðeri bulup ekrana yazdýralým
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
	//2.en büyük deðeri bulalým.
	for (satir = 0; satir < 3; satir++) {
		for (sutun = 0; sutun < 2; sutun++) {
			if (matris2[satir][sutun] >= mak2 && matris2[satir][sutun] != mak)
				mak2 = matris2[satir][sutun];
		}
	}
	cout << "2.Mak:" << mak2 << endl;

	//Ayný döngü içerisinde mak ve mak2 deðerlerini bulalým
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


	//Matrisin en büyük elemanýnýn bulunduðu sütunda yer alan en küçük elemaný bulalým
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
	cout << "Mak deðerin olduðu sütun:" << maksutun + 1 << endl;
	cout << "Mak deðerin olduðu sütundaki min deðeri:" << min << endl;

	//4*4'lük içerisinde -20 ile 50 arasýnda rastgele deðer tutan matriste yer alan satýrlardaki ve sütunlardaki deðerlerden en büyük ve en küçük deðerleri ekrana yazdýralým
	int rastgele[4][4], i, j;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			rastgele[i][j] = rand() % 71 - 20;
			//Son deðer 71+(-20)-1=50
			cout << rastgele[i][j] << "\t";
		}
		cout << endl;
	}
	//Deðerlerimiz -20 ile 50 arasýnda olduðu için aþaðýdaki atamalarý yapýyoruz. Min deðerine alabileceði maksimum deðeri, mak deðerine alabileceði minimum deðeri atýyoruz
	int min_satir[4] = { 50,50,50,50 }, mak_satir[4] = { -20,-20,-20,-20 }, min_sutun[4] = { 50,50,50,50 }, mak_sutun[4] = { -20,-20,-20,-20 };
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
		cout << i + 1 << ".satýrdaki mak:" << mak_satir[i] << endl;
		cout << i + 1 << ".satýrdaki min:" << min_satir[i] << endl;
		cout << i + 1 << ".sütundaki mak:" << mak_sutun[i] << endl;
		cout << i + 1 << ".sütundaki min:" << min_sutun[i] << endl;
	}

	char harfler[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','r','q','s','t','u','v','x','w','y','z' };
	//Random 25 kelime 6 harfli 2 boyutlu dizide tutulacak
	char kelime[25][6];
	int random;
	for (i = 0; i < 25; i++ ) {
		for (j = 0; j < 6; j++) {
			random = rand() % 26 + 0; //0 ile 25 arasýnda deðer üretir
			kelime[i][j] = harfler[random];
			cout << kelime[i][j];
		}
		cout << endl;
	}
	cout << "-------------------------------" << endl;
	char sesli[5] = { 'a','e','i','o','u' };
	char sessiz[21] = {'b','c','d','f','g','h','j','k','l','m','n','p','r','q','s','t','v','x','w','y','z' };
	for (i = 0; i < 25; i++) {
		for (j = 0; j < 6; j++) {
			if (j % 2 == 0) {
				random = rand() % 21 + 0; //0 ile 20 arasýnda deðer üretir
				kelime[i][j] = sessiz[random];
			}
			else {
				random = rand() % 5 + 0; //0 ile 4 arasýnda deðer üretir
				kelime[i][j] = sesli[random];
			}
			cout << kelime[i][j];
		}
		cout << endl;
	}

	system("pause");
}