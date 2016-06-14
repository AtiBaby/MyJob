#include <cstdlib>
#include <iostream>
#include <stdio.h>


using namespace std;

// Olvasás
/*
int main(int argc, char *argv[]){
    FILE *f;
    f=fopen("proba.txt","r");
    char s[100];
    while(!feof(f)){
       fscanf(f,"%s",s);
       printf(s);
    }
    fclose(f);
    cout<<"\n";
    system("PAUSE");
    return EXIT_SUCCESS;
}*/

// Hozzáfûzés
/*
int main(int argc, char *argv[]){
    FILE *f;
    f=fopen("proba.txt","a");
    char hozzafuz[100];
    gets(hozzafuz);
    fprintf(f,"%s",hozzafuz);
    fclose(f);
    system("PAUSE");
    return EXIT_SUCCESS;
}*/

// Írás

/*int main(int argc, char *argv[])
{
    FILE *f;
    f=fopen("proba.txt","w");
    char s[100];
    gets(s);
    fprintf(f,"%s",s);
    fclose(f);
    cout<<"\n";
    system("PAUSE");
    return EXIT_SUCCESS;
}*/

// Bitenkénti olvasás
/*
int main(int argc, char *argv[]){
    FILE *f;
    f=fopen("proba.txt","r");
    char s[100], c;
    while(!feof(f)){
       fread(&c,1,5,f);
       printf("%c",c);
    }
    fclose(f);
    cout<<"\n";
    system("PAUSE");
    return EXIT_SUCCESS;
}*/

// Fájlmásoló program (billentyûzetrõl elsõ és második fájlnév)
/*
int main(int argc, char *argv[]){
    char elso[50], masodik[50];
    cout<<"Adja meg a fajlneveket:\n";
    gets(elso);
    gets(masodik);
    FILE *f;
    FILE *k;
    char s[100];
    f=fopen(elso,"r");
    k=fopen(masodik,"w");
    while(!feof(f)){
       fscanf(f,"%s",s);
    }
    fprintf(k,"%s",s);
    fclose(f);
    fclose(k);
    system("PAUSE");
    return EXIT_SUCCESS;
}*/

int main(int argc, char *argv[]){
    FILE *f1;
    FILE *f2;
    char s1[100], s2[100], s3[100];
    cout<<"Titkositando fajl: "; 
    cin>>s1;
    cout<<"Titkos fajl: ";
    cin>>s2;
    cout<<"Jelszo: ";
    cin>>s3;
    f1=fopen(s1,"rb");
    f2=fopen(s2,"wb");
    int l; 
    int count=0;
    for(l=0;s3[l]!=0;l++);
    int i=0, t;
    char c;
    while(!feof(f1)){
       t=fread(&c,1,1,f1);
       if(t){
          c=c^s3[i];
          fwrite(&c,1,1,f2);
          i++;
          i%=l;
          count++;
          }
    }
    cout<<count<<endl;
    fclose(f1);
    fclose(f2);
    system("PAUSE");
    return EXIT_SUCCESS;
}
