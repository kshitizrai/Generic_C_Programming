#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct complex_number
{
	float real;
	float imaginary;
};

struct Stack
{
	void *elemS;
	int elemSize;
	int logLength;
	int allocLength;
};

void StackNew(struct Stack *s, int elemSize)
{
	s->logLength = 0;
	s->allocLength = 4;
	s->elemS = (malloc(4 * elemSize));
	s->elemSize = elemSize;
}

void stackDispose(struct Stack *s)
{
	free(s->elemS);
}

void stackGrow(struct Stack *s)
{
	s->allocLength *=2;
	s->elemS = realloc(s->elemS , s->allocLength*s->elemSize); 
}

void stackPush(struct Stack *s , void *elemAddr)
{
	if(s->logLength == s->allocLength)
		stackGrow(s);

	void *target = (char *)(s->elemS) + s->logLength*s->elemSize;

	memcpy(target,elemAddr,s->elemSize);

	s->logLength++;
}

void stackPop(struct Stack *s , void *elemAddr)
{
	void *source = (char *)(s->elemS) + s->elemSize*(s->logLength-1);
	memcpy(elemAddr,source,s->elemSize);

	struct complex_number *ref = (struct complex_number *)(elemAddr);
	printf("%f + i %f \n",ref->real,ref->imaginary);
	s->logLength--;
}

int main()
{ 
	struct Stack s;
	StackNew(&s,sizeof(struct complex_number));
	
	struct complex_number *elem = malloc(sizeof(struct complex_number));

	(elem)->real = 1.00;
	(elem)->imaginary = 2.00;
	stackPush(&s,elem);
	(elem)->real = 2.00;
	(elem)->imaginary = 4.00;
	stackPush(&s,elem);
	(elem)->real = 3.00;
	(elem)->imaginary = 6.00;
	stackPush(&s,elem);
	(elem)->real = 4.00;
	(elem)->imaginary = 8.00;
	stackPush(&s,elem);
	(elem)->real = 5.00;
	(elem)->imaginary = 10.00;
	stackPush(&s,elem);

	stackPop(&s,elem);
	stackPop(&s,elem);
	stackPop(&s,elem);
	stackPop(&s,elem);
	stackPop(&s,elem);
}