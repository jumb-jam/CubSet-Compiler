#include "decl.h"



// Get next character, putback a character if required
static int next(){
    int c;

    if(Putback){
        c = Putback;
        Putback = 0;
        return c;
    }

    c = fgetc(Infile);
    if(c == '\n'){
        Line++;
    }

    return c;
}

static void putback(int c){
    Putback = c;
}

// Skip whitespaces
static int skip(){
    int c;
    c = next();

    while(c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f'){
        c = next();
    }
    
    return c;
}

static int charpos(char *s, int c) {
    char *p;

    p = strchr(s, c);
    return (p ? p - s : -1);
}

static int scanint(c){
    int k;
    int val = 0;

    while((k = charpos("0123456789",c)) >= 0){
        val = val*10 + k;
        c = next();
    }

    putback(c);
    return val;
}

// Scan and return the next token found in the input.
// Return 1 if token valid, 0 if no tokens left.

int scan(token *t){
    int c;

    c = skip();

    switch(c){
        case EOF:
            t->token = T_EOF;
            return 0;
        case '+':
            t->token = T_PLUS;
            break;
        case '-':
            t->token = T_MINUS;
            break;
        case '*':
            t->token = T_STAR;
            break;
        case '/':
            t->token = T_SLASH;
            break;
        default:
            if(isdigit(c)){
                t->intvalue = scanint(c);
                t->token = T_INTLIT;
                break;
            }
            printf("Unrecognised character %c on line %d\n", c, Line);
            exit(1);
    }

    return 1;
}