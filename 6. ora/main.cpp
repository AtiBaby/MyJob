#include <cstdlib>
#include <iostream>

using namespace std;

// Labirintus: mindig jobbra fordulunk, de ha csak körbe-körbe megyünk akkor egy pillanatra átváltunk a másik falra és azon megyünk tovább
// Labirintus ábrázolása: n*n mátrix és 1-fal darabját jelöli (konstanskét adjuk meg)       jobbra, le,  balra,   fel
// Lépés: jobbra mellettünk egy nemüres cella található. Hely és irány van (x,y). Az I(x,y)={(1,0);(0,1);(-1,0);(0,-1)}

int A[10][10]={
    0,0,0,0,0,0,0,0,0,0,
    0,1,1,1,0,1,1,1,1,0,
    0,1,0,0,0,0,1,0,1,0,
    0,1,0,1,1,1,1,0,1,0,
    0,1,0,0,1,0,0,0,1,0,
    0,1,1,0,1,0,1,0,1,0,
    0,1,1,0,0,0,1,1,1,0,
    0,1,0,0,1,0,0,0,1,0,
    0,1,1,1,1,1,1,1,1,0,
    0,0,0,0,0,0,0,0,0,0,
};

int hely[2], B[2], J[2], I[2];
int voltefordulas=0;


int palyaszele(int x, int y){
    if((x==0 || y==0) || (x==9 || y==9)){
       return 2;
    } else {
       return 1;
    }
}

void Bfordulhate(int I[2]){
     B[0]=I[1];
     B[1]=-I[0];
     if( A[(hely[0]+B[0])][(hely[1]+B[1])]==0 ){
        I[0]=B[0];
        I[1]=B[1];
        voltefordulas=1;
     }
}
     
void Jfordulhate(int I[2]){
     J[0]=-I[1];
     J[1]=I[0];
     if( A[(hely[0]+J[0])][(hely[1]+J[1])]==0 ){
        I[0]=J[0];
        I[1]=J[1];
        voltefordulas=1;
     }

}

void Megfordul(int I[2]){
     int uj[2];
     uj[0]=-I[0]; uj[1]=-I[1];
     I[0]=uj[0]; I[1]=uj[1];
}

void lepes(int hely[2]){
     int voltlepes=0;
     int szamlalo=0;
     while(voltlepes==0 && szamlalo<3){
        voltefordulas=0;
        szamlalo++;
        /*cout<<"Hely: ("<<hely[0]<<","<<hely[1]<<")\n";
        cout<<"I: ("<<I[0]<<","<<I[1]<<")\n";*/
        Jfordulhate(I);
        if( A[(hely[0]+I[0])][(hely[1]+I[1])]==0 ){
           hely[0]=hely[0]+I[0];
           hely[1]=hely[1]+I[1];
           voltlepes=1;
           break;
        }
        if(voltefordulas==1){
           goto vege;
        }
        Bfordulhate(I);
        if(voltefordulas==1){
           goto vege;
        }
        Megfordul(I);
        vege: ;
     }
}

int main(int argc, char *argv[])
{
    int i, j, szam;
    char c;
    cout<<"10*10 labirintusbol valo kijutas: \n";
    hely[0]=2;
    hely[1]=7;
    I[0]=1;
    I[1]=0;
    while(palyaszele(hely[0],hely[1])==1){
        lepes(hely);
        for(i=0;i<10;i++){
           cout<<"\n";
           for(j=0;j<10;j++){
              if(i==hely[0] && j==hely[1]){
                 c=1;
                 cout<<c;
              } else if(A[i][j]==1){
                 c=219;
                 cout<<c;
              } else if(A[i][j]==0){
                 cout<<" ";
              }
           }
        }
    }
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
