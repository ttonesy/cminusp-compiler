/*
   AST.h - Header File for Abstract Syntax Tree Construction

   Antonio Luna
   Lab 7 | CS 370 | ast.h | CMINUS
   4/12/2024

   Description: This header file declares the necessary data structures,
   types, and functions for constructing and manipulating an Abstract Syntax Tree (AST)
   for the CMINUS language.

   Features:
   - Enumerated Types: Defines ASTtype for identifying different kinds of AST nodes
   (e.g., function declarations, variable declarations, expressions),
   AST_OPERATORS for mathematical and logical operators, and AST_MY_DATA_TYPE for data
   types in the language (int, void).
   - AST Node Structure: Defines the ASTnodetype structure, which represents a node
   in the AST. Each node contains information about its type, operator (if applicable),
   variable name (if applicable), value (if applicable), data type, and pointers to
   child or sibling nodes.
*/


#include<stdio.h>
#include<malloc.h>
#include "symtable.h"

#ifndef AST_H
#define AST_H
extern int mydebug;

/* define the enumerated types for the AST.  THis is used to tell us what
sort of production rule we came across */

enum ASTtype {
   A_FUNCTIONDEC,
   A_VARDEC,
   A_WRITE,
   A_COMPOUND,
   A_NUM,
   A_EXPR,
   A_PARAM,
   A_EXPRSTMT,
   A_VAR,
   A_ASSIGNMENT,
   A_RETURN,
   A_READ,
   A_CALL,
   A_ARG,
   A_IF,
   A_WHILE,
   A_UNARY
};

// Math Operators
enum AST_OPERATORS {
   A_PLUS,
   A_MINUS,
   A_MULT,
   A_DIV,
   A_LT,
   A_GT,
   A_LE,
   A_GE,
   A_EQ,
   A_NE,
   A_MOD
};

// Data Types
enum AST_MY_DATA_TYPE {
   A_INTTYPE,
   A_VOIDTYPE
};

/* define a type AST node which will hold pointers to AST structs that will
   allow us to represent the parsed code
*/

typedef struct ASTnodetype
{
   enum ASTtype type;
   enum AST_OPERATORS operator;
   char* name;
   char* label;
   int value;
   enum AST_MY_DATA_TYPE my_data_type;
   struct SymbTab* symbol;
   struct ASTnodetype* s1, * s2, * next; /* used for holding IF and WHILE components -- not very descriptive */
} ASTnode;


/* uses malloc to create an ASTnode and passes back the heap address of the newley created node */
ASTnode* ASTCreateNode(enum ASTtype mytype);

void PT(int howmany);


/*  Print out the abstract syntax tree */
void ASTprint(int level, ASTnode* p);

/* Parameter checking */
int check_params(ASTnode* actuals, ASTnode* formals);


#endif // of AST_H
