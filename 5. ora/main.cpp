#include <cstdlib>
#include <iostream>
#define N 100
#include <stdlib.h>

using namespace std;
// Mátrix szorzás megvalósítása. 

/*int SOK(int n, int A[N][N], int B[N][N], int i, int j){    // Sor-oszlop kombináció
    int k, osszeg=0;
    for(k=0;k<n;k++)
       osszeg=osszeg+A[i][k]*B[k][j];
    return osszeg;
}

int main(int argc, char *argv[])
{ 
    int n, szam, i, j;
    cout<<"Adja meg a matrix nagysagat: (n*n)\n";
    cin>>n;
    int A[n][n], B[n][n], C[n][n];
    
    cout<<"Adja meg az A matrix elemeit:\n";
    for(i=0;i<n;i++)
       for(j=0;j<n;j++){
          cin>>szam;
          A[i][j]=szam;
    }
    
    cout<<"Adja meg az B matrix elemeit:\n";
    for(i=0;i<n;i++)
       for(j=0;j<n;j++){
    cin>>szam;
    B[i][j]=szam;
    }
    
    int k, osszeg;
    for(i=0;i<n;i++){
       for(j=0;j<n;j++){
          osszeg=0;
          for(k=0;k<n;k++){
             osszeg=osszeg+A[i][k]*B[k][j];
             }
          C[i][j]=osszeg;
       }
    }
       
    cout<<"\nAz A matrix elemei:\n";
    for(i=0;i<n;i++){
       cout<<"\n";
       for(j=0;j<n;j++){
          cout<<A[i][j]<<" ";}
    }
    cout<<"\nAz B matrix elemei:\n";
    for(i=0;i<n;i++){
       cout<<"\n";
       for(j=0;j<n;j++){
          cout<<B[i][j]<<" ";}
    }
    cout<<"\nAz C matrix eredmenye:\n";
    for(i=0;i<n;i++){
       cout<<"\n";
       for(j=0;j<n;j++){
          cout<<C[i][j]<<" ";}
    }
    cout<<"\n";
    
    system("PAUSE");
    return EXIT_SUCCESS;
}*/


//Gauss-elimináció
float A[N][N];

float kiszamol(int i, int j, float A[N][N]){
    float z;
    z=A[j][i]/A[i][i];
    return z;
}

float kivon(int i, int j, int n, float A[N][N], float z){
    int k;
    for(k=i;k<n;k++)
       A[j][k]=A[j][k]-(z*A[i][k]);
}

int main(int argc, char *argv[])
{
    int i, j, n;
    float szam, z;
    cout<<"Adja meg a matrix nagysagat:\n";
    cin>>n;
    cout<<"Adja meg az A matrix elemeit:\n";
    for(i=0;i<n;i++)
       for(j=0;j<n;j++){
          cin>>szam;
          A[i][j]=szam;
    }
    /*srand(time(NULL));
    for(i=0;i<n;i++){
       cout<<"\n";
       for(j=0;j<n;j++){
          A[i][j]=rand()%20-10;
          cout<<A[i][j]<<" ";
       }
    }*/
    for(i=0;i<n-1;i++){
       for(j=i+1;j<n;j++){
          z=kiszamol(i,j,A);
          kivon(i,j,n,A,z);
       }
}
    cout<<"\nAz A matrix elemei Gauss-eliminacio utan:\n";
    for(i=0;i<n;i++){
       cout<<"\n";
       for(j=0;j<n;j++){
          cout<<A[i][j]<<" ";
       }
    } cout<<"\n";
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
