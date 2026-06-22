#include <string.h>
#include "defs.h"

int keyword(char *s)
{
 if(strcmp(s,"print")==0)
 {
  return TOK_PRINT;
 }
 return 0;
}
