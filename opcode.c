#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "opcode.h"
#include "extern.h"
#include "errorr.h"
#include "table.h"
#include "colors.h"




char* 	getOperand(char*,int);
char* 	getLabel(char*, int, int);
char* 	skip_tab_and_space(char*);
char* 	skipAlpha(char*);
int 	hasError (char*);
int   	isAlpha (int );
int 	allowedCharacters(int );

static char **symbolTable;
/*symbolTable=(char**)malloc( 20*sizeof(char*) );*/
int	symTableCounter=0;

static char error[]="ERROR #";
opcode arr[MAX_OP_AMOUNT]={
	{"mov","1111","0111"},
	{"cmp","1111","1111"},
	{"add","1111","0111"},
	{"sub","1111","0111"},
	{"not","0000","0111"},
	{"clr","0000","0111"},
	{"lea","0110","0111"},
	{"inc","0000","0111"},
	{"dec","0000","0111"},
	{"jmp","0000","0101"},
	{"bne","0000","0101"},
	{"red","0000","0111"},
	{"prn","0000","1111"},
	{"jsr","0000","0101"},
	{"rts","0000","0000"},
	{"hlt","0000","0000"}};




/* interpret line of code, fetches operation and prints operation code 
*  gets string and counters of all special signs (colon,comma,semicolon..)
*  returns operation code
*/
void analyze_line(char *line,int hasColon,int hasComma,int hasSemicolon,int hasDot,int lineNumber)
{
	int opCode;

	/*char label[MAX_LABEL_LENGTH];*/
	char *operation, *source_operand, *original_line;

	symTableCounter = 0;

	original_line=line;

	/*printf("%s\n",parser(line,':',3));*/
    if(hasDot == 1)
    {
        if(is_const(line))
            line = getLabel(line,hasDot,lineNumber);
        else
            /*error: The setting of the inv constant is correct*/
            return;
    }

	if(hasColon > 1)
	{
		errorr(501,lineNumber);
		return;
	}

	if(hasColon == 1)  
		line = getLabel(line,hasDot,lineNumber);

	if(hasError(line))
		return;

	line = skip_tab_and_space(line);
	operation = line;
	line = skipAlpha(line);
	
/* check if we got right op*/
	if((opCode = detectOpCode(operation)) == -1 )
		{errorr(602,lineNumber);return;}

	printf("correct operation was assigned , operation number: %d \n",opCode);
	
	line = skip_tab_and_space(line);

	printf("THE NEXT LINE IS #%s#\n",line);

	if(opCode == 14 || opCode == 15)
	{
		errorr(702,lineNumber);
		return;
	}

/* get source and destination operands if exist */

	source_operand = line;
	
	if(hasComma > 1) 
	{
		errorr(701,lineNumber);
		return;
	}
	if(hasComma == 1)
	{
		line = getOperand(line,lineNumber);
		line++;
		line = getOperand(line,lineNumber);
	}
	if(hasComma == 0)
		line = getOperand(line,lineNumber);
	return;
}

/* Fetch label from line of code 
*  Gets line of code
*  Returns label if defined correctly or error message
*/
char* getLabel(char *line, int hasDot, int lineNumber)
{
	int i = 0 ,j = 0;
	char *label;

	line = skip_tab_and_space(line);

	if(!isAlpha(*line ))
		return errorr(502,lineNumber);

	while(i < MAX_LABEL_LENGTH && isAlphaNumeric(*(line+i))) {
		i++;
	}

    /*if(hasEqual)
            insert_label_as_mdefine(label);
       */
	if(line[i] == COLON)
	{
		label = (char*) malloc((i + 1) * sizeof(char));
		if(label == NULL)
			return errorr(101,lineNumber);

        strncpy(label,line,i);
//		while(j < i)
//		{
//			label[j] = *line;
//            j++;
//            line++;
//		}

		label[i] = END_STRING;
		printf("correct label was assigned : %s\n",label);
		if(!insert_to_table(label,hasDot, 0)) { // change this zero to the real line_number if needed
			// free all allocated memory and exit
		}
		return line;
	}
	else if(i == MAX_LABEL_LENGTH )
		return errorr(504,lineNumber);
	else
		return errorr(502,lineNumber);
}


	char *is_const(char *line)
	{
		strncmp(line,DEFINE,7);
	}


/* Fetch operands from line of code 
*  Gets line of code
*  Returns operands if defined correctly or error message
*/

char *getOperand(char *line,int lineNumber)
{
	/*static int sourceOrDest;*/
	/*int i=0;*/
	char *original;
	original = line;
/*
	while(isAlphaNumeric(*line) || allowedCharacters(*line))
	{
		*(label+i)=*line;
		line++;
		i++;
	}*/
	return "";
}

/* 
* Get operation string
* Return operation code 0 to 15
* if not found return -1
*/

int detectOpCode (char * oper)
{
	int i;
	for(i = 0; i < MAX_OP_AMOUNT; i++)
		if( oper[0] == arr[i].op[0] && oper[1] == arr[i].op[1] && oper[2] == arr[i].op[2] 
			&& (oper[3] == ' ' || oper[3] == '\0'))
			return i;
	return -1;
}

/* check wether the line has "ERROR #" 
*  returns 1 if has, otherwise 0
*/

int hasError (char *line)
{
	int i = 0;
	while(*(error+i) == *(line+i) )
		i++;
	return (*(error+i) =='\0' )? 1 : 0;
}

/* 
* Gets pointer to a string
* Return pointer to original string without leading tabs and spaces
*/
char* skip_tab_and_space(char *line)
{
	while(*line == SPACE || *line == TAB )
		line++;
	return line;
}

/* 
* Get pointer to a string
* Return pointer to original string without leading letters
*/
char* skipAlpha(char *line)
{
	while(isAlpha(*line))
		line++;
	return line;
}

int isAlpha (int chr)
{
	return ((chr >= 'a' && chr <= 'z') || (chr >= 'A' && chr <= 'Z'));
}

//todo jfalsdfj

int isDigit (int chr)
{
	return (chr >= '0' && chr <= '9');
}

int isAlphaNumeric (int chr)
{
	return (isDigit (chr) ||  isAlpha (chr));
}

int allowedCharacters(int chr)
{
	return (chr == '-' || chr == '+' || chr == '#' || chr == '[' || chr == ']');
}











