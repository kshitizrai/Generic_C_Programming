#include <stdio.h>
#include <string.h>

struct complex_number
{
	float real;
	float imaginary;
};

void print_Complex(struct complex_number *c1)
{
	printf("%f + %fi \n",c1->real,c1->imaginary);
}

void swap(void *elem1 , void *elem2 , int elemSize)
{
	char buffer[elemSize];
	memcpy(buffer,elem1,elemSize);
	memcpy(elem1,elem2,elemSize);
	memcpy(elem2,buffer,elemSize);
}

int main()
{
	struct complex_number num1,num2;

	num1.real = 10.1;
	num1.imaginary	= 15.5;

	num2.real = 0.552;
	num2.imaginary = 12.2;

	printf("Before Swapping \n");
	printf("Number 1 : ");
	print_Complex(&num1);
	printf("Number 2 : ");
	print_Complex(&num2);
	swap(&num1,&num2,sizeof(struct complex_number));

	printf("After Swapping \n");
	printf("Number 1 : ");
	print_Complex(&num1);
	printf("Number 2 : ");
	print_Complex(&num2);

}