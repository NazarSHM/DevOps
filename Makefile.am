AUTOMAKE_OPTIONS = foreign
SUBDIRS = tests

bin_PROGRAMS = FuncA
FuncA_SOURCES = main.cpp FuncA.cpp FuncA.h

install-exec-hook:
	mkdir -p $(DESTDIR)/usr/bin
	cp FuncA $(DESTDIR)/usr/bin
