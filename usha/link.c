#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct node
{
	char *value;
	char *name;
	struct node*next;
};

typedef struct node snode;
snode* create_node(char*);

void insert_node_first(char*);
void insert_node_last(char*);
void deletenode();
void custom_deletenode();
void search();
void display();
//typedef struct node snode;

snode *newnode,*ptr,*prev,*temp;
snode *first=NULL,*last = NULL;

int main()
{
	int ch;

	FILE *fp,*fp1;
	char data[128], *val;
	int i=0,z;
	fp=fopen("input.txt","r");

	while(fgets(data,sizeof(data),fp)!=NULL){
		val=strdup(data);
		for(z = 0; z < strlen(val); z++ )
		{
			if(val[z] == '\n') val[z] = '\0';
		}
		printf("\n---%s---\n", val);
		if(i==0)
		{
			insert_node_first(val);
		} else {
			insert_node_last(val);
		}
		i++;
	}
	printf("\nFile data\n_______________________________");
	display();
	custom_deletenode();
	printf("\nUpdated file data\n_______________________________");
	display();



	// char ans='y';
	// while(ans == 'y')
	// {
	// 	printf("\n 1.insert node at first");
	// 	printf("\n 2.insert node at last");
	// 	printf("\n 3. delete node");
	// 	printf("\n 4.search");
	// 	printf("\n 5.display");
	// 	printf("\n enter the choice");
	// 	scanf("%d",&ch);
	// 	switch(ch)
	// 	{
	// 		case 1:
	// 			insert_node_first();
	// 			break;
	// 		case 2:
	// 			insert_node_last();
	// 			break;
	// 		case 3:
	// 			deletenode();
	// 			break;
	// 		case 4:
	// 			search();
	// 			break;
	// 		case 5:
	// 			display();
	// 			break;
	// 	}
		// printf("\n do u want to continue(y/n)");
		// scanf("%s",&ans);
		// printf("%c\n", ans);

	// }
	return 0;
}

snode* create_node(char *val)
{
	newnode=(snode *)malloc(sizeof(snode));
	if(newnode==NULL)
	{
		printf("memory not allocated");
		return 0;
	}
	else
	{
		newnode->value=val;
		newnode->next=NULL;
		return newnode;
	}
}

void insert_node_first(char *val)
{
	// int val;
	//  char *name=NULL;

	// printf("enter the value of data");
	// scanf("%d",&val);
	newnode=create_node(val);
	if(first == last && first == NULL)
	{
		first =last=newnode;
		first->next=NULL;
		last->next=NULL;
	}
	else
	{
		temp=first;
		first =newnode;
		first->next=temp;
	}
}
void insert_node_last(char *val)
{
	// int val;
	// printf("enter value of data");
	// scanf("%d",&val);
	newnode = create_node(val);
	if(first==last&&last ==NULL)
	{
		first = last = newnode;
		first->next=NULL; 
		last->next = NULL;
	}
	else
	{
		last->next=newnode;
		last=newnode;
		last->next=NULL;
	}
}

void deletenode(int pos)
{
	int count =0,i;
	if(first==NULL)
	{
		printf("no node to delete");
	}
	else
	{
		// printf("enter position");
		// scanf("%d",&pos);
		ptr=first;
		if(pos==1)
		{
			first=ptr->next;
			printf("element deleted");
		}
		else
		{
			while(ptr!=NULL)
			{
				ptr=ptr->next;
				count=count+1;
			}
			if(pos>1&&pos<=count)
			{
				ptr=first;
				for(i=1;i<pos;i++)
				{
					prev=ptr;
					ptr=ptr->next;
				}
				prev->next=ptr->next;
			}
			else
			{
				printf("not a valid one");
			}
			free(ptr);
			printf("element deleted");
		}
	}
}

void search()
{
	int flag=0,key,pos=0;
	if(first==NULL)
	{
		printf("no nodes");
	}
	else
	{
		printf("enter the value to search");
		scanf("%d",&key);
		for(ptr=first;ptr!=NULL;ptr=ptr->next)
		{
			pos=pos+1;
			if(ptr->value==key)
			{
				flag=1;
				break;
			}
		}
		
		if(flag==1)
		{
			printf("\nFound at key=%d, pos=%d",key,pos);
		}
		else
		{
			printf("not found");
		}
	}
}

void display()
{
	// struct node *temp;
	temp=first;
	if(temp==NULL)
	{
		printf("no elements to display");
		return;
	}
	
	printf("Elements in linked list are\n");
	while(temp!=NULL)
	{
		printf("%s\n",temp->value);
		temp=temp->next;
	}
}

// void  display()
// {
//   struct node *temp;
//   temp=first;
//   if(temp==NULL)
//   {
//     printf("no elements\n");
//     return;
//   }
//   printf("elements in linked list are\n");
//   while(temp!=NULL)
//   {
//     printf("%d\n",temp->data);
//     temp=temp->next;
//   }
// }




void custom_deletenode()
{
	int pos=1,count =0,i,length;
	if(first==NULL)
	{
		printf("no node to delete");
	}
	else
	{
		
		temp=first;
		if(temp==NULL)
		{
			printf("no elements to display");
			return;
		}
		
		while(temp!=NULL)
		{
			length=strlen(temp->value);
			printf("\nValue=%s, Length=%d\n",temp->value,length);
			if(length<4){
				deletenode(pos);
				// ptr=first;
				// if(pos==1)
				// {
				// 	first=ptr->next;
				// 	printf("element deleted");
				// }
				// else
				// {
				// 	while(ptr!=NULL)
				// 	{
				// 		ptr=ptr->next;
				// 		count=count+1;
				// 	}
				// 	if(pos>1&&pos<=count)
				// 	{
				// 		ptr=first;
				// 		for(i=1;i<pos;i++)
				// 		{
				// 			prev=ptr;
				// 			ptr=ptr->next;
				// 		}
				// 		prev->next=ptr->next;
				// 	}
				// 	else
				// 	{
				// 		printf("not a valid one");
				// 	}
				// 	free(ptr);
				// 	printf("element deleted");
				// }
			}
			pos=pos+1;
			temp=temp->next;
		}

	}
}