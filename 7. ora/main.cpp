#include <cstdlib>
#include <iostream>

using namespace std;

// Be: n,m. Ki: n*m-es mátrix 1-n*m-ig csigavonalban

int main(int argc, char *argv[])
{
    int n, m, i=0, j=0, oszlopvege, sorvege, soreleje, oszlopeleje, szamlalo=1;
    cin>>n;
    cin>>m;
    int matrix[n][m];
    sorvege=n-1; oszlopvege=m-1; soreleje=0; oszlopeleje=-1;
    for(;szamlalo<=(n*m);){
       for(oszlopeleje++,j=oszlopeleje;j<=oszlopvege ; j++){
          if(szamlalo<=(n*m)){
          matrix[i][j]=szamlalo;
          szamlalo++;
          } else {
             goto vege;
          }
       }
       j=j-1;
       for(i=soreleje+1,soreleje++;i<=sorvege;i++){
          if(szamlalo<=(n*m)){
          matrix[i][j]=szamlalo;
          szamlalo++;
          } else {
             goto vege;
          }
       }
       i=i-1;
       for(j=oszlopvege-1,oszlopvege--;j>=oszlopeleje;j--){
          if(szamlalo<=(n*m)){
          matrix[i][j]=szamlalo;
          szamlalo++;
          } else {
             goto vege;
          }
       }
       j=j+1;
       for(i=sorvege-1, sorvege--;i>=soreleje;i--){
          if(szamlalo<=(n*m)){
          matrix[i][j]=szamlalo;
          szamlalo++;
          } else {
             goto vege;
          }
       }
       i=i+1;
    }
    vege:
    for(i=0;i<n;i++){
       cout<<"\n";
       for(j=0;j<m;j++){
          if(matrix[i][j]<10){
          cout<<" "<<matrix[i][j]<<" ";
          } else {
          cout<<matrix[i][j]<<" ";
          }
       }
    }
    cout<<"\n";
    system("PAUSE");
    return EXIT_SUCCESS;
}
