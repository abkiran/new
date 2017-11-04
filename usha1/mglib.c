#include<glib.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define M 20
#define success 0
#define failure 1
#define FREE(x)	\
	if (x != NULL)	\
	{\
		free(x);\
		x = NULL;\
	}\


typedef struct node
{
	char *name;
	char *id;
	char *dept_id;
}NODE;

GSList* file(GSList *list, char *filename);
int sortcmp(gpointer item1,gpointer item2);
NODE* create(char *line);
GSList* add(GSList* temp,char *line);
int comp(gpointer data,gpointer userdata);
int search(GSList *list);
GSList* sortid(GSList* list);
int display(GSList *list);
void print_fun(gpointer item,gpointer prefix);

GSList *list=NULL,
	*iterator=NULL;

int main(int argc,char *argv[])
{
	if(argc<2)
	{
		printf("insufficient arguments");
		return 0;
	}

	list = file(list,argv[1]);
	search(list);
	display(list);
	list=sortid(list);
	
	/*for(iterator = list;iterator;iterator = iterator->next)
         printf("%s\n",(char*)iterator->string);
	 g_slist_free(list);*/

	return 0;

}
GSList* file(GSList *list, char *filename)
{
	FILE *fp = NULL;
	size_t read;
	size_t line_size = 0;	
	char *line;
	//char *string;
	
	fp = fopen(filename, "r");
	if (fp == NULL)
	{
	 	printf("\n File not found");
		return 0;
	}
	while ((read = (getline(&line,&line_size, fp))) != -1)
	{
  		printf("\n%s\n", line);
		list=add(list,line);
		FREE(line);
	}
		
	/*for(iterator = list; iterator; iterator = iterator->next)
	{
       		printf("%s\n",((NODE *)iterator->data)->name);
		printf("%s\n",((NODE *)iterator->data)->id);
		printf("%s\n",((NODE*)iterator->data)->dept_id);	
	}*/

	fclose(fp);
	//g_slist_free(list);
	return list;
}

NODE* create(char *line)
{
	NODE *newlist=NULL;
	char *token1=NULL;
	newlist = (NODE*)malloc(sizeof(NODE));
	if(newlist==NULL)
	{
		printf("list not founf");
		return 0;
	}
	token1=strtok(line,",");
	printf("%s\n",token1);
	newlist->name=(char *)malloc(sizeof(char)*(strlen(token1)+1));
	if(newlist->name==NULL)
	{
		printf("memory not allocated");
		free(newlist);
		return 0;
	}
	strcpy(newlist->name,token1);
	//printf("%s",newlist->name);
	token1= strtok(NULL,",");
	if(token1!=NULL)
	{
		newlist->id=(char *)malloc(sizeof(char)*(strlen(token1)+1));
		if(newlist->id==NULL)
		{
			printf("\n memory not allocated");
			free(newlist->name);
			free(newlist);
			return 0;
		}
		
		strcpy(newlist->id,token1);
	}
	//printf("%s",newlist->id);
	token1=strtok(NULL,",");
	if(token1!=NULL)
	{
		newlist->dept_id=(char*)malloc(sizeof(char)*(strlen(token1)+1));
		if(newlist->dept_id==NULL)
		{
			printf("\n memory not allocated");
			
		free(newlist->name);
		free(newlist->id);
		free(newlist);	
		return 0;
		}
		//free(newlist->name);
		//free(newlist->id);
		strcpy(newlist->dept_id,token1);
	
	//printf("%s",newlist->dept_id);
	}
return newlist;
}

GSList* add(GSList* list,char *line)
{
	NODE* new = create(line);
	list=g_slist_append(list,(void*)new);
	if(list == NULL)
	{
		printf("\n node is not added");
		return NULL;
	}
	return list;
}		

int comp(gpointer data,gpointer userdata)
{
	NODE *temp =(NODE*)data;
	NODE *newlist=NULL;
	if(strcmp(newlist->name,(char*)userdata)==0)
	{
		return 0;
	}
	return 1;

}

int search(GSList *list)
{
	char name[M];
	printf("enter the name to search");
	scanf("%s",name);
	GSList *temp = g_slist_find_custom(list,(gpointer)(name),(GCompareFunc)comp);
	if (temp == NULL)
	{
		printf("\nNOT found");
		return failure;
	}
	gpointer item = temp->data;
	NODE *emp = (NODE*)item;
	printf("Emp found: %s\t%s\t%d\n", emp->name, emp->id, emp->dept_id);
	return success;
}

int sortcmp(gpointer item1,gpointer item2)
{
	NODE *temp1=(NODE*)item1;
	NODE *temp2=(NODE*)item2;
	if(temp1->dept_id==temp2->dept_id)
	{
		return 0;
	}
	else if(temp1->dept_id > temp2->dept_id)
	{
		return 1;
	}
	else
		return -1;
} 
	
GSList* sortid(GSList* list)
{
	if(list == NULL)
	{
		printf("\n list is empty");
		return NULL;
	}
	GSList *temp=g_slist_sort(list,sortcmp);
	display(temp);
	return temp; 
}

int display(GSList *list)
{
	g_slist_foreach(list,print_fun,NULL);
	return success;
}

void print_fun(gpointer item,gpointer prefix)
{
	NODE *temp=(NODE*)item;
	printf("%s %s %s\n",temp->name,temp->id,temp->dept_id);
}
