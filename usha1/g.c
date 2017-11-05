#include<stdio.h>
#include<glib.h>
#include<stdlib.h>
#include<string.h>

#define M 20
#define success 0
#define failure 1
#define FREE(x)\
	if(x!=NULL)\
	{\
		free(x);\
		x=NULL;\
	}\

typedef struct emp
{
	char *name;
	char *id;
	int dept_id;
}NODE;

GSList* read(char *filename, GSList* list);
NODE* createnode(char* str);
GSList* add(GSList* list,char* str);
int display(GSList* list);
void print_fun(gpointer item,gpointer prefix);
int search_display(GSList* list);
int search_comp(gpointer data,gpointer user_data);
GSList* sort_id(GSList* list);
int sort_comp(gpointer data1,gpointer data2);
GSList* sort_name(GSList* list);
int name_comp(gpointer data1,gpointer data2);
GSList* del_last(GSList* list);
GSList* reverse(GSList* list);
GSList* del_all(GSList* list);
int free_list(GSList* list);
void free_fun(gpointer data);

GSList* read(char *filename, GSList* list)
{
	FILE* fp=NULL;
	size_t linesize=0;
	int count;
	char *line=NULL;
	fp=fopen(filename,"r");
	if(fp==NULL)
	{
		printf("\n filenot found");
		return NULL;
	}
	while((count=getline(&line,&linesize,fp))!=-1)
	{
		printf("\n %s",line);
		list=add(list,line);
		FREE(line);
	}
	fclose(fp);
	return list;
}

GSList* add(GSList* list,char* str)
{
	NODE* newnode = createnode(str);
	list=g_slist_append(list,(void*)newnode);
	if(list==NULL)
	{
		printf("\n node not added");
		return 0;
	}
	return list;
}

NODE* createnode(char* str)
{
	char* token = NULL;
	token = strtok(str,",");
	NODE* newnode = (NODE*)malloc(sizeof(NODE));
	if(newnode == NULL)
	{
		printf("node not cretaed");
		return 0;
	}
	newnode->name=(char*)malloc(sizeof(char)*(strlen(token)+1));
	if(newnode->name == NULL)
	{
		printf("\n memory not allocated");
		FREE(newnode);
		return 0;
	}
	strcpy(newnode->name,token);
	token=strtok(NULL,",");
	if(token!=NULL)
	{
		newnode->id=(char*)malloc(sizeof(char)*(strlen(token)+1));
		if(newnode->id==NULL)
		{
			printf("memory not allocated");
			FREE(newnode);
			FREE(newnode->name);
			return 0;
		}
		strcpy(newnode->id,token);
	}
	token=strtok(NULL,",");
	if(token!=NULL)
	{
		newnode->dept_id = atoi(token);

		
	}

	return newnode;
}

int display(GSList* list)
{
	g_slist_foreach(list,print_fun,NULL);
	return success;
}

void print_fun(gpointer item,gpointer prefix)
{
	NODE* temp=(NODE*)item;
	printf("\nname=%s\n id=%s \n dept_id=%d\n",temp->name,temp->id,temp->dept_id);
}

int search_display(GSList* list)
{
	char string[M];
	printf("enter name to search");
	scanf("%s",string);
	GSList* temp = g_slist_find_custom(list,(gpointer)string,search_comp);
	if(temp==NULL)
	{
		printf("\n not found");
		return failure;
	}
	gpointer item = temp->data;
	NODE* node = (NODE*)item;
	printf("%s %s %d",node->name,node->id,node->dept_id);
	return success;
}

int search_comp(gpointer data,gpointer user_data)
{
	NODE* temp=(NODE*)data;
	if(strcmp(temp->name,user_data)==0)
	{
		return success;
	}
	return failure;
}

GSList* sort_id(GSList* list)
{
	if(list==NULL)
	{
		printf("\n list is empty");
		return NULL;
	}
	GSList* temp = g_slist_sort(list,sort_comp);
	display(temp);
	return temp;
}
int sort_comp(gpointer data1,gpointer data2)
{
	NODE* temp1=(NODE*)data1;
	NODE* temp2=(NODE*)data2;
	if(temp1->dept_id == temp2->dept_id)
	{
		return 0;
	}
	else if(temp1->dept_id > temp2->dept_id)
		return 1;
	else
		return -1;
}

GSList* sort_name(GSList* list)
{
	if(list==NULL)
	{
		printf("\n list is empty");
		return NULL;
	}
	GSList* temp = g_slist_sort(list,name_comp);
	display(temp);
	return temp;
}
int name_comp(gpointer data1,gpointer data2)
{
	NODE* temp1=(NODE*)data1;
	NODE* temp2=(NODE*)data2;
	if(strcmp(temp1->name,temp2->name) < 0 )
	{
		return 0;
	}
	else if(strcmp(temp1->name, temp2->name)>0)
	{
		return 1;
	}
	return -1;
}
GSList* del_last(GSList* list)
{
	if (list == NULL)
        {
                printf("\nlist is empty");
                return NULL;
        }
	GSList* last = g_slist_last(list);
	list = g_slist_remove(list, (gconstpointer)last->data);
	//list=g_slist_remove(list,(gconstpointer)last->data);
	return list;
}

GSList* del_all(GSList* list)
{
	if(list == NULL)
	{
		printf("\n list is empty");
		return NULL;
	}
	GSList* last = g_slist_last(list);
	list = g_slist_remove_all(list,(gconstpointer)last->data);
	return list;
} 

GSList* reverse(GSList* list)
{
	if(list==NULL)
	{
		printf("no elements");
		return NULL;
	}
	list=g_slist_reverse(list);
	return list;
}
int free_list(GSList* list)
{
	if (list != NULL)
	{
	g_slist_free_full(list, free_fun);
	}
	return success;

}
void free_fun(gpointer data)
{
	NODE *temp = (NODE*)data;
	FREE(temp->name);
	FREE(temp->id);

}


int main(int argc,char* argv[])
{
	GSList* list=NULL;
	if(argc<2)
	{
		printf("\n insufficient arguments");
		return 0;
	}
	list=read(argv[1],list);
	display(list);	
	search_display(list);
	//printf("\nsorted id is\n");
	//list= sort_id(list);
	printf("\nsorted names are\n");
	list = sort_name(list);
	printf("\n sorted id are\n");
	list=sort_id(list);
	printf("\nafter deletion\n");
	del_last(list);
	del_last(list);
	display(list);
	printf("\n reverse list\n");
	list=reverse(list);
	display(list);
	printf("\nall\n");
//	del_all(list);
//	display(list);
	free_list(list);
	display(list);
	return 0;
}

