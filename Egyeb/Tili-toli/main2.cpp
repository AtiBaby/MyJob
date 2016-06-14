#include <cstdlib>
#include <iostream>
#define N 4

using namespace std;

int A[N][N]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,0};

int ellenoriz(int szam){
     int i, j;
     for(i=0;i<N;i++){
        for(j=0;j<N;j++){
           if(A[i][j]==szam)
              return 0;
     }  }
     return 1;
}

void letol(){
     int i, j, seged;
     for(i=0;i<N;i++){
        for(j=0;j<N;j++){
           if(A[i][j]==0){
              goto folytat2;
           }
        }
     }
     folytat2:
     if(i!=(N-1)){
        seged=A[i+1][j];
        A[i+1][j]=0;
        A[i][j]=seged;
     }
}

void feltol(){
     int i, j, seged;
     for(i=0;i<N;i++){
        for(j=0;j<N;j++){
           if(A[i][j]==0){
              goto folytat1;
           }
        }
     }
     folytat1:
     if(i!=0){
        seged=A[i-1][j];
        A[i-1][j]=0;
        A[i][j]=seged;
     }
}

void balratol(){
     int i, j, seged;
     for(i=0;i<N;i++){
        for(j=0;j<N;j++){
           if(A[i][j]==0){
              goto folytat3; 
           }
        }
     }
     folytat3:
     if(j!=(N-1)){
        seged=A[i][j+1];
        A[i][j+1]=0;
        A[i][j]=seged;
     }
}

void jobbratol(){
     int i, j, seged;
     for(i=0;i<N;i++){
        for(j=0;j<N;j++){
           if(A[i][j]==0){
              goto folytat4;
           }
        }
     }
     folytat4:
     if(j!=0){
        seged=A[i][j-1];
        A[i][j-1]=0;
        A[i][j]=seged;
     }
}


void letrehoz(){
    int i, muvelet;
    srand(time(NULL));
    for(i=0;i<1000;i++){
       muvelet=rand()%4+1;
       switch(muvelet){
          case 1:
             feltol();
             break;
          case 2:
             letol();
             break;
          case 3:
              balratol();
              break;
          case 4:
              jobbratol();
              break;
       }
    }
}


void kiir(){
     int i, j;
     char c1=201, c2=205, c3=203, c4=187, c5=186, c6=204, c7=206, c8=185, c9=200, c10=202, c11=188;
     cout<<c1<<c2<<c2<<c3<<c2<<c2<<c3<<c2<<c2<<c3<<c2<<c2<<c4;
     for(i=0;i<(2*N-1);i++){
        if(i%2==0){
           cout<<"\n"<<c5;
           for(j=0;j<N;j++)
              if(A[i/2][j]==0){
              cout<<"  "<<c5;
              } else if(A[i/2][j]/10!=0){
              cout<<A[i/2][j]<<c5;
              } else {
              cout<<" "<<A[i/2][j]<<c5;       
              }
           cout<<"\n";
        } else {
           cout<<c6<<c2<<c2<<c7<<c2<<c2<<c7<<c2<<c2<<c7<<c2<<c2<<c8;
        }
     }
     cout<<c9<<c2<<c2<<c10<<c2<<c2<<c10<<c2<<c2<<c10<<c2<<c2<<c11;
}


int kesz(){
    int i, j, szamlalo=1;
    for(i=0;i<N;i++){
       for(j=0;j<N;j++){
          if(i!=N-1 || j!=N-1){
             if(A[i][j]!=szamlalo){
                return 0;
             }
          szamlalo++;  
    }  }  }
    return 1;
}


int main(int argc, char *argv[])
{
    cout<<"Ez a tili-toli jatek. Iranyitas a kovetkezo gombokkal:\nw-fel, a-balra, s-le, d-jobbra\n";
    char irany=0;
    letrehoz();
    kiir();
    cout<<" Lepes: ";
    while(kesz()==0){
       int seged;
       do{
       irany=getchar();    // w=119, a=97, s=115, d=100
       fflush(stdin);
       seged=irany;
       }while(seged!=119 && seged!=97 && seged!=115 && seged!=100);
       switch(seged){
          case 115:
             feltol();
             break;
          case 119:
             letol();
             break;
          case 97:
             balratol();
             break;
          case 100:
             jobbratol();
             break;
       }
       kiir();
       cout<<" Lepes: ";
    }
    cout<<"\n";
    kiir();
    cout<<" Megoldottad a jatekot!\n";
    system("PAUSE");
    return EXIT_SUCCESS;
}
