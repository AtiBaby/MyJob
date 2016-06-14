#include <cstdlib>
#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;

/*int hossz(char *s){
    int h=0, i;
    for(i=0;s[i]>0;i++){
       h++;
    }
    return h;
}

int main(int argc, char *argv[])
{
    int i;
    char s[100];
    cin>>s;
    for(i=0;s[i]>0;i++)   // A tomb vége mindig nulla
    cout<<s[i]<<" ";
    cout<<"\nHossz: "<<hossz(s)<<"\n";
    system("PAUSE");
    return EXIT_SUCCESS;
}*/

void nagybetu(char *s){
      int i;
      for(i=0;s[i]>0;i++){
         cout<<char(toupper(s[i]));
      }
      cout<<"\n";
}

int kodok(char *s){
    int i;
    for(i=0;s[i]>0;i++){
       cout<<int(s[i])<<" ";   //Típuskonverzió
    }
    cout<<"\n";
}

int main(int argc, char *argv[])
{
    int i;
    char s[100];
    cin>>s;
    kodok(s);
    nagybetu(s);
    system("PAUSE");
    return EXIT_SUCCESS;
}

/*void hanyszo(char *s){
     int i, szamlalo=1;
     for(i=0;s[i]>0;i++){
        if(s[i]==' ' && s[i-1]!=' '){
           szamlalo++;
        }
     }
     cout<<"\nSzavak szama: "<<szamlalo<<"\n";
}

int main(int argc, char *argv[])
{
    int i;
    char s[100];
    gets(s);
    cout<<s;
    hanyszo(s);
    system("PAUSE");
    return EXIT_SUCCESS;
}*/

/*int szotagszam(char *s){
     int i, j, szotagok=0;
     char maganhangzok[]={'a','e','i','o','u','A','E','I','O','U'};
     for(i=0;s[i]>0;i++){
        for(j=0;maganhangzok[j]>0;j++){
           if(s[i]==maganhangzok[j]){
              szotagok++;
           }
        }
     }
     return szotagok;
}

int main(int argc, char *argv[])
{
    char s[100];
    gets(s);
    cout<<"Szotagok szama: "<<szotagszam(s)<<"\n";
    system("PAUSE");
    return EXIT_SUCCESS;
}*/

// String osszefuzese

/*int main(int argc, char *argv[])
{
    char s1[100], s2[100];
    cin>>s1;
    cin>>s2;
    int i, j;
    for(i=0;s1[i]>0;i++){
       ;
    }
    for(j=0;s2[j]>0;j++,i++){
       s1[i]=s2[j];
    }
    s1[i]=0;
    cout<<s1<<"\n";
    system("PAUSE");
    return EXIT_SUCCESS;
}*/

/*int main(int argc, char *argv[])
{
    char a[100];
    char *b;
    b=a;
    gets(b);
    cout<<"A:"<<a<<"\n";
    cout<<"B:"<<b<<"\n";
    system("PAUSE");
    return EXIT_SUCCESS;
}*/

/*int main(int argc, char *argv[])
{
    int a[10];
    int *b;
    int i;
    srand(time(NULL));
    for(i=0;i<10;i++){
       a[i]=rand()%100;
    }
    for(i=0;i<10;i++){
       cout<<a[i]<<" ";
    }
    cout<<"\n";
    for(b=a;b<a+10;b++){
       cout<<*b<<" ";
    }
    cout<<"\n";
    system("PAUSE");
    return EXIT_SUCCESS;
}*/

/*int main(int argc, char *argv[])
{
    int *a, *b;
    int i;
    
    /*a=new int;
    b=a;
    *a=2;
    cout<<*b<<"\n";
    delete a;*/
    /*
    a=new int[10];
    for(i=0;i<10;i++)
       a[i]=rand()%100;
    for(i=0;i<10;i++)
       cout<<a[i]<<" ";
    cout<<"\n";
    delete[]a;
    system("PAUSE");
    return EXIT_SUCCESS;
}*/

// 0-n-ig számok be számoljunk átlagot és szórást

/*int main(int argc, char *argv[])
{
    int i, osszeg=0, meddig, mennyi, *szamok;
    float *atlag, *szoras, kulonbseg=0;
    cout<<"Adja meg a tartomanyt: ";
    cin>>meddig;
    cout<<"Adja meg a veletlen szamok szamat: ";
    cin>>mennyi;
    srand(time(NULL));
    szamok=new int[mennyi];
    atlag=new float;
    szoras=new float;
    for(i=0;i<mennyi;i++){
       szamok[i]=rand()%meddig;
    }
    for(i=0;i<mennyi;i++){
       osszeg=osszeg+szamok[i];
    }
    *atlag=osszeg/mennyi;
    for(i=0;i<mennyi;i++)
       kulonbseg=kulonbseg+(szamok[i]-*atlag)*(szamok[i]-*atlag);
    kulonbseg=kulonbseg/mennyi;
    *szoras=sqrt(kulonbseg);
    cout<<"A szamok: ";
    for(i=0;i<mennyi;i++){
       cout<<szamok[i]<<" ";
    }
    cout<<"\nAz atlaguk: "<<*atlag<<"\nA szorasuk: "<<*szoras<<"\n";
    delete atlag;
    delete szoras;
    delete []szamok;
    system("PAUSE");
    return EXIT_SUCCESS;
}*/
