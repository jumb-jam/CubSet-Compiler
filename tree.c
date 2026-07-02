#include "decl.h"

ASTnode* make_ast_node(int op, struct ASTnode* left, struct ASTnode* right, int intvalue){
    ASTnode* node;
    node = (ASTnode*)malloc(sizeof(ASTnode));

    if(node == NULL){
        fprintf(stderr, "Unable to allocate ASTnode\n");
        exit(1);
    }

    node->op = op;
    node->left = left;
    node->right = right;
    node->intvalue = intvalue;

    return node;
}

ASTnode *make_ast_leaf(int op, int intvalue) {
    return (make_ast_node(op, NULL, NULL, intvalue));
}

ASTnode *make_ast_unary(int op, ASTnode *left, int intvalue) {
    return (make_ast_node(op, left, NULL, intvalue));
}