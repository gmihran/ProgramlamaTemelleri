//Bu kontrol işlemi son yapılan örneğe eklenebilir.

char harfler[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','r','q','s','t','u','v','x','w','y','z'};
k=true;
for (i=0;i<=harfler.length();i++)
    {
      if (h==harfler[i])
        k=false;
    }
    
    //Eğer kullanıcı kelimede olmayan bir harfi tekrar girerse hakkı azalmasın
