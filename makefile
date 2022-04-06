# Project: repair-del-program
# Makefile created by Red Panda C++ beta.0.13.2

CPP      = g++
CC       = gcc
OBJ      = main.o
LINKOBJ  = main.o
CLEANOBJ  =  main.o
LIBS     =  -L"/usr/include/jsoncpp/json" -fsanitize=address
INCS     =  
CXXINCS  =  
BIN      = repair-del-program
CXXFLAGS = $(CXXINCS)  -Wall -Wextra -g3 -pipe -fsanitize=address -D__DEBUG__
CFLAGS   = $(INCS)  -Wall -Wextra -g3 -pipe -fsanitize=address -D__DEBUG__
RM       = rm -rf

.PHONY: all all-before all-after clean clean-custom

all: all-before $(BIN) all-after

clean: clean-custom
	${RM} $(CLEANOBJ) $(BIN) > NUL 2>&1

$(BIN): $(OBJ)
	$(CPP) $(LINKOBJ) -o $(BIN) $(LIBS)

main.o: main.cpp
	$(CPP) -c /media/gfdgd_xi/4818D9C118D9ADE6/Users/30256/Desktop/repair-del-program/main.cpp -o main.o $(CXXFLAGS)  -finput-charset=UTF-8 -fexec-charset=UTF-8
