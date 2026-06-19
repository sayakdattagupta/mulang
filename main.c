#include <stdio.h>
#include <stdlib.h>
#include "defs.h"

int line; int putback_buf; FILE *infile;

extern int scan(struct token *t);
char *tokstr[] = {"TOK_PLUS","TOK_MINUS","TOK_ASTERISK","TOK_SLASH","TOK_INTLIT"};
static void init()
{
 line=1;
 putback_buf=0;
}
static void scanfile()
{
 struct token T;
 while(scan(&T))
 {
  printf("Token %s",tokstr[T.token]);
  if(T.token==TOK_INTLIT)
  {
   printf(", value %d",T.intvalue);
  }
  printf("\n");
 }
}

int main(int argc, char *argv[])
{
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
 scanfile();
 fclose(infile);
 return 0;
}
