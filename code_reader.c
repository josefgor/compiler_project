#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"errorr.h"
#include"code_analyzer.h"
#include "code_reader.h"



/* Devide code to fragments and show logical errors */
/* Transfer code for precise analysis */


int allowed_characters(char c)
{
	return (c>='0'&&c<=';') || (c>='+'&&c<='.') || (c>='a'&&c<='z')	|| (c>='A'&&c<='[') 
		|| c=='#' || c=='\"' || c==']' || c=='=' || c=='\0' || c==EOF;
}

int secondary_characters(char c)
{
	return c=='=' || c=='+' || c=='-' || c=='[' || c=='#' || c==']' || c==',' ;
}


void read_code(FILE *fl)
{
	int line_number,i,skip_line;
	char c,line[MAX_LINE_LENGTH+SPARE_CHARACTERS]=" ",*label,*oper;
	char *operands [MAX_OPERAND_AMOUNT];
	int is_label=1,is_operation=1,is_operand=0,got_comma=0;
	line_number=skip_line=0;
	for(i=0;i<MAX_OPERAND_AMOUNT;i++)
		operands[i]=NULL;
	i=0;
	
	for (c = getc(fl); c != EOF && i<=MAX_LINE_LENGTH ; c = getc(fl))
	{
		c=(c==TAB)?SPACE:c;
		if(c==SEMICOLON)
		{
			if(i!=0)
				errorr(207,line_number+1);
			skip_line=1;
		}
        	else IF_WE_GOT_NEW_LINE
/*if (c == '\n')*/
		{
			line_number++;
			if(!skip_line)
			{
				/*printf("PROBLEM FOUND HERE\nis_operand=%d got_comma=%d\n",is_operand,got_comma);*/
				*(line+i+1)=END_STRING;
				if(is_label==0 && is_operation==1 && i==0)
					errorr(505,line_number);
					/*printf("PROBLEM FOUND HERE\n");*/
				else if(is_operation==1 && i>0)
				{
					oper=(char*)malloc((i+2)*sizeof(char));
					strcpy(oper,line);
					analyze_line(label,oper,operands,line_number);
					/*free*/
				}
				else if(is_operand==got_comma+1)
				{
					if(is_operand>=MAX_OPERAND_AMOUNT)
						errorr(505,line_number);
					else if(i==0)
						errorr(705,line_number);
					else
					{ 
						*(line+i+1)=END_STRING;
						operands[is_operand-1]=(char*)malloc((i+2)*sizeof(char));
						strcpy(operands[is_operand-1],line);
						analyze_line(label,oper,operands,line_number);
					}
				}
				else if(is_operand!=got_comma+1)
					errorr(701,line_number);
/*				analyze_line(label,oper,operands,line_number);*/
			}
			is_label=is_operation=1;
			is_operand=got_comma=*(line+1)=skip_line=0;
			*line=SPACE;
			for(i=0;i<MAX_OPERAND_AMOUNT;i++)
				operands[i]=NULL;
			i=0;
		}
		else if(skip_line==1 || (c==SPACE && *(line+i)==SPACE) )
			continue;
		else if (c==SPACE)
		{
			if(is_operation==1)
			{
				*(line+i+1)=END_STRING;
				oper=(char*)malloc((i+2)*sizeof(char));
				strcpy(oper,line);
				/*operation_number(oper,line_number+1);*/
				is_operand=1;
				*line=SPACE;
				is_operation=is_label=i=*(line+1)=0;
				/*free*/
				/*continue;*/
			}
			else if(is_operand==got_comma+1)
			{
				i++;
				*(line+i)=SPACE;
			}
		}
		else if ( c==COLON ) 
		{
			if(is_label==1)
			{
				*(line+i+1)=END_STRING;
				label=(char*)malloc((i+2)*sizeof(char));
				strcpy(label,line);
				/*label_to_symbol_table(label,line_number+1);*/
				*line=SPACE;
				*(line+1)=is_label=i=0;
				/*free*/
			}
			else
			{
				errorr(505,line_number+1);
				skip_line=1;
			}
		}
		else if (c==COMMA)
		{
			if(is_operand==got_comma+1)
			{
				*(line+i+1)=END_STRING;
				operands[is_operand-1]=(char*)malloc((i+2)*sizeof(char));
				strcpy(operands[is_operand-1],line);
				/*operand_x(operands[is_operand-1],line_number+1);*/
				is_operand++;
				got_comma++;
				*line=SPACE;
				*(line+1)=i=0;
				
			}
			else
			{
				errorr(705,line_number+1);
				skip_line=1;
			}

		}

		else if(allowed_characters(c))
		{
			i++;
			line[i]=c;
			
			
		}
		else
		{
			skip_line=1;
			/*line_number++;*/
			errorr(202,(line_number+1));
		}
		
	}

	if(i>MAX_LINE_LENGTH)
		errorr(204,line_number);

	fclose(fl);
	return;

}

