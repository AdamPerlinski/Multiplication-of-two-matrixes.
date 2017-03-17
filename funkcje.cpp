#include "stdafx.h"
int** allocateMemory(int a, int b){
	//a - ilo�� wierszy
	//b - ilo�� kolumn
	// int **wsk =allocateMemory(2,2);
	int **plik = (int **)malloc(sizeof(int *) * a);
		for (int i = 0; i<a; i++)
			plik[i] = (int *)malloc(sizeof(int) * b);
	return plik;
}
void freeMemory(int **plik, int a){
	//plik - wska�nik na tablice
	//a - ilo�� wierszy
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
	//w_tab - wska�nik na tablice
	//nazwa - nazwa pliku np. "plik.txt"
	//x - ilo�� wierszy macierzy
	//y - ilo�� kolumn macierzy
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
	//w_tabA - wska�nik na macierz A
	//w_tabB - Wska�nik na macierz B
	//w_tabC - Wska�nik na macierz C
	//a - ilo�� wierszy macierzy wynikowej
	//b - ilo�� kolumn macierzy wynikowej
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
	//a - ilo�� wierszy macierzy
	//b - ilo�� kolumn macierzy
	//w_tab - wektor na tablice macierzy.
	FILE *plik_t;
	plik_t = fopen(nazwa, "w+");
	fprintf(plik_t, "%d %d\n",a,b);//wielko�� tablicy
	for (int i = 0; i < a-1; i++)
	{
		for (int j = 0; j < b; j++)
			fprintf(plik_t, "%d\t", w_tab[i][j]);
		fprintf(plik_t, "\n");
	}
	fclose(plik_t);
	return 0;
}
