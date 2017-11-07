#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct node
{
	char *name;
	char *dept;
	char *designation;
	struct node *next;
}NODE;

NODE *head = NULL;

NODE* insert(NODE **head , char *line )
{
	NODE *temp = NULL;
	temp = (NODE *)malloc(sizeof(NODE));
	if(temp == NULL)
	{
		printf(" error in allocating temp\n");
		return NULL;
	}
	
	temp->name = (char*)malloc(sizeof(char) * strlen(line) + 1);
	if(temp->name ==NULL)
	{
		printf("\n error in allocating memory for name");
		return NULL;
	}
	
	strcpy(temp->name , line);
	temp->next = *head;
	*head = temp;
	return temp;
}

int delete(NODE *newnode)
{
	NODE *temp= newnode->next;	
	newnode->next = temp->next;
	temp->next = NULL;
	free(temp);
	return 0 ;
}

int updatelist(NODE **head)
{
	NODE *temp = *head;
	NODE *deletehead = NULL;
	int len = 0;
	int flag = 0 ;

	while(temp !=NULL && temp->next != NULL )
	{
		flag=0;
		len = strlen(temp->next->name);
		if(len < 10)
		{
			flag = 1;
			delete(temp);
		}
		
		if(flag == 0)
		{
			temp = temp->next;
		}
		if((strlen(temp->name))<10)
 		{
			deletehead = temp;
			*head = temp->next;
 			free(deletehead);
 		}
	}
	
return 0;
}
int printlist(NODE *head)
{
	if(head == NULL )
	{
		printf("list is empty");
		return 0;
	}
	else
	{
	printf(" the elements in the list are: \n");
	while(head != NULL)
	{
		printf("\n %s ",head->name);
		head = head->next;
	}
	}
return 0;
}

int main(int argc , char *argv[])
{	
	FILE *fp = NULL;
	NODE *temp = NULL;
	size_t len = 0;
	size_t read;
	char *line = NULL;
	
	fp = fopen(argv[1] , "r");
	
	if (fp == NULL)
	{
	 	printf("\n File not found");
		return 0;
	}

	while((read=getline(&line , &len , fp)) != -1)
	{
		printf("%s", line);
		temp = insert(&head ,line);
		
		if(temp == NULL)
		{
			free(line);
			fclose(fp);
			break;
		}
	}	
 printlist(head);
 updatelist(&head);
 printf("\n");
 printf("after updation\t");
 printlist(head);
 return 0;
}
	
