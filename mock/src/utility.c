#include<head.h>

GSList* read(char *filename,GSList* list)
{
	int count;
	size_t line_size=0;
	char *line = NULL;
	FILE *fp=NULL;
	fp = fopen(filename,"r");
	if(fp == NULL)
	{
		printf("no file to open\n");
		return 0;
	}
	printf("\nfilename = %s\n",filename);
	while((count = getline(&line,&line_size,fp))!=-1)
	{
		printf("\n%s\n",line);
		list = add_to_list(list,line);
		FREE(line);
	}
	fclose(fp);
	return list;
}

int display(GSList* list)	
{
	g_slist_foreach(list,print_fun,NULL);
	return success;
}

void print_fun(gpointer item,gpointer prefix)
{
	NODE* temp = (NODE*)item;
	printf(" name = %s\n id = %s\n age = %d\n",temp->name,temp->id,temp->age);
}

GSList* add_to_list(GSList* list,char *str)
{
	NODE* newnode = createnode(str);
	if(newnode == NULL)
	{
		printf("\n node not created");
		return 0;
	}
	list = g_slist_append(list,(void*)newnode);
	if(list == NULL)
	{
		printf("\n list is not added");
		return NULL;
	}
	return list;
}

NODE* createnode(char *str)
{
	char *token = NULL;
	token = strtok(str," ");
	NODE* newnode = (NODE*)malloc(sizeof(NODE));
	if(newnode == NULL)
	{
		printf("\n no nodes to create");
		return 0;
	}
	
	strcpy(newnode->name,token);
	token = strtok(NULL," ");
	if(token != NULL)
	{
		strcpy(newnode->id,token);
	}

	token = strtok(NULL," ");
	if(token != NULL)
	{
		newnode->age = atoi(token);
	}
	return newnode;
}
GSList* write_to_file(char *filename,GSList* list)
{
	FILE* fp = NULL;
	fp = fopen(filename,"w");
	if(fp == NULL)
	{
		printf("\n file not found");
		return 0;
	}
	printf("%s\n",filename);
	g_slist_foreach(list,write_fun,fp);
	fclose(fp);
	return list;
}

void write_fun(gpointer item,gpointer fp)
{
	NODE* temp = (NODE*)item;
	char age[MAX];
	fputs(temp->name,fp);
	fputs(" ",fp);
	fputs(temp->id,fp);
	fputs(" ",fp);
	sprintf(age,"%d",temp->age);
	fputs(age,fp);
	fputs("\n",fp);
}

GSList* sort_age(GSList* list)
{
	if(list == NULL)
	{
		printf("\n list is empty");
		return NULL;
	}
	GSList* temp = g_slist_sort(list,sort);
	display(temp);
	return temp;
}

int sort(gpointer item1,gpointer item2)
{
	//printf("***********");
	NODE* temp1 = (NODE*)item1;
	NODE* temp2 = (NODE*)item2;
	if(temp1->age == temp2->age)
	{
		return 0;
	}
	else if(temp1->age > temp2->age)
		return 1;
	else
		return -1;
}

GSList *remove_duplicates (GSList* list)
{
    GSList *a, *b, *dub;

    /* Pick elements one by one */
    for (a = list; a; a = a->next) {
        /* Compare the picked element with rest of the elements */
        for (b = a->next; b;) {
            dub = b;
            b = b->next;
            printf("%s\n", dub->data);
            if (strcmp(a->data,dub->data)==0)
                list = g_slist_delete_link (list, dub);
        }
    }

    /* return list without duplicates */
    return list;
}

// int remove_duplicates(GSList* list)	
// {
// 	// GSList *iterator=NULL;
// 	int i=0;
// 	for(iterator = list;iterator;iterator = iterator->next)
// 	{
//         printf("name=%s\n",iterator->name);
// 		g_slist_foreach(list,remove_duplicates_fun,iterator->name);
// 	}
// 	return success;
// }

// void remove_duplicates_fun(gpointer item,gpointer prefix)
// {
// 	NODE* temp = (NODE*)item;
// 	printf("name = %s\n id = %s\n age = %d\n",temp->name,temp->id,temp->age);
// 	printf("name = %s\n",prefix);
// }

// void remove_duplicates(char *sentence)
// {
// 	char *temp = NULL;
// 	char *temp1;
// 	temp = strtok(sentence," ");
// 	if(temp != NULL)
// 	{
// 		strcpy(temp1,temp);
// 		while((temp = strtok(NULL, " "))!= NULL)
// 		{
// 			if(strstr(temp1,temp) == NULL)
// 			{
// 				strcat(temp1," ");
// 				strcat(temp1,temp);
// 			}
// 		}
// 	}
// 	strcpy(sentence,temp1);
// 	puts(sentence);
// 	FREE(temp1);
// }


// GSList* sort_name(GSList* list)
// {
// 	if(list == NULL)
// 	{
// 		printf("\n list is empty");
// 		return NULL;
// 	}
// 	GSList* temp = g_slist_sort(list,name_comp);
// 	display(temp);
// 	return temp;
// }

// int name_comp(gpointer data1,gpointer data2)
// {
// 	NODE* temp1 = (NODE*)data1;
// 	NODE* temp2 = (NODE*)data2;
// 	if(strchr(temp1->name,temp2->name)== 0)
// 	{
// 		GSList* last = g_slist_last(list);
// 		list = g_slist_remove(list,(gconstpointer)last->data);
// 	}
// 	return list;
// }
