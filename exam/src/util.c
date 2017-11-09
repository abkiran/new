#include<head.h>

GSList* read(char* filename,GSList* list)
{
	int count;
	size_t line_size = NULL;
	char* line = NULL;
	char ch='\0',*res = NULL;
	NODE* pat = NULL,*temp = NULL;
	FILE* fp = NULL;
	fp = fopen(filename,"r");
	if(fp== NULL)
	{
		printf("filenot ");
		return 0;
	}
	while((count =getline(&line,&line_size,fp))!=-1)
	{
		printf("%s",line);
		list= add(list,line);
		ch = check(temp,pat);
		if(ch == 'y')
		{
			printf("\n pattern found %s",line);
			res = remove_space(line);
			strcpy(temp->text,res);
			list = g_slist_append(list,(gpointer)temp);
		}
	}
	fclose(fp);
	free(line);
	return list;
}

int display(GSList* list)
{
	g_slist_foreach(list,print_fun,NULL);
	return 0;
}
void print_fun(gpointer item,gpointer prefix)
{
	NODE* temp = (NODE*)item;
	printf("%s",temp->text);
}
GSList* add(GSList* list,char*str)
{

	NODE* temp = create(str);
	list = g_slist_append(list,(void*)temp);
	if(list == NULL)
	{
		printf("\n node not created");
		return 0;
	}
	return list;
}
NODE* create(char *str)
{
	NODE* newnode = (NODE*)malloc(sizeof(NODE));
	if(newnode == NULL)
	{
		printf("\n node not");
		return 0;
	}
	newnode->text = (char*)malloc(sizeof(char)*(strlen(str)+1));
	if(newnode->text == NULL)
	{
		printf("memory not");
		return 0;
	}
	strcpy(newnode->text,str);
	return newnode;
}

GSList *write_to_file(GSList* list,char *filename)
{
	FILE* fp = NULL;
	fp = fopen(filename,"w");
	if(fp == NULL)
	{
		printf("\n no file");
		return 0;
	}
	g_slist_foreach(list,write_fun,fp);
	return list;
}
void write_fun(gpointer item,gpointer fp)
{
	NODE* temp =(NODE*)item;
	fputs(temp->text,fp);
	fputs(" ",fp);
}
char check(NODE* temp,char *pat)
{
	char *token = NULL;
	char buffer[20],*check_pat=NULL;
	int count =0;
	strcpy(buffer,temp->text);
	token = strtok(temp->text,".?");
	while(token != NULL)
	{
		count++;
		check_pat = strcasestr(buffer,pat);
		if(count >= 4)
		{
			break;
		}
		token = strtok(NULL," ");
	}
	if(count >= 4 && check_pat != NULL)
	{
		printf("\n pattern found");
		return 'y';
	}
	else
	return 'n';
}

char *remove_space(char *line)
{
	char *temp = NULL;
	int i =0;
	temp = (char*)malloc(sizeof(char)*(strlen(line)+1));
	strcpy(temp,line);
	while(*line != '\0')
	{
		while((*line == ' ')&&(*(line+1) == ' '))
		{
			line++;
		}
		temp[i] = *line;
		i++;
		line++;
	}
	temp[i] = '\0';
	printf("%s",temp);
	return temp;
}
void free_fun(gpointer data)
{
	NODE *temp =(NODE*)data;
	if(temp == NULL)
	{
		return;
	}
	free(temp->text);
	free(temp);
}
