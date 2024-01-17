#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"errorr.h"

#define MAX_LINE_LENGTH  	81
#define SPARE_CHARACTERS	30
#define MAX_PART_AMOUNT		4
#define MAX_OPERAND_AMOUNT	15
#define MAX_LABEL_LENGTH	31
#define MAX_OP_LENGTH		3
#define OP_CODES_AMOUNT		16
#define FILE_ENTRY_VAR		2

#define NEW_LINE		'\n'
#define TAB	          	'\t'
#define SPACE	          	' '
#define COLON	          	':'
#define SEMICOLON		';'
#define DOT	          	'.'
#define COMMA 	         	','
#define END_STRING	     	'\0'
#define NUMBER  	   	'#'
#define NEGATIVE 	    	'-'
#define POSITIVE  	   	'+'
#define LEFT_BRACKET	   	'['
#define RIGHT_BRACKET		']'
#define ZERO_CHAR		'0'
#define EQUAL			'='

/* Devide code to fragments and show logical errors */
/* Transfer code for precise analysis */

int insert_label_to_symbol_table(char *label)
{
	return 0;
}

void analyze_line(char *label,char* operation, char *operands[],int line_number)
{
	int i=0,j;
	printf("!!! ANALYZING line %d !!!\n",line_number);
	printf("label=%s\noperation=%s\noperands:\n",label,operation);
	for(i=0;operands[i]!=NULL;i++)
		printf("operand %d is %s\n",i,operands[i]);
	j=insert_label_to_symbol_table(label);
	if(j)
		printf("label %s was added successfully",label);

	return;
}
