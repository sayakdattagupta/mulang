#ifndef DEFS_H
#define DEFS_H

enum { TOK_PLUS, TOK_MINUS, TOK_SLASH, TOK_ASTERISK, TOK_INTLIT };

struct token {
 int token;
 int intvalue;
};

#endif
