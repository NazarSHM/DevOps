AUTOMAKE_OPTIONS = foreign
SUBDIRS = tests

bin_PROGRAMS = FuncA unit_tests http_server

FuncA_SOURCES = main.cpp FuncA.cpp FuncA.h
unit_tests_SOURCES = tests/test.cpp FuncA.cpp
unit_tests_CXXFLAGS = -Iinclude
http_server_SOURCES = server.cpp FuncA.cpp
http_server_CXXFLAGS = -Iinclude
http_server_LDADD = -lpthread


install-exec-hook:
	mkdir -p $(DESTDIR)/usr/bin
	cp FuncA $(DESTDIR)/usr/bin
