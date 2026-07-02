#pragma once
#include "def.h"
#include "data.h"

int scan(token* t);

ASTnode* make_ast_node(int op, ASTnode* left, ASTnode* right, int intvalue);
ASTnode* make_ast_leaf(int op, int intvalue);
ASTnode* make_ast_unary(int op, ASTnode* left, int intvalue);

ASTnode* binexpr(int prev_tk_prec);

int Interpret_AST(ASTnode* root);

void generateCode(ASTnode* root);

void freeall_registers(void);
void cg_preamble();
void cg_postamble();
int cg_load(int value);
int cg_add(int r1, int r2);
int cg_sub(int r1, int r2);
int cg_mul(int r1, int r2);
int cg_div(int r1, int r2);
void cg_print_int(int r);