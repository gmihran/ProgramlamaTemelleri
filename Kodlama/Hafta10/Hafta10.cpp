#include <iostream>
#include <locale.h>
#include <random>
#include <time.h>
#include <string>
using namespace std;
int main() {
  setlocale(LC_ALL,"turkish");
  srand(time(NULL));
  
  //Araştırma ödevi: C++ 11 (Modern C++) ile gelen yenilikler araştırılıp, 
  //10 tane yenilik kendi cümlelerinizle kaynak belirterek ve örnekler gerçekleştirilip ekran görüntüsü alınarak 
  //bir word belgesi veya powerpoint sunusu olarak online.beykoz üzerinden teslim edilecek.

  //Ödev: Bu soruyu while döngüsü ile çözmeye çalışalım.
  //İlk 100 asal sayıyı bir dizide tutarak bu diziyi ekrana yazdıralım
  int i;
  int asal[100],sayi=2,miktar;
  bool asal_durum;
  for(miktar=0;miktar<100;)
  {
    asal_durum=true; //sayının asal olduğunu farzedelim
    for (i=2;i<sayi;i++)
      if (sayi%i==0)
      {
        asal_durum=false;
        //sayı asal değildir
        break;
      }
    if (asal_durum)
    {
      asal[miktar]=sayi;
      miktar++;
    }
    sayi++;    
  }
  //Modern C++ ile gelen bir özellik:
  for (int deger:asal)
  //for döngüsü ile asal dizisinin içinde gezinmeyi sağladık. 
  //Bu döngüde asal dizisinin içindeki değerler deger değişkeni içerisinde teker teker saklanacak.
    cout << deger << " ";
  cout << endl;

  //Modern C++ ile gelen bir özellik:
  auto kim="Gözde";
  cout << kim << endl;
  auto s=123;
  cout << s << endl;
  s=1234;
  cout << s << endl;

  //50-80 değerleri arasında rastgele üretilen 10 sayıdan  en büyük ve en küçük sayıyı, 
  //tek ve çift sayıların miktarını ve ortalamasını ekrana yazdıralım
  //Ör : Klavyeden 2,3,-4,1,-3 girilirse;
  //Çıktı: 
  //En büyük sayı: 3 
  //En küçük sayı: -4
  //Pozitif: 3 tane sayı vardır. Ortalama: 2
  //Negatif: 2 tane sayı vardır. Ortalama: -3.5
  int rastgele[10];
  //int i;
  for (i=0;i<10;i++)
  {
    rastgele[i]=rand()%31+50;
    //50-80 değerleri arasında değer üretir 
    //Son değer: 31+50-1=80
    //+ ile belirtilen değer başlangıç değeridir.
    cout << rastgele[i] << " ";
    
  }
  //Min - Mak Değerleri, tek ve çift sayıların toplamını ve miktarını bulalım.
  int min=80,mak=50,ttoplam=0,ctoplam=0,tmiktar=0,cmiktar=0;
  for (i=0;i<10;i++){
    //Min - Mak Değerleri
    if (min>rastgele[i])
      min=rastgele[i];
    if (mak<rastgele[i])
      mak=rastgele[i];
    //tek ve çift sayıların toplamını ve miktarını bulalım.
    if (rastgele[i]%2==0){
      ctoplam+=rastgele[i];
      //ctoplam=ctoplam+rastgele[i];
      cmiktar+=1;
    }
    else{
      ttoplam+=rastgele[i];
      tmiktar++;
      //++tmiktar; tmiktar=tmiktar+1;
      //tmiktar+=1;
    }
  }
  cout << "Min:" << min << endl;
  cout << "Mak:" << mak << endl;
  cout << "Çift Miktar:" << cmiktar << endl;
  //cout << "Çift Toplam:" << ctoplam << endl;
  cout << "Çift Ortalama:" << float(ctoplam)/cmiktar << endl;
  //Bölünen değer float olursa bölüm sonucu float olur. 
  //float(ctoplam/cmiktar) ctoplam değeri int olduğu için bu işlemin sonucu int çıkar. Bu yüzden bölünen değeri float yapmalıyız.
  cout << "Tek Miktar:" << tmiktar << endl;
  //cout << "Tek Toplam:" << ttoplam << endl;
  cout << "Tek Ortalama:" << float(ttoplam)/tmiktar << endl;

  //Adam asmaca oyunu:
  //Kurallar:
  //Kelime daha önce tanımlanmış kelimeler arasından rastgele seçilir
  //Ekrana kelimenin uzunluğu kadar _ ekleniyor
  //Ör: kelime : kitap ise ekrana _ _ _ _ _ yazdırılacak
  //8 kere yanlış harf girme hakkı vardır.
  //Eğer tüm harfler hak bitmeden bilinmişse "Tebrikler", bilinmemişse "Kaybettiniz" yazdırıp tekrar oynamak isteyip istemediğini soralım
  string kelimeler[10]={"kelime","kazak","kedi","summer","hello","enough","kahve","congratulations","harddisk","darkness"};
  int r;
  //rand 0-9 arasında değer üretecek
  r=rand()%10; //Son değer: 10+0-1=9
  string kelime=kelimeler[r];
  char harf[kelime.length()],h;
  cout << "kelime:"<<  kelime << endl;
  for (i=1;i<=kelime.length();i++){
    //cout << "_ ";
    harf[i]='_';
    cout << harf[i] << " ";
  }

  int hak=8;
  while(hak>0){ //while(hak!=0)
    cout << "\nHarf:";
    cin >> h;
    bool durum=true;
    for (i=0;i<kelime.length();i++)
    {
      if (kelime[i]==h){
        harf[i]=h; //harf[i]=kelime[i];
        durum=false;
        }
    }
    if(durum)
      hak--;
    cout << "Kalan hakkınız:" << hak << endl;
    for (i=0;i<kelime.length();i++){
      cout << harf[i] << " ";
    }
    //kelimeyi doğru tahmin etti mi? Yani bütün harflerini bildi mi kontrol edelim.
    //1. ihtimal: harf char dizisinin içinde _ karakteri yoksa doğru bilmiştir.
    //2. ihtimal: harf char dizisinin bütün karakterlerini alıp string yaparsak ve kelime ile karşılaştırırsak ve eşit olursa 
    //doğru bilmiştir.
    //3. ihtimal: kelime değişkeninin içindeki tüm harfleri char dizisinin harfleri ile karşılaştırdığımızda 
    //bütün harfler birbirine eşitse doğru bilmiştir. 
	  
    //Aşağıdaki işlem birden fazla yöntemle çözülebilir.
    //Eğer _ sayısı 0'a eşitse doğru bilmiştir. Bunun doğruluğu kontrol edilebilir.
    bool kontrol=true; //Kullanıcının doğru bilmiş olduğunu farzediyoruz
    for (char deger:harf)
    {
      if (deger=='_')
      {
        //Kullanıcı doğru bilememiştir
        kontrol=false;
        break;
        //for döngüsü kırıldı. _ değerini bulduğumuz için tekrar bakmaya devam etmedik.
      }
    }
    if (kontrol)
      break;
      //while döngüsü kırıldı. Oyun bitti
  } 
  cout << "Tutulan Kelime:" << kelime;
 
}
