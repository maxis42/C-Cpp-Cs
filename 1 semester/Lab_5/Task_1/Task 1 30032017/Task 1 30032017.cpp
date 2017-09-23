//Task
//Two random arrays, form third array from A\B.
//Delete all repeating elements from third array, sort in ascending order.
//Use "linear search" method.

#include "stdafx.h"
#include <conio.h>
#include <time.h>
#include <cstdlib>


int main()
{
	const int N = 30;
	int a[N + 1], b[N + 1], c[N], tmp[N], cnt, len, tmp_var;
	const unsigned short RANGE(20);

	srand(static_cast<unsigned>(time(nullptr)));

	for (int i = 0; i < N; i++)
	{
		a[i] = static_cast<int>(rand() % RANGE);
		b[i] = static_cast<int>(rand() % RANGE);
	}

	printf_s("\n \n \t %s \n \t", "Initial random array A:");
	for (int i = 0; i < N; i++)
	{
		if (i % 10 == 0) printf_s("\n \t %4d", a[i]);
		else printf_s("%4d", a[i]);
	}

	printf_s("\n \n \t %s \n \t", "Initial random array B:");
	for (int i = 0; i < N; i++)
	{
		if (i % 10 == 0) printf_s("\n \t %4d", b[i]);
		else printf_s("%4d", b[i]);
	}

	len = 0;
	for (int i = 0; i < N; i++)
	{
		cnt = 1;
		b[N] = a[i];
		while (b[cnt] != b[N]) cnt++;
		if (cnt == N) tmp[len++] = b[N];
	}

	for (int i = 0; i < len; i++) c[i] = -1;

	cnt = 0;
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (c[j] == tmp[i]) break;
			if (j == i)	c[cnt++] = tmp[i];
		}
	}
	
	for (int i = 0; i < (cnt - 1); i++)
		for (int j = 0; j < (cnt - 1) - i; j++)
			if (c[j] > c[j + 1])
			{
				tmp_var = c[j]; c[j] = c[j + 1]; c[j + 1] = tmp_var;
			}
	
	tmp_var = 0;
	printf_s("\n \n \t %s \n \t", "Final array C:");
	for (int i = 0; i < cnt; i++)
	{
		if (cnt % 10 == 0) printf_s("\n \t %4d", c[tmp_var++]);
		else printf_s("%4d", c[tmp_var++]);
	}

	_getch();
	return 0;
}

