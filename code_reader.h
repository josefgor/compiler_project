#define MAX_LINE_LENGTH  	81
#define SPARE_CHARACTERS	30
#define MAX_PART_AMOUNT		4
#define MAX_OPERAND_AMOUNT	15
#define MAX_LABEL_LENGTH	31
#define MAX_OP_LENGTH		3
#define OP_CODES_AMOUNT		16
#define FILE_ENTRY_VAR		2
#define IF_WE_GOT_NEW_LINE      if (c == '\n')

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

void read_code(FILE *);