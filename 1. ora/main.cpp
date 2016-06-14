#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    /*int adat=5;
    cout<<5<<" "<<adat<<endl;
    adat=3*adat;
    cout<<adat<<endl;
    cout<<"Kerek egy szamot: ";
    cin>>adat;
    if(adat>0)
       cout<<adat<<": Pozitiv szam"<<endl;
    else
       if(adat<0)
         cout<<adat<<": Negativ szam"<<endl;
       else
         cout<<adat<<": A szam nulla"<<endl;
    cout<<"Megadott szam negyzete: "<<adat*adat<<endl;*/
    
    // Téglalap és kör területeit kiszámoló program
    int a, b, r; 
    float T1, T2;
    cout<<"Adja meg a teglalap oldalait:";
    scanf("%i %i", &a, &b);
    cout<<"Adja meg a kor sugarat:";
    scanf("%i", &r);
    T1=a*b;
    T2=3.14*r*r;
    if(T1>T2){
      cout<<"Kor: "<<T2<<"  Teglalap: "<<T1<<"  A teglalap terulete a nagyobb."<< endl;
    } else {
      cout<<"Kor: "<<T2<<"  Teglalap: "<<T1<<"  A kor terulete a nagyobb."<< endl;
    }
    
    //  Egész számot visszaadó Négyzetgyökvonó program
    int i,szam;
    cout<<"Kerek egy szamot (negyzetgyokvonas):";
    cin>>szam;
    for(i=0;(i*i<=szam);i=i+1);
      cout<<szam<<" Negyzetgyoke: "<<i-1;
      cout<<"\n";
      
    // Faktorilást megvalósító program:
    int meddig, szor=0;
    cout<<"Faktorialist megvalosito program. Kerek egy szamot:";
    cin>>meddig;
    for(i=1,szor=1;i<=meddig;szor=szor*i,i=i+1);
    cout<<"A szamok szorzata 1-"<<meddig<<"-ig: "<<szor<<"\n";
    system("PAUSE");
    return EXIT_SUCCESS;
}
