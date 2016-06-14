#include <cstdlib>
#include <iostream>

using namespace std;

// 33. feladat: Legyen adott egy malom játéktábla egy 3*3*3 elemû tömbben. Elemei: 0, ha nem áll ott bábú; 1, ha fehér; 2, ha fekete.
// Döntse el, hogy van-e az állásban "malom"!

int tabla[3][3][3]={{{1,2,0},{2,0,2},{1,2,2}},{{1,0,0},{2,0,2},{0,0,0}},{{1,2,0},{2,0,0},{1,0,0}}};

int vanmalom(){
    int malom=0;
    int i, sor, oszlop;
    for(i=0;i<3;i++){
       for(sor=0;sor<3;sor=sor+2){
          malom=malom+(tabla[i][sor][0]==tabla[i][sor][1] && tabla[i][sor][1]==tabla[i][sor][2] && tabla[i][sor][0]>0);
       }
       for(oszlop=0;oszlop<3;oszlop=oszlop+2){
          malom=malom+(tabla[i][0][oszlop]==tabla[i][1][oszlop] && tabla[i][1][oszlop]==tabla[i][2][oszlop] && tabla[i][0][oszlop]>0);
       }
    }
    for(oszlop=0,sor=1;oszlop<3;oszlop=oszlop+2){
       malom=malom+(tabla[0][sor][oszlop]==tabla[1][sor][oszlop] && tabla[1][sor][oszlop]==tabla[2][sor][oszlop] && tabla[0][sor][oszlop]>0);
    }
    for(oszlop=1,sor=0;sor<3;sor=sor+2){
       malom=malom+(tabla[0][sor][oszlop]==tabla[1][sor][oszlop] && tabla[1][sor][oszlop]==tabla[2][sor][oszlop] && tabla[0][sor][oszlop]>0);
    }
    return malom;
}

void kiirallas(){
     int i, j, k;
     cout<<"Malom:\n";
     cout<<tabla[0][0][0]<<"   "<<tabla[0][0][1]<<"   "<<tabla[0][0][2]<<"\n";
     cout<<" "<<tabla[1][0][0]<<"  "<<tabla[1][0][1]<<"  "<<tabla[1][0][2]<<"\n";
     cout<<"  "<<tabla[2][0][0]<<" "<<tabla[2][0][1]<<" "<<tabla[2][0][2]<<"\n";
     cout<<tabla[0][1][0]<<tabla[1][1][0]<<tabla[2][1][0]<<"   "<<tabla[2][1][2]<<tabla[1][1][2]<<tabla[0][1][2]<<"\n";
     cout<<"  "<<tabla[2][2][0]<<" "<<tabla[2][2][1]<<" "<<tabla[2][2][2]<<"\n";
     cout<<" "<<tabla[1][2][0]<<"  "<<tabla[1][2][1]<<"  "<<tabla[1][2][2]<<"\n";
     cout<<tabla[0][2][0]<<"   "<<tabla[0][2][1]<<"   "<<tabla[0][2][2]<<"\n";
}

int main(int argc, char *argv[])
{
    int malom=0;
    malom=vanmalom();
    if(malom==0){
       cout<<"Nincs malom\n";
    } else {
       cout<<"Van malom\n";
    }
    kiirallas();
    system("PAUSE");
    return EXIT_SUCCESS;
}
