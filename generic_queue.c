#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define bool	int
#define	FALSE	0
#define TRUE	1

struct complex_number
{
	float real;
	float imaginary;
};

struct Queue
{
	int front,rear,size;
	unsigned int capacity;
	void *arr;
	int eleSize;
};

struct Queue *createQueue(unsigned int capacity , unsigned int size)
{
	struct Queue *queue = (struct Queue*)(malloc(sizeof(struct Queue)));

	queue->front = 0;
	queue->size = 0;
	queue->capacity = capacity;
	queue->rear = -1;
	queue->eleSize = size;
	queue->arr = malloc(sizeof(capacity * size));
}

bool isFull(struct Queue *queue)
{
	return(queue->size == queue->capacity);
}

bool isEmpty(struct Queue *queue)
{
	return(queue->size == 0);
}

void enQueue(struct Queue *queue , void *info)
{
	if(isFull(queue))
	{
		printf("Queue is Full \n");
		return;
	}
	queue->rear = (queue->rear+1)%queue->capacity;
	void *target = (char*)(queue->arr) + (queue->rear)*(queue->eleSize);
	memcpy(target,info,queue->eleSize);
	queue->size = queue->size+1;
}

void deQueue(struct Queue *queue, void *elem)
{
	if(isEmpty(queue))
	{
		printf("Queue is Empty \n");
		elem = NULL;
		return;
	}
	void *source = (char*)(queue->arr) + (queue->front)*(queue->eleSize);
	queue->front = (queue->front+1)%queue->capacity;
//	printf("%d \n",queue->front);
	memcpy(elem,source,queue->eleSize);
	queue->size = queue->size-1;
}

void print(void *element)
{
	if(element == NULL)
	{
		printf("Trace Down Error\n");
		return;
	}	
	printf("%f + i %f\n",((struct complex_number*)(element))->real,((struct complex_number*)(element))->imaginary);
}

void deQueue_Full(struct Queue *queue,void (*printfun)(void *))
{
	while(!isEmpty(queue))
	{
		void *elem = malloc(queue->eleSize);
		deQueue(queue,elem);
		print(elem);
	}
	printf("\n");
}

int main()
{
	struct Queue *queue = createQueue(5,sizeof(struct complex_number));

	struct complex_number *elem = malloc(sizeof(struct complex_number));

	(elem)->real = 1.00;
	(elem)->imaginary = 2.00;
	enQueue(queue,elem);
	(elem)->real = 2.00;
	(elem)->imaginary = 4.00;
	enQueue(queue,elem);
	(elem)->real = 3.00;
	(elem)->imaginary = 6.00;
	enQueue(queue,elem);
	(elem)->real = 4.00;
	(elem)->imaginary = 8.00;
	enQueue(queue,elem);
	(elem)->real = 5.00;
	(elem)->imaginary = 10.00;
	enQueue(queue,elem);

	deQueue_Full(queue,print);
}