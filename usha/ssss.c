/********************************************************************
*	NAME    : f1.c
*
*  DESCRIPTION  : File operations program
*
*  DATE      NAME    	 REFERENCE          REASON
*
*  24-OCT-17  SHANKAR    		      Initial Creation.
*
*  Copyright 2017, Aricent Technologies (Holdings) Ltd
*
**************************************************************************/


/***************************************************************************
*                       HEADER FILES
***************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/***************************************************************************
*                       	MACROS
***************************************************************************/


#define N 30
#define MAX 256

/****************************************************************************
*
*       Function Name   : check_write
*       Description     : checks for a substring and removes it
*       Returns         : void
*
****************************************************************************/


void check_write(char* darr[], int n, char* outfile, char* pat)
{
	int i,
		flag = 0;
	char* pt_base;
	FILE *fp2 = fopen(outfile, "w");
	if(fp2 == NULL)
	{
		printf("File not opened");
		return;
	}
	for(i = 0;i < n; i++)
	{
		while(pt_base = strcasestr(darr[i], pat))
		{
			memmove(pt_base, (pt_base + strlen(pat)),((strlen(pt_base) - strlen(pat)) + 1));
			flag = 1;
		}
		if(flag == 1)
		{
			fputs(darr[i], fp2);
			flag =0;
		}
	}
	fclose(fp2);

}			

/****************************************************************************
*
*       Function Name   : main
*       Description     : Opens a file and reads contents
*       Returns         : Returns 0 if success 
*
****************************************************************************/



int main(int argc, char* argv[])
{
	FILE *fp1 = NULL;
	char res[MAX],
		*darr[N];
	int i = 0;
	if(argc == 4)
	{
	fp1 = fopen(argv[1], "r");
	if(fp1 == NULL)
        {
                printf("File not opened");
                return;
        }
	while(fgets(res, sizeof(res), fp1) != NULL)
	{
		darr[i] = (char*) malloc (sizeof(char) * (strlen(res) + 1));
		if(darr[i] == NULL)
		{
			printf("\nMemory not allocated");
			return 0;
		} 
		strcpy(darr[i], res);		
		i++;	
	//	printf("%s", darr[i]);
	}
	check_write(darr, i, argv[2], argv[3]);
	}
	else
	{
		printf("\nInsufficient args");
	}
	i--;
	while(i >= 0)
	{
		free(darr[i]);
		darr[i] = NULL;
		i--;
	}
	fclose(fp1);
	return 0;
}