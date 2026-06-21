#include <stdio.h>
#include <stdlib.h>
#include "defs.h"
#include "data.h"

extern struct ASTnode *mkastnode(int op, struct ASTnode *left, struct ASTnode *right, int intvalue);
extern struct ASTnode *mkastleaf(int op, int intvalue);

extern int line;
extern struct token Token;
extern int scan(struct token *t);

static int arithop(int tok)
{
 switch (tok)
 {
  case TOK_PLUS: return A_ADD;
  case TOK_MINUS: return A_SUBTRACT;
  case TOK_ASTERISK: return A_MULTIPLY;
  case TOK_SLASH: return A_DIVIDE;
  default:
   fprintf(stderr,"unknown token on line %d\n",line);
   exit(1);
 }
}

static struct ASTnode *primary(void)
{
 struct ASTnode *n;
 switch (Token.token)
 {
  case TOK_INTLIT:
   n = mkastleaf(A_INTLIT,Token.intvalue);
   scan(&Token);
   return n;
  default:
   fprintf(stderr,"syntax err on line %d\n",line);
   exit(1);
 }
}

struct ASTnode *binexpr(void)
{
 struct ASTnode *left, *right;
 int nodetype;

 left = primary();

 if(Token.token == TOK_EOF)
  return left;

 nodetype = arithop(Token.token);

 scan(&Token);

 right = binexpr();

 return mkastnode(nodetype, left, right, 0);
}
