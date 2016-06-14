#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    // Bemenetk�nt megadunk darabsz�mot, ut�na az adatokat �s a gyakoris�got (a v�ltoz� adatai milyen gyakran fordultak el�).
    // Ez alapj�n sz�molunk v�rhat� �rt�ket.
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
    
    //0-100 k�z� es� t�rtsz�mokat bek�r�nk, sz�moljuk meg, hogy az adott tartom�nyban h�ny 
    //darab esik (0-10,10-20,...) negat�v �rt�kig megy a program.
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
    
    //Ugyanaz, mint az el�bb csak el�tte mi adjuk meg a 9 db elv�laszt�pontot �s ut�na pakoljuk bele az elemeket a megfelel� helyre.
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
    
    //Bemen� sz�m pr�msz�m-e?
    /*int szam, i=2;
    cout<<"Adjon meg egy termeszetes szamot, hogy eld�nts�k primszam-e!";
    cin>>szam;
    while(szam%i!=0){
       i++;
    }
       if(szam==i){
          cout<<"A megadott szam primszam\n";
       } else {
          cout<<"A megadott szam nem primszam\n";
       }*/
       
    //n-ig (amit megadunk) az �sszes pr�msz�mot ki�rni  (i -  a pr�m sorsz�ma; j - tesztele, hogy pr�m-e; k - tesztel�pr�m sorsz�ma)
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
    
    //Eratoszten�szi szita: 2 .... n egy t�mb, a 2 pr�m, t�bbsz�r�seit leh�zom, a k�v. le nem h�zott sz�m pr�msz�m. Annak a t�bbsz�r�seit is leh�zzuk...
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

    //Adjunk meg k�t sz�msorozatot (hossz� �s r�vid). A X-nek van-e olyan szakasza, amely megegyezik Y-nal.
    //   1 3 2 4 1 5 2 3
    //   2 4 1   (X a 3.indext�l azonos)
    int X[10], Y[5], talalt=0, k=0, n=0, szam, i=0, j;
    cin>>szam;
    while(szam>0){
       X[n]=szam;
       n++;
       cin>>szam;
    }
    cin>>szam;
    while(szam>0){                                 // n db �rt�k van X-ben
       Y[k]=szam;                                  // k db �rt�k van Y-ban
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
