#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    // Írjon programot amely összeadja a bekért számokat.
    /*int szam=0, ossz=0;
    cout<<"Adja meg milyen muveletet akar végrehajtani:\n   1. Negativ szamig adok ossze.\n   2. 100-ig adok ossze.\n";
    cin>>szam;

    if(szam==1){
      cout << "Adjon meg szamokat!";
      cin >> szam;

      while(szam>=0){
       ossz=ossz+szam;
       cin >> szam;
      }
      cout << ossz << "\n";
    }

    else if(szam==2){
      cout << "Adjon meg szamokat!";

      while(ossz<100){
         cin >> szam;
         ossz=ossz+szam;
      }
      cout << ossz << "\n";
    }

    else cout<<"Rossz szamot adtal meg.\n";*/

    //Játékprogram: 1-100 között kell a számot kitalálni!
    /*int szam, szamlalo=0, tipp;
    srand(time(NULL));
    szam=rand()%100+1;
    cout << "Gondoltam egy szamra!\n";
    cin>>tipp;
    szamlalo++;
    while(!(tipp==szam)){
      if(tipp<szam){
        cout<<"A tipp nagyobb, mint a " << tipp << " (gondolt szam).";
      } else {
        cout<<"A tipp kisebb, mint a " << tipp << " (gondolt szam).";
      }
      cin>>tipp;
      szamlalo++;
    }
    if(szamlalo==1){
      cout << "Gratulalok, " << szamlalo << " eltalaltad.\n";
    } else {
      cout << "Eltalaltad, " << szamlalo << "-ra\n";
    }*/

    // 1-100-ig töltsünk fel egy 20 elemû tömböt véletlen számokkal és írassuk ki a legkisebbet, legnagyobbat, a 20-nál kisebbek számát!
    /*int tomb[20];
    int i=0, szam, max, min, kisebb20=0;
    srand(time(NULL));
    while(i<20){
    szam=rand()%100+1;
    tomb[i]=szam;
    i++;
    }
    i=0;
    max=tomb[0];
    min=tomb[0];
    cout<<"Tomb elemei: ";
    while(i<20){
       cout<< tomb[i] << " ";
    if(tomb[i]<20)   // 20-nál kisebbek vizsgálata
       kisebb20++;
    if(min>tomb[i])  // Minimum vizsgálata
       min=tomb[i];
    if(max<tomb[i])  // Maximum vizsgálata
       max=tomb[i];
    i++;
    }
    cout << "\n\nA legkisebb elem: " << min << "\nA legnagyobb elem: " << max << "\nA 20-nal kisebb szamok szama: " << kisebb20 << "\n\n";*/

    // 1-100-ig töltsünk fel egy 20 elemû tömböt véletlen számokkal és vizsgáljuk meg, hogy van-e két egyforma!
    /*int tomb[20];
    int i=0, j=0, szam;
    srand(time(NULL));
    while(i<20){
    szam=rand()%100+1;
    tomb[i]=szam;
    i++;}
    i=0;
    cout<<"Tomb elemei: ";
    while(i<20){
    cout<< tomb[i] << " ";
    i++;}
    cout << "\n";
    for(i=0;i<20;i++){
       for(j=i+1;j<20;j++){
          if(tomb[i]==tomb[j])
             cout << "A kovetkezo elembol tobb is van: " << tomb[i] << "\n";
       }
    }*/

    // Buborékrendezés (Minimumrendezéses)
    /*int tomb[20], i=0, seged, szam;
    srand(time(NULL));
    cout<<"Tomb elemei: ";
    while(i<20){
    szam=rand()%100+1;
    tomb[i]=szam;
    cout<< tomb[i] << " ";
    i++;
    }
    cout << "\n";
    for(i=0;i<20;i++){
       for(int j=i+1;j<20;j++){
          if(tomb[i]>=tomb[j]){
              seged=tomb[j];
              tomb[j]=tomb[i];
              tomb[i]=seged;
          }
       }
    }
    i=0;
    cout<< "Az rendezett tomb: ";
    while(i<20){
    cout << tomb[i] << " ";
    i++;}
    cout << "\n";*/

    // Buborékrendezés (Hagyományos/Original)
    /*int tomb[20], i=0, seged, szam;
    srand(time(NULL));
    cout<<"Tomb elemei: ";
    while(i<20){
    szam=rand()%100+1;
    tomb[i]=szam;
    cout<< tomb[i] << " ";
    i++;
    }
    cout << "\n";
    for(i=20;i>0;i--){
       for(int j=0;j<i;j++){
          if(tomb[j]>=tomb[j+1]){
              seged=tomb[j];
              tomb[j]=tomb[j+1];
              tomb[j+1]=seged;
          }
       }
    }
    i=0;
    cout<< "Az rendezett tomb: ";
    while(i<20){
    cout << tomb[i] << " ";
    i++;}
    cout << "\n";*/

    // Billentyûzetrõl bekér két számot 'a' és 'b'! Írjuk ki az 'a' számot 'b' alapú számrendszerben.
    /*int a, b, i=0, q=1, r, szam[100];
    cout<<"Adja meg a szamot es a szamrendszert!";
    scanf("%i %i", &a, &b);
    while(q!=0){
       r=a%b;
       q=a/b;
       a=q;
       szam[i]=r;
       i++;
    }
    for(i=i-1;i>=0;i--)
    cout<<szam[i];
    cout<<"\n";*/

    // 2 db 5-jegyû szám 8-as számrendszerben adunk be számokat, adjuk õket össze és írjuk ki
    int a[5], b[5], c[6], i;
    cin >> a[4] >> a[3]>> a[2]>> a[1]>> a[0];
    cin >> b[4] >> b[3]>> b[2]>> b[1]>> b[0];
    for(i=0;i<6;i++)
       c[i]=0;
    cout << "A ket szam: ";
    for(i=4;i>=0;i--)
    cout << a[i];
    cout << " es ";
    for(i=4;i>=0;i--)
    cout << b[i];
    for(i=0;i<5;i++)
       if(c[i]+a[i]+b[i]>=8){
          c[i]=c[i]+a[i]+b[i]-8;
          c[i+1]=c[i+1]+1;
       } else {
          c[i]=c[i]+a[i]+b[i];
       }
    if(c[5]==0){   //Azért van itt, mert különben rak egy nullát a összeg kiíratásakor!
        i--;
    }
    cout << "\nA szam az osszeadas utan: ";
    for(;i>=0;i--)
    cout << c[i];
    cout << "\n";
    system("PAUSE");
    return EXIT_SUCCESS;
}
