#include <stdio.h>
#include <stdlib.h>
#include "defs.h"

extern void cgpreamble(void);
extern void cgpostamble(void);
extern void cgprintint(int r);
extern int cgload(int value);
extern int cgadd(int r1, int r2);
extern int cgsub(int r1, int r2);
extern int cgmult(int r1, int r2);
extern int cgdiv(int r1, int r2);

static int genAST(struct ASTnode *n)
{
 int Lreg,Rreg;
 if (n->left) Lreg = genAST(n->left);
 if (n->right) Rreg = genAST(n->right);

 switch (n->op)
 {
  case A_ADD: return (cgadd(Lreg,Rreg));
  case A_SUBTRACT: return (cgsub(Lreg,Rreg));
  case A_MULTIPLY: return (cgmult(Lreg,Rreg));
  case A_DIVIDE: return (cgdiv(Lreg,Rreg));
  case A_INTLIT: return (cgload(n->intvalue));

  default:
   fprintf(stderr,"Uknown AST op %d\n",n->op);
   exit(1);
 }
}

void genCode(struct ASTnode *n)
{
 int reg;
 cgpreamble();
 reg=genAST(n);
 cgprintint(reg);
 cgpostamble();
}
