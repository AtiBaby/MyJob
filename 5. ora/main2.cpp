#include <cstdlib>
#include <iostream>
#define N 100

using namespace std;

//Rácshálós feladat: 0,1 elemu rácsháló (n*n mátrix) és meg kell vizsgálni, hogy az egyesek 
//összefüggo alakzatott alkotnak. Sarkoknál érintkezo pontok is összefüggok.

int A[N][N];
int SZ[8][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};

int szomszedvizsgalat( int x, int y, int n, int A[N][N]){// Van-e 2-es szomszéd
    int i, van=0;
    for(i=0;(i<8) && (van<1);i++){
       if((x+SZ[i][0]>=0) && (x+SZ[i][0]<n) && (y+SZ[i][1]>=0) && (y+SZ[i][1]<n) && (A[x+SZ[i][0]][y+SZ[i][1]]==2)){
          van=1;
       }
    }
    return van;
}

void kereses1(int *x, int *y, int n){
     int i=*x, j=*y+1, kell=0;
     if(i>=n){
        i=0;
     }
     while(i<n){
        while(j<n){
           if(A[i][j]==1){
              kell=1;
              goto szunet;         //Ha talált egy helyt ahol 1-es van akkor kilép a while-ból
           } else {
              j++;
           }
        }
        j=0;
        i++;
     }
     szunet:
     if(kell==1){
     *x=i;
     *y=j;
     } else {    //Az else aghoz csak úgy juthat el, ha az egész while ciklusnak vége van
     *x=0;       //mivel a while csak i>=n áll meg, ezért a mátrix bejárást elõrõl kell kezdeni. 
     *y=-1;
     }
}

int main(int argc, char *argv[])
{
    int i, j, x=0, y=0, n, hanyszor=0, db=0;    // db = ennyi 1-esem van a mátrixban
    srand(time(NULL));
    cout<<"Adja meg a matrix nagysagat:\n";
    cin>>n;
    for(i=0;i<n;i++){
       for(j=0;j<n;j++){
          A[i][j]=rand()%2;
       }
    }
    
    for(i=0;i<n;i++){     // Kiíratás és megszámolom hány db 1-es van benne
       cout<<"\n";
       for(j=0;j<n;j++){
          cout<<A[i][j];
          if(A[i][j]==1){
             db++;
          }
       }
    }
    cout<<"\n";
    
    for(i=0;i<n;i++)             /* Megkeresem az elsõ 1-est*/
       for(j=0;j<n;j++)
          if(A[i][j]==1){
             A[i][j]=2;          /*Amint megtaláltam átírom kettessé*/
             goto kilep;
          }
    kilep:
    
    while(hanyszor<2*db){
          kereses1(&x,&y,n);
          if((szomszedvizsgalat(x,y,n,A))==1){
             A[x][y]=2;
          }
          hanyszor++;
    }
    
    for(i=0;i<n;i++){
       cout<<"\n";
       for(j=0;j<n;j++){
          cout<<A[i][j];
       }
    }
    cout<<"\n";
    
    for(i=0;i<n;i++)
       for(j=0;j<n;j++){
          if(A[i][j]==1){
            cout<<"Nem osszefuggo alakzat\n";
            system("PAUSE");
            return EXIT_SUCCESS;
          }
       }
    cout<<"Osszefuggo alakzat\n";
    system("PAUSE");
    return EXIT_SUCCESS;
}
