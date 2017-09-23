// Task 1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <conio.h>
#include <time.h>
#include <cstdlib>

int main()
{
	const int R(5), C(10);
	const int RANGE(40);
	int a[R][C], Min_a[C], Min_indices[C];
	int iMin, tmp;

	srand(static_cast<unsigned>(time(nullptr)));

	for (int i = 0; i < R; i++)
		for(int j = 0; j < C; j++)
			a[i][j] = static_cast<int>(rand() % RANGE);
	
	printf_s("\n\tInitial array %d x %d:", R, C);
	for (int i = 0; i < R; i++)
	{
		printf_s("\n\t");
		for (int j = 0; j < C; j++) printf_s("%4d", a[i][j]);
	}

	for (int j = 0; j < C; j++)
	{
		Min_a[j] = a[0][j];
		for (int i = 0; i < R; i++)
			if (Min_a[j] > a[i][j]) Min_a[j] = a[i][j];
	}

	printf_s("\n\n\tMinimums array:\n\t");
	for (int i = 0; i < C; i++) printf_s("%4d", Min_a[i]);

	for (int i = 0; i < C; i++) Min_indices[i] = i;

	for (int i = 0; i < C - 1; i++)
	{
		iMin = i;
		for (int j = i; j < C; j++)
			if (Min_a[j] < Min_a[iMin]) iMin = j;
		if (iMin != i)
		{
			tmp = Min_a[i];
			Min_a[i] = Min_a[iMin];
			Min_a[iMin] = tmp;

			tmp = Min_indices[i];
			Min_indices[i] = Min_indices[iMin];
			Min_indices[iMin] = tmp;

			for (int k = 0; k < R; k++)
			{
				tmp = a[k][i];
				a[k][i] = a[k][iMin];
				a[k][iMin] = tmp;
			}
		}
		
	}

	printf_s("\n\n\tSorted minimums array:\n\t");
	for (int i = 0; i < C; i++) printf_s("%4d", Min_a[i]);

	printf_s("\n\n\tMinimums indices array:\n\t");
	for (int i = 0; i < C; i++) printf_s("%4d", Min_indices[i]);
	
	printf_s("\n\n\tFinal sorted array:");
	for (int i = 0; i < R; i++)
	{
		printf_s("\n\t");
		for (int j = 0; j < C; j++) printf_s("%4d", a[i][j]);
	}

	_getch();
	return 0;
}

