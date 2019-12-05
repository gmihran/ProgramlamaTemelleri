//Kaynak:https://www.technopat.net/sosyal/konu/cde-string-ici-karakter-arama.329218/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void myStringSearch(const char*,const char,int *);

int main()
{
    char myString[]="aabkaaa";
    char charToFind='k';
    
    int result;
    myStringSearch(myString,charToFind,&result);
    
    if(result!=-1)
        printf("KARAKTER BULUNDU %d\n",result+1);
    else
        printf("KARAKTER BULUNAMADI.\n");
}
void myStringSearch(const char*param1,const char param2,int *sonuc)
{    int i,tut=0;

    for(;*param1!='\0';param1++)
    {    
        if(tut==0)
            if(*param1==param2)
            {    *sonuc=i;
                    tut++;
            }
    i++;
    }

}