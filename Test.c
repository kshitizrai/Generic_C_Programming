#include <stdio.h>
#include <stdlib.h>

struct fraction
{
	int num;
	int denum;	
};

int main()
{
	struct fraction f;
	f.num = 22;
	f.denum = 7;
	((struct fraction*)(&f.denum))->num = 12;
	((struct fraction*)(&f.denum))->denum = 33;

	printf("%d %d \n",f.num,((struct fraction*)(&f.denum))->denum);
	
}