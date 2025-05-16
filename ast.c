/*   Abstract syntax tree code

    This code is used to define an AST node,
    routine for printing out the AST
    defining an enumerated type so we can figure out what we need to
    do with this.  The ENUM is basically going to be every non-terminal
    and terminal in our language.


    ast.c

    Antonio Luna
    Lab 9 | CS 370 | YACC
    5/1/2024

    Changelog | 3/25/2024:

    1. PT Function Implementation: The PT function now prints a specified number of spaces,
       addressing the previously missing implementation.

    2. ASTtypeToString Function: Updated to handle AST_MY_DATA_TYPE, returning "INT" or "VOID"
       for my_data_type with a switch case.

    3. Enhanced ASTprint Function:
        - Added handling for AST node types such as A_VARDEC, A_FUNCTIONDEC, A_COMPOUND, A_WRITE,
          A_NUM, A_EXPR, A_PARAM, A_EXPRSTMT, A_VAR, A_ASSIGNMENT, A_RETURN, A_READ, A_CALL, A_ARG,
          A_IF, and A_WHILE.
        - Introduced functionality for printing detailed information about various node types,
          using ASTtypeToString for type names and detailing array sizes for variable declarations.

    Overall these changes allow us to print out the AST in a more detailed and structured manner,
    providing a better understanding of the AST structure and the nodes within it.

    Changelog | 4/12/2024:

    1. Added check_params Function: This function compares actual and formal parameters to determine
       if they are the same type and length. It returns 0 if they are not the same and 1 if they are.

    Changelog | 5/1/2024:

    1. Added p->label to the ASTnode for label creation in the MIPS code generation.
*/


#include<stdio.h>
#include<malloc.h>
#include "ast.h" 


/* uses malloc to create an ASTnode and passes back the heap address of the newley created node */
//  PRE:  Ast Node Type
//  POST:   PTR To heap memory and ASTnode set and all other pointers set to NULL
ASTnode* ASTCreateNode(enum ASTtype mytype)

{
    ASTnode* p;
    if (mydebug) fprintf(stderr, "Creating AST Node \n");
    p = (ASTnode*)malloc(sizeof(ASTnode));
    p->type = mytype;
    p->s1 = NULL;
    p->s2 = NULL;
    p->next = NULL;
    p->label = NULL;
    p->value = 0;
    return(p);
}

/*  Helper function to print tabbing */
//PRE:  Number of spaces desired
//POST:  Number of spaces printed on standard output

void PT(int howmany)
{
    // print howmany spaces
    for (int i = 0; i < howmany; i++) {
        printf(" ");
    }
}

//  PRE:  A declaration type
//  POST:  A character string that is the name of the type
//          Typically used in formatted printing
char* ASTtypeToString(enum AST_MY_DATA_TYPE mytype)
{
    /*missing
     switch case statement to return int or void based on my_data_type*/
    switch (mytype)
    {
    case A_INTTYPE: return "INT";
        break;

    case A_VOIDTYPE: return "VOID";
        break;

    }

}

/*  Print out the abstract syntax tree */
// PRE:   PTR to an ASTtree
// POST:  indented output using AST order printing with indentation

void ASTprint(int level, ASTnode* p)
{
    int i;
    if (p == NULL) return;

    switch (p->type) {

    case A_VARDEC:
        // Check if there is a value associated with the variable
        // If there is a value, we have an array
        if (p->value > 0)
        {
            PT(level); printf("Variable %s %s [%d] level %d offset %d", ASTtypeToString(p->my_data_type), p->name,
                p->value, p->symbol->level, p->symbol->offset);
            printf("\n");
            ASTprint(level, p->s1);
            ASTprint(level, p->next);
        }
        else {
            PT(level); printf("Variable %s %s level %d offset %d", ASTtypeToString(p->my_data_type), p->name,
                p->symbol->level, p->symbol->offset);
            printf("\n");
            ASTprint(level, p->s1);
            ASTprint(level, p->next);
        }
        break;

        // Variable declaration
    case A_FUNCTIONDEC:
        PT(level); printf(" Function %s %s level %d offset %d", ASTtypeToString(p->my_data_type), p->name,
            p->symbol->level, p->symbol->offset);
        printf("\n");

        if (p->s1 != NULL) //check if there are parameters
        {
            PT(level);
            ASTprint(level + 2, p->s1);
        }
        ASTprint(level + 2, p->s2); // compound
        ASTprint(level, p->next); // next function
        break;

        // Compound statement
    case A_COMPOUND:
        PT(level); printf("Compound Statement\n");
        ASTprint(level + 1, p->s1); // local decs
        ASTprint(level + 1, p->s2); // statement list
        ASTprint(level, p->next);
        break;

        // Write statement
    case A_WRITE:
        PT(level);
        if (p->name != NULL)
        {
            printf("Write String %s\n", p->name);
            // we know its a write string
        }
        else
        {
            // it is an expression
            printf("Write Expression\n");
            ASTprint(level + 1, p->s1);
        }
        ASTprint(level, p->next);
        break;

        // Number value
    case A_NUM:
        PT(level);
        printf("NUMBER value %d \n", p->value);
        break;

        // Expression operator (e.g. +, -, *, /, %, <, >, <=, >=, ==, !=)
    case A_EXPR:
        PT(level);
        printf("EXPRESSION operator ");
        switch (p->operator)
        {
        case A_PLUS:
            printf("+ \n");
            break;
        case A_MINUS:
            printf("- \n");
            break;
        case A_MULT:
            printf("* \n");
            break;
        case A_DIV:
            printf("/ \n");
            break;
        case A_MOD:
            printf("%% \n");
            break;
        case A_LT:
            printf("< \n");
            break;
        case A_GT:
            printf("> \n");
            break;
        case A_LE:
            printf("<= \n");
            break;
        case A_GE:
            printf(">= \n");
            break;
        case A_EQ:
            printf("== \n");
            break;
        case A_NE:
            printf("!= \n");
            break;
        case A_UNARY:
            printf("Unary-Minus\n");
            break;

        default:
            printf("Unknown operator in A_EXPR in ASTprint");
            break;
        }
        ASTprint(level + 1, p->s1);
        ASTprint(level + 1, p->s2);
        break;

        // Function parameter
    case A_PARAM:
        PT(level);
        printf("Parameter: %s %s", ASTtypeToString(p->my_data_type), p->name);
        // Check if the parameter is marked as an array
        if (p->value != 0)
        {
            printf("[]"); // Indicate that this parameter is an array
        }
        printf(" level %d offset %d\n", p->symbol->level, p->symbol->offset);
        // Recursively print the next parameter, if any
        if (p->next != NULL)
        {
            ASTprint(level, p->next);
        }
        break;

        // Expression statement
    case A_EXPRSTMT:
        PT(level);
        printf("EXPRESSION Statement\n");
        ASTprint(level + 1, p->s1); // Print the expression
        ASTprint(level, p->next); // Continue printing statements in the list
        break;

        // Variable and Variable Array
    case A_VAR:
        PT(level);
        // Check if the variable is an array
        if (p->s1 == NULL)
        {
            printf("VARIABLE %s level %d offset %d\n", p->name, p->symbol->level, p->symbol->offset);
            ASTprint(level + 1, p->s1);
        }
        // If the variable is an array, print the array size
        else
        {
            printf("VARIABLE %s level %d offset %d\n", p->name, p->symbol->level, p->symbol->offset);
            PT(level + 1);
            printf("[\n");
            ASTprint(level + 2, p->s1);
            PT(level + 1);
            printf("]\n");
        }
        break;

        // Assignment statement
    case A_ASSIGNMENT:
        PT(level);
        printf("ASSIGNMENT Statement\n");
        ASTprint(level + 1, p->s1);
        PT(level);
        printf("is assigned \n");
        ASTprint(level + 1, p->s2);
        ASTprint(level, p->next);
        break;

        // Return statement
    case A_RETURN:
        PT(level);
        printf("RETURN Statement\n");
        // Print the return value if it exists
        if (p->s1 != NULL)
        {
            printf(" ");
            ASTprint(level + 1, p->s1); // Only print s1 if it exists
        }
        ASTprint(level, p->next); // Continue printing statements in the list
        break;

        // Read statement
    case A_READ:
        PT(level);
        printf("READ Statement\n");
        ASTprint(level + 1, p->s1);
        ASTprint(level, p->next);
        break;

        // Function call
    case A_CALL:
        PT(level);
        printf("CALL Statement function %s\n", p->name);
        PT(level + 1);
        printf("(\n");
        ASTprint(level + 2, p->s1);
        PT(level + 1);
        printf(")\n");
        break;

        // Function argument
    case A_ARG:
        PT(level);
        printf("CALL Argument \n");
        ASTprint(level + 1, p->s1);
        ASTprint(level, p->next);
        break;

        // If and If-Else statement
    case A_IF:
        PT(level);
        printf("IF Statement\n");

        // Check if there is an expression
        if (p->s1 != NULL)
        {
            PT(level + 1);
            printf("IF Expression\n");
            ASTprint(level + 2, p->s1);
        }
        // Check if there is an IF body
        if (p->s2->s1 != NULL)
        {
            PT(level + 1);
            printf("IF Body\n");
            ASTprint(level + 2, p->s2->s1);
        }
        // Check if there is an ELSE body
        if (p->s2->s2 != NULL)
        {
            PT(level + 1);
            printf("ELSE Body\n");
            ASTprint(level + 2, p->s2->s2);
        }
        ASTprint(level, p->next);
        break;

        // While statement
    case A_WHILE:
        PT(level);
        printf("WHILE Statement\n");

        // Check if there is an expression
        if (p->s1 != NULL)
        {
            PT(level + 1);
            printf("WHILE Expression\n");
            ASTprint(level + 2, p->s1);
        }
        // Check if there is a body
        if (p->s2 != NULL)
        {
            PT(level + 1);
            printf("WHILE Body\n");
            ASTprint(level + 2, p->s2);
        }
        ASTprint(level, p->next);
        break;

        // error handling
    default: printf("unknown AST Node type %d in ASTprint\n", p->type);


    } // end of switch

} // end of ASTprint

// PRE: PTRS to actual and formals
// POST: 0 if they are not the same type or length
//      1 if they are

int check_params(ASTnode* actuals, ASTnode* formals)
{
    if (actuals == NULL && formals == NULL) return 1;

    if (actuals == NULL || formals == NULL) return 0;

    if (actuals->my_data_type != formals->my_data_type) return 0;

    return check_params(actuals->next, formals->next);
}


/* dummy main program so I can compile for syntax error independently
main()
{
}
/* */
