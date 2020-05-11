#include <stdio.h>
#include <conio.h>
#include <windows.h>
const char size = 10;

char s = 0;
int tmp = 0;
int j=0;


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

int a[size];
int *p_a = a;

int t[j];
int *p_t = t;

printf("\r\nВведіть масив натуральних чисел:\r\n");
do
{
    if (s<size)
    	printf("a[%d] = ", s+1);
        scanf ("%d", &a[s]);
    s++;
}
while (s<size);


for (int i = 0; i < size; i++)
{
    if (abs(tmp) < abs(p_a[i]))
    {
        tmp = p_a[i];
    }
}

printf("\n\n\n");

for (int i = 0; i < size; i++)
{
	if (abs(*p_a) == abs(tmp))
	{
		p_t[j] = i+1;
		j++;
	}
	*p_a++;
}

printf("Номери:");
for (int i = 0; i < j; i++)
{
	if (i+1 == j)
	{
		printf(" %d.\r\n", p_t[i]);
	} else printf(" %d,", p_t[i]);
}

// Вертаєм chcp
    SetConsoleCP(chcp);                
	SetConsoleOutputCP(chcpOut);
//
    getch();
    return 0;
}