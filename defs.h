#ifndef DEFS_H
#define DEFS_H

enum { TOK_PLUS, TOK_MINUS, TOK_SLASH, TOK_ASTERISK, TOK_INTLIT, TOK_EOF };

struct token {
 int token;
 int intvalue;
};

enum { A_ADD, A_SUBTRACT, A_MULTIPLY, A_DIVIDE, A_INTLIT };

struct ASTnode
{
 int op;
 struct ASTnode *right;
 struct ASTnode *left;
 int intvalue;
};

#endif
