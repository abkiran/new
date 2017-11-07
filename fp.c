#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void  strcpy_new(char *src,char *dest);
void  substr_search(char *src,char *pattern);
int main()
{

	int opt;
	void (*ptr) (char *str1, char *str2);
	char *input,
		*dest=NULL;
	printf("\n\tEnter The Input String\n");
	fgets(input,100,stdin);
	printf("\tPlease Enter Your Choice\n\tFor String Search Press 1\n\tFor String Copy Press 2\n");
	scanf("%d",&opt);
	printf("\nSource=%s\n", input);
	dest=(char *)malloc((strlen(input)+1)*sizeof(char));

	switch(opt)
	{
		case 1:
			printf("\n\tEnter The Pattern To Search\n");
			scanf("%s",dest);
			printf("pat=%s\n",dest);		
			ptr=substr_search;
			break;
		case 2:
			ptr = strcpy_new;
			break;
		default:
			printf("\n\tInvalid Option Found\n");
	}
	(*ptr)(input,dest);
	return 0;
}
void strcpy_new(char *src,char *dest)
{
	while(*src!='\0')
	{
		*dest=*src;
		src++;
		dest++;
	}
	printf("\nCopied string:%s\n", dest);
}
void substr_search(char *src,char *pattern)
{
	
	printf("pat=%s\n",pattern);
	char *res;
	res=(char *)malloc(sizeof(char)*(strlen(src)+1));
	res=strstr(src,pattern);
	printf("\nResult = %s\n",res);
}