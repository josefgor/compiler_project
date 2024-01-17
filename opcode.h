/* each single variable holds:
*  1. operation code which consists of 3 chars
*  2. source addressing mode consists of 5 digits 0-4
*  3. destination addressing mode consists of 5 digits 0-4
*  where 0-immidiate ..,1-straight ..,2-index ..,3-register addressing
*  4 - no operand to be addressed
*/


#define MAX_LINE_LENGTH 81
#define MAX_LABEL_LENGTH 31
#define MAX_OP_LENGTH	 3
#define MAX_OP_AMOUNT	 16
#define MAX_ERROR_CHAR	 7
#define TAB          	'\t'
#define SPACE          	' '
#define COLON          	':'
#define COMMA          	','
#define END_STRING     	'\0'
#define DEFINE ".define"


typedef struct
{
	char	op[3],		/* operation code made of 3 letters */
		smode[4],	/* source addressing mode */
		dmode[4];	/* destination addressing mode */
} opcode;



void analyze_line(char *line,int hasColon,int hasComma,int hasSemicolon,int hasDot,int lineNumber);
char* getLabel(char *line, int hasDot, int lineNumber);
char *getOperand(char *line,int lineNumber);
int detectOpCode (char * oper);
int hasError (char *line);
char* skip_tab_and_space(char *line);
char* skipAlpha(char *line);
int isAlpha (int chr);
int isDigit (int chr);
int isAlphaNumeric (int chr);
int allowedCharacters(int chr);
