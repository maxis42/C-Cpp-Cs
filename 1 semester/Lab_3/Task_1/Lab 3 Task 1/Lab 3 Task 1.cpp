// Lab 3 Task 1.cpp
// Task: Define row sum.

#include "stdafx.h"
#include <conio.h>
#include <math.h>


int main()
{
	double x, r(1.0), sum(1), eps;
	int i(1);

	printf_s("\n %s \n", "Task: Define row sum.");
	printf_s("\n %s", "Input X: ");
	scanf_s("%lf", &x);

	printf_s("\n %s", "Input precision: ");
	scanf_s("%lf", &eps);

	while (fabs(r)>=eps)
	{
		r *= (-1) * pow(x, 2) / (2 * i *(2 * i - 1));
		sum += r;
		i++;
	}

	printf_s("\n %s %lf", "Row sum: ", sum);
	printf_s("\n %s %lf", "Last argument: ", r);
	printf_s("\n %s %i", "Iterations number: ", i);
	printf_s("\n %s %lf", "Cosinus(x): ", cos(x));

	_getch();
	return 0;
}

