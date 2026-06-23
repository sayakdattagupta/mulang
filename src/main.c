#include <stdio.h>
#include <stdlib.h>
#include "defs.h"
#define extern_
#include "data.h"
#undef extern_

int line; int putback_buf; FILE *infile; struct token Token;

extern int scan(struct token *t);
extern void statements(void);
extern void cgpreamble(void);
extern void cgpostamble(void);

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
 cgpreamble();
 statements();
 cgpostamble();
 fclose(infile);
 return 0;
}
