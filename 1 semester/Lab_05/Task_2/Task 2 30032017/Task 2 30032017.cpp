//Task
//Two random arrays without repeats, form third with A&B with the "binary search".

#include "stdafx.h"
#include <conio.h>
#include <time.h>
#include <cstdlib>
#include <algorithm>


int main()
{
	const int N = 30;
	int A[N], B[N], C[N], TMP1[N], TMP2[N];
	int cnt1(0), cnt2(0), cnt3(0);
	const unsigned short RANGE(20);

	printf_s("\n \n \t %s \n \t", "Two random arrays without repeats, form third with A&B with the \"binary search\".");

	srand(static_cast<unsigned>(time(nullptr)));

	//Forming two random arrays TMP1 and TMP2
	for (int i = 0; i < N; i++)
	{
		TMP1[i] = static_cast<int>(rand() % RANGE);
		TMP2[i] = static_cast<int>(rand() % RANGE);
	}
	
	for (int i = 0; i < N; i++) A[i] = -1;
	for (int i = 0; i < N; i++) B[i] = -1;

	//Forming two random arrays A and B from TMP1 and TMP2 without repeats
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (A[j] == TMP1[i]) break;
			if (j == i)	A[cnt1++] = TMP1[i];
		}
		for (int j = 0; j <= i; j++)
		{
			if (B[j] == TMP2[i]) break;
			if (j == i)	B[cnt2++] = TMP2[i];
		}
	}

	//Printing initial arrays
	printf_s("\n \n \t %s \n \t", "Initial random array A:");
	for (int i = 0; i < cnt1; i++)
	{
		if (i % 10 == 0) printf_s("\n \t %4d", A[i]);
		else printf_s("%4d", A[i]);
	}

	printf_s("\n \n \t %s \n \t", "Initial random array B:");
	for (int i = 0; i < cnt2; i++)
	{
		if (i % 10 == 0) printf_s("\n \t %4d", B[i]);
		else printf_s("%4d", B[i]);
	}

	//Sorting arrays A and B in ascending order
	for (int i = 0; i < cnt1; i++)
	{
		for (int j = 0; j < (cnt1 - 1) - i; j++)
		{
			if (A[j] > A[j + 1])
			{
				int tmp = A[j + 1];
				A[j + 1] = A[j];
				A[j] = tmp;

			}
		}
	}

	for (int i = 0; i < cnt2; i++)
	{
		for (int j = 0; j < (cnt2 - 1) - i; j++)
		{
			if (B[j] > B[j + 1])
			{
				int tmp = B[j + 1];
				B[j + 1] = B[j];
				B[j] = tmp;

			}
		}
	}

	//Forming array C from elements A&B with the binary search
	for (int i = 0; i < std::max(cnt1, cnt2); i++)
	{
		int bnd1 = 0;
		int bnd2 = std::max(cnt1, cnt2);
		while (bnd1 < bnd2)
		{
			int mid = (bnd1 + bnd2) / 2;
			if (A[mid] == B[i])
			{
				C[cnt3++] = B[i];
				break;
			}
			if (B[i] < A[mid]) bnd2 = --mid;
			else bnd1 = ++mid;
		}
	}

	//Printing final array
	printf_s("\n \n \t %s \n \t", "Final array C:");
	for (int i = 0; i < cnt3; i++)
	{
		if (i % 10 == 0) printf_s("\n \t %4d", C[i]);
		else printf_s("%4d", C[i]);
	}

	printf_s("\n \n \t %s \n \t", "Press any key to exit...");
	_getch();
	return 0;
}

