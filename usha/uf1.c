/********************************************************************
*	NAME    : file1.c
*
*  DESCRIPTION  : File operations program
*
*  DATE      NAME    	 REFERENCE          REASON
*
*  24-OCT-17  USHASREE   		      Initial Creation.
*
*  Copyright 2017, Aricent Technologies (Holdings) Ltd
*
**************************************************************************/

/***************************************************************************
*                       HEADER FILES
***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/***************************************************************************
*                       	MACROS
***************************************************************************/
#define BUF 128 /* can change the buffer size as well */
#define N 10 /* change to accomodate other sizes, change ONCE here */



char search_in_file(char* arr[],int n,char* ofname,char* str);
/****************************************************************************
*
*       Function Name   : main
*       Description     : Opens a file and reads contents
*       Returns         : Returns 0 if success 
*
****************************************************************************/
int main(int argc, char *argv[]) 
{
	char line[BUF],
		*arr[N];	
	FILE *fp = NULL;
	int i = 0;
	int total = 0,
	    result;
	//char fname[100],key[100];
	//printf("\nenter a filename:");
	//scanf("%s",fname);
		if(argc ==4)
		{
		fp = fopen(argv[1], "r");
		if(fp == NULL)
		{
			printf("could not open a file\n");
			return 0;
		}
		
	
			while(fgets(line,sizeof(line), fp)!= NULL)
			 {
				arr[i] = (char *) malloc(sizeof(char)*strlen(line)+1);
				if(arr[i] == NULL)
				{
					printf("\n memory not allocated");
					return 0;
				}
				strcpy(arr[i],line);
				i++;
			}

			search_in_file(arr,i,argv[2],argv[3]);
		}
			else
			{
				printf("\n insufficient arguments");

		}
		i--;
		while(i>=0)
		{
			free(arr[i]);
			arr[i] = NULL;
			i--;

}
fclose(fp);
return 0;
}


/****************************************************************************
*
*       Function Name   : search_in_file
*       Description     : checks for a substring and removes it
*       Returns         : void
*
****************************************************************************/
char search_in_file(char* arr[],int n,char* ofname,char* str)
{
	FILE *fp1;
	int i;
	fp1 = fopen(ofname,"w");
	if(fp1== NULL)
	{
		printf("\nFile not opened");
		return 0;
	}

	//print file contents
	// for(i=0;i<n;i++)
	// {
	// 	printf("%s",arr[i]);
	// }
	int line_num = 1;
	int find_result = 0;
	int is_found=0;
	char temp[512], *pt_base;

	for(i=0;i<n;i++){
		if((strstr(arr[i], str)) != NULL) {
			printf("\nA match found on line: %d\n", line_num);
			// printf("\n%s\n", arr[i]);
			find_result++;
		}
		line_num++;
	}
	if(find_result == 0) {
		printf("\nSorry, couldn't find a match.\n");
	}

	for(i = 0;i < n; i++)
	{
		while(pt_base = strstr(arr[i], str))
		{
			printf("%s\n", pt_base);
			memmove(pt_base, (pt_base + strlen(str)),((strlen(pt_base) - strlen(str)) + 1));
			is_found = 1;
		}
		if(is_found == 1)
		{
			printf("\n %s",arr[i]);
			fputs(arr[i], fp1);
			is_found =0;
		}
	}

	if(fp1) {
		fclose(fp1);
	}
	return(0);
}

