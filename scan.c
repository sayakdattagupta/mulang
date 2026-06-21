#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "defs.h"

extern int line;
extern int putback_buf;
extern FILE *infile;

static int next(void);
static int skip(void);
static int scanint(int c);
static int chrpos(char *s, int c);

static void putback(int c)
{
 putback_buf = c;
}

static int next(void)
{
 int c;
 if(putback_buf)
 {
  c=putback_buf;
  putback_buf=0;
  return c;
 }
 c=fgetc(infile);
 if('\n'==c)
  line++;
 return c;
}

static int skip(void)
{
 int c;
 c=next();
 while(' ' == c || '\n' == c || '\r' == c || '\f' == c || '\t' == c)
 {
  if('\n'==c)
   line++;
  c = next();
 }
 return c;
}

int scan(struct token *t)
{
 int c;
 c=skip();
 switch (c)
 {
  case EOF:
   t->token=TOK_EOF;
   return 0;
  case '+':
   t->token=TOK_PLUS;
   break;
  case '-':
   t->token=TOK_MINUS;
   break;
  case '*':
   t->token=TOK_ASTERISK;
   break;
  case '/':
   t->token=TOK_SLASH;
   break;
  default:
   if(isdigit(c))
   {
    t->intvalue = scanint(c);
    t->token = TOK_INTLIT;
    break;
   }
   printf("unrecognised character %c on line %d\n",c,line);
   exit(1);
 }

 return 1;
}

static int scanint(int c)
{
 int k,val=0;
 while ((k=chrpos("0123456789",c))>=0)
 {
  val = val*10+k;
  c=next();
 }
 putback(c);
 return val;
}

static int chrpos(char *s, int c)
{
 char *p;
 p = strchr(s,c);
 return (p?p-s:-1);
}
