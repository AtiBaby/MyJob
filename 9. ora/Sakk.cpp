#include <cstdlib>
#include <iostream>
#define M 10
#define N 10

// Bejárható-e lólépésben a sakktábla minden mezeje 1-szer a bemenetként megadott indulási helyrõl.
// Gráfos megoldás lesz visszalépéses eljárással.

using namespace std;

int Irany[8][2]={ {2,1} , {1,2} , {-1,2} , {-2,1} , {-2,-1} , {-1,-2} , {1,-2} , {2,-1}};

int A[N][M];
int n, m;


int lougras(int x,int y,int hanylepes){
    int r, i;
    if(hanylepes==0){
       r=1;
    } else {
       r=0;
       if(!( x<0 || y<0 || x>=n || y>=m || A[x][y]!=0)){
          A[x][y]=hanylepes;
          cout<<"\n";
          int a,b;
          for(a=0;a<n;a++){
             cout<<"\n";
             for(b=0;b<m;b++){
                if(A[a][b]<10){
                   cout<<" "<<A[a][b];
                } else {
                   cout<<A[a][b];
                }
             }
          }
          i=0;
          while(r==0 && i<8){
             r=lougras(x+Irany[i][0],y+Irany[i][1],hanylepes-1);
             i++;
          }
          if(r==0){
             A[x][y]=0;
          }
       }
    }
    return r;
}

int main(int argc, char *argv[])
{
    int x=0, y=0;
    cout<<"Adja meg a tabla meretet:";
    cin>>n>>m;
    int i, j;
    for(i=0;i<n;i++){
       for(j=0;j<m;j++){
          A[i][j]=0;
       }
    }
    if(lougras(x,y,m*n)==1){
       cout<<"\nVan megoldas";
    } else {
       cout<<"\nNincs megoldas";
    }
    system("PAUSE");
    return EXIT_SUCCESS;
}
