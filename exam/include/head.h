#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<glib.h>

typedef struct node
{
	char *text;
}NODE;

GSList* list=NULL;
GSList* read(char *filename,GSList* list);
int display(GSList *list);
void print_fun(gpointer item,gpointer prefix);
GSList *add(GSList* list,char* str);
NODE* create(char* str);
GSList* write_to_file(GSList* list,char *filename);
void write_fun(gpointer item,gpointer fp);
char check(NODE* temp, char *pat);
char *remove_space(char *line);
void free_fun(gpointer data);
