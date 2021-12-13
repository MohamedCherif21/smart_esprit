/*
 * Initial main.c file generated by Glade. Edit as required.
 * Glade will not overwrite this file.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "interface.h"
#include "support.h"
#include  "fonction.h"
#include "callbacks.h"

int
main (int argc, char *argv[])
{
  GtkWidget *Ajouter_Etudiant,*Gestion_des_Etudiants,*Modifier_Etudiant,*treeview,*button;

#ifdef ENABLE_NLS
  bindtextdomain (GETTEXT_PACKAGE, PACKAGE_LOCALE_DIR);
  bind_textdomain_codeset (GETTEXT_PACKAGE, "UTF-8");
  textdomain (GETTEXT_PACKAGE);
#endif

  gtk_set_locale ();
  gtk_init (&argc, &argv);

  add_pixmap_directory ("../pixmaps");

  /*
   * The following code was added by Glade to create one of each component
   * (except popup menus), just so that you see something after building
   * the project. Delete any components that you don't want shown initially.
   */
  Gestion_des_Etudiants = create_Gestion_des_Etudiants ();
  gtk_widget_show (Gestion_des_Etudiants);
  

  gtk_main ();
  return 0;
}

