#include<head.h>

int main(int argc,char* argv[])
{
	if(argc<3)
	{
		printf("\n insufficeine");
		return 0;
	}
	int i;
	for(i=0;i<argc;++i)
	{
		list = read(argv[i],list);
	}
	printf("%s",list);
	display(list);
	write_to_file(list,"output.txt");
	display(list);
}
