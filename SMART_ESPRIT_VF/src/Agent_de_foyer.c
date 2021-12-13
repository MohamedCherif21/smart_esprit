#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include "fonction.h"



void ajouter(Etudiant E,char txt[],int choix2[])
{
    FILE *f;
    f=fopen(txt,"a");
    if(f!=NULL)
    {

	if (choix2[0]==1)
strcpy(E.genre,"homme");

if (choix2[1]==1)
strcpy(E.genre,"femme");

        fprintf(f,"%s %s %d %d %d %s %d %s %s %s %d %s\n",E.nom,E.prenom,E.naissance.jour,E.naissance.mois,E.naissance.annee,E.genre,E.niveau.niv,E.niveau.spec,E.adresse,E.chambre,E.CIN,E.tel);
        fclose(f);
    }
}

enum
{
	NOM,
	PRENOM,
	DATE,
	GENRE,
	NIVEAU,
	ADRESSE,
	CHAMBRE,
	CIN,
	TEL,
	COLUMNS,
};


void afficher(GtkWidget *liste,char txt[])
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	char name[30],h[11],room[20],adrisa[100];
	char prename[30],ech[20],gcn[20],hch[20],sexe[50];
	int j,m,a,nivo,g;
	char ch3[20],d_naissance[100],cat[100];

	FILE *f;
	f=fopen(txt,"r");

	store=gtk_tree_view_get_model(liste);

if(store==NULL)
{    
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Nom",renderer,"text",NOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Prenom",renderer,"text",PRENOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Date de naissance",renderer,"text",DATE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("genre",renderer,"text",GENRE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Niveau",renderer,"text",NIVEAU,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Adresse mail",renderer,"text",ADRESSE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Chambre",renderer,"text",CHAMBRE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("N°cin",renderer,"text",CIN,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("N°tel",renderer,"text",TEL,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	

store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_STRING);

while(fscanf(f,"%s %s %d %d %d %s %d %s %s %s %d %s \n",name,prename,&j,&m,&a,sexe,&nivo,ch3,adrisa,room,&g,h)!= EOF)
 {
	sprintf(cat,"%d",j);
	strcpy(d_naissance,strcat(cat,"/"));
	sprintf(cat,"%d",m);
	strcat(d_naissance,strcat(cat,"/"));
	sprintf(cat,"%d",a);
	strcat(d_naissance,cat);
	sprintf(cat,"%d",nivo);
	strcat(cat,ch3);

gtk_list_store_append(store,&iter);				gtk_list_store_set(store,&iter,NOM,name,PRENOM,prename,DATE,d_naissance,GENRE,sexe,NIVEAU,cat,ADRESSE,adrisa,CHAMBRE,room,CIN,g,TEL,h,-1);
 }

gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref (store);

}
else
{
	store=NULL;
store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_STRING);
	
	if(strcmp(txt,"etudiant.txt")==0)
	{

while(fscanf(f,"%s %s %d %d %d %s %d %s %s %s %d %s \n",name,prename,&j,&m,&a,sexe,&nivo,ch3,adrisa,room,&g,h)!= EOF)
	{
			sprintf(cat,"%d",j);
			strcpy(d_naissance,strcat(cat,"/"));
			sprintf(cat,"%d",m);
			strcat(d_naissance,strcat(cat,"/"));
			sprintf(cat,"%d",a);
			strcat(d_naissance,cat);
			sprintf(cat,"%d",nivo);
			strcat(cat,ch3);
			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store,&iter,NOM,name,PRENOM,prename,DATE,d_naissance,GENRE,sexe,NIVEAU,cat,ADRESSE,adrisa,CHAMBRE,room,CIN,g,TEL,h,-1);
	}
	}
	else 
	{
while(fscanf(f,"%s %s %s %s %s %s %s %d %s\n",name,prename,d_naissance,sexe,cat,adrisa,room,&g,h)!= EOF)
	{
		gtk_list_store_append(store,&iter);
		gtk_list_store_set(store,&iter,NOM,name,PRENOM,prename,DATE,d_naissance,GENRE,sexe,NIVEAU,cat,ADRESSE,adrisa,CHAMBRE,room,CIN,g,TEL,h,-1);}	
	}

gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref (store);
}
fclose(f);
}



void modifier(int choix3,Etudiant E,char carte[])
{
    FILE *f,*l;
    char name[30],prename[30],ch3[20],adrisa[100],sexe[50];
    char room[20],gcn[20],h[11],niv[10],nivau[10];
    int j,m,a,nivo,g;
    f=fopen("etudiant.txt","r");
    l=fopen("tmp.txt","a+");
    if(f!=NULL)
    {

  while(fscanf(f,"%s %s %d %d %d %s %d %s %s %s %d %s \n",name,prename,&j,&m,&a,sexe,&nivo,ch3,adrisa,room,&g,h)!= EOF)
        {
	    sprintf(gcn,"%d",g);
            if ((strcmp(carte,gcn)==0))
            
		{	
             	strcpy(name,E.nom);
fscanf(l,"%s %s %d %d %d %s %d %s %s %s %d %s \n",name,prename,&j,&m,&a,sexe,&nivo,ch3,adrisa,room,&g,h);
		  
		strcpy(prename,E.prenom);
fscanf(l,"%s %s %d %d %d %s %d %s %s %s %d %s \n",name,prename,&j,&m,&a,sexe,&nivo,ch3,adrisa,room,&g,h);
		

		nivo=choix3 ;
fscanf(l,"%s %s %d %d %d %s %d %s %s %s %d %s \n",name,prename,&j,&m,&a,sexe,&nivo,ch3,adrisa,room,&g,h);
		
		strcpy(room,E.chambre);
fscanf(l,"%s %s %d %d %d %s %d %s %s %s %d %s \n",name,prename,&j,&m,&a,sexe,&nivo,ch3,adrisa,room,&g,h);
  		
		strcpy(h,E.tel);
fscanf(l,"%s %s %d %d %d %s %d %s %s %s %d %s \n",name,prename,&j,&m,&a,sexe,&nivo,ch3,adrisa,room,&g,h);
                
		fprintf(l,"%s %s %d %d %d %s %d %s %s %s %d %s \n",name,prename,j,m,a,sexe,nivo,ch3,adrisa,room,g,h);
		}

            else
            {
                fprintf(l,"%s %s %d %d %d %s %d %s %s %s %d %s \n",name,prename,j,m,a,sexe,nivo,ch3,adrisa,room,g,h);
            }
	     
        }
    }
    fclose(f);
    fclose(l);
    remove("etudiant.txt");
    rename("tmp.txt","etudiant.txt");
}


void rechercher(char entry[],int rechoix)
{
    FILE *f,*l;
    char name[30],d_naissance[20],cat[15],h[11],adrisa[100],sexe[50];
    char prename[30],gcn[20];
    int j,m,a,nivo,g,trouve=0;
    char ch3[20],room[20];
    f=fopen("etudiant.txt","r");
    l=fopen("temp.txt","a");
    if(f!=NULL)
    {
       if (rechoix==2)
      {  
   while(fscanf(f,"%s %s %d %d %d %s %d %s %s %s %d %s \n",name,prename,&j,&m,&a,sexe,&nivo,ch3,adrisa,room,&g,h)!= EOF)
        {sprintf(gcn,"%d",g);
            
            if(strcmp(entry,gcn)==0)
            {
		trouve=1;
		sprintf(cat,"%d",j);
		strcpy(d_naissance,strcat(cat,"/"));
		sprintf(cat,"%d",m);
		strcat(d_naissance,strcat(cat,"/"));
		sprintf(cat,"%d",a);
		strcat(d_naissance,cat);
		sprintf(cat,"%d",nivo);
		strcat(cat,ch3);
		
                fprintf(l,"%s %s %s %s %s %s %s %s %s\n",name,prename,d_naissance,sexe,cat,adrisa,room,gcn,h);
            }
        }
	 if (trouve==0)
	    {
		strcpy(name,"invalid");
		strcpy(prename,"invalid");
		strcpy(d_naissance,"invalid");
		strcpy(cat,"invalid");
		strcpy(adrisa,"invalid");
		strcpy(room,"invalid");
		g=0;
		strcpy(h,"invalid");
                fprintf(l,"%s %s %s %s %s %s %s %d %s\n",name,prename,d_naissance,sexe,cat,adrisa,room,g,h);
	     }
      }
      

        if (rechoix==3)
      {  
  while(fscanf(f,"%s %s %d %d %d %s %d %s %s %s %d %s \n",name,prename,&j,&m,&a,sexe,&nivo,ch3,adrisa,room,&g,h)!= EOF)
        {
            if(strcmp(entry,room)==0)
            {
		trouve=1;
		sprintf(cat,"%d",j);
		strcpy(d_naissance,strcat(cat,"/"));
		sprintf(cat,"%d",m);
		strcat(d_naissance,strcat(cat,"/"));
		sprintf(cat,"%d",a);
		strcat(d_naissance,cat);
		sprintf(cat,"%d",nivo);
		strcat(cat,ch3);
		sprintf(gcn,"%d",g);
                fprintf(l,"%s %s %s %s %s %s %s %s %s\n",name,prename,d_naissance,sexe,cat,adrisa,room,gcn,h);
            }
        }
	 if (trouve==0)
	    {
		strcpy(name,"invalid");
		strcpy(prename,"invalid");
		strcpy(d_naissance,"invalid");
		strcpy(cat,"invalid");
		strcpy(adrisa,"invalid");
		strcpy(room,"invalid");
		g=0;
		strcpy(h,"invalid");
                fprintf(l,"%s %s %s %s %s %s %s %d %s\n",name,prename,d_naissance,sexe,cat,adrisa,room,g,h);
	     }
       }

     
    }
    fclose(f);
    fclose(l);
}


void supprimer(char ch[])
{
    FILE *f,*l;
    char name[30],adrisa[100];
    char prename[30],h[11],room[20];
    int j,m,a,nivo,g;
    char ch3[20],gstr[10],gcn[40],sexe[50];
    f=fopen("etudiant.txt","r");
    l=fopen("tmp.txt","w");
    if(f!=NULL)
    {
      while(fscanf(f,"%s %s %d %d %d %s %d %s %s %s %d %s \n",name,prename,&j,&m,&a,sexe,&nivo,ch3,adrisa,room,&g,h)!= EOF)
        {
            sprintf(gcn,"%d",g);

            if(strcmp(ch,gcn)!=0)
            {
                fprintf(l,"%s %s %d %d %d %s %d %s %s %s %d %s \n",name,prename,j,m,a,sexe,nivo,ch3,adrisa,room,g,h);
            }
        }
    }
    fclose(f);
    fclose(l);
    remove("etudiant.txt");
    rename("tmp.txt","etudiant.txt");
}


int niveau(int account[],char txt[])
{


 FILE *f;
    char name[30],h[11];
    char prename[30],room[20],adrisa[100],sexe[50];
    int j,m,a,nivo,g,somme1=0,somme2=0,somme3=0,somme4=0,somme5=0,totale=0;
    char ch3[20];
    f=fopen(txt,"r");
  if(f!=NULL)
  {
        
          
		while(fscanf(f,"%s %s %d %d %d %s %d %s %s %s %d %s \n",name,prename,&j,&m,&a,sexe,&nivo,ch3,adrisa,room,&g,h)!= EOF)
			
        	{ 		if((account[0]==1) && (nivo==1))

                                 {
                                  somme1++;

                                 }

  				if((account[1]==1) && (nivo==2))
                                {
                                 somme2++;

                                }

 				if((account[2]==1) && (nivo==3))
                                {
              			 somme3++;

            			}

 				if((account[3]==1) && (nivo==4))
            			{
              			somme4++;

            			}

 				if((account[4]==1) && (nivo==5))
            			{
              			somme5++;

            			}
       
    		}
totale=somme1+somme2+somme3+somme4+somme5;
 }
    fclose(f);
return totale;
}






