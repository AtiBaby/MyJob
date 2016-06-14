#include <cstdlib>
#include <iostream>

using namespace std;

// Torpedó megvalósítása: 2 db egyes, 3 db kettes, 2 db hármas, 1 db negyes.
//Cella értékei: 0-nincs;1-van hajó,de nem ismert;2-nem talált;3-talált;4-süllyedt;

int A[12][12];

int johely(int x,int y){
    int i, j, r, szamlalo=0;
    for(i=-1;i<=1;i++)
       for(j=-1;j<=1;j++)
          szamlalo+=A[x+i][y+j];
    if(szamlalo==0){
       r=1;
    } else {
       r=0;
    }
    return r;
}

void hajoElhelyezes(int hajomeret){
    int i, j, x, y, irany, szamlalo, sikerult=0;
    do{
    szamlalo=0;
    irany=rand()%2;   // 0-függõleges,1-vízszintes
    if(irany==1){
       x=rand()%10+1;
       y=rand()%(11-hajomeret)+1;
       for(i=0;i<hajomeret;i++){
          szamlalo+=johely(x,y+i);
       }
       if(szamlalo==hajomeret){
          for(i=0;i<hajomeret;i++){
          sikerult=1;
          A[x][y+i]=1;
          }
       }
    } else {
       y=rand()%10+1;
       x=rand()%(11-hajomeret)+1;
       for(i=0;i<hajomeret;i++){
          szamlalo+=johely(x+i,y);
       }
       if(szamlalo==hajomeret){
          for(i=0;i<hajomeret;i++){
          sikerult=1;
          A[x+i][y]=1;
          }
       }
    }
    }while(sikerult==0);
}

void kiiratas(){
     int i, j;
     char betu='A';
     char c1=218, c2=196, c3=191, c4=179, c5=192, c6=217, c7=178;
     // c7 a hajó helyét mutatja, c8 a nem talált helyét, a többi a keret részei
     cout<<"   1234567890\n  "<<c1<<c2<<c2<<c2<<c2<<c2<<c2<<c2<<c2<<c2<<c2<<c3<<"\n";
     for(i=1;i<11;i++){
        cout<<" "<<betu<<c4;
        for(j=1;j<11;j++){
           if(A[i][j]==0 || A[i][j]==1){
              cout<<" ";
           } else if(A[i][j]==2){
              cout<<"X";
           } else if(A[i][j]==3){
              cout<<"0";
           } else {
              cout<<c7;
           }
        }
        betu++;
        cout<<c4<<"\n";
    }
    cout<<"  "<<c5<<c2<<c2<<c2<<c2<<c2<<c2<<c2<<c2<<c2<<c2<<c6<<"\n";
}

void tipp(int *x, int *y){
     int jo=0, oszlop;
     char sor;
     cout<<"Tipp: ";
     while(jo==0){
        cin>>sor>>oszlop;
        if((sor>='a')&&(sor<='j')||(sor>='A')&&(sor<='J') && ((oszlop>=1)&&(oszlop<=11))){
           jo=1;
           *y=oszlop;
           if((sor>='a')&&(sor<='j')){
              *x=sor-'a'+1;
           } else {
              *x=sor-'A'+1;
           }
        } else {
           cout<<"Rosszul adtad meg a koordinatat!\n";
        }
     }
}

int vege(){
    int a=1, i, j;
    for(i=1;i<=10;i++){
       for(j=1;j<=10;j++){
          if(A[i][j]==1){   // Ha van-e még hajó amit nem találtunk el.
             a=0;
          }
       }
    }
    return a;
}

void tablamodositas(int x, int y){   // Ha minden hajót kilõttünk akkor 1-es ad vissza
    if(A[x][y]==0){
       cout<<"Nem talalt.\n";
       A[x][y]=2;  // nem talált
    } else if(A[x][y]==1){
    cout<<"Talalt.\n";
       A[x][y]=3;  // talált
    // Megvizsgálom, hogy süllyed-e a hajó
    // Cella értékei: 0-nincs; 1-van hajó,de nem ismert; 2-nem talált; 3-talált; 4-süllyedt;
    int x1=x, x2=x, y1=y, y2=y;
    while(A[x1][y]==1 || A[x1][y]==3){
       x1--;
    }
    x1++;
    while(A[x2][y]==1 || A[x2][y]==3){
       x2++;
    }
    x2--;
    while(A[x][y1]==1 || A[x][y1]==3){
       y1--;
    }
    y1++;
    while(A[x][y2]==1 || A[x][y2]==3){
       y2++;
    }
    y2--;
    int i, j, c=1;
    for(i=x1;i<=x2;i++)
       if(A[i][y]!=3){
          c=0;
       }
    for(i=y1;i<=y2;i++)
       if(A[x][i]!=3){
          c=0;
       }
    if(c==1){
       cout<<"Elsulyedt.\n";
       for(i=x1-1;i<=x2+1;i++){
          for(j=y1-1;j<=y2+1;j++){
             if(A[i][j]==0 || A[i][j]==2){
                A[i][j]=2;
             } else {
                A[i][j]=4;
             }
          }
       }
    }
    }
}

int main(int argc, char *argv[])
{
    int i, j, hajok[4]={2,3,2,1};
    int x, y;
    srand(time(NULL));
    cout<<"Torpedos jatek. A tippet az alabbi modon kerem megadni:  A8,C4...\n(ahol A-oszlop , 8-sor)\n";
    for(i=0;i<12;i++){          // Mátrix kinullázása
       for(j=0;j<12;j++){
          A[i][j]=0;
       }
    }
    for(i=0;i<4;i++){
       for(j=1;j<=hajok[i];j++){
          hajoElhelyezes(i+1);
       }
    }
    while(vege()==0){
       kiiratas();
       tipp(&x,&y);
       tablamodositas(x,y);
    }
    system("PAUSE");
    return EXIT_SUCCESS;
}
