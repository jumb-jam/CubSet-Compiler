#include "decl.h"

int arithm_op(int tok){  // converting operation tokens to astnodes
    switch (tok)
    {
    case T_PLUS:
        return A_PLUS;
    case T_MINUS:
        return A_MINUS;
    case T_STAR:
        return A_MULTIPLY;
    case T_SLASH:
        return A_DIVIDE;
    default:
        break;
    }
}

static ASTnode* primary(){  // check if token is intlit and converts to astnode
    ASTnode* node;

    if(Token.token == T_INTLIT){
        node = make_ast_leaf(A_INTLIT,Token.intvalue);
        scan(&Token);
        return node;
    }
    else{
        fprintf(stderr, "syntax error on line %d\n", Line);
        exit(1);
    }
}

static int opPrec[] = {0,10,10,20,20,0};  // eof,plus,minus,multiply,divide,intlit

static int opPrecedence(int tokentype){
    int prec = opPrec[tokentype];
    if (prec == 0) {
        fprintf(stderr, "syntax error on line %d, token %d\n", Line, tokentype);
        exit(1);
    }
    return prec;
}

ASTnode* binexpr(int prev_tk_prec){
    ASTnode* left;
    ASTnode* right;

    int tokentype;

    left = primary();

    tokentype = Token.token;
    if(tokentype == T_EOF){
        return left;
    }

    while(opPrecedence(tokentype) > prev_tk_prec){
        scan(&Token);

        right = binexpr(opPrec[tokentype]);

        left = make_ast_node(arithm_op(tokentype),left,right,0);

        tokentype = Token.token;
        if(tokentype == T_EOF){
            return left;
        }

    }

    return left;
}

