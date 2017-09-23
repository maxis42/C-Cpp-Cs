// Lab 2 Task 2.cpp
// Task: What area the point is inside?

#include "stdafx.h"
#include <conio.h>
#include <math.h>


int main()
{
	double r, x, y;

	printf_s("\n %s \n", "Task: What area the point is inside?");
	printf_s("\n %s", "Input R, x, y: ");
	scanf_s("%lf %lf %lf", &r, &x, &y);

	if (sqrt(pow(x, 2) + pow(y, 2)) > r) printf_s("\n %s", "Outside the circle");
	else if (fabs(x)+fabs(y)<=r) printf_s("\n %s", "Inside the square");
	else printf_s("\n %s", "Inside the circle and outside the square");
	
	_getch();
	return 0;
}

