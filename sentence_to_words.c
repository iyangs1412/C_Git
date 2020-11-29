#include<stdio.h>
#include<stdlib.h>
int main()
{
	char *a, *pa, *pb;
	a=(char*)malloc(100*sizeof(char));
	if(a==NULL )
	{
		printf("内存分配失败,程序退出\n");
		exit(0); 
	}
	pa = pb = a;
	gets(a);
	while(*pa!='\0')
	{
		if(*pa==' ')
		{
			*pa = '\0';
			puts(pb);
			pb = pa+1;
		}
		pa++;
	}
	puts(pb);
	free(a);
	return 0;
}
