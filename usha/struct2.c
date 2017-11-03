#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
struct Employees1 {
	char *emp_name;
	char *dept_name;
};

struct Employees1 *employee1;
 
struct Employees2 {
	char *emp_name;
	char *designation;
};

struct Employees2 *employee2;
 
struct Employees {
	char *emp_name;
	char *dept_name;
	char *designation;
};

struct Employees *employee;
 
int main( ) {

	employee = (struct Employees*)malloc(10 * sizeof(struct Employees));
	employee1 = (struct Employees1*)malloc(10 * sizeof(struct Employees1));
	employee2 = (struct Employees2*)malloc(10 * sizeof(struct Employees2));
	int n,i=0;
	int k=0,z,ecount1=0,ecount2=0;
	const char *delimiter_characters = ",";



	FILE *fp,*fp1;
	char data[128], *token;
	fp=fopen("one.txt","r");
	fp1=fopen("two.txt","r");

	while(fgets(data,sizeof(data),fp)!=NULL){

		if(i==0)
		{
			i++;
			continue;
		}
		printf("%s\n", data);
		token=strtok(data,delimiter_characters);
		for(z = 0; z < strlen(token); z++ )
		{
			if(token[z] == '\n') token[z] = '\0';
		}
		employee1[i].emp_name=strdup(token);
		token=strtok(NULL,delimiter_characters);
		for(z = 0; z < strlen(token); z++ )
		{
			if(token[z] == '\n') token[z] = '\0';
		}
		employee1[i].dept_name=strdup(token);

		i++;
		ecount1++;
		// employee1[i].emp_name="Kiran";
	}
	
	// for(i=1;i<=ecount1;i++){
	// 	printf("_______________________\n");
	// 	printf("Employee1 - %d:\n", i);
	// 	printf("\nemp name---->%s", employee1[i].emp_name);
	// 	printf("\ndept name---->%s", employee1[i].dept_name);
	// 	printf("\n_______________________\n");
	// }


	i=0;
	while(fgets(data,sizeof(data),fp1)!=NULL){

		if(i==0)
		{
			i++;
			continue;
		}
		printf("%s\n", data);
		token=strtok(data,delimiter_characters);
		for(z = 0; z < strlen(token); z++ )
		{
			if(token[z] == '\n') token[z] = '\0';
		}
		employee2[i].emp_name=strdup(token);
		token=strtok(NULL,delimiter_characters);
		for(z = 0; z < strlen(token); z++ )
		{
			if(token[z] == '\n') token[z] = '\0';
		}
		employee2[i].designation=strdup(token);

		i++;
		ecount2++;
		// employee2[i].emp_name="Kiran";
	}

	// for(i=1;i<=ecount2;i++){
	// 	printf("_______________________\n");
	// 	printf("Employee2 - %d:\n", i);
	// 	printf("\nemp name---->%s", employee2[i].emp_name);
	// 	printf("\ndesignation---->%s", employee2[i].designation);
	// 	printf("\n_______________________\n");
	// }

	for(i=1;i<=ecount1;i++){
		if(strcmp(employee1[i].emp_name,employee2[i].emp_name) == 0){
			employee[i].emp_name = strdup(employee1[i].emp_name);
			employee[i].dept_name = strdup(employee1[i].dept_name);
			employee[i].designation = strdup(employee2[i].designation);
		}		
	}

	for(i=1;i<=ecount1;i++){
		printf("_______________________\n");
		printf("Employee - %d:\n", i);
		printf("\nemp name---->%s", employee[i].emp_name);
		printf("\ndept name---->%s", employee[i].dept_name);
		printf("\ndesignation---->%s", employee[i].designation);
		printf("\n_______________________\n");
	}


	

	return 0;
}