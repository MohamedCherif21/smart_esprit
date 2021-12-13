#include<gtk/gtk.h>
typedef struct 
{
char id[30];
char type[30];
char plat[30];
char ing[30];
char date[30];
char dessert[30];
char letype [30];
int nb; 
}nutri ;

void ajouter_nb(nutri A);
void supp_nb(char id[]);
nutri rech_nb(char id[]);
void modi_nb(char id[], nutri U);
void afficher_nb (GtkWidget *treeview1 ,char *l);

