#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<glib.h>

typedef struct node
{
	char *name;
	char *id;
	char *dept_id;
	GSList *next;
}NODE;

int file(GSList *list, char *filename);
NODE* create(char *string);

GSList* add(GSList* temp,char *string);
GSList *list=NULL,
	*newlist=NULL,
	*iterator=NULL;

int main(int argc,char **argv)
{
	if(argc<2)
	{
		printf("insufficient arguments");
		return 0;
	}
	else
	file(list,argv[1]);

	for(iterator = list;iterator;iterator = iterator->next)
	{
         printf("name=%s\n",iterator->name);
         printf("id=%s\n",iterator->id);
         printf("dept_id=%s\n",iterator->dept_id);
	}
	 // g_slist_free(list);

return 0;

}
	
int file(GSList *list, char *filename)
{
	FILE *fp = NULL;
	int read;
	size_t line_size = 0;	
	char *line = NULL;
	fp = fopen(filename, "r");
	if (fp == NULL)
	{
	 	printf("\n File not found");
		return 0;
	}
	while ((read = (getline(&line,&line_size, fp))) != -1)
	{
  		printf("%s", line);
		add(list,line);
		
	}
	     

	fclose(fp);
	return 0;
}

	

NODE* create(char *string)
{
	NODE *newlist=NULL;
	char *token1=NULL;
	newlist = (NODE*)malloc(sizeof(NODE));
	if(newlist==NULL)
	{
		printf("list not founf");
		return 0;
	}
	token1=strtok(string,",");
	newlist->name=(char *)malloc(sizeof(char)*(strlen(token1)+1));
	if(newlist->name==NULL)
	{
		printf("memory not allocated");
		free(newlist);
		return 0;
	}
	strcpy(newlist->name,token1);
	token1= strtok(NULL,",");
	if(token1!=NULL)
	{
		newlist->id=(char *)malloc(sizeof(char)*(strlen(token1)+1));
		if(newlist->id==NULL)
		{
			printf("\n memory not allocated");
			return 0;
		}
		free(newlist->name);
		strcpy(newlist->id,token1);
	}
	token1=strtok(NULL,",");
	if(token1!=NULL)
	{
		newlist->dept_id=(char*)malloc(sizeof(char)*(strlen(token1)+1));
		if(newlist->dept_id==NULL)
		{
			printf("\n memory not allocated");
			return 0;
		}
		free(newlist->name);
		free(newlist->id);
		strcpy(newlist->dept_id,token1);
	}
	return newlist;
}

GSList* add(GSList* list,char *string)
{
	list=create(string);
	list=g_slist_append(list,string);
	return list;
}