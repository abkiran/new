#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
struct Employees {
	char *emp_id;
	char *emp_name;
	char *dept_id;
};

struct Employees *employee;
 
int main( ) {

	employee = (struct Employees*)malloc(10 * sizeof(struct Employees));
	int n,i=0;
	int k=0,ecount=0;
	const char *delimiter_characters = ",";



	FILE *fp,*fp1;
	char data[128], *token;
	fp=fopen("usha/one.txt","r");

	while(fgets(data,sizeof(data),fp)!=NULL){

		if(i==0)
		{
			i++;
			continue;
		}
		printf("%s\n", data);
		token=strtok(data,delimiter_characters);
		
		employee[i].emp_id=strdup(token);
		token=strtok(NULL,delimiter_characters);
		employee[i].emp_name=strdup(token);
		token=strtok(NULL,delimiter_characters);
		employee[i].dept_id=strdup(token);

		i++;
		ecount++;
		// employee[i].emp_name="Kiran";
	}
	
	for(i=1;i<=ecount;i++){
		printf("_______________________\n");
		printf("Employee - %d:\n", i);
		printf("\nemp id--->%s\n", employee[i].emp_id);
		printf("\nemp name---->%s\n", employee[i].emp_name);
		printf("\ndept id---->%s\n", employee[i].dept_id);
		printf("_______________________\n");
	}

	fp1 = fopen("usha/two.txt","w");
	if(fp1== NULL)
	{
		printf("\nFile not opened");
		return 0;
	}

	fputs("emp_id,emp_name,dept_id\n", fp1);
	for(i=1;i<=ecount;i++){
		fputs(employee[i].emp_id, fp1);
		fputs(",", fp1);
		fputs(employee[i].emp_name, fp1);
		fputs(",", fp1);
		fputs(employee[i].dept_id, fp1);
		// fputs("\n", fp1);
	}

	return 0;
}