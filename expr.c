#include <stdio.h>
#include <stdlib.h>
#include "defs.h"
#include "data.h"

extern struct ASTnode *mkastnode(int op, struct ASTnode *left, struct ASTnode *right, int intvalue);
extern struct ASTnode *mkastleaf(int op, int intvalue);

extern int line;
extern struct token Token;
extern int scan(struct token *t);

static int OpPrec[] = {10,10,20,20};

static int op_prec(int tokentype)
{
 if(tokentype>TOK_ASTERISK)
 {
  return 0;
 }
 int prec = OpPrec[tokentype];
 if(prec==0)
 {
  fprintf(stderr,"syntax err token %d on line %d",tokentype,line);
  exit(1);
 }
 return (prec);
}

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

struct ASTnode *binexpr(int ptp)
{
 struct ASTnode *left, *right;
 int tokentype;

 left = primary();

 tokentype = Token.token;

 if(tokentype == TOK_SEMI)
  return left;

 while(op_prec(tokentype)>ptp)
 {
  int current_op = tokentype;
  scan(&Token);
  right=binexpr(op_prec(current_op));
  left=mkastnode(arithop(current_op),left,right,0);
  tokentype=Token.token;
  if(tokentype==TOK_SEMI)
   return left;
 }
 return left;
}
