#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int isvowel(char );
int main()
{
		char str1[100],
			 word1[100];
		char *token;
		char *wtoken;
		printf("Enter a string and a word\n");
		int i=0;
		fgets(str1,100,stdin);
		fgets(word1,100,stdin);
		for(i = 0; i < strlen(str1); i++ )
		{
			if(str1[i] == '\n') str1[i] = '\0';
		}
		for(i = 0; i < strlen(word1); i++ )
		{
			if(word1[i] == '\n') word1[i] = '\0';
		}
		char *arr[100];
		char *arr1[100];

		i = 0;
		char *p = strtok (str1, " ");
		char *array[100];
		int token_count=0;

		while (p != NULL)
		{
		    array[i++] = p;
		    p = strtok (NULL, " ");
			token_count++;
		}

		i = 0;
		char *p1 = strtok (word1, " ");
		char *array1[100];
		int wtoken_count=0;

		while (p1 != NULL)
		{
		    array1[i++] = p1;
		    p1 = strtok (NULL, " ");
			wtoken_count++;
		}

		if(token_count!=wtoken_count){
			printf("\nWord counts are not matching\n");
			return 0;
		}

		i=0;
		for (i = 0; i < wtoken_count; ++i) 
		{
			// printf("\n\n%s,%s\n\n",array[i],array1[i]);
			check(array[i],array1[i]);
		}
		return 0;
}
void check(char *str, char word[])
{
		int len = strlen(str),i,q;
		char *string = (char *)malloc(sizeof(char)*(2 * strlen(str)));
		strcpy(string,str);
		for(i=0;i<len;)
		{
				q = isvowel(string[0]);
				if(q==1)
				{
					break;
				}
				// *(string +len) = *(string+i);
				// *(string +i)='\0';
				string[len] = string[0];
				string[0]='\0';
				// len=len+1;
				string++;
				// break;
				
		}
		// printf("\nstr=%s\n", string);
		// *(string +len) = 'a';
		// *(string +len +1)='y';
		// *(string +len +2)='\0';
		
		string[len] = 'a';
		string[len+1]='y';
		string[len+2]='\0';

		// printf("%s",string);
		if(strcmp(string,word)==0)
		{
				printf("\n\n %s is a piglatin of %s\n",word,str);
		}
		else
				printf("\n\n %s is not a piglatin of %s\n",word,str);
}
int isvowel(char ch)
{
		ch = tolower(ch);
		if((ch =='a')||(ch =='e')||(ch =='i')||(ch =='o')||(ch == 'u'))
		{
				return 1;
		}
		return 0;
}