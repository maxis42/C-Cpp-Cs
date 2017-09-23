//Task
//Random array with repeating numbers.
//Form new array without repeats.

#include "stdafx.h"
#include <conio.h>
#include <time.h>
#include <cstdlib>


int main()
{
	const int N = 50;
	int a[N], b[N], count(0);
	const unsigned short RANGE(20);

	srand(static_cast<unsigned>(time(nullptr)));

	printf_s("\n \n \t %s \n \t", "Initial random array:");
	for (int i = 0; i < N; i++)
	{
		a[i] = static_cast<int>(rand() % RANGE);
		if (i % 10 == 0) printf_s("\n \t %4d", a[i]);
		else printf_s("%4d", a[i]);
		b[i] = -1;
	}
	
	printf_s("\n \n \t %s \n \t", "New array without repeats:");
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (b[j] == a[i]) break;
			if (j == i)	b[count++] = a[i];
		}
	}
	
	for (int i = 0; i < count; i++)
	{
		if (i % 10 == 0) printf_s("\n \t %4d", b[i]);
		else printf_s("%4d", b[i]);
	}

	_getch();
	return 0;
}

