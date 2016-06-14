#include <cstdlib>
#include <iostream>
#include <math.h>

using namespace std;

/*// Tömb legkisebb elemének megkeresése fv segítségével

int keres(int a[100], int k){   // k = ténylegesen mennyi van benne
    int i, min;
    min=a[0];
    for(i=0;i<k;i++){
       if(min>a[i])
          min=a[i];
    }
    return min;
}

int main(int argc, char *argv[])
{
    int tomb[100], szam, k=0;
    cout<<"Adja meg a tomb elemeit: (negativ szamig)";
    cin>>szam;
    while(szam>=0){
       tomb[k]=szam;
       cin>>szam;
       k++;
    }
    szam=keres(tomb,k);
    cout<<"\nA legkisebb elem: "<<szam<<"\n";
    system("PAUSE");
    return EXIT_SUCCESS;
}*/


// Játék: van egy négyelemû tömb, melyben adott pozicióban 1-6 lehet. Nincs ismétlõdés.
// "|" jel ha jó helyen van, "-" jel  ha eltaláltuk, de nincs jó helyen!
// Az 1. fv feltölti a tömböt 4 véletlen számmal ismétlõdés nélkül.

int A[4], B[4];

void letrehozas(){
    int j, jo, i, ujszam;
    srand(time(NULL));
    A[0]=rand()%6+1;
    for(i=1;i<4;i++){
       ujszam=rand()%6+1;
       for(j=0;j<i;j++){
          while(ujszam==A[j]){
             ujszam=rand()%6+1;
             j=0;
          }
          A[i]=ujszam;
       }  
    }
}

int sorbe(){
    int i, j;
    for(i=0;i<4;i++)
       cin>>B[i];
    int c=0;
    for(i=0;i<4;i++){
       if(B[i]<1 || B[i]>6){
          c++;
       }
    }
    for(i=0;i<3;i++){
       for(j=i+1;j<4;j++){
          if(B[i]==B[j]){
             c++;
          }
       }
    }
    return c;
}

int johely(){
    int c=0, i;
    for(i=0;i<4;i++){
       if(A[i]==B[i]){
          c++;
          B[i]=0;
       }
    }
    return c;
}

int bennevan(){
    int c=0, i, j;
    for(i=0;i<4;i++){
       for(j=0;j<4;j++){
          if(A[i]==B[j]){
             c++;
          }
       }
    }
    return c;
}

int main(int argc, char *argv[])
{
    int i, t, u;
    cout<<"Ez egy szinkitalasos jatek, csak szamokkal. Kezdodjek a jatek! :-)\n";
    letrehozas();
    /*for(i=0;i<4;i++)
       cout<<A[i]<<" ";
       cout<<"\n";*/
    t=sorbe();
    while(t>0){
       cout<<"Rosszul adtad meg a szamokat!\n";
       t=sorbe();
    }
    t=0;
    while(t!=4){
       t=johely();
       u=bennevan();
       if(t==4){
         cout<<"Eltalaltad!\nA helyes megoldas: ";
         for(i=0;i<4;i++)
            cout<<A[i]<<" ";
            cout<<"\n";
         system("PAUSE");
         return EXIT_SUCCESS;
       }
       for(i=0;i<t;i++){
          cout<<"|";
       }
       for(i=0;i<u;i++){
          cout<<"-";
       }
       cout<<endl;
       t=sorbe();
       while(t>0){
          cout<<"Rosszul adtad meg a szamokat!\n";
          t=sorbe();
       }
    }
    system("PAUSE");
    return EXIT_SUCCESS;
}


/*int main(int argc, char *argv[])
{
    // Állítsunk elõ síkbeli vektorokat és keressük meg a leghosszabbat.
    int x, y, i, A[100][2], h[2], n=0;
    cout<<"Adja meg a vektorokat:\n";
    cin>>x>>y;
    while(x>=0 && y>=0){
       A[n][0]=x;
       A[n][1]=y;
       cin>>x>>y;
       n++;
    }
    h[0]=A[0][0];
    h[1]=A[0][1];
    for(i=1;i<n;i++)
          if( sqrt(A[i][0]*A[i][0]+A[i][1]*A[i][1]) > sqrt(h[0]*h[0]+h[1]*h[1]) ){
              cout<<sqrt(A[i][0]*A[i][0]+A[i][1]*A[i][1])<< sqrt(h[0]*h[0]+h[1]*h[1])<<" ";
              h[0]=A[i][0];
              h[1]=A[i][1];
              }
    cout<<"A leghosszabb vektor koordinatai: ("<<h[0]<<","<<h[1]<<")\n";*/
    
    //Bemenet (x,y) párok és kimenet az i,j, amelynél (Xi,Yi),(Xj,Yj) a lehetõ legközelebb van a derékszöghöz.
    /*int A[100][2], x, y, i, j, n, e, f;
    cout<<"Adjon meg vektorokat:\n";
    cin>>x>>y;
    while(x>=0 && y>=0){
       A[n][0]=x;
       A[n][1]=y;
       cin>>x>>y;
       n++;
    }
    for(i=0;i<n;i++)
       for(j=i+1;j<n;j++){
          if((((A[i][0])*A[j][0]+(A[i][1])*A[j][1]) * ((A[i][0])*A[j][0]+(A[i][1])*A[j][1]))/ (A[i][0]*A[i][0]+A[i][1]*A[i][1]) * 
          (A[j][0]*A[j][0]+A[j][1]*A[j][1])>(((A[e][0])*A[f][0]+(A[e][1])*A[f][1]) * ((A[e][0])*A[f][0]+(A[e][1])*A[f][1]))/ 
          (A[e][0]*A[e][0]+A[e][1]*A[e][1]) * (A[f][0]*A[f][0]+A[f][f]*A[f][1])){
          e=i; f=j;
          }}
    cout<<"A legnagyobb szoget zar be: ("<<A[e][0]<<","<<A[e][1]<<") es ("<<A[f][0]<<","<<A[f][1]<<")\n";
    system("PAUSE");
    return EXIT_SUCCESS;
}*/
