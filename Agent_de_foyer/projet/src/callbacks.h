#include <gtk/gtk.h>


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
