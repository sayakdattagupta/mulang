#include <stdio.h>
#include <stdlib.h>
#include "defs.h"
#include "data.h"

static int reglist[4] = {0,0,0,0};
static char *regname[4] = {"%r8","%r9","%r10","%r11"};

void freeall_registers(void)
{
 reglist[0]=reglist[1]=reglist[2]=reglist[3]=0;
}

static int alloc_register(void)
{
 for(int i=0;i<4;i++)
 {
  if(reglist[i]==0)
  {
   reglist[i]=1;
   return i;
  }
 }
 fprintf(stderr,"REGISTER SPILL on line %d\n",line);
 exit(1);
}

static void free_register(int reg)
{
 if(reglist[reg]!=1)
 {
  fprintf(stderr,"Attempted to free unallocated register %d on line %d\n",reg,line);
  exit(1);
 }
 reglist[reg]=0;
}

void cgpreamble() {
  freeall_registers();
  fputs(
    "\t.text\n"
    ".globl\tmain\n"
    "\t.type\tmain, @function\n"
    "main:\n"
    "\tpushq\t%rbp\n"
    "\tmovq\t%rsp, %rbp\n", stdout);

  fputs("\t.section\t.note.GNU-stack,\"\0\",@progbits\n", stdout);
}

void cgpostamble() {
  fputs(
    "\tmovq\t%r8, %rax\n"
    "\tmovq\t%rbp, %rsp\n"
    "\tpopq\t%rbp\n"
    "\tret\n", stdout);
}

int cgload(int value)
{
 int r = alloc_register();
 printf("\tmovq\t$%d, %s\n",value,regname[r]);
 return r;
}

int cgadd(int r1,int r2)
{
 printf("\taddq\t%s, %s\n",regname[r1],regname[r2]);
 free_register(r1);
 return r2;
}

int cgsub(int r1,int r2) {
 printf("\tsubq\t%s, %s\n",regname[r2],regname[r1]);
 free_register(r2);
 return (r1);
}

int cgmult(int r1,int r2) {
 printf("\timulq\t%s, %s\n",regname[r2],regname[r1]);
 free_register(r2);
 return (r1);
}

int cgdiv(int r1,int r2) {
 printf("\tmovq\t%s, %%rax\n", regname[r1]); 
 printf("\tcqto\n");                          
 printf("\tidivq\t%s\n", regname[r2]);       
 printf("\tmovq\t%%rax, %s\n", regname[r1]);  
 free_register(r2);                          
 return (r1);
}

void cgprintint(int r) {
 printf("\tmovq\t%s, %%rdi\n",regname[r]); 
 printf("\tcall\tprintint\n");             
 free_register(r);  
}
