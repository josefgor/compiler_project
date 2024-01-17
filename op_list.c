#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "op_list.h"

static const char op[][3] = {	"mov","cmp","add","sub",
				"not","clr","lea","inc",
				"dec","jmp","bne","red",
				"prn","jsr","rts","hlt"};

#define	 OP0	mov
#define	 OP1	cmp
#define	 OP2	add
#define	 OP3	sub
#define	 OP4	not
#define	 OP5	clr
#define	 OP6	lea
#define	 OP7	inc
#define	 OP8	dec
#define	 OP9	jmp
#define	 OP10	bne
#define	 OP11	red
#define	 OP12	prn
#define	 OP13	jsr
#define	 OP14	rts
#define	 OP15	hlt


/* print matrix */

char* opCode(int opCode)
{
	char * res;
	res=(char*)malloc(10);
	printf("return opCode dec from op_list\n");
	strcpy(res,op[0]);
/*	res=op[0];*/
	return res;
}
