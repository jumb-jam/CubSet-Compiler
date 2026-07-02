#include "decl.h"

static int genAST(ASTnode* root){
    int left,right;

    if(root->left){
        left = genAST(root->left);
    }
    if(root->right){
        right = genAST(root->right);
    }

    switch(root->op){
        case A_PLUS:
            return cg_add(left,right);
        case A_MINUS:
            return cg_sub(left,right);
        case A_MULTIPLY:
            return cg_mul(left,right);
        case A_DIVIDE:
            return cg_div(left,right);
        case A_INTLIT:
            return cg_load(root->intvalue);
        default:
            fprintf(stderr, "Unknown AST operator %d\n", root->op);
            exit(1);
    }
}

void generateCode(ASTnode* root){
    int reg;

    cg_preamble();
    reg = genAST(root);
    cg_print_int(reg);
    cg_postamble();
}