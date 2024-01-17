#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"errorr.h"
#include"code_reader.h"

#define FIRST_ARGUMENT		1
#define ERROR_WITH_FILE		102
#define FILE_ENTRY_VAR		2
#define ERROR_MSG	 	"File does not exist or can not be opened!\n"
#define HELP_MSG	 	"Your command should look something like this: './<text_file_name>.txt'\n"

typedef struct segment
{
	char *segment;
	struct segment *next_segment;
}segment;


/* Loading code from file given as argument and transfering it to code recognizing unit */
/* Shows error in case the file reading failed */
FILE *is_entry_file_accessible(int entry,char *from_file)
{
	FILE *fl;
	if(entry==FILE_ENTRY_VAR)
	{
		fl=fopen(from_file,"r");
		if(fl!=NULL)
			return fl;
        	printf(ERROR_MSG);
		return NULL;
	}
	else
	{
		printf(HELP_MSG);
		return NULL;
	}
}

/* Accessing file with code */
/* In case of error - exit */
int main(int argc, char *argv[])
{
	FILE *fl;

	if((fl=is_entry_file_accessible(argc,argv[FIRST_ARGUMENT]))!= NULL)
		read_code(fl);
	else
		errorr(ERROR_WITH_FILE,0);
	return 0;
}