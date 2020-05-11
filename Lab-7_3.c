#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
int Low=-100, High=100; 
int n = 0;
int m = 0;

int maxn(int n, int m, int a[][m])
{
	int max = a[0][1];
for (int i=0; i < n; i++){
for (int j=0; j < m; j++)
    if (i<j && a[i][j] > max)
    {
        max = a[i][j];
    }
}
return max;
}

int mas_a_rand(int n, int m, int a[][m])
{
	srand(time(0));
	for (int i=0; i<n; i++)
		for (int j=0; j < m; j++)
		{
		    a[i][j]=Low + rand() % (High - Low + 1);
		}
}

int mas_a_printf(int n, int m, int a[][m])
{
    printf("\n");
    	for (int i=0; i<n; i++)
        {
    		for (int j=0; j < m; j++)
    		    printf("[%d][%d] %d\t", i, j, a[i][j]);printf("\n");
    	}
}

int size()
{
    printf("\r\nВведіть: ");
    
    printf("\r\nКількість рядків матриці: ");
        scanf ("%d", &n);
    
    printf("Кількість стовпців матриці: ");
        scanf ("%d", &m);
}

int chcp, chcpOut = 0;
int main(void)
{
// память chcp
    chcp = GetConsoleCP();
    chcpOut = GetConsoleOutputCP();

// UTF-8
    SetConsoleCP(65001);                
    SetConsoleOutputCP(65001);
//
size();
int a[n][m];

mas_a_rand(n,m,a);
mas_a_printf(n,m,a);

printf("\r\nМаксимальний елемент серед елементiв,\nякi знаходяться вище головної дiагоналi: %d\r\n", maxn(n, m, a));


// Вертаєм chcp
    SetConsoleCP(chcp);                
    SetConsoleOutputCP(chcpOut);
//
    getch();
    return 0;
}