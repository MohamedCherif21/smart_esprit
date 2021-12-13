#include <gtk/gtk.h>

typedef struct capteur capteur;
struct capteur{
char ref[30];
char type[30];
char constructeur[30];
char dateAjout[30];
char bloc[30];
int valMax;
int valMin;
int valInit;
int etage;
};

typedef struct debit debit;
struct debit{
int jour;
int heure;
int numCapteu;
float valeurDebit;
};


typedef struct temp temp;
struct temp{
int jour;
int heure;
int numCapteu;
float valeurTemp;
};

typedef struct FUMEE FUMEE;
struct FUMEE{
int jour;
int heure;
int numCapteu;
int etatF;
};

typedef struct MOUV MOUV;
struct MOUV{
int jour;
int heure;
int numCapteu;
int etatM;
};

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

int i,j,w,v,z;

GtkWidget *acceuil;
  GtkWidget *gestion_Capteur;
  GtkWidget *catalogue;
GtkWidget *etages_contenant_des_pannes;
GtkWidget *capteurs_defectueux;
GtkWidget *liste_des_alarmes;
GtkWidget *window_verif_supp;
GtkWidget *window_acceuil;
GtkWidget *LOGIN;
GtkWidget *Gestion_des_Etudiant;
GtkWidget *Gestion_Restau;





void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_AcceuiCatalogue_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_catalogue_Acceuil_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_button2_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_AjouterCapteur_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_SupprimerCapteur_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_ModifierCapteur_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_button3_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_chercherCapteur_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton4_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button_pannes_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_alarmes_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_capteurs_defectueux_clicked  (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_capteurDef_acceuil_clicked   (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_etagePanne_acceuil_clicked   (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_alarmes_acceuil_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_button33_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button35_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button34_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeviewkhouloud_row_activated      (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

//khloud

void
on_affi_mo_clicked                     (GtkWidget       *button,
                                        gpointer         user_data);

void
on_actu_mo_clicked                     (GtkWidget       *button,
                                        gpointer         user_data);

void
on_rech_mo_clicked                     (GtkWidget       *button,
                                        gpointer         user_data);

void
on_Modif_mo_clicked                     (GtkWidget       *button,
                                        gpointer         user_data);

void
on_ajout_mo_clicked                     (GtkWidget       *button,
                                        gpointer         user_data);
void
on_supp_mo_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_supp_tree_mo_clicked                (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_auth_youtube_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_auth_facebook_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_auth_instagram_clicked              (GtkButton       *button,
                                        gpointer         user_data);
void
on_checkbutton2MO_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton1MO_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_ok_mo_clicked                       (GtkWidget       *button,
                                        gpointer         user_data);

void
on_radiobutton1MO_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton2MO_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);


void
on_FacebookMO_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_youtubeMO_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_InstagramMO_clicked                   (GtkButton       *button,
                                        gpointer         user_data);


void
on_checkbutton4MO_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton3MO_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton4MO_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton3MO_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

//////////////////////////////////////////////


void
on_button_ajouter_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_ajouter_tab_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_modifier_tab_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_return_ajouter_clicked       (GtkButton       *button,
                                        gpointer         user_data);



void
on_button_return_modifier_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_modifier_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_chercher_tab_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_checkbutton_nom_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton_prenom_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton_niveau_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton_chambre_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton_tel_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button_affich_tab_clicked           (GtkWidget       *button,
                                        gpointer         user_data);

void
on_treeview_row_activated              (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_button_supprim_tab_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview_columns_changed            (GtkTreeView     *treeview,
                                        gpointer         user_data);

void
on_radiobutton_modif1_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_modif2_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_modif4_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_modif5_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_modif3_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button_modif_enregistrer_clicked    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_modif_enregistrer_clicked    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_calcul_tab_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_checkbutton_calcul_1_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton_calcul_3_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton_calcul_4_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton_calcul_2_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton_calcul_5_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button_calcul_sum_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_retour_calcul_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_oui_supprimer_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_nom_supprimer_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_label_supprimer_set_move_cursor     (GtkLabel        *label,
                                        gpointer         user_data);

void
on_radiobutton_cher_chambre_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_cher_cin_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_cher_nom_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button_retour_home_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton_homme_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_femme_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton4_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton5_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);


void
on_radiobutton_hamma_homme_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_hamma_femme_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_hamma_chambre_toggled   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_hamma_cin_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_hamma1_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_hamma2_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_hamma3_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_hamma4_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_hamma5_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_modifH_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_modifF_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton1_ajout_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton2_ajout_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);
//////////////////


void on_button_ok_clicked                   (GtkWidget       *button,
                                        gpointer         user_data);

void on_button_gosupp_clicked               (GtkWidget       *button,
                                        gpointer         user_data);

void on_button_gomodif_clicked              (GtkWidget       *button,
                                        gpointer         user_data);

void on_button_gorech_clicked               (GtkWidget       *button,
                                        gpointer         user_data);

void on_button_goajout_clicked              (GtkWidget       *button,
                                        gpointer         user_data);

void on_button_affich_clicked               (GtkWidget       *button,
                                        gpointer         user_data);

void on_Home_ajout_clicked                  (GtkWidget       *button,
                                        gpointer         user_data);



void on_radiobutton1_ajout_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void on_radiobutton2_ajout_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void on_button_homesupp_clicked             (GtkWidget       *button,
                                        gpointer         user_data);

void on_button_supp_clicked                 (GtkWidget       *button,
                                        gpointer         user_data);

void on_button_homerech_clicked             (GtkWidget       *button,
                                        gpointer         user_data);

void on_button_aff_clicked                  (GtkWidget       *button,
                                        gpointer         user_data);

void on_button_homemodif_clicked            (GtkWidget       *button,
                                        gpointer         user_data);

void on_button_modif_clicked                (GtkWidget       *button,
                                        gpointer         user_data);

void on_checkbutton_n_toggled               (GtkToggleButton *togglebutton,
                                             gpointer         user_data);

void on_checkbutton_t_toggled               (GtkToggleButton *togglebutton,
                                             gpointer         user_data);

void on_checkbutton_s_toggled               (GtkToggleButton *togglebutton,
                                      	     gpointer         user_data);

void on_checkbutton_r_toggled               (GtkToggleButton *togglebutton,
                                             gpointer         user_data);

void on_checkbutton_u_toggled               (GtkToggleButton *togglebutton,
                                             gpointer         user_data);

void on_checkbutton_p_toggled               (GtkToggleButton *togglebutton,
                                             gpointer         user_data);

void on_radiobutton_modifF_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void on_radiobutton_modifH_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button_ajouter2_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_button37_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button38_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button39_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button40_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button41_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button42_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button43_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button44_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button45_clicked                    (GtkButton       *button,
                                        gpointer         user_data);
