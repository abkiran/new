#include<stdio.h>
#include<glib.h>
#include<stdlib.h>
#include<string.h>

#define MAX 20
#define success 0
#define failure 1
#define FREE(x)\
	if(x != NULL)\
	{\
		free(x);\
		x=NULL;\
	}\

typedef struct records
{
	char name[255];
	char id[3];
	int age;
}NODE;

GSList *list;
GSList* read(char *filename,GSList *list);
int display(GSList* list);
void print_fun(gpointer item,gpointer prefix);
GSList* add_to_list(GSList* list,char* str);
void write_fun(gpointer item,gpointer fp);
GSList* write_to_file(char *filename,GSList* list);
NODE* createnode(char *str);
GSList* sort_age(list);
int sort(gpointer item1,gpointer item2);
GSList* sort_name(GSList* list);
int name_comp(gpointer data1,gpointer data2);
int name_comp(gpointer data1,gpointer data2);
// int remove_duplicates(GSList* list);
// void remove_duplicates_fun(gpointer item,gpointer prefix);
GSList *remove_dup (GSList *list);