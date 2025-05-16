# Lab9 CS370 Spring 2024
#	Antonio Luna
#	 5/1/2024
#		
#  makefile for LAB9
# To compile the program, type "make"
# To remove the executable file and all object files, type "make clean"


all: lab9

lab9: lab9.l lab9.y ast.c symtable.c emit.c
	lex lab9.l
	yacc -d lab9.y
	gcc -o lab9 lex.yy.c y.tab.c ast.c symtable.c emit.c

clean:
	rm -f lab9 lex.yy.c y.tab.c y.tab.h
