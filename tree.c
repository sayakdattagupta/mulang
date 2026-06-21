#include <stdio.h>
#include <stdlib.h>
#include "defs.h"

struct ASTnode *mkastnode(int op,struct ASTnode *left,struct ASTnode *right,int intvalue)
{
 struct ASTnode *n;
 n = (struct ASTnode *) malloc(sizeof(struct ASTnode));
 n->op = op;
 n->left = left;
 n->right = right;
 n->intvalue = intvalue;
 return n;
}

struct ASTnode *mkastleaf(int op,int intvalue)
{
 return (mkastnode(op,NULL,NULL,intvalue));
}

struct ASTnode *mkastunary(int op,struct ASTnode *child,int intvalue)
{
 return (mkastnode(op,child,NULL,intvalue));
}
