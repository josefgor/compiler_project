#include <stdio.h>

#include "colors.h"


void yellowColor (void)
{
	printf("\033[1;33m");
}

void redColor (void)
{
	printf("\033[1;31m");
}

void greenColor (void)
{
	printf("\033[1;32m");
}

void blueColor (void)
{
	printf("\033[1;34m");
}

void purpleColor (void)
{
	printf("\033[1;35m");
}

void resetColor (void)
{
	printf("\033[0m");
}
