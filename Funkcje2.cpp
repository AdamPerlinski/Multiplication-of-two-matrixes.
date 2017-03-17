#include "stdafx.h"
void DrawArray(int **t, int y, int x)
{
	int j;
	for(int i = 0 ; i < y ; i++)
	{
		for(j = 0 ; j < x ; j++)
		{
			printf("%d %s", t[i][j],"\t");
		}
		printf("%s","\n");
	}
}

int** AllocArray(int y, int x)
{
	int **wsk = (int**)malloc(y * sizeof(int*));
	for(int i = 0 ; i < y ; i++)
	{
		wsk[i] = (int*)malloc(x * sizeof(int));
	}
	return wsk;
}

void DestroyArray(int **t, int y)
{
	for(int i = 0 ; i < y ; i++)
		free(t[i]);
	free(t);
}
void czekaj()
{
        getchar();
        getchar();
}