#ifndef DATA_H
#define DATA_H

#include <stdio.h>
#include "defs.h"

#ifndef extern_
#define extern_ extern
#endif

extern_ int line;
extern_ int putback_buf;
extern_ FILE *infile;
extern_ struct token Token;
extern_ char Text[TEXTLEN+1];

#endif
