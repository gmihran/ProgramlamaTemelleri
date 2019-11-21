#include <iostream>
#include <string.h>
using namespace std;
int main() {
  int x=5,y,z;

  y=x++;
  z=x+y;
  cout << x << "-" << y << "-" << z <<endl;

  //Kullanıcıdan aldığımız sayıya kadar ekrana aşağıdaki çıktıyı yazdırmaya çalışalım
  //Ör; 10 girerse;
	/*
	1
	22
	333
	4444
	55555
	666666
	7777777
	88888888
	999999999
	10101010101010101010
  */
  int sayi,i,j;
  
  cout << "Sayı:";
  cin >> sayi;
  for (i=1;i<=sayi;i++)
  {
    for (j=1;j<=i;j++)
      cout << i;
    cout << endl;
  }
  //cout << i << j << endl;

  //i ve j kullanıcının girdiği sayının 1 fazlasına eşittir. Çünkü bu değer şartı sağlamadığı için döngüler sona erer.

  //Kullanıcının girdiği sayıya kadar (sayı dahil değil) ekrana aşağıdaki çıktıyı yazdırmaya çalışalım
  //Kullanıcı 7 girerse;
	/*
	1 1
	2 22
	3 333
	4 4444
	5 55555
	6 666666
	*/
  //int sayi,i,j;

  cout << "Sayı:";
  cin >> sayi;
  for (i=1;i<sayi;i++)
  {
    cout << i << " ";
    for (j=1;j<=i;j++)
      cout << i;
    cout << endl;
  }


  //Ekrana aşağıdaki çıktıyı yazdırmaya çalışalım
	/*
	1
	2 3
	4 5 6
	7 8 9 10
	11 12 13 14 15
	16 17 18 19 20 21
	*/
  //1.çözüm:
  int sayac=0;

  for (i=1;i<=6;i++)
  {
    for (j=1;j<=i;j++)
      cout << ++sayac << " ";
    cout << endl;
  }
  //2.çözüm:
  sayac=1;
  for (i=1;i<=6;i++)
  {
    for (j=1;j<=i;j++)
      cout << sayac++ << " ";
    cout << endl;
  }

  //Kullanıcının girdiği değer kadar satırda ekrana aşağıdaki çıktıyı yazdırmaya çalışalım
  //Ör; 5 girerse;
	/*
	1
	2 3
	4 5 6
	7 8 9 10
	11 12 13 14 15
	*/
  //int sayac,sayi,i,j;

  sayac=0;
  cout << "Sayı:";
  cin >> sayi;
  for (i=1;i<=sayi;i++)
  {
    for (j=1;j<=i;j++)
      cout << ++sayac << " ";
    cout << endl;
  }

  //Kullanıcının girdiği değere kadar ekrana aşağıdaki çıktıyı yazdırmaya çalışalım
  //Ör; 14 girerse;
	/*
	1
	2 3
	4 5 6
	7 8 9 10
	11 12 13 14 
	*/
  //int sayac,sayi,i,j;

  sayac=0;
  cout << "Sayı:";
  cin >> sayi;
  for (i=1;;i++)
  {
    //i: sonsuz döngü
    for (j=1;j<=i;j++)
    {
      cout << ++sayac << " ";
      if (sayac==sayi)
        //j döngüsü kırıldı
        break;
    }
    cout << endl;
    if (sayac==sayi)
      //i döngüsü kırıldı
      break;  
    
  }

  //1 ile 10 arasındaki sayıları while döngüsü ile ekrana yazdıralım
  //while(koşul) {}
  //while(true) sonsuz döngüdür
  int deger=1;
  while(deger<=10)
  {
    cout << deger;
    deger=deger+1;
  }
  cout << endl;

  //Kullanıcının girdiği değere kadar olan sayıları ekrana yazdıralım
  deger=1;
  
  cout << "Sayı:";
  cin >> sayi;
  while(deger<=sayi)
  {
    //koşul doğru olduğu sürece çalışır
    cout << deger;
    deger=deger+1; //sayac
  }
  cout << endl;
  //Sayıyı tersten yazdıralım:
  while(sayi>=1)
  {
    cout << sayi--;
  }
  cout << endl;

  //Kullanıcı 0 sayısını girene kadar girdiği değerlerin toplamını hesaplayıp ekrana yazdıralım
  //1.yöntem:
  int toplam=0;
  sayi=1; //döngüye girebilmesi için sayı değerinin 0 olmaması gerekiyor

  while(sayi!=0)
  {
    cout << "Sayı:";
    cin >> sayi;
    toplam+=sayi;
  }
  cout << "Toplam:" << toplam << endl;

  //2.yöntem:
  toplam=0;
  while(true)
  {
    //while döngüsü sonsuz döngüdür.
    cout << "Sayı:";
    cin >> sayi;
    if (sayi==0)
      //sayı 0 girilirse döngü kırılır
      break;
    toplam+=sayi;
  }
  cout << "Toplam:" << toplam << endl;

  //3.yöntem
  toplam=0;
  do
  {
    //Bu döngü en az 1 kez çalışır
    cout << "Sayı:";
    cin >> sayi;
    toplam+=sayi;
  }while(sayi!=0);
  cout << "Toplam:" << toplam << endl;

  //Kullanıcı 0 sayısını girene kadar girdiği değerlerden pozitif ve negatif olanların toplamlarını ve miktarlarını ekrana yazdıralım
  //Ör: 1 -2 8 3 -2 -3 0 sayılarını girerse çıktı aşağıdaki gibi olmalıdır.
  //Pozitif toplamı:12 miktarı:3
  //Negatif toplamı:-7 miktarı:3
  //int sayi;
  int ptoplam=0,ntoplam=0,psayac=0,nsayac=0;
  do{
    cout << "Sayı:";
    cin >> sayi;
    if (sayi>0){
      ptoplam+=sayi; 
      psayac++;
    }
    else if (sayi<0){
      ntoplam+=sayi;
      nsayac++;
    }
  }while(sayi!=0);
  cout << "Pozitif toplamı:" << ptoplam;
  cout << " miktarı:" << psayac << endl;
  cout << "Negatif toplamı:" << ntoplam;
  cout << " miktarı:" << nsayac << endl;

  //Girilen sayının tersten okunuşu kendisine eşit mi?
	//sayı=1234
	//ters=4321
  //Sayının tersi kendisine eşit değil
  //sayı=19891
  //tersi=19891
  //Sayının tersi kendisine eşit
  
  //ters=0
  //sayi=123
  //Eğer sayi>=1 ise aşağıdaki işlemler tekrar edecek
  //ters=ters*10+sayi%10=0+3=3
  //sayi=sayi/10=12
  //ters=ters*10+sayi%10=30+2=32
  //sayi=sayi/10=1
  //ters=ters*10+sayi%10=320+1=321
	int sayiyedek,ters=0;

  cout << "Sayı:";
  cin >> sayi;
  sayiyedek=sayi;
  while(sayi>=1)
  {
    ters=ters*10+sayi%10;
    //sayi%10 işlemi sayi değerinin birler basamağını alır.
    //ters değerinin 10'a çarpmamızın sebebi birler basamağına bir basamak eklemek içindir.
    sayi=sayi/10;
    //sayının birler basamağındaki değeri yok saydık
  }
  cout << "Sayının tersi:" << ters << endl;
  if (sayiyedek==ters)
    cout << "Sayının tersi kendisine eşit";
  else
    cout << "Sayının tersi kendisine eşit değil";
  cout << endl;

  //Girilen kelimeyi ekrana yazdıralım
  string kelime;
  cout << "Kelime:";
  cin >> kelime;
  cout << "Girilen kelime:" << kelime << endl;
  //Girilen kelimenin 1.harfini ekrana yazdıralım
  cout << "Kelimenin 1.harfi:" << kelime[0] << endl;
  //Kelimenin karakter sayısını (uzunluğunu) ekrana yazdıralım
  cout << "Kelimenin uzunluğu:" << kelime.length() << endl;
  //Kelimenin son harfini ekrana yazdıralım
  cout << "Kelimenin son harfi:" << kelime[kelime.length()-1] << endl;


}