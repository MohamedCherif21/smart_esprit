## Process this file with automake to produce Makefile.in

INCLUDES = \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	@PACKAGE_CFLAGS@

bin_PROGRAMS = technicien

technicien_SOURCES = \
	main.c \
	support.c support.h \
	interface.c interface.h \
	callbacks.c callbacks.h \
	crud.c crud.h \
	tree.c tree.h \
	menu.c menu.h \
	Agent_de_foyer.c fonction.h \
	fonction_fakhri.c fonction_fakhri.h

technicien_LDADD = @PACKAGE_LIBS@ $(INTLLIBS)

