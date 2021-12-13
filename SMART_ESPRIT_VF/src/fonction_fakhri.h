#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>

typedef struct user user;
struct user 
{
char id[20];
char nom[20];
char type[20];//etudiant agent_foyer agent_resto nutri tech liste 
char sexe[20];//bouton radio
char login[20];
char pw[20];
char role[10];//pour se connecter à son espace
};

char x[20];
int ajouter_USER(user u);
void modifier_user(user u,int tn,int tt,int ts,int tr,int tu,int tp);
void afficher_user(GtkWidget *liste);
void supprimer_user(char U[20]);
int chercher_user(char x[20]);
int verif(char b[20],char a[20]);
int cherche_user(char p[20],char nom[20],char t[20],char sx[20],char log[20],char pw[20],char r[20]);
