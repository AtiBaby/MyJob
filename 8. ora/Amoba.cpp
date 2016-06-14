#include <cstdlib>
#include <iostream>
#define N 20

using namespace std;

// Amõba ellenõrzés: 0-Nem ismert (.), 1-Elsõ játékos jele (X), 2-Második játékos jele (O).
//     Szabályos-e?
//     Nyerõ állás-e?

int A[N][N];

void kiiras(){
     int i, j;
     for(i=0;i<N;i++){
        cout<<"\n\t";
        for(j=0;j<N;j++){
           if(A[i][j]==0){
              cout<<".";
           } else if(A[i][j]==1){
              cout<<"X";
           } else {
              cout<<"O";
           }
        }
     }
     cout<<"\n";
}

int ellenoriz(){
    int i, j, r=0, c1=0, c2=0;
    for(i=0;i<N;i++){
       for(j=0;j<N;j++){
          if(A[i][j]==1){
             c1++;
          } else if(A[i][j]==2){
             c2++;
          }
          if(abs(c1-c2)>1){
             cout<<"Hibas!";
             r=1;
          }
       }
    }
    return r;
}

int max(int a,int b, int c,int d,int e){
    int t=0;
    if(a<b){
       t=b;
    } else {
       t=a;
    }
    if(t<c){
       t=c;
    }
    if(t<d){
       t=d;
    }
    if(t<e){
       t=e;
    }
    return t;
}

int vizszintes(int x, int y, int g){
    int c=0;
    while( (y+c<N) && (A[x][y+c]==g) ){       // Ellenõrizni kell a pálya szélét (y+c)<N-nel.
       c++;
    }
    return c;
}

int fuggoleges(int x, int y, int g){
    int c=0;
    while( (x+c<N) && (A[x+c][y]==g) ){
       c++;
    }
    return c;
}

int atlos1(int x, int y, int g){
    int c=0;
    while( ((x+c<N) && (y+c<N)) && (A[x+c][y+c]==g) ){
       c++;
    }
    return c;
}

int atlos2(int x, int y, int g){
    int c=0, d=0;
    while( ((x-d<N) && (y+c<N)) && (A[x-d][y+c]==g) ){
       c++;
       d--;
    }
    return c;
}

int main(int argc, char *argv[])
{
    int i, j, v=0, f=0, at1=0, at2=0, szamlalo=0;
    int tipp1, tipp2;
    int m1=0, m2=0;         // Adott játékos leghosszabb elemei egymás mellett
    for(i=0;i<N;i++){       // A mátrix kinullázása
       for(j=0;j<N;j++){
          A[i][j]=0;
       }                 
    }
    do{
    szamlalo++;
    if(szamlalo%2==1){
       cout<<"1. jatekos kovetkezik:\n";
    } else {
       cout<<"2. jatekos kovetkezik:\n";
    }
    cin>>tipp1>>tipp2;
    while(A[tipp1][tipp2]!=0 || ( (tipp1<=0 || tipp1>N) || (tipp2<=0 || tipp2>N) ) ){
       cout<<"Rossz helyre tettel! Oda mar tett valaki vagy rosszul adtad me az indexet.\n";
       cin>>tipp1>>tipp2; 
    }
    if(szamlalo%2==1){
       A[tipp1][tipp2]=1;
    } else {
       A[tipp1][tipp2]=2;
    }
    for(i=0;i<N;i++){
       for(j=0;j<N;j++){
          if(A[i][j]!=0){
          v=vizszintes(i,j,A[i][j]);
          f=fuggoleges(i,j,A[i][j]);
          at1=atlos1(i,j,A[i][j]);
          at2=atlos2(i,j,A[i][j]);
          }
          if(A[i][j]==1){
             m1=max(v,f,at1,at2,m1);
             cout<<"m1="<<m1;
          }
          if(A[i][j]==2){
             m2=max(v,f,at1,at2,m2);
             cout<<"m2="<<m2;
          }
       }
    }
    kiiras();
    }while( m1!=5 && m2!=5 );
    if(szamlalo%2==1){
       cout<<"\n1. jatekos nyert!\n";
    } else {
       cout<<"\n2. jatekos nyert!\n";
    }
    system("PAUSE");
    return EXIT_SUCCESS;
}
