#include "pch.h"
#include <iostream>
#include <locale.h>
//Bu örnek Yapay Zeka ile çözülebilir
//Bilgisayar SOS yazmaya çalışabilir veya kullanıcının yazmaması için gerekli yerleri doldurabilir.
using namespace std;
char sos[3][3] = { '#','#','#','#','#','#','#','#','#' }, pc_deger;
int i, j;
bool kontrol = false;
void yazdir(){
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			cout << sos[i][j];
		}
		cout << endl;
	}
}
void pc() {
	//Eğer # kalmamışsa bu fonksiyon çağrılmamalıdır
	char deger[2] = { 'S','O' };
	int x = rand() % 2 + 0;
	pc_deger = deger[x];
	int satir, sutun;
	do {
		satir = rand() % 3 + 0;
		sutun = rand() % 3 + 0;
	} while (sos[satir][sutun]!='#');
	sos[satir][sutun] = pc_deger;
}

void durum() {
	int sayac = 0;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			if (sos[i][j] == '#') 
					sayac++;	
		}		
	}
	if (sayac == 0) 
		kontrol = true; //oyun bitti
		
}
void kullanici() {
	//Eğer # kalmamışsa bu fonksiyon çağrılmamalıdır
	int satir, sutun;
	char deger;
	do{
	cout << "Satır değeri:";
	cin >> satir;
	cout << "Sütun değeri:";
	cin >> sutun;
	} while (sos[satir-1][sutun-1] != '#');
	cout << "S-O :";
	cin >> deger;
	//Burada S-O doğru girildi mi? Kontrol edilecek.
	sos[satir - 1][sutun - 1] = deger;
}

int main()
{
	//sos oyunu
	//Bilgisayar boş olan alanlara rastgele s o s koyar
	//Biz de onu yenmeye çalışırız
	setlocale(LC_ALL, "turkish");
	do{
		pc();
		durum();
		if (kontrol)
			break;
		yazdir();
		kullanici();
		
	} while (kontrol == false);
	//else if () {
		//SOS yazıldı mı? Kontrol edilecek

	//}
	yazdir();
	cout << "Oyun bitti";
}
