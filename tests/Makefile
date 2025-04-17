SHELL = /bin/bash

srcdir = .
top_srcdir = ..
top_builddir = ..
builddir = .
prefix = /usr/local

CXX = g++
CXXFLAGS = -g -O2
CPPFLAGS = 
DEFS = -DPACKAGE_NAME=\"DevOps\" -DPACKAGE_TARNAME=\"devops\" -DPACKAGE_VERSION=\"1.0\" -DPACKAGE_STRING=\"DevOps\ 1.0\" -DPACKAGE_BUGREPORT=\"\" -DPACKAGE_URL=\"\" -DPACKAGE=\"devops\" -DVERSION=\"1.0\"
LDFLAGS = 
LIBS = 

check_PROGRAMS = taylorSineTest1 taylorSineTest2 taylorSineTest3 taylorSineTest4
TESTS = $(check_PROGRAMS)

SRC_COMMON = $(top_builddir)/FuncA.cpp $(top_builddir)/FuncA.h

taylorSineTest1_SOURCES = taylorSineTest1.cpp $(SRC_COMMON)
taylorSineTest2_SOURCES = taylorSineTest2.cpp $(SRC_COMMON)
taylorSineTest3_SOURCES = taylorSineTest3.cpp $(SRC_COMMON)
taylorSineTest4_SOURCES = taylorSineTest4.cpp $(SRC_COMMON)

all: $(check_PROGRAMS)

%: %.cpp $(top_builddir)/FuncA.cpp
	$(CXX) $(CPPFLAGS) $(DEFS) $(CXXFLAGS) -o $@ $^ $(LIBS)
    
check: $(TESTS)
	@echo "Running tests..."
	@./taylorSineTest1
	@./taylorSineTest2
	@./taylorSineTest3
	@./taylorSineTest4

clean:
	rm -f $(check_PROGRAMS) *.o

.PHONY: all check clean
