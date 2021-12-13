#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonction_fakhri.h"
#include <gtk/gtk.h>
enum
{	CIN,
	NOM,
	TYPE,
	SEXE,
	USER_NAME,
	PW,
	ROLE,
	COLUMNS
};

////////////////////////////////////////////////////////////////////////////

int verif( char log[20],char pw [20])
{
FILE *f;
f=fopen("utilisateur.txt","r");
int T=0;
char ch1[20];
char ch2[20];
char ch3[20];
char ch4[20];
char ch5[20];
char ch6[20];
char ch7[20];
if(f!=NULL)
{
while(fscanf(f,"%s %s %s %s %s %s %s\n",ch1,ch2,ch3,ch4,ch5,ch6,ch7)!=EOF)
{
if ((strcmp(ch5,log)==0)&&(strcmp(ch6,pw)==0)){T=1;}
}

}
fclose(f);
return T;
}
///////////////////////////////////////////////////////////////////////////
int cherche_user(char p[20],char nom[20],char t[20],char sx[20],char log[20],char pw[20],char r[20])
{
user u;
int test=0;
FILE *F;
F=fopen("utilisateur.txt","r");
while(fscanf(F,"%s %s %s %s %s %s %s\n",u.id,u.nom,u.type,u.sexe,u.login,u.pw,u.role)!=EOF);
{
if (strcmp(p,u.id)==0)
{
strcpy(nom,u.nom);
strcpy(t,u.type);
strcpy(sx,u.sexe);
strcpy(log,u.login);
strcpy(pw,u.pw);
strcpy(r,u.role);
test=1;
}
}
return test;
}



///////////////////////////////chercher////////////////////////////////////
int chercher_user(char x[20])
{
	FILE * F;
	int T=0;
	char L[100];
	F=fopen("utilisateur.txt","r");
	while (fgets(L,100,F)!=NULL)
	{       
		
  		if (strstr(L,x)){T=1;}
     		
	}
return T;
}
////////////////////////////ajouter//////////////////////////////////////////
int ajouter_USER (user u)
{	
	FILE *F;
	F=fopen("utilisateur.txt","a");
	if (chercher_user(u.id)==1)
	{ 
		return 0;
	}
	else
	{
	fprintf(F,"%s %s %s %s %s %s %s\n",u.id,u.nom,u.type,u.sexe,u.login,u.pw,u.role);
	fclose(F);
	return 1;
	}
             

}
////////////////////////////////////////////////////////////////
void afficher_user(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
char nom[20];
char id[20];
char user_name[20];
char pw[20];
char type[20];
char sexe[20];
char role[20] ;
char L[200];
store=NULL;
FILE *F;
store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("cin",renderer,"text",CIN,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("nom",renderer,"text",NOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("user_name",renderer,"text",USER_NAME,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("mot_de_passe",renderer,"text",PW,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("type",renderer,"text",TYPE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("sexe",renderer,"text",SEXE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("role",renderer,"text",ROLE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);



store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
F=fopen("utilisateur.txt","r");
if (F==NULL)
{
	
}
else 
{ F=fopen("utilisateur.txt","a+");
	do
	{      
		gtk_list_store_append(store,&iter);

			 gtk_list_store_set(store,&iter,CIN,id,NOM,nom,USER_NAME,user_name,PW,pw,TYPE,type,SEXE,sexe,ROLE,role,-1);


	}
	while (fscanf(F,"%s %s %s %s %s %s 	%s\n",id,nom,type,sexe,user_name,pw,role)!=EOF);
	fclose(F);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}
}
}
////////////////////////////////////////////////////////////////////////
void supprimer_user(char U[20])
{	
FILE* F,*G;
user u;
F=fopen("utilisateur.txt","r");
G=fopen("newuti.txt","a");
while(fscanf(F,"%s %s %s %s %s %s %s\n",u.id,u.nom,u.type,u.sexe,u.login,u.pw,u.role)!=EOF)
{
if (!strcmp(U,u.id)==0)
	{
	fprintf(G,"%s %s %s %s %s %s %s\n",u.id,u.nom,u.type,u.sexe,u.login,u.pw,u.role);
	}
}
fclose(G);
fclose(F);
remove("utilisateur.txt");
rename("newuti.txt","utilisateur.txt");
printf("suppression affectue avec succeé\n ");

}
//////////////////////////////modifier///////////////////////////////////
void modifier_user(user x,int tn,int tt,int ts,int tr,int tu,int tp)
{
FILE* F,*G;
user u;
F=fopen("utilisateur.txt","r");
G=fopen("newuti.txt","a");
while(fscanf(F,"%s %s %s %s %s %s %s\n",u.id,u.nom,u.type,u.sexe,u.login,u.pw,u.role)!=EOF)
{
	if (strcmp(x.id,u.id)==0)
	{
	fprintf(G,"%s %s %s %s %s %s 	%s\n",x.id,x.nom,x.type,x.sexe,x.login,x.pw,x.role);
	}
	else 
	{
	fprintf(G,"%s %s %s %s %s %s 	%s\n",u.id,u.nom,u.type,u.sexe,u.login,u.pw,u	.role);
	}
}
fclose(G);
fclose(F);
remove("utilisateur.txt");
rename("newuti.txt","utilisateur.txt");
}




