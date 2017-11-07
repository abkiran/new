#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int isvowel(char );
int main()
{
	char str[100],
		 word[100];
	char *token;
	char *wtoken;
	printf("Enter a string and a word\n");
	int i=0,j=0,n;
	fgets(str,100,stdin);
	n=strlen(str);
	str[n] = '\0';
    while (i < n)
    {
        if(str[i]==' ' && (str[i+1]==' ' || str[i-1]==' '))
        {
            for(j=i;j<n;j++)
            str[j]=str[j+1];
            n--;
        }
        else
        {
            i++;
        }
    }
    
	printf("%s", str);
	strcpy(word,str);
	char *p = strtok (str, " ");
	i=0;
	while (p != NULL)
	{
	    i++;
	    p = strtok (NULL, " ");
	}
	printf("%d\n",i);
	if(i>2 || strstr(word,"?")!=0 || strstr(word,"-")!=0 ){
		printf("%s\n",word);
	}



	return 0;
}