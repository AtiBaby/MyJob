#include <cstdlib>
#include <iostream>

using namespace std;

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
