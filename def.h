#pragma once

#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

enum{
    T_EOF,T_PLUS,T_MINUS,T_STAR,T_SLASH,T_INTLIT   // token types
};

typedef struct token{
    int token;
    int intvalue;
}token;

enum{
    A_PLUS,A_MINUS,A_MULTIPLY,A_DIVIDE,A_INTLIT   // AST node types
};

typedef struct ASTnode {
  int op;                               // "Operation" to be performed on this tree
  struct ASTnode *left;                 
  struct ASTnode *right;
  int intvalue;                         // For A_INTLIT, the integer value
}ASTnode;