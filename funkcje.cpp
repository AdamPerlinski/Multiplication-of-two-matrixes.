#include "stdafx.h"
int** allocateMemory(int a, int b){
	//a - iloœæ wierszy
	//b - iloœæ kolumn
	// int **wsk =allocateMemory(2,2);
	int **plik = (int **)malloc(sizeof(int *) * a);
		for (int i = 0; i<a; i++)
			plik[i] = (int *)malloc(sizeof(int) * b);
	return plik;
}
void freeMemory(int **plik, int a){
	//plik - wskaŸnik na tablice
	//a - iloœæ wierszy
	for (int i = 0; i<a; i++)
		free(plik[i]);
	free(plik);
}
coordinates getsize(char *nazwa){
	//nazwa - nazwa pliku
	int *w;
	coordinates temp;
	FILE *plik;
		plik = fopen(nazwa, "r");
			w=&temp.x;
				fscanf(plik,"%d",w);
			w=&temp.y;
				fscanf(plik,"%d",w);
		fclose(plik);
	return temp;
}

int load(int **w_tab, char *nazwa, int a, int b){
	//w_tab - wskaŸnik na tablice
	//nazwa - nazwa pliku np. "plik.txt"
	//x - iloœæ wierszy macierzy
	//y - iloœæ kolumn macierzy
	FILE *plik_t;
	int *w=0;
	int x;
	plik_t = fopen(nazwa, "r");
	fscanf(plik_t, "%d", &x);.
	fscanf(plik_t, "%d", &x);
	for (int i = 0; i<a; i++){
		for (int j = 0; j<b; j++){
			fscanf(plik_t, "%d", &x);
			w_tab[i][j] = x;
		}
	}
	fclose(plik_t);
	return 0;
}
int multiplyMatrix(int **w_tabA,int **w_tabB,int **w_tabC,int a,int b){
	//w_tabA - wskaŸnik na macierz A
	//w_tabB - WskaŸnik na macierz B
	//w_tabC - WskaŸnik na macierz C
	//a - iloœæ wierszy macierzy wynikowej
	//b - iloœæ kolumn macierzy wynikowej
	int suma = 0;
    for(int i = 0; i < a-1; i++){//wierszA
		for(int j = 0; j < b; j++){//kolumnaB
			suma = 0;
				for(int k = 0; k < a; k++){  
					suma += w_tabA[i][k]*w_tabB[k][j];
					w_tabC[i][j] = suma;
				}
		}
    }
	return 0;
}
int save(char *nazwa,int a,int b,int **w_tab){
	//nazwa - nazwa pliku np. "plik.txt"
	//a - iloœæ wierszy macierzy
	//b - iloœæ kolumn macierzy
	//w_tab - wektor na tablice macierzy.
	FILE *plik_t;
	plik_t = fopen(nazwa, "w+");
	fprintf(plik_t, "%d %d\n",a,b);//wielkoœæ tablicy
	for (int i = 0; i < a-1; i++)
	{
		for (int j = 0; j < b; j++)
			fprintf(plik_t, "%d\t", w_tab[i][j]);
		fprintf(plik_t, "\n");
	}
	fclose(plik_t);
	return 0;
}
