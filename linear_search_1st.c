#include <stdio.h>
#include <string.h>

struct complex_number
{
	float real;
	float imaginary;
};

void *lsearch(void *key , void *base , int n , int elemSize)
{
	for(int i=0 ; i<n ; i++)
	{
		void *elemAdd = (char *)base + i*elemSize;
		if(memcmp(key,elemAdd,elemSize) == 0)
			return(elemAdd);
	}
	return(NULL);
}

int main()
{
	struct complex_number num[4];
	num[0].real = 1.23;
	num[0].imaginary = 2.31;
	num[1].real = 2.34;
	num[1].imaginary = 3.45;
	num[2].real = 3.57;
	num[2].imaginary = 4.89;
	num[3].real = 8.76;
	num[3].imaginary = 8.62;

	struct complex_number key = {.real=8.76,.imaginary=8.62};
	int size = sizeof(num)/sizeof(struct complex_number);

	double *found = lsearch(&key , num , size , sizeof(struct complex_number));

	if(found != NULL)
		printf("Success \n");
	else
		printf("No Such Element \n");
}