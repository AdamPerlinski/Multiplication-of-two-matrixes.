// Mnozenie.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int _tmain(int argc, _TCHAR* argv[])
{
	coordinates sizeA;
	coordinates sizeB;
	coordinates sizeC;
	int **matrixA=0;
	int **matrixB=0;
	int **result=0;
	int status = 0;

	sizeA = getsize("plik_macierzA.txt"); //Sprawdzenie rozmiaru Macierzy A
	matrixA = allocateMemory(sizeA.x,sizeA.y); //Alokacja pami�ci dla macierzy A
	load(matrixA,"plik_macierzA.txt",sizeA.x,sizeA.y); //Wczytanie warto�ci macierzy A 
	
	sizeB = getsize("plik_macierzB.txt"); //Sprawdzenie rozmiaru Macierzy B
	matrixB = allocateMemory(sizeB.x,sizeB.y); //Alokacja pami�ci dla macierzy B
	load(matrixB,"plik_macierzB.txt",sizeB.x,sizeB.y); //Wczytanie warto�ci macierzy B 

	if (sizeA.y==sizeB.x){ // Sprawdzenie czy liczba kolumn r�wna si� licznie wierszy.
		sizeC.x=sizeA.y; //przypisanie rozmiaru nowej macierzy
		sizeC.y=sizeB.y; //przypisanie rozmiaru nowej macierzy
			result = allocateMemory(sizeC.x,sizeC.y); //A teraz lokujemy jej pami��
			multiplyMatrix(matrixA,matrixB,result,sizeC.x,sizeC.y); // Mno�enie macierzy 
			save("Wynik_mnozenia.txt",sizeC.x,sizeC.y,result); //Zapisanie wyniku do pliku.
	}
	else{
		printf("Nie mozna pomnozyc macierzy poniewaz liczba kolumn nie rowna si� liczbie wierszy.\n\n");
		printf("Naci�nij Enter aby kontynuowac..");
		getchar();
		getchar();
	}
	freeMemory(matrixA,sizeA.x);//Czyszczenie pami�ci 
	freeMemory(matrixB,sizeB.x);
	freeMemory(result,sizeC.x);
	return 0;
}