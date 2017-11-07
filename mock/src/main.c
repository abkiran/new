#include<head.h>

int main(int argc,char* argv[])
{

	//GSList* list = NULL;
	if(argc != 3)
	{
		printf("\n insufficent arguments");
		return 0;
	}
	int i=0;
	for (int i = 1; i < argc; ++i)
	{
		list = read(argv[i],list);
	}
	printf("%s",list);
	display(list);
	printf("\n********* Sorted age list is*********\n");
	list = sort_age(list);
	printf("\n********** Writing to output file********\n");
	display(list);
	printf("\nFile written");
	
	list=remove_duplicates(list);
	write_to_file("output.txt",list);
	display(list);

	//printf("\n sorted elements are\n");
	//list = sort_age(list);
	//display(list);
	return 0;
}
	
