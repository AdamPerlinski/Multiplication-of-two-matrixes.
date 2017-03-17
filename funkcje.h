struct coordinates{
	int x;
	int y;
};
coordinates getsize(char *nazwa);//nazwa pliku  z którego pobraæ wielekoœæ tablicy
int** allocateMemory(int a, int b);// alokacja tablicy 2 wymiarowej, iloœæ wierszy/kolumny
void freeMemory(int **plik, int a); //wskaŸnik na tablicê, iloœæ wierszy.
int load(int **w_tab,char *nazwa,int a, int b);//wskaŸnik na macierz, nazwa pliku , iloœæ kolumn, iloœæ wierszy 
int multiplyMatrix(int **w_tabA,int **w_tabB,int **w_tabC,int x,int y);//wskaŸnik na tablicê A, wskaŸnik na tablicê B, wskaŸnik na tablicê wynikow¹, wymiary tablicy wynikowej x,y. 
int save(char *nazwa,int a,int b,int **w_tab);//Nazwa pliku .txt, iloœæ wierszy, iloœæ kolumn, wskaŸnik na tablicê.