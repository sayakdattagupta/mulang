#include <stdio.h>
#include <stdlib.h>
#include "defs.h"

int line; int putback_buf; FILE *infile; struct token Token;

extern int scan(struct token *t);
extern struct ASTnode *binexpr(int ptp);
extern int interpretAST(struct ASTnode *n);

static void init()
{
 line=1;
 putback_buf=0;
}

int main(int argc, char *argv[])
{
 struct ASTnode *result_tree;
 if(argc!=2)
 {
  fprintf(stderr,"Usage: %s <input_file>\n",argv[0]);
  exit(1);
 }
 init();
 infile = fopen(argv[1],"r");
 if(infile==NULL)
 {
  fprintf(stderr,"Unable to open file: %s\n",argv[1]);
  exit(1);
 }
 scan(&Token);
 result_tree = binexpr(0);
 printf("Evaluated result: %d\n", interpretAST(result_tree));
 fclose(infile);
 return 0;
}
