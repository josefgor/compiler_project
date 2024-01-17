#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "errorr.h"

#define ERROR_101	"ERROR #101 : leak of dynamic memory"
#define ERROR_201	"ERROR #201 : given string contains not only digits! "
#define ERROR_117	"ERROR #117 : ERROR!! ERROR!!"
#define ERROR_203	"ERROR #203 : given string contains not only digits and letters! "
#define ERROR_501	"ERROR #501 : wrong label definition"
#define ERROR_502	"ERROR #502 : wrong label definition (label name must begin with a letter)"
#define ERROR_503	"ERROR #503 : wrong label definition (non-alphanumeric character in label name)"
#define ERROR_504	"ERROR #504 : wrong label definition (label length exceeded)"
#define ERROR_602	"ERROR #602 : wrong operation code"
#define ERROR_701	"ERROR #701 : wrong operands"
#define ERROR_702	"ERROR #702 : operation shouldn't have operands"
#define ERROR_801	"ERROR #801 : symbol allready exist"
#define ERROR_802	"ERROR #802 : unable to allocate memory"



/* Prints error according to it's number in red */
char* errorr (int errorNum,int lineNumber)
{
	printInRed();
	switch (errorNum)
	{
	case 101:	printf(ERROR_101);printf("\n");resetColor();return ERROR_101;
	case 501:	printf(ERROR_501);printf(" in line %d \n",lineNumber);resetColor();return ERROR_501;
	case 502:	printf(ERROR_502);printf(" in line %d \n",lineNumber);resetColor();return ERROR_502;
	case 503:	printf(ERROR_503);printf(" in line %d \n",lineNumber);resetColor();return ERROR_503;
	case 504:	printf(ERROR_504);printf(" in line %d \n",lineNumber);resetColor();return ERROR_504;
	case 602:	printf(ERROR_602);printf(" in line %d \n",lineNumber);resetColor();return ERROR_602;
	case 701:	printf(ERROR_701);printf(" in line %d \n",lineNumber);resetColor();return ERROR_701;
	case 702:	printf(ERROR_702);printf(" in line %d \n",lineNumber);resetColor();return ERROR_702;
	default:	printf(ERROR_117);printf("\n");resetColor();return ERROR_117;
	}
	
	return "";
}

/* Changes color to red */
void resetColor(void)
{
	printf(ANSI_RESET_ALL);
}

/* Changes color to default color */
void printInRed(void)
{
	printf(ANSI_COLOR_RED);
}

