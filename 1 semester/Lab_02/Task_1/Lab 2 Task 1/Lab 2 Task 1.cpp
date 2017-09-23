// Lab 2 Task 1.cpp
// Task: Will the parallelepiped go through the circle?

#include "stdafx.h"
#include <conio.h>
#include <math.h>


int main()
{
	double r, l1, l2, l3;
	double d1, d2, d3, min_d; //parallelepiped max diagonal

	printf_s("\n %s \n", "Task: Will the parallelepiped go through the circle?");
	printf_s("\n %s", "Input R, l1, l2, l3: ");
	scanf_s("%lf %lf %lf %lf", &r, &l1, &l2, &l3);

	d1 = sqrt(pow(l2, 2) + pow(l1, 2));
	d2 = sqrt(pow(l3, 2) + pow(l1, 2));
	d3 = sqrt(pow(l2, 2) + pow(l3, 2));
	
	printf_s("\n %s %f", "Diagonal 1: ", d1);
	printf_s("\n %s %f", "Diagonal 2: ", d2);
	printf_s("\n %s %f", "Diagonal 3: ", d3);

	if (d1 <= d2)
	{
		if (d1 <= d3) min_d = d1;
		else min_d = d3;
	}
	else
	{
		if (d2 <= d3) min_d = d2;
		else min_d = d3;
	}

	if (min_d<2*r) printf_s("\n\n %s", "OK to go through");
	else printf_s("\n\n %s", "Failed to go through");

	_getch();
	return 0;
}

