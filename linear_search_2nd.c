#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int StrCmp(void *elem1, void *elem2)
{
	char *s1 = *(char **)(elem1);
	char *s2 = *(char **)(elem2);

	return(strcmp(s1,s2));
}

void *lsearch(void *key,void *base,int n,int elemSize,int (*cmpfn)(void * , void *))
{
	for(int i=0 ; i<n ; i++)
	{
		void *elemAddr = (char *)base + i*elemSize;

		if(cmpfn(elemAddr,key) == 0)
			return(elemAddr);
	}
	return(NULL);
}

int main()
{
	char *notes[] = {"Ab" , "F#" , "B" , "Gb" , "D"};
	char *favouriteNode = "Gb";

	char **found = lsearch(&favouriteNode,notes,5,sizeof(char *),StrCmp);

	if(found != NULL)
		printf("Success!!\n");
	else
		printf("No Such String\n");
}