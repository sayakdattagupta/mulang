#include <stdio.h>
#include <stdlib.h>
#include "defs.h"
#include "data.h"

extern int scan(struct token *t);
extern struct ASTnode *binexpr(int ptp);
extern int genAST(struct ASTnode *n);

void match(int t,char *word)
{
 if(Token.token==t)
 {
  scan(&Token);
 }
 else
 {
  fprintf(stderr,"%s expected on line %d\n",word,line);
  exit(1);
 }
}
void semi(void)
{
 match(TOK_SEMI,";");
}
void statements(void)
{
 int reg;
 struct ASTnode *tree;
 while(1)
 {
  match(TOK_PRINT,"print");
  tree=binexpr(0);
  reg=genAST(tree);
  cgprintint(reg);
  freeall_registers();
  match(TOK_SEMI,";");
  if(Token.token==TOK_EOF)
   break;
 }
}
