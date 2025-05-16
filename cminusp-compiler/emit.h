/*
	emit.h

	Antonio Luna
	Lab 9 | CS 370 | YACC
	5/1/2024

	Header file for emit.c
	Provides connection to the AST and the output file

*/

#ifndef EMIT_H
#define EMIT_H
#include "ast.h"

#define WSIZE 4
#define LOG_WSIZE 2


void EMIT(ASTnode* p, FILE* fp);
void EMIT_STRINGS(ASTnode* p, FILE* fp);
void EMIT_AST(ASTnode* p, FILE* fp);
void EMIT_GLOBALS(ASTnode* p, FILE* fp);



#endif