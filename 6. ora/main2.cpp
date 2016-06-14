#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    /*int H[100][2], I[100][2];
    int e=0;       // Hány lépést tettünk meg idáig
    H[e][0]=0;
    H[e][1]=0;
    I[e][0]=0;
    I[e][1]=0;
    cel[0]=9;
    cel[1]=9;
    while(((H[e][0]!=cel[0]) || (H[e][1]!=cel[1])) && e>=0){
       H[e-1][0]=H[e][0]+I[e][0];
       H[e-1][1]=H[e][1]+I[e][1];
       if(L[H[e+1][0]][[H[e+1][1]]==0){
          I[e+1][0]=-I[e][1];
          I[e+1][1]=-I[e][0];
       } else {
          T=I[e][0];
          I[e][0]=I[e][1];
          I[e][1]=-T;
          if((H[e][0]+I[e][0]==H[e-1][0]) && (H[e][1]+I[e][1]==H[e-1][1])){
             e--;
             T=I[e][0];
             I[e][0]=I[e][1];
             I[e][1]=-T;
          }
       }
    
    }*/
    
    H=(0,0) I=(1,0)
    int lepes(H,I,e)
    if(H=cel){
       R=1;
    } else {
       B<-Bal(I)
       H'<-H+B
       if(lepes(H',B,e+1)){
          R=1;
       } else {
          H'=H+I
          lepes
       }
    }
    system("PAUSE");
    return EXIT_SUCCESS;
}
