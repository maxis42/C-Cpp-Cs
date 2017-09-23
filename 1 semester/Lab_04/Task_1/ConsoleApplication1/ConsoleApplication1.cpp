//Task
//Random array, change so that all even numbers in the ascending order,
//all odd numbers on the initial position.

#include "stdafx.h"
#include <conio.h>
#include <time.h>
#include <cstdlib>
#include <algorithm>

int main()
{
	const int N = 50;
	int a[N], b[N], c[N];
	const unsigned short RANGE(20);

	srand(static_cast<unsigned>(time(nullptr)));

	printf_s("\n \n \t %s \n \t", "Initial random array:");
	for (int i = 0; i < N; i++)
	{
		a[i] = static_cast<int>(rand() % RANGE);
		b[i] = a[i];
		c[i] = a[i];
		if (i % 10 == 0) printf_s("\n \t %4d", a[i]);
		else printf_s("%4d", a[i]);
	}

	for (int i = 0; i < (N - 1); i++)
		for (int j = 0; j < (N - 1) - i; j++)
			if (b[j] > b[j + 1]) std::swap(b[j], b[j + 1]);

	printf_s("\n \n \t %s \n \t", "Sorted array:");
	for (int i = 0; i < N; i++)
	{
		if (i % 10 == 0) printf_s("\n \t %4d", b[i]);
		else printf_s("%4d", b[i]);
	}

	printf_s("\n \n \t %s \n \t", "Final array:");
	
	int j(0);
	for (int i = 0; i < N; i++)
	{
		if (c[i] % 2 == 0)
		{
			do	c[i] = b[j++];
			while (b[j-1] % 2 != 0);
		}
		if (i % 10 == 0) printf_s("\n \t %4d", c[i]);
		else printf_s("%4d", c[i]);
	}

	_getch();
	return 0;
}

