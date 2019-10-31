#include <iostream>
using namespace std;
//std isim uzayını projemize dahil ettik
int main() {
  //Klavyeden girilen değerin tek veya çift olduğunu yazdıralım
  int sayi;
  
  cout << "Bir sayı girin:";
  cin >> sayi;
  if (sayi%2==0)
    cout << sayi << " çifttir\n";
  else 
    cout << sayi << " tektir" << endl;
  
  //Satır sonu verip, yazdırma işleminin alt satırdan başlamasını sağlamak için "\n" veya endl kullanırız

  //1 ile 100 arasındaki sayıları ekrana alt alta yazdıralım
  int i;
  
  for (i=1;i<=100;i=i+1)
  //Şart doğru olduğu sürece döngü devam eder
    cout << i << endl;
  //1 ile 100 arasındaki tek sayıları yan yana ekrana yazdıralım
  for (i=1;i<=100;i=i+2)
    cout << i << " ";
  
  cout << endl;
  sayi=0;
  sayi=sayi+1;
  sayi++;
  ++sayi;
  sayi+=1;
  cout << sayi << endl;
  //Bu 4 işlem sayi değerini 1 arttırır
  sayi=0;
  cout << sayi << endl;
  cout << "sayi++ :" << sayi++ << endl;
  cout << sayi << endl;
  cout <<"++sayi :" << ++sayi << endl;
  cout << sayi << endl;
  int toplam;
  toplam=sayi++;
  cout << "Toplam:" << toplam << " Sayı:" << sayi << endl;
  //toplam:2, sayi:3
  toplam=++sayi;
  cout << "Toplam:" << toplam << " Sayı:" << sayi << endl;
  cout <<"--toplam :" << --toplam << endl;
  toplam*=2; //toplam=toplam*2;
  cout << "Toplam:" << toplam << endl;
  toplam/=3; //toplam=toplam/3;
  cout << "Toplam:" << toplam << endl;
  //100 ile 1 arasındaki sayıları yan yana ekrana yazdıralım
  for (i=100;i>=1;i--)
    cout << i << " ";
  cout << endl;

  //Kullanıcının girdiği sayılar arasındaki sayıları ekrana yazdıralım
  int s1,s2;
  cout << "İki sayı girin:";
  cin >> s1 >> s2;
  //İlk girilen sayı ikinci girilen sayıdan büyük ise bu döngü çalışmaz
  for (i=s1;i<=s2;i++)
    cout << i << " ";
  cout << endl;

  //Kullanıcının girdiği iki değer arasındaki sayıları (küçük değerden büyük değere kadar olan sayıları) ekrana yazdıralım
  //cout << "İki sayı girin:";
  //cin >> s1 >> s2;
  int bos;
  if (s1>s2)
  {
    //Yer değiştirelim
    bos=s1;
    s1=s2;
    s2=bos;
    //swap(s1,s2);
  }
  for (i=s1;i<=s2;i++)
    cout << i << " ";
  cout << endl;
  
  
  //0 ile 100 arasındaki tek sayıları ve toplamlarını ekrana yazdıralım
  
  int t=0;
  for (i=0;i<=100;i++)
    if (i%2==1)
    {
      cout << i << " ";
      t+=i;
    }
  cout << "\nToplam:" << t << endl;


  
  //Kullanıcının girdiği iki değer arasında 2’ye veya 5’e bölünen sayıları, sayıların toplamlarını ve ortalamalarını ekrana yazdıralım
  //Sayılardan ilk girilen büyük ise sayıların yerini değiştirelim
  //Sayıların yerini değiştirmek için swap fonksiyonunu kullanabilirsiniz
  // if (sayi%2==0 || sayi%5==0)

  int sayi1, sayi2, sayac=0;
  float toplm=0;
  cout << "2 Değer Giriniz: ";
  cin >> sayi1 >> sayi2;
  if (sayi1 > sayi2){
    swap(sayi1,sayi2);
  }
  for (i=sayi1; i<= sayi2; i++){
    if (i%2 == 0 || i%5 == 0){
      toplm += i;
      cout << i << " ";
      sayac++;
    }
  }
  cout << "\nToplam Değer : " << toplm;
  cout << "\nOrtalama Değer : " << toplm/sayac << endl;
  
  int bolunen, bolen;
  float bolum;
  cout << "Bölünen:";
  cin >> bolunen;
  cout << "Bölen:";
  cin >> bolen;
  if (bolen==0)
    cout << "Tanımsız\n";
  else
  {
    bolum=float(bolunen) / bolen;
    //Sonucun ondalıklı olabilmesi için bölünen değerin de float olarak tanımlanması ya da float değere dönüştürülmesi gerekmektedir.
    cout << "Bölüm:" << bolum << endl;
  }
    
    
// Ekrana aşağıdaki çıktıyı yazdırmaya çalışalım
//Kullanıcının girdiği değer kadar bu işlemi tekrar edelim.
//Ör; 6 girilirse; çıktı aşağıdaki gibi olacak.
/*
*****
*****
*****
*****
*****
*****
*/
int j;

cout << "Bir sayı: ";
cin>> sayi;
for (i=1;i<=sayi;i++)
cout << "*****\n";

for (i=1;i<=2;i++)
for (j=1;j<=3;j++)
cout << i << " " << j << endl ;

// Ekrana aşağıdaki çıktıyı yazdırmaya çalışalım
//Kullanıcının girdiği değer kadar yıldız sayısını ve bu işlemi tekrar edelim.
//Ör; 2 ve 3 değerleri girilirse; çıktı aşağıdaki gibi olacak.
/*
**
**
**
*/

cout << "2 sayı giriniz: ";
cin >> s1 >> s2;
for (i=1;i<=s1;i++)
//satır sayısı : s1
{
  for (j=1;j<=s2;j++)
  //yıldız sayısı : s2
    cout << "*";
  cout << endl;
}
  
/*
1
12
123
1234
12345
*/
//İçteki döngü dıştaki döngü kadar çalışacak

for (i=1;i<=5;i++)
{
  for (j=1;j<=i;j++)
    cout << j;
  cout << endl;
}


//Klavyeden girilen değere göre aşağıdaki çıktıyı veren program
//Ör; 6 girilirse;
/*
1 1
2 12
3 123
4 1234
5 12345
6 123456
*/
cout << "Sayı:";
cin >> sayi;
for (i=1;i<=sayi;i++)
{
  cout << i << " ";
  for (j=1;j<=i;j++){
    cout << j;
  } 
  cout << endl;
}
}

//Ödev:Çarpım tablosunu hazırlayalım
/*
1*1=1 2*1=2 3*1=3.... 10*1=10
1*2=2 2*2=4 3*2=6.... 10*2=20
.............................
1*10=10 2*10=20 3*10=30 .... 10*10=100
*/



