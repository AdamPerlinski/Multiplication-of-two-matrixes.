struct coordinates{
	int x;
	int y;
};
coordinates getsize(char *nazwa);//nazwa pliku  z kt�rego pobra� wieleko�� tablicy
int** allocateMemory(int a, int b);// alokacja tablicy 2 wymiarowej, ilo�� wierszy/kolumny
void freeMemory(int **plik, int a); //wska�nik na tablic�, ilo�� wierszy.
int load(int **w_tab,char *nazwa,int a, int b);//wska�nik na macierz, nazwa pliku , ilo�� kolumn, ilo�� wierszy 
int multiplyMatrix(int **w_tabA,int **w_tabB,int **w_tabC,int x,int y);//wska�nik na tablic� A, wska�nik na tablic� B, wska�nik na tablic� wynikow�, wymiary tablicy wynikowej x,y. 
int save(char *nazwa,int a,int b,int **w_tab);//Nazwa pliku .txt, ilo�� wierszy, ilo�� kolumn, wska�nik na tablic�.