#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include"tree.h"
#include"crud.h"
#include <time.h>
#include "menu.h"
#include  "fonction.h"





void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{


 	gchar *ref;
        gchar *type;
	gchar *constructeur;
        gchar *dateAjout;
	gchar *bloc;
	gint valMax;
	gint valMin;
	gint valInit;
        gint etage;
        

        int x;
        GtkTreeModel     *model;
        GtkTreeIter iter;
        GtkWidget *p=lookup_widget(gestion_Capteur,"treeview1");
        GtkTreeSelection *selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
	
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {
                gtk_tree_model_get (model,&iter,0,&ref,1,&type,2,&constructeur,3,&dateAjout,4,&valMax,5,&valMin,6,&valInit,7,&etage,8,&bloc,-1);//recuperer les information de la ligne selectionneé

                gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestion_Capteur,"entry2")),dateAjout);
		gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestion_Capteur,"entry12")),constructeur);
		gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestion_Capteur,"entry13")),bloc);
		/*gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestion_Capteur,"entry10")),valMax);
		gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestion_Capteur,"entry11")),valMin);*/
                
		gtk_spin_button_set_value (GTK_SPIN_BUTTON(lookup_widget(gestion_Capteur,"spinbutton7")),valMax);
		gtk_spin_button_set_value (GTK_SPIN_BUTTON(lookup_widget(gestion_Capteur,"spinbutton8")),valMin);
                gtk_spin_button_set_value (GTK_SPIN_BUTTON(lookup_widget(gestion_Capteur,"spinbutton4")),etage);
                gtk_spin_button_set_value (GTK_SPIN_BUTTON(lookup_widget(gestion_Capteur,"spinbutton3")),valInit);

                if(strcmp(type,"Temperature")==0) x=0;
                if(strcmp(type,"Debit")==0) x=1;
		if(strcmp(type,"Fumee")==0) x=2;
		if(strcmp(type,"Dechets")==0) x=3;
		if(strcmp(type,"Mouvement")==0) x=4;




                gtk_combo_box_set_active(GTK_COMBO_BOX(lookup_widget(gestion_Capteur,"combobox2")),x);
		GtkWidget* msg=lookup_widget(gestion_Capteur,"label25");
                gtk_label_set_text(GTK_LABEL(msg),ref);
		


                gtk_widget_show(lookup_widget(gestion_Capteur,"button7"));//afficher le bouton modifier
        GtkWidget* msg1=lookup_widget(gestion_Capteur,"label27");
        gtk_widget_hide(msg1);

}



}




int choix[] = {0,0,0}; 
int choix1[] = {0,0,0,0};






void
on_catalogue_Acceuil_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_widget_show (acceuil);
 gtk_widget_destroy (catalogue);


}


void
on_button2_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
/*preparation du treeView*/
GtkWidget *p;
GtkWidget *p1;
FILE*f1=NULL;
capteur c;
char type[30];
gtk_widget_hide (acceuil);
gestion_Capteur = create_gestion_Capteur ();
p=lookup_widget(gestion_Capteur,"treeview1");
p1=lookup_widget(gestion_Capteur,"treeview3");
i=0;
Capteurtree(p,"capteurs.txt",type);

i=0;
Capteurtree(p1,"capteurs.txt",type);

gtk_widget_show (gestion_Capteur);
}


void
on_AjouterCapteur_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *cal1;
GtkWidget *combobox;
GtkWidget *labelNom;
GtkWidget *labelsuccess;
GtkWidget *labelCombo;
GtkWidget *labelExist;
FILE*f=NULL;
capteur c;
int jj1,mm1,aa1,b=1;
char type[30];

labelNom=lookup_widget(gestion_Capteur,"label9");
labelCombo=lookup_widget(gestion_Capteur,"label15");
labelExist=lookup_widget(gestion_Capteur,"label8");
labelsuccess=lookup_widget(gestion_Capteur,"label10");
combobox=lookup_widget(gestion_Capteur,"combobox1");
cal1=lookup_widget(gestion_Capteur,"calendar1");
           gtk_widget_hide (labelsuccess);

strcpy(c.ref,gtk_entry_get_text(GTK_ENTRY(lookup_widget(gestion_Capteur,"entry1"))));


// saisie controlé
if(strcmp(c.ref,"")==0){
                gtk_widget_show (labelNom);
b=0;

}else
{
           gtk_widget_hide (labelNom);
}

if(gtk_combo_box_get_active (GTK_COMBO_BOX(combobox))==-1){
                gtk_widget_show (labelCombo);
b=0;
}
else{

           gtk_widget_hide (labelCombo);
}
if(b==1){

/*strcpy(c.constructeur,gtk_entry_get_text(GTK_ENTRY(lookup_widget(gestion_Capteur,"entry13"))));*/
if (choix1[0]==1)
strcpy(c.constructeur,"Microship");
else if (choix1[1]==1)
strcpy(c.constructeur,"Analog-Devices");
else if (choix1[2]==1)
strcpy(c.constructeur,"Atmel");
else if (choix1[3]==1)
strcpy(c.constructeur,"Texas-Instruments");

if (choix[0]==1)
strcpy(c.bloc,"A");
else if (choix[1]==1)
strcpy(c.bloc,"B");
else if (choix[2]==1)
strcpy(c.bloc,"C");


c.valMax =gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(gestion_Capteur,"spinbutton5")));
c.valMin =gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(gestion_Capteur,"spinbutton6")));
c.valInit =gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(gestion_Capteur,"spinbutton1")));
c.etage =gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(gestion_Capteur,"spinbutton2")));
strcpy(c.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)));
//recuperer la date du calendrier jour,mois,annee
gtk_calendar_get_date (GTK_CALENDAR(cal1),
                       &aa1,
                       &mm1,
                       &jj1);

if(exist(c.ref)==1) {

                gtk_widget_show (labelExist);

}
else{
           gtk_widget_hide (labelExist);
f=fopen("capteurs.txt","a+");
fprintf(f,"%s %s %s %d/%d/%d  %d %d %d %d %s\n",c.ref,c.type,c.constructeur,jj1,mm1+1,aa1,c.valMax,c.valMin,c.valInit,c.etage,c.bloc);
fclose(f);
                gtk_widget_show (labelsuccess);


/*mise a jour du treeView*/
GtkWidget *p;
p=lookup_widget(gestion_Capteur,"treeview1");
Capteurtree(p,"capteurs.txt",type);



}
}

}


void
on_SupprimerCapteur_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
window_verif_supp = create_window_verif_supp ();
gtk_widget_show (window_verif_supp);
        }




void
on_ModifierCapteur_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
char type[30];
capteur c;
        strcpy(c.ref,gtk_label_get_text(GTK_LABEL(lookup_widget(gestion_Capteur,"label25"))));
        strcpy(c.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(lookup_widget(gestion_Capteur,"combobox2"))));
        strcpy(c.dateAjout,gtk_entry_get_text(GTK_ENTRY(lookup_widget(gestion_Capteur,"entry2"))));
	strcpy(c.constructeur,gtk_entry_get_text(GTK_ENTRY(lookup_widget(gestion_Capteur,"entry12"))));
	strcpy(c.bloc,gtk_entry_get_text(GTK_ENTRY(lookup_widget(gestion_Capteur,"entry13"))));
	/*if (choix1[0]==1)
	strcpy(c.constructeur,"Microship");
	else if (choix1[1]==1)
	strcpy(c.constructeur,"Analog Devices");
	else if (choix1[2]==1)
	strcpy(c.constructeur,"Atmel");
	else if (choix1[3]==1)
	strcpy(c.constructeur,"Texas Instruments");*/
	c.valMax =gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(gestion_Capteur,"spinbutton7")));
	c.valMin =gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(gestion_Capteur,"spinbutton8")));
        c.valInit =gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(gestion_Capteur,"spinbutton3")));
        c.etage =gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(gestion_Capteur,"spinbutton4")));

        supp(c.ref);
        ajout(c);
        Capteurtree(lookup_widget(gestion_Capteur,"treeview1"),"capteurs.txt",type);
        GtkWidget* msg=lookup_widget(gestion_Capteur,"label26");
        gtk_widget_show(msg);

}


void
on_button3_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_widget_show (acceuil);
        gtk_widget_destroy (gestion_Capteur);
}


void
on_chercherCapteur_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *p1;
GtkWidget *entry;
GtkWidget *labelType;
GtkWidget *nbResultat;
GtkWidget *message;
char type[30];
char chnb[30];
int b=0,nb;
entry=lookup_widget(gestion_Capteur,"entry7");
labelType=lookup_widget(gestion_Capteur,"label64");
p1=lookup_widget(gestion_Capteur,"treeview3");

strcpy(type,gtk_entry_get_text(GTK_ENTRY(entry)));
if(strcmp(type,"")==0){
  gtk_widget_show (labelType);b=0;
}else{
b=1;
gtk_widget_hide (labelType);}

if(b==0){return;}else{

nb=ChercherCapteurTree(p1,"capteurs.txt",type);//type entry ecrie par lutilisateur
/* afficher le nombre de resultats obtenue par la recherche */
sprintf(chnb,"%d",nb);
nbResultat=lookup_widget(gestion_Capteur,"label66");
message=lookup_widget(gestion_Capteur,"label65");
gtk_label_set_text(GTK_LABEL(nbResultat),chnb);//set_text n'accepte que chaine de caractere 

gtk_widget_show (nbResultat);
gtk_widget_show (message);




}

}



void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choix1[1] = 1;
else
choix1[1] = 0;
}


void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choix1[0] = 1;
else
choix1[0] = 0;
}


void
on_radiobutton4_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choix1[3] = 1;
else
choix1[3] = 0;
}


void
on_radiobutton3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choix1[2] = 1;
else
choix1[2] = 0;
}


void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choix[0] = 1;
else
choix[0] = 0;
}


void
on_checkbutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choix[1] = 1;
else
choix[1] = 0;
}


void
on_checkbutton3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
choix[2] = 1;
else
choix[2] = 0;
}


void
on_button_pannes_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
/*preparation du treeView*/
GtkWidget *p2;
FILE*f1=NULL;
debit d;
gtk_widget_hide (acceuil);
etages_contenant_des_pannes = create_etages_contenant_des_pannes ();
p2=lookup_widget(etages_contenant_des_pannes,"treeview8");

i=0;
Debittree(p2,"debit.txt");


gtk_widget_show (etages_contenant_des_pannes);
}


void
on_button_alarmes_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
/*preparation du treeView*/
GtkWidget *p4;
GtkWidget *p5;
FILE*f1=NULL;
MOUV M;
FUMEE F;
gtk_widget_hide (acceuil);
liste_des_alarmes = create_liste_des_alarmes ();
p4=lookup_widget(liste_des_alarmes,"treeview9");
p5=lookup_widget(liste_des_alarmes,"treeview10");

v=0;
Fumeetree(p4,"fumee.txt");

z=0;
Mouvtree(p5,"mouvement.txt");



gtk_widget_show (liste_des_alarmes);
}


void
on_button_capteurs_defectueux_clicked  (GtkButton       *button,
                                        gpointer         user_data)
{
/*preparation du treeView*/
GtkWidget *p3;
FILE*f1=NULL;
temp t;

gtk_widget_hide (acceuil);
capteurs_defectueux = create_capteurs_defectueux ();
p3=lookup_widget(capteurs_defectueux,"treeview7");

v=0;
Temptree(p3,"temperature.txt");



gtk_widget_show (capteurs_defectueux);
}


void
on_button_capteurDef_acceuil_clicked   (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_widget_show (acceuil);
        gtk_widget_destroy (capteurs_defectueux);
}


void
on_button_etagePanne_acceuil_clicked   (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_widget_show (acceuil);
        gtk_widget_destroy (etages_contenant_des_pannes);
}


void
on_button_alarmes_acceuil_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_widget_show (acceuil);
        gtk_widget_destroy (liste_des_alarmes);
}


void
on_button33_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *p1;
GtkWidget *entry;
GtkWidget *labelType;
GtkWidget *nbResultat;
GtkWidget *message;
char type[30];
char chnb[30];
int b=0,nb;
entry=lookup_widget(gestion_Capteur,"entry14");
labelType=lookup_widget(gestion_Capteur,"label113");
p1=lookup_widget(gestion_Capteur,"treeview1");

strcpy(type,gtk_entry_get_text(GTK_ENTRY(entry)));
if(strcmp(type,"")==0){
  gtk_widget_show (labelType);b=0;
}else{
b=1;
gtk_widget_hide (labelType);}

if(b==0){return;}else{

nb=ChercherCapteurTree(p1,"capteurs.txt",type);//type entry ecrie par lutilisateur
/* afficher le nombre de resultats obtenue par la recherche */
sprintf(chnb,"%d",nb);
nbResultat=lookup_widget(gestion_Capteur,"label117");
message=lookup_widget(gestion_Capteur,"label115");
gtk_label_set_text(GTK_LABEL(nbResultat),chnb);//set_text n'accepte que chaine de caractere 

gtk_widget_show (nbResultat);
gtk_widget_show (message);





}
}


void
on_button35_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
        gtk_widget_destroy (window_verif_supp);
}


void
on_button34_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkTreeSelection *selection;
        GtkTreeModel     *model;
        GtkTreeIter iter;
        GtkWidget* p;
        GtkWidget *label;
        gchar* ref;
        label=lookup_widget(gestion_Capteur,"label27");
        p=lookup_widget(gestion_Capteur,"treeview1");
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {  gtk_tree_model_get (model,&iter,0,&ref,-1);
           gtk_list_store_remove(GTK_LIST_STORE(model),&iter);//supprimer la ligne du treeView

           supp(ref);// supprimer la ligne du fichier

           /*gtk_widget_hide (label);}
	else{
                gtk_widget_show (label);*/
        }
gtk_widget_destroy (window_verif_supp);
}


void
on_treeviewkhouloud_row_activated      (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}

//khouloud///


GtkTreeSelection *selection1;



int x1;//
int t1[2]={0,0};//modifier
int x3;//
int t[2]={0,0};//ajouter



void
on_affi_mo_clicked                     (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *message;


int nb1=0;
int nb2=0;
int nb3=0;
int min,x,y;

	char id[30];
	char type[30];
	int nb;
	char plat[30];
	char ing[30];
	char date[30];
	char dessert[30];
	char letype [30];

	char resultat [30];
      
  FILE* F;

F=fopen("menu.txt","r");
if(F!=NULL)
{

    
    while(fscanf(F,"%s %s %s %s %s %d %s %s\n",id,type,ing,plat,date,&nb,dessert ,letype)!=EOF)
    {
        if((strcmp(plat,"Petit_déjeuner")==0))
        nb1+=nb;
                                             
 if(strcmp(plat,"déjeuner")==0)
{
      nb2+=nb;
 }
 if(strcmp(plat,"Diner")==0)
{
      nb3+=nb;
 }

if(nb1<nb2)
x=nb1;
else
{
    x=nb2;
}

y=nb3;

if(x<y)
min=x;
else
{
    min=y;
}

if(min==nb1){
    strcpy(resultat,"Petit_déjeuner");
}
if(min==nb2){
    strcpy(resultat,"déjeuner");
}
if(min==nb3){
    strcpy(resultat,"Diner");
}


}

fclose(F);
message = lookup_widget(button, "label11");
gtk_label_set_text(GTK_LABEL(message),resultat);



}
}







void
on_actu_mo_clicked                     (GtkWidget       *objet,             
                                        gpointer         user_data)
{

        GtkTreeModel     *model;
        GtkTreeSelection *selection;
        GtkTreeIter iter;
        GtkWidget* p=lookup_widget(objet,"treeviewkhouloud");
	gchar *type;
        gchar *plat;
        gchar *etat;
        gchar *date;
  	gchar *nb;
        gchar *id;//gchar* type gtk ==> chaine en c car la fonction gtk_tree_model_get naccepte que gchar*
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))//test sur la ligne selectionnée
        {  gtk_tree_model_get (model,&iter,0,&id,1,&type,2,&plat,3,&etat,4,&date,5,&nb,-1);
  
 gtk_entry_set_text(GTK_ENTRY(lookup_widget(objet,"entryid_nb")),id);

GtkWidget *dd,*type,*plat,*ing,*date,*ty,*se,*da,*po;

	dd = lookup_widget (objet,"entryid_nb");
	type = lookup_widget(objet,"labelchef_nb");
	plat = lookup_widget(objet,"labeling_nb");
	ing = lookup_widget(objet, "labelplat_nb");
	date = lookup_widget(objet, "labeldate_nb");

	ty = lookup_widget (objet,"entrychef_nb");
	se = lookup_widget (objet,"entrying_nb");
	da = lookup_widget (objet,"comboboxplat_nb");
	po = lookup_widget (objet,"entrydate_nb");

	strcpy(id,gtk_entry_get_text(GTK_ENTRY(dd)));
	nutri A= rech_nb(id);

	gtk_label_set_text(GTK_LABEL(type),A.type); 
	gtk_label_set_text(GTK_LABEL(plat),A.plat);
	gtk_label_set_text(GTK_LABEL(ing),A.ing);
	gtk_label_set_text(GTK_LABEL(date),A.date);

	gtk_entry_set_text(GTK_LABEL(ty),A.type);  
	gtk_entry_set_text(GTK_LABEL(se),A.plat);
	gtk_label_set_text(GTK_LABEL(da),A.ing);
	gtk_entry_set_text(GTK_LABEL(po),A.date);
			
                gtk_notebook_prev_page(GTK_NOTEBOOK(lookup_widget(objet,"notebookkhouloud")));//redirection vers la page precedente
}

//mise a jour treeview
afficher_nb(p ,"menu.txt");

}





////////////////////////  RECHERCHE   ////////////////////////////
void
on_rech_mo_clicked                     (GtkWidget      *button,
                                        gpointer         user_data)
{




GtkWidget *dd,*type,*plat,*ing,*date,*ty,*se,*da,*po,*lb;
char idd[20];

int k=-1;
char type1[20];
char plat1[20];
char date1[20];
char nb1[20];
char id[20];
char ing1[20];
	char dessert[30];
	char letype [30];



FILE *F;
dd = lookup_widget (button,"entryid_nb");
type = lookup_widget(button, "labelchef_nb");
plat = lookup_widget(button, "labeling_nb");
ing = lookup_widget(button, "labelplat_nb");
date = lookup_widget(button, "labeldate_nb");
lb= lookup_widget(button, "labelid");

ty = lookup_widget (button,"entrychef_nb");
se = lookup_widget (button,"entrying_nb");
da = lookup_widget (button,"comboboxplat_nb");
po = lookup_widget (button,"entrydate_nb");




strcpy(idd,gtk_entry_get_text(GTK_ENTRY(dd)));

F = fopen ("menu.txt", "r");


if (F!=NULL)
 {
  while (fscanf (F,"%s %s %s %s %s %s %s %s \n",id,type1,plat1,ing1,date1,nb1,dessert,letype) != EOF)
  {
  
    if (strcmp (idd,id) == 0)
      {
      k=1;
      } 
     } 
    
     fclose (F);
  }

if(k==-1)
{
gtk_label_set_text(GTK_LABEL(lb),"l'id n'existe pas ");

}else
{
    nutri A= rech_nb(idd);
    gtk_label_set_text(GTK_LABEL(lb),"Id Exist ");/* code */
gtk_label_set_text(GTK_LABEL(type),A.type);
gtk_label_set_text(GTK_LABEL(plat),A.plat);
gtk_label_set_text(GTK_LABEL(ing),A.ing);
gtk_label_set_text(GTK_LABEL(date),A.date);


gtk_entry_set_text(GTK_LABEL(ty),A.type);
gtk_entry_set_text(GTK_LABEL(se),A.plat);
gtk_label_set_text(GTK_LABEL(da),A.ing);
gtk_entry_set_text(GTK_LABEL(po),A.date);
}



}




///////////////// MODIFIER //////////////////////////////////
void
on_Modif_mo_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *dd,*ty,*se,*da,*po,*nb,*lb;
int v=-1;
char id[20];
char idd[20];
char type1[20];
char plat1[20];
char ing1[20];
char date1[20];
char groupe1[20];
char mode1[20];
char nb1[20];
nutri U ;

dd = lookup_widget (objet_graphique,"entryid_nb");
ty = lookup_widget (objet_graphique,"entrychef_nb");
se = lookup_widget (objet_graphique,"entrying_nb");
da = lookup_widget (objet_graphique,"comboboxplat_nb");
po = lookup_widget (objet_graphique,"entrydate_nb");
nb = lookup_widget (objet_graphique,"spinbuttondechet_nb");
lb = lookup_widget (objet_graphique,"labelid");


if (x1==1) 
strcpy(U.letype,"plat_principal");
 if (x1==2) 
strcpy(U.letype,"entree");
 if (x1==0) 
strcpy(U.letype,"NULL");

 if (t1[0]==1)
 strcat(U.dessert,"boisson"); 
if(t1[1]==1)
 strcat (U.dessert,"fruit");
if((t1[1]==0)&&(t1[0]==0))
 strcpy (U.dessert,"NULL");




FILE *F;

F = fopen ("menu.txt", "r");


if (F!=NULL)
 {
  while (fscanf (F,"%s %s %s %s %s %s %s %s  \n",id,type1,plat1,ing1,date1,nb1,groupe1,mode1) != EOF)
  {
  
    if (strcmp (idd,id) == 0)
      {
      v=1;
      } 
     } 
    
     fclose (F);
  }

    
    gtk_label_set_text(GTK_LABEL(lb),"Modification valiée");

U.nb=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(nb));
strcpy(id,gtk_entry_get_text(GTK_ENTRY(dd)));
strcpy(U.type,gtk_entry_get_text(GTK_ENTRY(ty)));
strcpy(U.plat,gtk_entry_get_text(GTK_ENTRY(se)));
strcpy(U.ing,gtk_combo_box_get_active_text(GTK_COMBO_BOX(da)));
strcpy(U.date,gtk_entry_get_text(GTK_ENTRY(po)));


modi_nb(id,U);





//mise a jour treeview
 GtkWidget* p=lookup_widget(objet_graphique,"treeviewkhouloud");
afficher_nb(p ,"menu.txt");
}





///////////////// AJOUTER ///////////////////////
void
on_ajout_mo_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *ty,*se,*da,*po,*nb,*Ajouter,*labeldate,*labelmain,*labelty;
Ajouter=lookup_widget(objet_graphique,"Ajouter");
nutri A ;
char id[30];
int i, longueurChaine = 0;
char chaine[] = "000100020003000400050006000700080009001000110012001300140015001600170018001900200021002200230024002500260027002800290030";
int b=1;

ty = lookup_widget (objet_graphique,"chef_nb");
se = lookup_widget (objet_graphique,"ing_nb");
da = lookup_widget (objet_graphique,"plat_nb");
po = lookup_widget (objet_graphique,"date_nb");
nb = lookup_widget (objet_graphique,"dechet_nb");


A.nb=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(nb));


strcpy(A.type,gtk_entry_get_text(GTK_ENTRY(ty)));
strcpy(A.plat,gtk_entry_get_text(GTK_ENTRY(se)));
strcpy(A.ing,gtk_combo_box_get_active_text(GTK_COMBO_BOX(da)));
strcpy(A.date,gtk_entry_get_text(GTK_ENTRY(po)));

labelty=lookup_widget(objet_graphique,"labelchef");
labelmain=lookup_widget(objet_graphique,"labeling");
labeldate=lookup_widget(objet_graphique,"labeldate");

if (x3==1) 
strcpy(A.letype,"plat_principal");
 if (x3==2) 
strcpy(A.letype,"entree");
 if (x3==0) 
strcpy(A.letype,"NULL");

 if (t[0]==1)
 strcat(A.dessert,"boisson"); 
if(t[1]==1)
 strcat (A.dessert,"fruit");
if((t[1]==0)&&(t[0]==0))
 strcpy (A.dessert,"NULL");


    longueurChaine = strlen(chaine);
 
    srand(time(NULL));
 
    for(i=0; i < 4; i++)
        {
            id[i] = chaine[rand()%longueurChaine];
        }

 strcpy(A.id,id);

// controle saisie
if(strcmp(A.type,"")==0){
		 
          gtk_label_set_text(GTK_LABEL(labelty),"saisir Chef !");
b=0;
}
else {
		  
          gtk_label_set_text(GTK_LABEL(labelty),"");
}

if(strcmp(A.plat,"")==0){
		  
          gtk_label_set_text(GTK_LABEL(labelmain),"saisir Ingrédient !");
b=0;
}
else {
		  
          gtk_label_set_text(GTK_LABEL(labelmain),"");
}


if(strcmp(A.date,"")==0){
		  
          gtk_label_set_text(GTK_LABEL(labeldate),"saisir date !");
b=0;
}
else {
		  
          gtk_label_set_text(GTK_LABEL(labeldate),"");
}


if(b==1){

ajouter_nb(A);
}
//mise a jour treeview
 GtkWidget* p=lookup_widget(objet_graphique,"treeviewkhouloud");
afficher_nb(p ,"menu.txt");
}




////////////////// SUPPRIMER /////////////////////////
void
on_supp_mo_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *dd,*lb;

char idd[20];
FILE *F;
int x=-1;
char type[20];
char plat[20];
char date[20];
char ing[20];
char id[20];
char nb [20];
char group[50];
char mode[50];

lb = lookup_widget (objet_graphique,"labelid"); 
dd = lookup_widget (objet_graphique,"entryid_nb");
strcpy(idd,gtk_entry_get_text(GTK_ENTRY(dd)));

F = fopen ("menu.txt", "r");


  if (F!=NULL)
 {
  while (fscanf (F,"%s %s %s %s %s %s %s %s \n",id,type,plat,ing,date,nb,group,mode) != EOF)
  {
  
    if (strcmp (idd,id) == 0)
      {
      x=1;
      } 
     } 
    
     fclose (F);
  }

if(x==-1)
{
gtk_label_set_text(GTK_LABEL(lb),"l'id n'existe pas ");
}else
{
    supp_nb(idd);
    gtk_label_set_text(GTK_LABEL(lb),"supprimer avec succes");/* code */
}


//mise a jour treeview
 GtkWidget* p=lookup_widget(objet_graphique,"treeviewkhouloud");
afficher_nb(p ,"menu.txt");
}




void
on_supp_tree_mo_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
   GtkTreeModel     *model;
        GtkTreeSelection *selection;
        GtkTreeIter iter;
        GtkWidget* p=lookup_widget(objet,"treeviewkhouloud");;

        gchar *id;//gchar* type gtk ==> chaine en c car la fonction gtk_tree_model_get naccepte que gchar*
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {  gtk_tree_model_get (model,&iter,0,&id,-1);
           gtk_list_store_remove(GTK_LIST_STORE(model),&iter);
            supp_nb( id);
}
}





void
on_checkbutton2MO_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
   if (gtk_toggle_button_get_active(togglebutton)) //boisson

   {t[1]=1;}    
}


void
on_checkbutton1MO_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
  if (gtk_toggle_button_get_active(togglebutton)) //fruit
  {t[0]=1;}   
}






/*void
on_radiobutton1MO_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}*/


/*void
on_radiobutton2MO_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}*/










void
on_checkbutton4MO_toggled                (GtkToggleButton *togglebutton,//boisson
                                        gpointer         user_data)
{
   if (gtk_toggle_button_get_active(togglebutton))

   {t1[0]=1;} 
else 
   {t1[0]=0;} 
}


void
on_checkbutton3MO_toggled                (GtkToggleButton *togglebutton,//fruit
                                        gpointer         user_data)
{
   if (gtk_toggle_button_get_active(togglebutton)) 

   {t1[1]=1;} 
else 
   {t1[1]=0;} 
}


/*void
on_radiobutton4MO_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
 if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton))) //entree
{x1=2;} 
else 
{x1=0;} 

}*/

/*void
on_radiobutton3MO_toggled                (GtkToggleButton *togglebutton,//plat_principal
                                        gpointer         user_data)
{
   

}*/
/*
void
on_button_meill_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *affiche;
affiche=lookup_widget(button,"affichage");
meilleur_menu(lookup_widget(affiche,"treeview1"));
*/



void
on_radiobutton1MO_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
 if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
 {x3=1;} 
}


void
on_radiobutton2MO_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
 if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton))) 
{x3=2;} 
}


void
on_radiobutton4MO_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
 if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton))) //entree
{x1=2;} 
else 
{x1=0;} 
}


void
on_radiobutton3MO_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
 {x1=1;} 
else 
{x1=0;}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////mohamed/////////////////////////////////////////////////////////////////////////////////////////////////////////////



int choix3=1,choice=1,calcul[5]={0,0,0,0,0};
int choix2[2]={0,0} ;
char sup[100],id[10],nv[200],nat[40],so[200],chambr[20],carte[20];
Etudiant E,ET;



void
on_button_affich_tab_clicked           (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview;
treeview=lookup_widget(button,"treeview");
afficher(treeview,"etudiant.txt");
}


void
on_treeview_row_activated              (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar* name;
gchar* prename;
gchar* adrisa;
gchar* d_naissance;
gchar* sexe;
gchar* cat;
gchar* e;
gchar* g;
gchar* h;

GtkTreeModel *model = gtk_tree_view_get_model(treeview);

if (gtk_tree_model_get_iter(model,&iter,path));
{
gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&name,1,&prename,2,&d_naissance,3,&sexe,4,&cat,5,&adrisa,6,&e,7,&g,8,&h,-1);
strcpy(sup,name);
strcpy(id,prename);
strcpy(chambr,e);
sprintf(carte,"%d",g);
strcpy(nat,h);

}
}



void
on_button_ajouter_tab_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Ajouter_Etudiant,*Gestion_des_Etudiants;
Ajouter_Etudiant= create_Ajouter_Etudiant ();
gtk_widget_show (Ajouter_Etudiant);
}


void
on_button_ajouter_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
   
GtkWidget *nom,*prenom,*chambre,*adres,*cin,*tel,*jour,*mois,*annee,*niveau,*spc,*Carte_in,*valnom,*togglebutton1,*togglebutton2;
char x[30];
int validite=0;
nom = lookup_widget(button, "entry_nom") ;
strcpy(E.nom,gtk_entry_get_text(GTK_ENTRY(nom)));

prenom = lookup_widget(button, "entry_prenom") ;
strcpy(E.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));

adres = lookup_widget(button, "entry_adresse") ;
strcpy(E.adresse,gtk_entry_get_text(GTK_ENTRY(adres)));

jour= lookup_widget(button, "spinbutton_jour");
E.naissance.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));

mois= lookup_widget(button, "spinbutton_mois");
E.naissance.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));

annee= lookup_widget(button, "spinbutton_annee");
E.naissance.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));

togglebutton1=lookup_widget(button,"radiobutton_homme");
togglebutton2=lookup_widget(button,"radiobutton_femme");

niveau= lookup_widget(button, "combobox_niveau");
strcpy(x,gtk_combo_box_get_active_text(GTK_COMBO_BOX(niveau)));
E.niveau.niv=atoi(x);

spc= lookup_widget(button, "combobox_spc");
strcpy(E.niveau.spec,gtk_combo_box_get_active_text(GTK_COMBO_BOX(spc)));

chambre= lookup_widget(button, "entry_chambre");
strcpy(E.chambre,gtk_entry_get_text(GTK_ENTRY(chambre)));

cin= lookup_widget(button, "entry_cin");
strcpy(x,gtk_entry_get_text(GTK_ENTRY(cin)));
E.CIN=atoi(x);

tel= lookup_widget(button, "entry_tel");
strcpy(E.tel,gtk_entry_get_text(GTK_ENTRY(tel)));


valnom = lookup_widget(button, "valid_nom") ; 
if (strlen(E.nom)==0)
{
gtk_label_set_text(GTK_LABEL(valnom),"invalide");}
else {
gtk_label_set_text(GTK_LABEL(valnom),"valide");
validite++;
}

valnom = lookup_widget(button, "valid_preno") ; 
if (strlen(E.prenom)==0)
{
gtk_label_set_text(GTK_LABEL(valnom),"invalide");}
else {
gtk_label_set_text(GTK_LABEL(valnom),"valide");
validite++;
}

valnom = lookup_widget(button, "valid_adres") ; 
if (strlen(E.adresse)==0)
{
gtk_label_set_text(GTK_LABEL(valnom),"invalide");}
else {
gtk_label_set_text(GTK_LABEL(valnom),"valide");
validite++;
}

valnom = lookup_widget(button, "valid_chambre") ; 
if (strlen(E.chambre)==0)
{
gtk_label_set_text(GTK_LABEL(valnom),"invalide");}
else {
gtk_label_set_text(GTK_LABEL(valnom),"valide");
validite++;
}


Carte_in = lookup_widget(button, "valid_cin") ; 
if ((strlen(x)!=8) && (strlen(x)!=7))
{
gtk_label_set_text(GTK_LABEL(Carte_in),"invalide");}
else {
gtk_label_set_text(GTK_LABEL(Carte_in),"valide");
validite++;
}
//////
valnom = lookup_widget(button, "valid_tel") ; 
if (strlen(E.tel)==0)
{
gtk_label_set_text(GTK_LABEL(valnom),"invalide");}
else {
gtk_label_set_text(GTK_LABEL(valnom),"valide");
validite++;
}
if(validite==6){ajouter(E,"etudiant.txt",choix2);}

}


//button_return_ajouter
void
on_button_return_ajouter_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Gestion_des_Etudiants,*Ajouter_Etudiant,*treeview;
//principale = create_principale ();
//gtk_widget_show (principale);
Ajouter_Etudiant=lookup_widget(button,"Ajouter_Etudiant");
gtk_widget_destroy(Ajouter_Etudiant);
}


//modif_tab
void
on_button_modifier_tab_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Modifier_Etudiant,*Gestion_des_Etudiants;
Modifier_Etudiant = create_Modifier_Etudiant ();
gtk_widget_show (Modifier_Etudiant);
}

//button_info_modif
on_button_modifier_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *nom,*prenom,*chambre,*tel,*Niveau;
char x[30];
//nom
nom = lookup_widget(button, "entry_modif_nom") ;
gtk_entry_set_text(GTK_ENTRY(nom),sup);
//prenom
prenom = lookup_widget(button, "entry_modif_prenom") ;
gtk_entry_set_text(GTK_ENTRY(prenom),id);

//chambre
chambre = lookup_widget(button, "entry_modif_chambre") ;
gtk_entry_set_text(GTK_ENTRY(chambre),chambr);
//tel
tel = lookup_widget(button, "entry_modif_tel") ;
gtk_entry_set_text(GTK_ENTRY(tel),nat);
}


//button_modif_enregistrer
void
on_button_modif_enregistrer_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *nom,*prenom,*chambre,*tel,*Niveau;
char y[30];
//nom
nom = lookup_widget(button, "entry_modif_nom") ;
strcpy(E.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
//prenom
prenom = lookup_widget(button, "entry_modif_prenom") ;
strcpy(E.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));

//chambre
chambre = lookup_widget(button, "entry_modif_chambre") ;
strcpy(E.chambre,gtk_entry_get_text(GTK_ENTRY(chambre)));
//tel
tel = lookup_widget(button, "entry_modif_tel") ;
strcpy(E.tel,gtk_entry_get_text(GTK_ENTRY(tel)));
modifier(choix3,E,carte);
}

//button_return_modifier
void
on_button_return_modifier_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Modifier_Etudiant;
Modifier_Etudiant=lookup_widget(button,"Modifier_Etudiant");
gtk_widget_destroy(Modifier_Etudiant);
}

//button_chercher_tab
void
on_button_chercher_tab_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *carte,*treeview,*Gestion_des_Etudiants;
int cn;
char entry[30]; 
//appel rechercher
remove("temp.txt");
carte= lookup_widget(button, "entry_chercher_tab");

if (choice==2)
{
strcpy(entry,gtk_entry_get_text(GTK_ENTRY(carte)));
rechercher(entry,choice);
}

if (choice==3)
{
strcpy(entry,gtk_entry_get_text(GTK_ENTRY(carte)));
rechercher(entry,choice);
}

//appel afficher
treeview=lookup_widget(button,"treeview");
afficher(treeview,"temp.txt");
}




//button_supprim_tab
void
on_button_supprim_tab_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Supprimer_Etudiant;
Supprimer_Etudiant = create_Supprimer_Etudiant ();
gtk_widget_show (Supprimer_Etudiant);

}

//OUI
void
on_button_oui_supprimer_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Supprimer_Etudiant;
supprimer(carte);
Supprimer_Etudiant=lookup_widget(button,"Supprimer_Etudiant");
gtk_widget_destroy(Supprimer_Etudiant);
}

//NON
void
on_button_nom_supprimer_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Supprimer_Etudiant;
Supprimer_Etudiant=lookup_widget(button,"Supprimer_Etudiant");
gtk_widget_destroy(Supprimer_Etudiant);
}


//button_calcul_tab
void
on_button_calcul_tab_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Calcul,*Gestion_des_Etudiants;
Calcul = create_Calcul ();
gtk_widget_show (Calcul);
}

                         /*---------Casse_à_Cocher---------*/
//checkbutton_calcul_1
void
on_checkbutton_calcul_1_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

if (gtk_toggle_button_get_active(togglebutton))
{calcul[0]=1;
}
else
{calcul[0]=0;}
}
//checkbutton_calcul_2
void
on_checkbutton_calcul_2_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{calcul[1]=1;
}
else
{calcul[1]=0;}
}
//checkbutton_calcul_3
void
on_checkbutton_calcul_3_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{calcul[2]=1;
}
else
{calcul[2]=0;}
}
//checkbutton_calcul_4
void
on_checkbutton_calcul_4_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{calcul[3]=1;}
else
{calcul[3]=0;}
}
//checkbutton_calcul_5
void
on_checkbutton_calcul_5_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{calcul[4]=1;}
else
{calcul[4]=0;}
}

//button_calcul_sum
void
on_button_calcul_sum_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *somme;
int sum;
somme = lookup_widget(button, "label_calcul_s") ;
sum=niveau(calcul,"etudiant.txt");
sprintf(so,"%d Etudiant dans ce Niveau",sum);
gtk_label_set_text(GTK_LABEL(somme),so);
}

//button_calcul_retour
void
on_button_retour_calcul_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Calcul;
Calcul=lookup_widget(button,"Calcul");
gtk_widget_destroy(Calcul);
}

void
on_button_retour_home_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
{
GtkWidget *Gestion_des_Etudiant,*Calcul;
Gestion_des_Etudiant = create_Gestion_des_Etudiant ();
gtk_widget_show (Gestion_des_Etudiant);
Calcul=lookup_widget(button,"Calcul");
gtk_widget_destroy(Calcul);
}

}

void
on_radiobutton_hamma_homme_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
	{choix2[0] = 1;}
else 
{choix2[0] = 0 ;}
}


void
on_radiobutton_hamma_femme_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
	{choix2[1] = 1;}
else 
{choix2[1] = 0 ;}
}


void
on_radiobutton_hamma_chambre_toggled   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
choice=3;
}


void
on_radiobutton_hamma_cin_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
choice=2;
}


void
on_radiobutton_hamma1_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
choix3=1;
}


void
on_radiobutton_hamma2_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
choix3=2;
}


void
on_radiobutton_hamma3_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
choix3=3;
}


void
on_radiobutton_hamma4_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
choix3=4;
}


void
on_radiobutton_hamma5_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
choix3=5;
}

//////fakhri////////////////////////////////////////


int s=1;
int testM=1;
int tn=0;
int tt=0;
int ts=0;
int tr=0;
int tu=0;
int tp=0;
void on_button_ok_clicked                   (GtkWidget       *button,
                                        gpointer         user_data)
{

GtkWidget *Login,*psw,*windowESadmin,*fen;
char user[20];
char pw[20];
Login=lookup_widget(button,"entry1_login");
psw =lookup_widget(button,"entry2_login");
strcpy(user,gtk_entry_get_text(GTK_ENTRY(Login)));
strcpy(pw,gtk_entry_get_text(GTK_ENTRY(psw)));
if (verif(user,pw)==1)
{
	fen=lookup_widget(button,"LOGIN");
	gtk_widget_destroy(fen);
	windowESadmin=create_ADMIN();
	gtk_widget_show(windowESadmin);
}
}


void on_button_gosupp_clicked               (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *fen_nv,*fen_act;
fen_act=lookup_widget(button,"ADMIN");
gtk_widget_destroy(fen_act);
fen_nv=create_SUPP();
gtk_widget_show(fen_nv);
}


void on_button_gomodif_clicked              (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *fen_nv,*fen_act;
fen_act=lookup_widget(button,"ADMIN");
gtk_widget_destroy(fen_act);
fen_nv=create_MODIF();
gtk_widget_show(fen_nv);
}


void on_button_gorech_clicked               (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *fen_nv,*fen_act;
fen_act=lookup_widget(button,"ADMIN");
gtk_widget_destroy(fen_act);
fen_nv=create_RECHERCHE();
gtk_widget_show(fen_nv);
}


void on_button_goajout_clicked              (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *fen_nv,*fen_act;
fen_act=lookup_widget(button,"ADMIN");
gtk_widget_destroy(fen_act);
fen_nv=create_AJOUT();
gtk_widget_show(fen_nv);
}


void on_button_affich_clicked               (GtkWidget       *button,
                                        gpointer         user_data)
{
 GtkWidget *tv;
 tv=lookup_widget(button,"treeview1");
 afficher_user(tv);
}


void on_Home_ajout_clicked                  (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *fen_nv,*fen_act;
fen_act=lookup_widget(button,"AJOUT");
gtk_widget_destroy(fen_act);
fen_nv=create_ADMIN();
gtk_widget_show(fen_nv);
}





void on_radiobutton1_ajout_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
s=1;
}


void on_radiobutton2_ajout_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
s=2;
}


void on_button_homesupp_clicked             (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *fen_nv,*fen_act;
fen_act=lookup_widget(button,"SUPP");
gtk_widget_destroy(fen_act);
fen_nv=create_ADMIN();
gtk_widget_show(fen_nv);
}


void on_button_supp_clicked                 (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *idd;
char U[20];
idd=lookup_widget(button,"entry1_supp");
strcpy(U,gtk_entry_get_text(GTK_ENTRY(idd)));
supprimer_user(U);
}


void on_button_homerech_clicked             (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *fen_nv,*fen_act;
fen_act=lookup_widget(button,"RECHERCHE");
gtk_widget_destroy(fen_act);
fen_nv=create_ADMIN();
gtk_widget_show(fen_nv);
}


void on_button_aff_clicked                  (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *id,*outputr;
GtkWidget *output1,*output2,*output3,*output4,*output5,*output6;
GtkWidget *output11,*output22,*output33,*output44,*output55,*output66;
int test;
char p[20];
char nom[20];
char t[20];
char sx[20];
char log[20];
char pw[20];
char r[20];
id=lookup_widget(button,"entry_rech");
strcpy(p,gtk_entry_get_text(GTK_ENTRY(id)));
test=cherche_user(p,nom,t,sx,log,pw,r);
if (test==1)
{
output1=lookup_widget(button,"aa1");
 gtk_label_set_text(GTK_LABEL(output1),"nom-->");
output2=lookup_widget(button,"aa2");
 gtk_label_set_text(GTK_LABEL(output2),"type-->");
output3=lookup_widget(button,"aa3");
 gtk_label_set_text(GTK_LABEL(output3),"sexe-->");
output4=lookup_widget(button,"aa4");
 gtk_label_set_text(GTK_LABEL(output4),"role-->");
output5=lookup_widget(button,"aa5");
 gtk_label_set_text(GTK_LABEL(output5),"user_name-->");
output6=lookup_widget(button,"aa6");
 gtk_label_set_text(GTK_LABEL(output6),"pw -->");
output11=lookup_widget(button,"nom");
 gtk_label_set_text(GTK_LABEL(output11),nom);
output22=lookup_widget(button,"type");
 gtk_label_set_text(GTK_LABEL(output22),t);
output33=lookup_widget(button,"sexe");
 gtk_label_set_text(GTK_LABEL(output33),sx);
output44=lookup_widget(button,"role");
 gtk_label_set_text(GTK_LABEL(output44),r);
output55=lookup_widget(button,"username");
 gtk_label_set_text(GTK_LABEL(output55),log);
output66=lookup_widget(button,"pw");
 gtk_label_set_text(GTK_LABEL(output66),pw);
}
else
{
 outputr=lookup_widget(button,"notrecherche");
 gtk_label_set_text(GTK_LABEL(outputr),"n existe pas");

}
}


void on_button_homemodif_clicked            (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *fen_nv,*fen_act;
fen_act=lookup_widget(button,"RECHERCHE");
gtk_widget_destroy(fen_act);
fen_nv=create_ADMIN();
gtk_widget_show(fen_nv);
}


void on_button_modif_clicked                (GtkWidget       *button,
                                             gpointer         user_data)
{
user x;
GtkWidget *idd,*nom,*type,*sexe,*role,*user,*pw ;
int Ri;
idd=lookup_widget(button,"entry_modif");
nom=lookup_widget(button,"entry1");
type=lookup_widget(button,"combobox_modif");
role=lookup_widget(button,"spinbutton_modif");
user=lookup_widget(button,"entry5");
pw=lookup_widget(button,"entry6");
strcpy(x.id,gtk_entry_get_text(GTK_ENTRY(idd)));
strcpy(x.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(x.login,gtk_entry_get_text(GTK_ENTRY(user)));
strcpy(x.pw,gtk_entry_get_text(GTK_ENTRY(pw)));
strcpy(x.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)));
Ri=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(role));
sprintf(x.role,"%d",Ri);
if (testM==1)
	strcpy(x.sexe,"Homme");
else if (testM==2) 
	strcpy(x.sexe,"Femme");

modifier_user(x,tn,tt,ts,tr,tu,tp);

}


void on_checkbutton_n_toggled               (GtkToggleButton *togglebutton,
                                             gpointer         user_data)
{
tn=1;
}


void on_checkbutton_t_toggled               (GtkToggleButton *togglebutton,
                                             gpointer         user_data)
{
tt=1;
}


void on_checkbutton_s_toggled               (GtkToggleButton *togglebutton,
                                      	     gpointer         user_data)
{
ts=1;
}


void on_checkbutton_r_toggled               (GtkToggleButton *togglebutton,
                                             gpointer         user_data)
{
tr=1;
}


void on_checkbutton_u_toggled               (GtkToggleButton *togglebutton,
                                             gpointer         user_data)
{
tu=1;
}


void on_checkbutton_p_toggled               (GtkToggleButton *togglebutton,
                                             gpointer         user_data)
{
tp=1;
}


void on_radiobutton_modifF_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
testM=1;
}


void on_radiobutton_modifH_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
testM=2;
}





void
on_button_ajouter2_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *login,*pw,*nom,*id,*Role,*type;
user u;
int role ;

nom=lookup_widget (button, "entry1_ajout");
id = lookup_widget (button, "entry2_ajout");
login = lookup_widget (button, "entry3_ajout");
pw = lookup_widget (button, "entry4_ajout");
type=lookup_widget(button,"combobox1_ajout");
Role=lookup_widget (button,"spinbutton1_ajout");
strcpy(u.login,gtk_entry_get_text(GTK_ENTRY(login)));
strcpy(u.pw,gtk_entry_get_text(GTK_ENTRY(pw)));
strcpy(u.id,gtk_entry_get_text(GTK_ENTRY(id)));
strcpy(u.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
role=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Role));
sprintf(u.role,"%d",role);
strcpy(u.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)));
if (s==1)
	strcpy(u.sexe,"Homme");
else if (s==2) 
	strcpy(u.sexe,"Femme");
ajouter_USER(u);
}


void
on_button37_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_widget_hide (window_acceuil);
acceuil = create_acceuil ();
gtk_widget_show (acceuil);
}


void
on_button38_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_widget_hide (window_acceuil);
Gestion_Restau = create_Gestion_Restau ();
gtk_widget_show (Gestion_Restau);
}


void
on_button39_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_widget_hide (window_acceuil);
Gestion_des_Etudiant = create_Gestion_des_Etudiant ();
gtk_widget_show (Gestion_des_Etudiant);
}


void
on_button40_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_widget_hide (window_acceuil);
LOGIN = create_LOGIN ();
gtk_widget_show (LOGIN);
}


void
on_button41_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button42_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_widget_show (window_acceuil);
        gtk_widget_destroy (acceuil);
}


void
on_button43_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_widget_show (window_acceuil);
        gtk_widget_destroy (Gestion_Restau);
}


void
on_button44_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_widget_show (window_acceuil);
        gtk_widget_destroy (Gestion_des_Etudiant);
}


void
on_button45_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_widget_show (window_acceuil);
        gtk_widget_destroy (LOGIN);
}

