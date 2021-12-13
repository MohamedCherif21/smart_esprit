#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include "callbacks.h"
#include<string.h>

/***************************************************** capteurs *******************************/
void ajout( capteur c){
FILE*f=NULL;
f=fopen("capteurs.txt","a+");
fprintf(f,"%s %s %s %s %d %d %d %d %s\n",c.ref,c.type,c.constructeur,c.dateAjout,c.valMax,c.valMin,c.valInit,c.etage,c.bloc);
fclose(f);

}

int exist(char*ref){
FILE*f=NULL;
 capteur c;
f=fopen("capteurs.txt","r");
while(fscanf(f,"%s %s %s %s %d %d %d %d %s\n",c.ref,c.type,c.constructeur,c.dateAjout,&c.valMax,&c.valMin,&c.valInit,&c.etage,c.bloc)!=EOF){
if(strcmp(c.ref,ref)==0)return 1;
}
fclose(f);
return 0;
}


void supp(char*ref){
FILE*f=NULL;
FILE*f1=NULL;
 capteur c;
f=fopen("capteurs.txt","r");

f1=fopen("ancien.txt","w+");
while(fscanf(f,"%s %s %s %s %d %d %d %d %s \n",c.ref,c.type,c.constructeur,c.dateAjout,&c.valMax,&c.valMin,&c.valInit,&c.etage,c.bloc)!=EOF){
if(strcmp(ref,c.ref)!=0)fprintf(f1,"%s %s %s %s %d %d %d %d %s\n",c.ref,c.type,c.constructeur,c.dateAjout,c.valMax,c.valMin,c.valInit,c.etage,c.bloc);
}
fclose(f);
fclose(f1);
remove("agents.txt");
rename("ancien.txt","capteurs.txt");
}

