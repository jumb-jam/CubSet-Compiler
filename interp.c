#include "decl.h" 


int Interpret_AST(ASTnode* root){
    int left,right;

    if(root->left){
        left = Interpret_AST(root->left);
    }
    if(root->right){
        right = Interpret_AST(root->right);
    }

    switch (root->op){
        case A_PLUS:
            return left + right;
            break;
        case A_MINUS:
            return left - right;
            break;
        case A_DIVIDE:
            return left / right;
        case A_MULTIPLY:
            return left * right;
        case A_INTLIT:
            return root->intvalue;
        default:
            fprintf(stderr, "Unknown AST operator %d\n",root->op);
            exit(1);
    }
}
