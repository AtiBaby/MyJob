#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    // Bemenetként megadunk darabszámot, utána az adatokat és a gyakoriságot (a változó adatai milyen gyakran fordultak elõ).
    // Ez alapján számolunk várható értéket.
    /*int B[100], n, i; 
    float A[100], S=0, X=0;
    cout<<"Adja meg a darabszamot (Hany szamot akar majd megadni).\n";
    cin>>n;
    cout<<"Adja meg a adatokat es a gyakorisagot.\n";
    for(i=0;i<n;i++){
       cin>>A[i];
       cin>>B[i];
    }
    for(i=0;i<n;i++){
       S=S+A[i]*B[i];
       X=X+1;
    }
    cout<<"A varhato ertek: "<<(S/X)<<"\n";*/
    
    //0-100 közé esõ törtszámokat bekérünk, számoljuk meg, hogy az adott tartományban hány 
    //darab esik (0-10,10-20,...) negatív értékig megy a program.
    /*float szam;
    int tomb[10], i;
    for(i=0;i<10;i++){
       tomb[i]=0;
    }
    i=0;
    cout<<"Adjon meg szamokat (negativ szamot adjal meg, ha vege legyen!):";
    cin>>szam;
    while(szam>=0){
       i=szam/10.0;
       tomb[i]++;
       cin>>szam;            
    }
    for(i=0;i<10;i++){
       cout<<"A "<<(10*i)<<"-"<<(10*(i+1))<<"kozott "<<tomb[i]<<" szam van.\n";
    }*/
    
    //Ugyanaz, mint az elõbb csak elõtte mi adjuk meg a 9 db elválasztópontot és utána pakoljuk bele az elemeket a megfelelõ helyre.
    /*float szam;
    int tomb[10], hatarok[11], i;
    for(i=0;i<10;i++){
       tomb[i]=0;
       hatarok[i]=0;
    }
    cout<<"Adja meg a doboz hatarait! (0-100)";
    for(i=1;i<10;i++){
       cin>>szam;
       hatarok[i]=szam;
    }
    hatarok[10]=100;
    cout<<"Adjon meg szamokat (negativ szamot adjal meg, ha vege legyen!):";
    cin>>szam;
    while(szam>=0){
       for(i=0;i<10 && hatarok[i]<=szam;i++);
       tomb[i-1]++;
       cin>>szam;
    }
    for(i=0;i<10;i++){
       cout<<"A "<<(hatarok[i])<<"-"<<(hatarok[i+1])<<" kozott "<<tomb[i]<<" szam van.\n";
    }*/
    
    //Bemenõ szám prímszám-e?
    /*int szam, i=2;
    cout<<"Adjon meg egy termeszetes szamot, hogy eldöntsük primszam-e!";
    cin>>szam;
    while(szam%i!=0){
       i++;
    }
       if(szam==i){
          cout<<"A megadott szam primszam\n";
       } else {
          cout<<"A megadott szam nem primszam\n";
       }*/
       
    //n-ig (amit megadunk) az összes prímszámot kiírni  (i -  a prím sorszáma; j - tesztele, hogy prím-e; k - tesztelõprím sorszáma)
    /*int j=3, k, n, i=0, P[1000];
       cout<<"Primszamok kiiratasa a megadott szamig.\n";
    cin>>n;
    if(n<2){
       cout<<"Nincs primszam\n";
    } else {
       P[i]=2;
       i++;
    for(;j<=n;j++){
       P[i]=j;
       k=0;
       while(j%P[k]!=0){
          k++;
          if(j==P[k]){
             i++;
          }
       }
    }
    cout<<"Primszamok: ";
       for(k=0;k<i;k++){
          cout<< P[k] <<" ";
       } cout<<"\n";
    }*/
    
    //Eratosztenészi szita: 2 .... n egy tömb, a 2 prím, többszöröseit lehúzom, a köv. le nem húzott szám prímszám. Annak a többszöröseit is lehúzzuk...
    /*int n, i, j;
    cout<<"Eratoszteneszi szita feladata:\nAdja meg az n-t:";
    cin>>n;
    if(n<2){
       cout<<"Nincs primszam\n";
    } else { cout<<"Primszamok: ";
    int P[n];
    for(i=2;i<=n;i++){
       P[i]=1;  
    }
    for(i=2;i<=n;i++){
       if(P[i])
       j=2*i;
       while(j<=n){
          P[j]=0;
          j=j+i;
       }
    }
    for(i=2;i<=n;i++){
       if(P[i]){
         cout<<i<<" ";
       }
    }
}*/

    //Adjunk meg két számsorozatot (hosszú és rövid). A X-nek van-e olyan szakasza, amely megegyezik Y-nal.
    //   1 3 2 4 1 5 2 3
    //   2 4 1   (X a 3.indextõl azonos)
    int X[10], Y[5], talalt=0, k=0, n=0, szam, i=0, j;
    cin>>szam;
    while(szam>0){
       X[n]=szam;
       n++;
       cin>>szam;
    }
    cin>>szam;
    while(szam>0){                                 // n db érték van X-ben
       Y[k]=szam;                                  // k db érték van Y-ban
       k++;
       cin>>szam;
    }
    while((i<n-k) && (talalt!=1)){
       j=0;
       while((j<k) && (Y[j]==X[i+j])){
          j++;
       }
       if(j==k){
          talalt=1;
       }
       i++;
    }
    if(talalt==1){
       cout<<"Talalt\n";
    } else {
       cout<<"Nem talalt\n";
    }
    system("PAUSE");
    return EXIT_SUCCESS;
}
