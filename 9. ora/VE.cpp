#include <cstdlib>
#include <iostream>

// HF. Gondolkodni a ládapakolás algoritmusán: rögzitett térfogatú teherautó, ládák, és hány fordulatból tudja elvinni a ládákat.

using namespace std;

// Visszalépéses algoritmus

int A[100][3];
int n, Max[100];
int V, E;

int berak(int k, int vt, int et){  // vt-ideiglenes terfogat , et-ideiglenes ertek, k-hanyadik pozicióban tartunk a tömbben.
    int i;
    for(i=0;i<n;i++){
       V=V+A[i][0];
       E=E+A[i][1];
    }
    int kt;
    for(kt=k;kt<n;kt++){
       if(vt+A[kt][0]<=V){
          A[kt][2]=1;
          berak(k+1,vt+A[kt][0],et=+A[kt][0]);
          A[kt][2]=0;
       }
    }
    if(et>E){
       E=et;
       int i;
       for(i=0;i<n;i++){
       Max[i]=A[i][2];
       }
    }
}

int main(int argc, char *argv[])
{
    cout<<"Adja meg a meretet:";
    cin>>n;
    int i, j, szamlalo=0;
    for(i=0;i<n;i++){
       for(j=0;j<3;j++){
          A[i][j]=0;
       }
    }
    int szam1=0, szam2=0;
    while(szam1>=0 && szam2>=0 && szamlalo<n){
    cout<<"Adja meg az elemeket";
    cin>>szam1;
    cin>>szam2;
    berak(szamlalo,szam1,szam2);
    szamlalo++;
    }
    for(i=0;i<n;i++){
       cout<<"\n";
       for(j=0;j<3;j++){
          cout<<A[i][j]<<" ";
       }
    }
    system("PAUSE");
    return EXIT_SUCCESS;
}
