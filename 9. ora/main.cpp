#include <cstdlib>
#include <iostream>
#define MAXSULY 15

using namespace std;

int ladak[50];

int minfordulat(int ladakszama){
    int i;
    
}

int main(int argc, char *argv[])
{
    int lada=0, i=0;
    cout<<"A teherauto maximum "<<MAXSULY<<" kg-ot tud elszallitani egyszerre.\n";
    cout<<"Adja meg a ladak sulyat: ";
    do{
    cin>>lada;
    ladak[i]=lada;
    i++;
    }while(i<50 && lada>0);
    minfordulat(i);
    system("PAUSE");
    return EXIT_SUCCESS;
}
