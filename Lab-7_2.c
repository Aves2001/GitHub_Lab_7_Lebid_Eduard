#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
int Low=-100, High=100; 
int k = 1;
int i, j = 0;
unsigned int size = 0;
int max = 0;
int s = 0;

int maxn (int max, int *p_a, int size)
{
	max = p_a[0];
	for (int i = 0; i < size; i++)
	{
		if (max < p_a[i])
		{
			max = p_a[i];
		}
	}
	 return max;
}

int summ (int *p_a, int size)
{
	char b1 = 0;
	char b2 = 0;
	int tmp1 = 0;
	int tmp2 = 0;
	int s = 0;
	for (int i = 0; i < size; i++)
	{

			if (b1==0 && p_a[i] > 0)
			{
				tmp1 = i;
				b1 = 1;
			}

			if (tmp1 != i && b2==0 && p_a[i] > 0)
			{
				tmp2 = i;
				b2 = 1;

			}
		}
if (tmp2 == 0)
{
	printf("2) У масиві менше 2-х додатніх чисел");
}
	else
	{
		for (int i = 0; i < size; i++)
		{
			if (tmp1 <= i && i <= tmp2)
			{
			s += p_a[i];
			}
		}
		printf("2) Сума елементів масиву,\nрозташованих між першим й другим\nдодатними елементами: %d\n", s);
	}
}

int mas_a_rand(int size, int *p_a)
{
	srand(time(0));
	for (int i=0; i<size; i++)
	p_a[i]=Low + rand() % (High - Low + 1);

}

int mas_a_printf(int size, int *p_a)
{
	for (int i = 0; i < size; i++)
	{
	printf("%d\n", p_a[i]);
	}
}

int sizes()
{
	printf("\r\nВведіть розмір:");
	scanf("%d", &size);
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

sizes();
int a[size];
int *p_a = a;
mas_a_rand(size, p_a);
mas_a_printf(size, p_a);

printf("\r\n\n1) максимальний елемент масиву: %d\n", maxn (max, p_a, size));
summ (p_a, size);

// Вертаєм chcp
    SetConsoleCP(chcp);                
    SetConsoleOutputCP(chcpOut);
//
    getch();
    return 0;
}