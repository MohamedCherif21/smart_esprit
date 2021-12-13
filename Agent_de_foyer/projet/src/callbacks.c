#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <gtk/gtk.h>

#include <string.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include  "fonction.h"

int choix=1,choice=1,account[5]={0,0,0,0,0};
int choix1[2]={0,0} ;
char sup[100],id[10],nv[100],nat[40],so[100],chambr[20],carte[20];
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
gchar* miveau;
gchar* e;
gchar* g;
gchar* h;

GtkTreeModel *model = gtk_tree_view_get_model(treeview);

if (gtk_tree_model_get_iter(model,&iter,path));
{
gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&name,1,&prename,2,&d_naissance,3,&sexe,4,&miveau,5,&adrisa,6,&e,7,&g,8,&h,-1);
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
   
GtkWidget *nom,*prenom,*chambre,*adres,*cin,*tel,*jour,*mois,*annee,*niveau,*spc,*Carte_cn,*valnom,*togglebutton1,*togglebutton2;
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


Carte_cn = lookup_widget(button, "valid_cin") ; 
if ((strlen(x)!=8) && (strlen(x)!=7))
{
gtk_label_set_text(GTK_LABEL(Carte_cn),"invalide");}
else {
gtk_label_set_text(GTK_LABEL(Carte_cn),"valide");
validite++;
}

valnom = lookup_widget(button, "valid_tel") ; 
if (strlen(E.tel)==0)
{
gtk_label_set_text(GTK_LABEL(valnom),"invalide");}
else {
gtk_label_set_text(GTK_LABEL(valnom),"valide");
validite++;
}
if(validite==6){ajouter(E,"etudiant.txt",choix1);}

}


void
on_button_return_ajouter_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Gestion_des_Etudiants,*Ajouter_Etudiant,*treeview;
Ajouter_Etudiant=lookup_widget(button,"Ajouter_Etudiant");
gtk_widget_destroy(Ajouter_Etudiant);
}

void
on_button_modifier_tab_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Modifier_Etudiant,*Gestion_des_Etudiants;
Modifier_Etudiant = create_Modifier_Etudiant ();
gtk_widget_show (Modifier_Etudiant);
}

on_button_modifier_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *nom,*prenom,*chambre,*tel,*Niveau;
char x[30];
nom = lookup_widget(button, "entry_modif_nom") ;
gtk_entry_set_text(GTK_ENTRY(nom),sup);

prenom = lookup_widget(button, "entry_modif_prenom") ;
gtk_entry_set_text(GTK_ENTRY(prenom),id);


chambre = lookup_widget(button, "entry_modif_chambre") ;
gtk_entry_set_text(GTK_ENTRY(chambre),chambr);

tel = lookup_widget(button, "entry_modif_tel") ;
gtk_entry_set_text(GTK_ENTRY(tel),nat);
}

void
on_button_modif_enregistrer_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *nom,*prenom,*chambre,*tel,*Niveau;
char y[30];

nom = lookup_widget(button, "entry_modif_nom") ;
strcpy(E.nom,gtk_entry_get_text(GTK_ENTRY(nom)));

prenom = lookup_widget(button, "entry_modif_prenom") ;
strcpy(E.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));

chambre = lookup_widget(button, "entry_modif_chambre") ;
strcpy(E.chambre,gtk_entry_get_text(GTK_ENTRY(chambre)));

tel = lookup_widget(button, "entry_modif_tel") ;
strcpy(E.tel,gtk_entry_get_text(GTK_ENTRY(tel)));
modifier(choix,E,carte);
}

void
on_button_return_modifier_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Modifier_Etudiant;
Modifier_Etudiant=lookup_widget(button,"Modifier_Etudiant");
gtk_widget_destroy(Modifier_Etudiant);
}

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


void
on_radiobutton_cher_cin_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
choice=2;
}
void
on_radiobutton_cher_chambre_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
choice=3;
}


void
on_button_supprim_tab_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Supprimer_Etudiant;
Supprimer_Etudiant = create_Supprimer_Etudiant ();
gtk_widget_show (Supprimer_Etudiant);

}

void
on_button_oui_supprimer_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Supprimer_Etudiant;
supprimer(carte);
Supprimer_Etudiant=lookup_widget(button,"Supprimer_Etudiant");
gtk_widget_destroy(Supprimer_Etudiant);
}

void
on_button_nom_supprimer_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Supprimer_Etudiant;
Supprimer_Etudiant=lookup_widget(button,"Supprimer_Etudiant");
gtk_widget_destroy(Supprimer_Etudiant);
}


void
on_button_calcul_tab_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Calcul,*Gestion_des_Etudiants;
Calcul = create_Calcul ();
gtk_widget_show (Calcul);
}


void
on_checkbutton_calcul_1_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

if (gtk_toggle_button_get_active(togglebutton))
{account[0]=1;
}
else
{account[0]=0;}
}

void
on_checkbutton_calcul_2_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{account[1]=1;
}
else
{account[1]=0;}
}

void
on_checkbutton_calcul_3_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{account[2]=1;
}
else
{account[2]=0;}
}

void
on_checkbutton_calcul_4_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{account[3]=1;}
else
{account[3]=0;}
}

void
on_checkbutton_calcul_5_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{account[4]=1;}
else
{account[4]=0;}
}

void
on_button_calcul_sum_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *somme;
int sum;
somme = lookup_widget(button, "label_calcul_s") ;
sum=niveau(account,"etudiant.txt");
sprintf(so,"%d Etudiant dans ce Niveau",sum);
gtk_label_set_text(GTK_LABEL(somme),so);
}


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
GtkWidget*Calcul;
Calcul=lookup_widget(button,"Calcul");
gtk_widget_destroy(Calcul);
}

}



void
on_radiobutton_homme_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
	{choix1[0] = 1;}
else 
{choix1[0] = 0 ;}


}


void
on_radiobutton_femme_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
	{choix1[1] = 1;}
else 
{choix1[1] = 0 ;}

}



void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
choix=1;
}



void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
choix=2;
}



void
on_radiobutton3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
choix=3;
}


void
on_radiobutton4_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
choix=4;
}


void
on_radiobutton5_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
choix=5;
}

