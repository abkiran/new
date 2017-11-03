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

// int tokenized_output( char* arr[], int line_count,char* delim, char* ofname );

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
	FILE *fp = NULL, *fp1;
	int i = 0;
	char *last_token; 
    const char *delimiter_characters = " ";

		if(argc ==3)
		{
			//Check input file
			fp = fopen(argv[1], "r");
			if(fp == NULL)
			{
				printf("could not open a file\n");
				return 0;
			}

			//Check output file
			fp1 = fopen(argv[2],"w");
			if(fp1== NULL)
			{
				printf("\nFile not opened");
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

				//generating tokens
	            fputs("\nLine Number: \n", fp1);
	            fputs(line, fp1);
	            fputs("\n", fp1);
				last_token = strtok( line, delimiter_characters );
	            while( last_token != NULL ){
	                printf( "%s\n", last_token );
	            	fputs("\n", fp1);
	                fputs(last_token, fp1);
	                last_token = strtok( NULL, delimiter_characters );
	            }

	            // write output


				i++;
			}

			// tokenized_output(arr,i,',',argv[2]);
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
// int tokenized_output( char* arr[], int line_count,char* delim, char* ofname ){
// 	FILE *fp1;
// 	int i,z;
// 	char *tokens;
// 	fp1 = fopen(ofname,"w");
// 	if(fp1== NULL)
// 	{
// 		printf("\nFile not opened");
// 		return 0;
// 	}
// 	printf("Kiran\n" );
// 	for (int i = 0; i < line_count; ++i)
// 	{
// 		z=0;
// 		tokens = strtok(arr[i],' ');
// 		while(tokens!=NULL){
// 			arr[i]=tokens;
// 			tokens=strtok(NULL,' ');
// 			// printf("%s\n", arr[i][z]);
// 		}
// 	}
// 	fclose(fp1);
// 	return 0;
// }
