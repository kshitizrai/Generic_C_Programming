#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack
{
	int allocLength;
	int logLength;
	int elemSize;
	void *elemS;
	void (*freefunc)(void *);
};

void stackNew(struct Stack *s , int elemSize , void (*freefun)(void *))
{
	s->allocLength = 4;
	s->logLength = 0;
	s->elemSize = elemSize;
	s->elemS = malloc(4*elemSize);
	s->freefunc = freefun;
}

void StringFree(void *elem)
{
	free(*(char **)elem);
}

void stackDispose(struct Stack *s)
{
	if(s->freefunc != NULL)
	{
		for(int i=0 ; i<s->logLength ; i++)
			s->freefunc((char*)s->elemS + i*(s->elemSize));
	}
	else
		free(s->elemS);
}

void stackGrow(struct Stack *s)
{
	s->allocLength *=2;
	s->elemS = realloc(s->elemS,s->allocLength*s->elemSize);
}

void stackPush(struct Stack *s , void *elemAddr)
{
	if(s->logLength == s->allocLength)
		stackGrow(s);
	void *target = (char*)(s->elemS) + s->logLength*s->elemSize;
	memcpy(target,elemAddr,s->elemSize);
	s->logLength++;
}

void stackPop(struct Stack *s, void *elemAddr)
{
	s->logLength--;
	void *source = (char*)(s->elemS) + s->logLength*s->elemSize;
	memcpy(elemAddr,source,s->elemSize); 

}

int main()
{
	struct Stack s;

	char *names[] = {"Kshitiz","Shaurya","Adithya","Manoj","Vashu"};
	stackNew(&s,sizeof(char *),StringFree);
	for(int i=0 ; i<5 ; i++)
	{
		char *copies = strdup(names[i]);
		stackPush(&s,&copies);
	}
	char *name;
	for(int i=0 ; i<4 ; i++)
	{
		stackPop(&s,&name);
		printf("%s \n",name);
	}
	stackDispose(&s);
}