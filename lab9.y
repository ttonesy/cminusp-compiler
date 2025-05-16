/*
    lab9.y

    Antonio Luna
    Lab 9 | CS 370 | YACC
    5/1/2024

    This YACC file specifies the grammar rules and actions for parsing input according 
    to a simple programming language.

    The grammar defines constructs like variable declarations, function declarations, 
    expressions, statements (such as if, while, return, etc.), and their associated 
    behaviors.

    It starts by specifying the starting symbol "Program" and defines various language 
    constructs using BNF-like notation.

    Tokens are defined using declarations such as %token <value> T_NUM, %token <string> 
    T_ID, T_STRING, which are later used in the grammar rules to recognize input 
    patterns.

    The file defines rules for parsing declarations, statements, expressions, 
    arithmetic and logical operations, loops, function calls, and more.

    Each grammar rule is associated with actions, which can include error handling, 
    semantic actions, and debugging statements. These actions are written in C code 
    within the grammar rules.

    Comments are included to enhance code readability and debugging, providing 
    information about the parsed constructs and their corresponding locations in the 
    input.

    Together with the companion lex file (lab5.l), this YACC file forms the basis of 
    a simple compiler for our simple programming language, capable of parsing and 
    analyzing input code according to the specified grammar rules.

    Changelog | 3/25/2024:

    Changes from Lab 5 (2/23/2024) to Lab 6 (3/25/2024):

    1. Added #include "ast.h" to include the Abstract Syntax Tree header for integrating AST construction.
    2. Added %type <node> directives for AST-related non-terminals to specify the type of AST node they generate.
    3. Added %type <d_type> for Type_Specifier and %type <operator> for Addop, Multop, Relop to handle specific AST node types and operators.
    4. Modified SDSA code blocks to create AST nodes and set their attributes based on the parsed input. 
        The AST nodes are created using ASTCreateNode and populated with the necessary information.
    5. Introduced handling for '%', the modulus operator, in the Multop grammar rule.

    Overall, these changes transition the YACC file from merely parsing input to constructing a 
    detailed Abstract Syntax Tree that represents the parsed program.

    Changelog | 4/12/2024:
    
    1. Added symbol table handling for variables and functions, including insertion, search, and deletion operations.
        - Updated the Var_Declaration, Var_List, Fun_Declaration, Param, and Param_List rules to insert variables and parameters into the symbol table.
    2. Added type checking for variable declarations and assignments to ensure consistency in data types.
        - Implemented checks in Var_Declaration and Assignment_Stmt rules to verify the data types of variables and expressions.
        - Added error handling for type mismatches.
        - Usage of check_params function to compare formal and actual parameters in function calls.
    3. Introduced OFFSET and GOFFSET global variables to manage memory allocation for variables and functions.
        - Updated Var_Declaration and Fun_Declaration rules to handle memory allocation based on variable types and function parameters.

    
    Changelog | 5/1/2024:
    
    1. Added A_UNARY support for symbol table implementation.
        - Updated Factor rule to handle unary minus operation.
        - Implemented symbol table insertion for unary operations.
    2. Added main method args -d and -o for debugging and output file name.
        - Modified main function to handle command-line arguments for debugging and output file name.
        - Opened the output file for writing the generated assembly code.
*/



%{
    /* begin specs */
    #include <stdio.h>
    #include <ctype.h>
    #include <stdlib.h>
    #include <string.h>
    #include "ast.h"
    #include "symtable.h"
    #include "emit.h"

    ASTnode *PROGRAM;

    int yylex(); /* prototype for the lexer function */

    extern int lineno; /*line number from LEX*/
    extern int mydebug; /*debugging flag*/

    int LEVEL = 0; /* global context variable for knowing how many levels deep we are in the tree */
    int OFFSET = 0; /* global variable for accumulating needed runtime space */
    int GOFFSET = 0; /* global variable for acuumlating global variable offset */
    int maxOFFSET = 0; /* largest offset needed for the current function */

    void yyerror(char *s) /* Called by yyparse on error */
    {
        /* Print error message */
        printf("YACC PARSE ERROR: %s on line number %d\n", s, lineno);
    }
%}


%start Program


%union {
    int value;
    char *string;
    ASTnode *node;
    enum AST_MY_DATA_TYPE d_type;
    enum AST_OPERATORS operator;
}


%token <value> T_NUM /* token for integer value */
%token <string> T_ID T_STRING /* tokens for identifier, string */
%token T_INT T_VOID T_READ T_IF T_ELSE T_WHILE T_WRITE T_RETURN /* tokens for keywords */
%token T_LT T_GT T_GE T_LE T_EQ T_NE /* tokens for relational operators */


%type <node> Declaration_List Declaration Var_Declaration Var_List
%type <node> Fun_Declaration Params Compound_Stmt Local_Declarations Statement_List 
%type <node> Statement Write_Stmt Expression Simple_Expression Additive_Expression
%type <node> Term Factor Var Call Param_List Param Expression_Stmt Assignment_Stmt
%type <node> Return_Stmt Read_Stmt Args Args_List Selection_Stmt Iteration_Stmt


%type <d_type> Type_Specifier
%type <operator> Addop Multop Relop


%% /* end specs, begin rules */

/*Program Definition*/
Program : Declaration_List  { PROGRAM = $1; /* pass up the declaration list */} 
        ;

/*Declaration List Definition*/
Declaration_List : Declaration  { $$ = $1; }
                 | Declaration Declaration_List 
                        { 
                            $$ = $1;            // set the first declaration
                            $$ -> next = $2;    // link declaration list with the next declaration
                        } 
                        ;

/*Declaration Definition*/
Declaration : Var_Declaration   { $$ = $1; /* pass up the var declaration */}
            | Fun_Declaration   { $$ = $1; /* pass up the fun declaration */} 
            ;

/*Variable Declaration*/
Var_Declaration : Type_Specifier Var_List ';'
                { /* we need to update all elements to the list to the type 
                     needs work */
                     /* Populate the s1 connected list with the 
                        defined type via $1 */
                    ASTnode *p = $2;                                        
                    while( p != NULL)
                    {
                        p->my_data_type = $1;                                               
                        // check each variable in the list to see if it has
                        // been defined at our level
                        if(Search(p->name, LEVEL, 0) != NULL)                               
                        {
                            // symbol already defined -- BARF
                            yyerror(p->name);                                             
                            yyerror("Symbol already defined");
                            exit(1);
                        }
                        // it was not in the table

                        if (p->value == 0)
                        {
                            // we have a scalar
                            p->symbol = Insert(p->name, p->my_data_type, SYM_SCALAR, LEVEL, 1, OFFSET);             // insert the variable into the symbol table
                            OFFSET = OFFSET + 1;                                                                    // increment the offset by 1
                        }
                        else 
                        {
                            p->symbol = Insert(p->name, p->my_data_type, SYM_ARRAY, LEVEL, p->value, OFFSET);       // insert the array into the symbol table
                            OFFSET = OFFSET + p->value;                                                             // increment the offset by the size of the array
                        }               
                        p = p->s1;                                                                                  // move to the next variable in the list
                    }

                    $$ = $2;                                                                                        // pass up the var list
                } 
                ;

/*Variable List Definition*/
Var_List : T_ID         
            { 
                $$ = ASTCreateNode(A_VARDEC);   // create a new node
                $$->name = $1;                  // set the name
            }
         | T_ID '[' T_NUM ']' 
            {
                $$ = ASTCreateNode(A_VARDEC);   // create a new node
                $$ -> name = $1;                // set the name    
                $$ -> value = $3;               // set the value
            }
         | T_ID ',' Var_List
            { 
                $$ = ASTCreateNode(A_VARDEC);   // create a new node
                $$ -> name = $1;                // set the name
                $$->s1 = $3;                    // link var list with the next var
            }
         | T_ID '[' T_NUM ']' ',' Var_List  
            {
                $$ = ASTCreateNode(A_VARDEC);   // create a new node
                $$ -> name = $1;                // set the name
                $$ -> value = $3;               // set the value
                $$ -> s1 = $6;                  // link var list with the next var
            } 
            ;

/*Types Specifiers*/
Type_Specifier : T_INT  { $$ = A_INTTYPE; }
               | T_VOID { $$ = A_VOIDTYPE; } ; /* Type specifier */

/*Function Declaration*/
Fun_Declaration : Type_Specifier T_ID 
                    {
                        // check to see if function has been defined
                        if(Search($2, LEVEL, 0) != NULL)
                        {
                            // id has already been used -- BARF
                            yyerror($2);
                            yyerror("Function name already in use");
                            exit(1);
                        } else {
                        // not in symbol table -- install it
                            Insert($2, $1, SYM_FUNCTION, LEVEL, 0,0);
                            GOFFSET = OFFSET;
                            OFFSET = 2;
                            maxOFFSET = OFFSET;
                        }
                    }
                    '(' Params ')'
                    {
                        Search($2, LEVEL, 0) -> fparms = $5;
                    }
                    
                    Compound_Stmt 
                    {
                        $$ = ASTCreateNode(A_FUNCTIONDEC);      // create a new node
                        $$ -> name = $2;                        // set the name
                        $$ -> my_data_type = $1;                // set the type
                        $$ -> s1 = $5;                          // set the params
                        $$ -> s2 = $8;                 
                        $$ -> symbol = Search($2, LEVEL, 0);         
                    
                        Search($2, LEVEL, 0) -> offset = maxOFFSET;         // Set the function's offset to max used in function
                        OFFSET = GOFFSET;                                   // resets the offset for global variable
                    }
                  ;

/*Function Parameters*/ 
Params : T_VOID { $$ = NULL; }
        | Param_List { $$ = $1; /* pass up the param list */ } 
        ;
        
/*Function Parameters List*/
Param_List : Param  { $$ = $1; }
           | Param ',' Param_List 
                    {
                        $$ = $1;            // set the first param
                        $$ -> next = $3;    // link param list with the next param
                    }
                    ;

/*Function Parameter*/
Param : Type_Specifier T_ID
            {
                if(Search($2, LEVEL + 1, 0) != NULL)                    // check if the parameter has already been used
                {
                    yyerror($2);                                        // print the error message
                    yyerror("Parameter already used");
                    exit(1);
                }

                $$ = ASTCreateNode(A_PARAM);    // create a new node
                $$ -> my_data_type = $1;        // set the type
                $$ -> name = $2;                // set the name
                $$ -> value = 0;                // set the value to 0 for array distinction
                $$ -> symbol = Insert($$->name, $$->my_data_type, SYM_SCALAR, LEVEL+1, 1, OFFSET);   // insert the parameter into the symbol table  

                OFFSET = OFFSET + 1;
            }
      | Type_Specifier T_ID '[' ']'
            {
                if(Search($2, LEVEL + 1, 0) != NULL)                // check if the parameter has already been used
                {
                    yyerror($2);                                    // print the error message
                    yyerror("Parameter already used");
                    exit(1);
                }
                $$ = ASTCreateNode(A_PARAM);    // create a new node
                $$ -> my_data_type = $1;        // set the type        
                $$ -> name = $2;                // set the name
                $$ -> value = 1;                // set the value to 1 for array distinction
                $$ -> symbol = Insert($$->name, $$->my_data_type, SYM_ARRAY, LEVEL+1, 1, OFFSET);
                OFFSET = OFFSET + 1;
            } 
            ;

/*Compound Statement*/
Compound_Stmt : '{' { LEVEL++; }
                    Local_Declarations Statement_List '}'
                    { 
                        $$ = ASTCreateNode(A_COMPOUND);     // create a new node
                        $$ -> s1 = $3;                      // set the local declarations
                        $$ -> s2 = $4;                      // set the statement list      
                        if(mydebug) Display();
                        // set the maxOFFSET
                        if (OFFSET > maxOFFSET) maxOFFSET = OFFSET;
                        OFFSET -= Delete(LEVEL);
                        LEVEL--;                      
                    }
                    ;

/*Local Declarations*/
Local_Declarations : /* empty */ { $$ = NULL; }
                   | Var_Declaration Local_Declarations
                   {
                        $$ = $1;            // set the first var declaration
                        $$ -> next = $2;   // link var declaration with the next var declaration
                   }
                   ;

/*Statement List*/
Statement_List : /* empty */ { $$ = NULL; }
               | Statement Statement_List 
               {
                    $$ = $1;            // set the first statement
                    $$ -> next = $2;    // link statement list with the next statement
               }
               ;

/*Statements*/
Statement : // We just pass up the statements
            Expression_Stmt { $$ = $1; }
          | Compound_Stmt   { $$ = $1; }
          | Selection_Stmt  { $$ = $1; }
          | Iteration_Stmt  { $$ = $1; }
          | Assignment_Stmt { $$ = $1; }
          | Return_Stmt     { $$ = $1; } 
          | Read_Stmt       { $$ = $1; }
          | Write_Stmt      { $$ = $1; }
          ;

/*Expression Statement*/
Expression_Stmt : Expression ';'   
                    {
                        $$ = ASTCreateNode(A_EXPRSTMT);     // create a new node
                        $$ -> s1 = $1;                      // set the expression
                    }
                 | ';' 
                    {
                        $$ = ASTCreateNode(A_EXPRSTMT);     // create a new node
                        $$ -> s1 = NULL;                    // set the expression to NULL for empty statement
                    } 
                    ;

/*If-Else Statement*/
Selection_Stmt : T_IF '(' Expression ')' Statement
                {
                    // create two nodes, to have enough children for the if-else statement
                    // the first node will have the expression and the if statement
                    // s2 will point to the second node, which will have the else statement
                    // s2 will be null if there is no else statement
                    $$ = ASTCreateNode(A_IF);           
                    $$ -> s1 = $3;                      
                    $$ -> s2 = ASTCreateNode(A_IF);     
                    $$ -> s2 -> s1 = $5;                
                    $$ -> s2 -> s2 = NULL;              
                }
               | T_IF '(' Expression ')' Statement T_ELSE Statement 
                {
                    $$ = ASTCreateNode(A_IF);   
                    $$ -> s1 = $3;                      
                    $$ -> s2 = ASTCreateNode(A_IF);     
                    $$ -> s2 -> s1 = $5;                
                    $$ -> s2 -> s2 = $7;                
                }
               ;

/*While loop*/
Iteration_Stmt : T_WHILE '(' Expression ')' Statement 
                {
                    $$ = ASTCreateNode(A_WHILE);    // create a new node
                    $$ -> s1 = $3;                  // set the expression
                    $$ -> s2 = $5;                  // set the statement
                }
                ;

/*Return Statement*/
Return_Stmt : T_RETURN ';'
            {
                $$ = ASTCreateNode(A_RETURN);       // create a new node
                $$ -> s1 = NULL;                    // set the expression to NULL for empty return
            }
            | T_RETURN Expression ';'               
            {
                $$ = ASTCreateNode(A_RETURN);       // create a new node
                $$ -> s1 = $2;                      // set the expression
            } 
            ;

/*Read Statement*/
Read_Stmt : T_READ Var ';' 
            {
                $$ = ASTCreateNode(A_READ);         // create a new node
                $$ -> s1 = $2;                      // set the variable
            } 
            ;

/*Write Statement*/
Write_Stmt : T_WRITE T_STRING ';' 
            {
                $$ = ASTCreateNode(A_WRITE);        // create a new node
                $$ -> name = $2;                    // set the string
                //$$ -> label = CreateLabel();        /* trying */
            }
           | T_WRITE Expression ';'
            {
                $$ = ASTCreateNode(A_WRITE);        // create a new node
                $$ -> s1 = $2;                      // set the expression
            } 
            ;

/*Assignment Statement*/
Assignment_Stmt : Var '=' Simple_Expression ';' 
                {
                    if ($1 -> my_data_type != $3 -> my_data_type)
                    {
                        yyerror("Type mismatch in assignment");
                        exit(1);
                    }
                    $$ = ASTCreateNode(A_ASSIGNMENT);       // create a new node    
                    $$ -> s1 = $1;                          // set the variable
                    $$ -> s2 = $3;                          // set the expression
                    $$ -> name = CreateTemp();
                    $$ -> symbol = Insert($$ -> name, $1 -> my_data_type, SYM_SCALAR,           
                    LEVEL, 1, OFFSET);                                                         

                    OFFSET = OFFSET + 1;
                } 
                ;

/*Variable or Variable Array*/
Var : T_ID 
        {
            struct SymbTab *p;
            p = Search($1, LEVEL, 1);
            if(p == NULL)
            {
                // reference variable not in symbol table
                yyerror($1);
                yyerror("Symbol used but not defined");
                exit(1);
            }
            if(p->SubType != SYM_SCALAR)
            {
                // a reference to a non SCALAR variable
                yyerror($1);
                yyerror("Symbol must be a SCALAR");
            }                
            $$ = ASTCreateNode(A_VAR);      // create a new node
            $$ -> name = $1;                // set the name
            $$ -> symbol = p;
            $$ -> my_data_type = p -> Declared_Type;
        }
    | T_ID '[' Expression ']' 
        { 
            struct SymbTab *p;
            p = Search($1, LEVEL, 1);
            if(p == NULL)                                           // check if the variable is in the symbol table
            {
                yyerror($1);
                yyerror("Symbol used but not defined");
                exit(1);
            }
            if(p->SubType != SYM_ARRAY)                             // check if the variable is an array
            {
                //A reference to a non scalar variable 
                yyerror($1);
                yyerror("Symbol must be a ARRAY"); 
                exit(1);
            }  
            $$ = ASTCreateNode(A_VAR);      // create a new node
            $$ -> name = $1;                // set the name
            $$ -> s1 = $3;                  // set the expression
            $$ -> symbol = p;               // i think this is right
            $$ -> my_data_type = p -> Declared_Type;

        } 
        ;

/*Expression*/
Expression : Simple_Expression { $$ = $1; } ;

/*Simple Expression*/
Simple_Expression : Additive_Expression { $$ = $1; }
                  | Additive_Expression Relop Additive_Expression
                    {
                        if($1 -> my_data_type != $3 -> my_data_type)    // check if the data types match
                        {
                            yyerror("type mismatch");                   // print the error message
                            exit(1);
                        }
                        $$ = ASTCreateNode(A_EXPR);     // create a new node
                        $$ -> s1 = $1;                  // set the first additive expression
                        $$ -> s2 = $3;                  // set the second additive expression
                        $$ -> operator = $2;            // set the operator
                        $$ -> name = CreateTemp();
                        $$ -> symbol = Insert($$ -> name, $1 -> my_data_type, SYM_SCALAR, 
                        LEVEL, 1, OFFSET);

                        $$ -> my_data_type = $1 -> my_data_type;        // set the data type

                        OFFSET = OFFSET + 1;
                    } 
                    ;

/*Relational Operators*/
Relop : // We just pass up the operator
        T_LT { $$ = A_LT; }
      | T_GT { $$ = A_GT; }
      | T_GE { $$ = A_GE; }
      | T_LE { $$ = A_LE; }
      | T_EQ { $$ = A_EQ; }
      | T_NE { $$ = A_NE; }
      ;

/*Additive Expression*/
Additive_Expression : Term { $$ = $1; }
                    | Additive_Expression Addop Term
                        {
                        if ($1 -> my_data_type != $3 -> my_data_type)       // check if the data types match
                        {
                            yyerror("Type mismatch");                       // print the error message
                            exit(1);
                        }
                            $$ = ASTCreateNode(A_EXPR);     // create a new node
                            $$ -> s1 = $1;                  // set the additive expression
                            $$ -> s2 = $3;                  // set the term
                            $$ -> operator = $2;            // set the operator
                            $$ -> name = CreateTemp();
                            $$ -> symbol = Insert($$->name, $1->my_data_type, SYM_SCALAR, 
                            LEVEL, 1, OFFSET);

                            OFFSET = OFFSET + 1;
                        } 
                        ;

/*Addition and Subtraction Operators*/
Addop : '+' { $$ = A_PLUS; }
      | '-' { $$ = A_MINUS; } 
      ;

/*Term*/
Term : Factor { $$ = $1; }
     | Term Multop Factor
        {
            if($1 -> my_data_type != $3 -> my_data_type)            // check if the data types match
            {
                yyerror("Type mismatch");
                exit(1);
            }
            $$ = ASTCreateNode(A_EXPR);     // create a new node
            $$ -> s1 = $1;                  // set the term
            $$ -> s2 = $3;                  // set the factor
            $$ -> operator = $2;            // set the operator

            $$ -> name = CreateTemp();
            $$ -> symbol = Insert($$ -> name, $1 -> my_data_type, SYM_SCALAR, 
            LEVEL, 1, OFFSET);
            OFFSET = OFFSET + 1;
        } 
     ;

/*Multiplication and Division Operators*/
Multop : '*'    { $$ = A_MULT; }
       | '/'    { $$ = A_DIV; } 
       | '%'    { $$ = A_MOD; }
       ;

/*Factor*/
Factor : '(' Expression ')' { $$ = $2; }
       | T_NUM              { 
                                $$ = ASTCreateNode(A_NUM);   // create a new node
                                $$ -> value = $1;            // set the value
                                $$ -> my_data_type = A_INTTYPE;
                            }
       | Var                { $$ = $1; }
       | Call               { $$ = $1; }
       | '-' Factor       
                            {
                                if($2 -> my_data_type != A_INTTYPE)
                                {
                                    yyerror("Type mismatch unary minus");
                                    exit(1);
                                }
                                $$ = ASTCreateNode(A_EXPR);     // create a new node
                                $$ -> s1 = $2;                  // set the factor
                                $$ -> operator = A_UNARY;       // set the operator to unary for ASTprint
                                $$ -> name = CreateTemp();
                                $$ -> my_data_type = A_INTTYPE;
                                $$ -> symbol = Insert($$ -> name, $2 -> my_data_type, SYM_SCALAR, LEVEL, 1, OFFSET);
                                OFFSET = OFFSET + 1;
                            } 
       ;  
 /*Function Call*/
Call : T_ID '(' Args ')' 
    {
        struct SymbTab *p;
        p = Search($1, 0, 0);

        if(p == NULL)                                   // check if the function name is known
        {
            //function name not known
            yyerror($1);
            yyerror("Function name not defined");
            exit(1);
        } 
        // name is there but is it a function?
        if(p->SubType != SYM_FUNCTION)
        {
            yyerror($1);
            yyerror("is not defined as a function");
            exit(1);
        }
        // check to see that the formal and actual parameters are same
        // length and type
        if(check_params($3, p->fparms) == 0) 
        {
            yyerror($1);
            yyerror("Actual and formals do not match");
            exit(1);
        }

        $$ = ASTCreateNode(A_CALL);     // create a new node
        $$ -> name = $1;                // set the name
        $$ -> s1 = $3;                  // set the arguments
        $$ -> symbol = p;
        $$ -> my_data_type = p -> Declared_Type;
    } 
    ;

/*Function Arguments*/
Args : Args_List 
        {
            $$ = $1;    // pass up the arguments list
        }
     | /* empty */ 
        {
            $$ = NULL;  // set the arguments to NULL for empty arguments
        } 
        ;


/*Function Arguments List*/
Args_List : Expression 
            {
                $$ = ASTCreateNode(A_ARG);      // create a new node
                $$ -> s1 =  $1;                 // set the expression
                $$ -> my_data_type = $1 -> my_data_type;            // set the data type
                $$ -> name = CreateTemp();                          
                $$ -> symbol = Insert($$-> name, $1 -> my_data_type, SYM_SCALAR, LEVEL, 1, OFFSET);
                OFFSET = OFFSET + 1;
            }
          | Expression ',' Args_List
            {
                $$ = ASTCreateNode(A_ARG);      // create a new node
                $$ -> s1 = $1;                  // set the expression
                $$ -> next = $3;                // link the arguments list with the next argument
                $$ -> my_data_type = $1 -> my_data_type;
                $$ -> name = CreateTemp();
                $$ -> symbol = Insert($$ -> name, $1 -> my_data_type, SYM_SCALAR, LEVEL, 1, OFFSET);
                OFFSET = OFFSET + 1;
            } 
            ;

%%

int main(int argc, char **argv) {
    FILE *fp;
    // read our input arguments
    int i;
    char s[100];
    // option -d turn on debug
    // option -o next argument is output file name
    for(i = 0; i < argc; i++)
    {
        if (strcmp(argv[i], "-d") == 0) mydebug = 1;
        if (strcmp(argv[i], "-o") == 0)
        {
            // we have a file input
            strcpy(s, argv[i+1]);
            strcat(s, ".asm");
        }
    }

    // now open the file that is referenced by s
    fp = fopen(s, "w");
    if (fp == NULL)
    {
        printf("Cannot open file %s\n", s);
        exit(1);
    }

    yyparse();
    if(mydebug) printf("\n\n\nFinished Parsing\n\n\n");
    // we know that global variable PROGRAM has a PTR to the top of the tree
    if(mydebug) Display();              // shows our global variables and functions
    if(mydebug) printf("\n\nAST PRINT\n\n");
    if(mydebug) ASTprint(0,PROGRAM);
    EMIT(PROGRAM, fp);  
}
