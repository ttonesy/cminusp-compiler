/*   
    Antonio Luna
    Lab 7 | CS 370 | LEX
    4/12/2024

    This LEX file defines a set of rules for tokenizing input for a simple compiler.
    It serves as a lexical analyzer for the companion yacc (lab5.y) routine, which
    constructs a basic compiler.

    The tokens recognized include keywords like int, void, if, else, while, return, 
    along with symbols such as arithmetic operators (+, -, *, /), comparison operators 
    (==, !=, <, >, <=, >=), parentheses, brackets, braces, commas, semicolons, and 
    string literals.

    Each token is associated with a corresponding token type, such as T_INT, T_VOID, 
    T_IF, T_ELSE, etc. When a token is matched, its type is returned.

    Additionally, this file handles numeric constants, identifiers (variables), and 
    string literals, providing appropriate handling for each.

    Comments starting with "//" are ignored.

    lineno is used to keep track of the current line number for error reporting.

    The associated yacc file (lab5.y) utilizes these tokens and their types to parse
    and analyze input expressions and statements, forming the backbone of a simple 
    compiler for our basic programming language.

    Changelog | 3/25/2024:

    Added % to the list of symbols to be recognized as a as a symbol.
*/


%{
    int lineno = 1; /* Line number counter */
    int mydebug = 0; /* Debug flag */
    #include "ast.h" /* Include the header file for the abstract syntax tree*/
    #include "y.tab.h" /* Include the yacc header file for token definitions */
%}

%%

int             { return (T_INT); } /* Return token type for 'int' */
void            { return (T_VOID); } /* Return token type for 'void' */
read            { return (T_READ); } /* Return token type for 'read' */
string          { return (T_STRING); } /* Return token type for 'string' */
if              { return (T_IF); } /* Return token type for 'if' */
else            { return (T_ELSE); } /* Return token type for 'else' */
while           { return (T_WHILE); } /* Return token type for 'while' */
write           { return (T_WRITE); } /* Return token type for 'write' */
return          { return (T_RETURN); } /* Return token type for 'return' */
"<"             { return (T_LT); } /* Return token type for '<' */
">"             { return (T_GT); } /* Return token type for '>' */
">="            { return (T_GE); } /* Return token type for '>=' */
"<="            { return (T_LE); } /* Return token type for '<=' */
"=="            { return (T_EQ); } /* Return token type for '==' */
"!="            { return (T_NE); } /* Return token type for '!=' */


\"[^\"]*\"      { /* Handle string literals */
                        if (mydebug)
                            fprintf(stderr, "STRING found\n");
                        yylval.string = strdup(yytext); /* Store the string literal */
                        return (T_STRING); /* Return token type for string */
                }

[a-zA-Z][a-zA-Z0-9_]*   { /* Handle identifiers (variables) */
                        if (mydebug) 
                            fprintf(stderr, "VARIABLE found\n"); 
                        yylval.string = strdup(yytext); /* Store the identifier */
                        return (T_ID); /* Return token type for identifier */
                        }

[0-9]+                  { /* Handle numeric constants */
                        if (mydebug) 
                            fprintf(stderr, "Digit found\n"); 
                        yylval.value = atoi((const char *)yytext); /* Convert string to integer */
                        return (T_NUM); /* Return token type for numeric constant */
                        }

[ \t]                   { /* Ignore whitespace */
                        if (mydebug) 
                            fprintf(stderr, "Whitespace found\n");
                        }

[\;=\-+*/%&|(),\[\]{}""] { /* Handle symbols */
                        if (mydebug) 
                            fprintf(stderr, "return a token %c\n", *yytext); 
                        return (*yytext); /* Return token type for symbol */
                        }

\n                  { /* Handle newline characters */
                        if (mydebug) 
                            fprintf(stderr, "carriage return %c\n", *yytext); 
                        lineno++; /* Increment line number */
                    }

\/\/[^\n]*      {/* ignore comments */}

%%

int yywrap(void) { 
    return 1;
}
