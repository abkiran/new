#include </usr/include/reglib/reglib.h>
#include<stdio.h>
#include<string.h>
typedef struct GSList
{
	char *name;
	char *id;
	int *dept_id;
	GSList *next;
};
//typedef struct_GSList GSList;
//GSList *g_slist_alloc(void);
GSList *list = NULL;
	//*number_list = NULL;

GSList* g_slist_alloc(void);
GSList* g_slist_append(GSList *list,
			 gpointer  data); 
int main(int argc,char *argv[])
{
	char *data;
	if(argc<2)
	{
		printf("insufficient arguments\n");
		return 0;
	}
	else
	{
		FILE *fp=NULL;
		fp=fopen(argv[1],"r");
		size_t line_size=0;
		size_t read;
		char *line = NULL,*token1,*token2,*token3;
		const char *delimiter_characters = ",";
		if(fp==NULL)
		{
			printf("no file found\n");
			return 0;
		}
	
	
			while(read=getline(&line,&line_size,fp)!=-1)
				printf("%s",line);
				
				token1=strtok(line,delimiter_characters);
				
				token2=strtok(NULL,delimiter_characters);

				token3=strtok(NULL,delimiter_characters);
				
				g_slist__append(&list,token1,token2,token3);
			}
return 0;
}
	
GSList* g_slist_append(GSList *list,char *name,char *id,char *dept_id)
{
	GSList *newlist;
	GSList *last;
	newlist = g_slist_alloc();
	// newlist->data=data;
	newlist->name = (char*)malloc(sizeof(char) * strlen(name) + 1);
	if(newlist->name ==NULL)
	{
		printf("\n error in allocating memory for name");
		return NULL;
	}
	strcpy(newlist->name , name);

	newlist->id = (char*)malloc(sizeof(char) * strlen(id) + 1);
	if(newlist->id ==NULL)
	{
		printf("\n error in allocating memory for id");
		return NULL;
	}
	strcpy(newlist->id , id);

	newlist->dept_id = (char*)malloc(sizeof(char) * strlen(dept_id) + 1);
	if(newlist->dept_id ==NULL)
	{
		printf("\n error in allocating memory for dept_id");
		return NULL;
	}
	strcpy(newlist->dept_id , dept_id);

	newlist->next=NULL;
	if(list)
	{
		last = g_slist_last(list);
		last->next=newlist;
		return list;
	}
	else
		return newlist;
}