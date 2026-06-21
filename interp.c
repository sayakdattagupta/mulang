#include <stdio.h>
#include <stdlib.h>
#include "defs.h"

int interpretAST(struct ASTnode *n)
{
 int Lval,Rval;
 if(n==NULL) return 0;

 if(n->left) Lval = interpretAST(n->left);
 if(n->right) Rval = interpretAST(n->right);

 switch(n->op)
 {
  case A_ADD: return(Lval+Rval);
  case A_SUBTRACT: return(Lval-Rval);
  case A_MULTIPLY: return(Lval*Rval);
  case A_DIVIDE: return(Lval/Rval);
  case A_INTLIT: return(n->intvalue);
  default:
   fprintf(stderr,"unknown op %d\n",n->op);
   exit(1);
 }
}
