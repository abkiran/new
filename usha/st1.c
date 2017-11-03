#include <stdlib.h>
#include <stdio.h>

struct Employees {
    char name[20];
    int age;
    int emp_id;
    char emp_name[20];
    int dept_id;
};

struct Employees *employee;    // Add this

void read_emp();

int main() {
    int no;
    // printf("No of Employees: ");
    // scanf("%d", &no);

    FILE *fp;
    int n,i=0;
    int k=0,ecount=0;
    char data[128], *token;
    const char *delimiter_characters = ",";
    
    fp=fopen("one.txt","r");
    while(fgets(data,sizeof(data),fp)!=NULL){
        if(i==0)
        {
            i++;
            continue;
        } 
        token=strtok(data,delimiter_characters);
        k=0;
        while(token!=NULL){
            read_emp(i,k,token);
            k++;
            token=strtok(NULL,delimiter_characters);
        }
        i++;
        ecount++;
    }

    for(i=1;i<ecount;i++){
        printf("Employee - %d:\n", i);
        printf("\neid--->%s\n", employee[i].emp_id);
        printf("\nename---->%s\n", employee[i].emp_name);
        printf("\ndid---->%s\n", employee[i].dept_id);
    }
    // printf("Below %d Employees\n", no);

    // for(i = 0; i < no; i++){
    //     printf("%d.name=%s\n", i, employee[i].name);
    //     printf("%d.age%d\n", i, employee[i].age);
    // }

    if (employee) {
        free(employee);
    }
    getchar();
    return 0;
}

void read_emp(int i, int k, char *token) {
    // Add the following line to allocate memory
    employee = (struct Employees*) malloc(token * sizeof(struct Employees));


    switch(k){
        case 0:
            employee[i].emp_id=token;
            printf("eid=%s\n", employee[i].emp_id);
            break;
        case 1:
            // employee[i].emp_name=token;
            // printf("ename=%s\n", employee[i].emp_name);
            break;
        case 2:
            employee[i].dept_id=token;
            printf("did=%s\n", employee[i].dept_id);
            break;
    }
    // return;

    // int i;
    // for (i = 0; i < no; i++) {
    //     // Remove the following line because it create an array of "i" elements
    //     // struct Employees employee[i];
    //     printf("Struct created for Employee_%d \n", i);
    //     getchar();
    //     printf("Name: ");
    //     scanf("%s",employee[i].name);
    //     printf("Age: ");
    //     scanf("%d",&employee[i].age);

    //     printf("%s\n",employee[i].name);
    //     printf("%d\n",employee[i].age);
    // }
}