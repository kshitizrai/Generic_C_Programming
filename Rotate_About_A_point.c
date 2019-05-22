#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void rotate(void *first , void *middle , void *end)
{
	int front_size = (char *)(middle) - (char *)(first);
	int back_size = (char *)(end) - (char *)(middle);

	char buffer[front_size];
	memcpy(buffer,first,front_size);
	memmove(first,middle,back_size);
	memcpy((char*)(end)-front_size,buffer,front_size);
	printf("No Error\n");
}

int main()
{
	int *arr = malloc(sizeof(int)*10);
	for(int i=1 ; i<=10 ; i++)
		arr[i-1] = i*2;
	rotate(arr,&arr[4],&arr[9]);
	for(int i=0 ; i<10 ; i++)
		printf("%d ",arr[i]);
	printf("\n");
}