// Lab 1.cpp
// Task: Input 3 points of the triangle from the console. Calculate side lengths, perimeter, area, radius of inside circle.

#include "stdafx.h"
#include <conio.h>
#include <math.h>

int main()
{
	double x1, y1, x2, y2, x3, y3;
	double l1, l2, l3, per, area, half_per, r_in_circle;

	printf_s("\n %s \n", "Task: Input 3 points of the triangle from the console. Calculate side lengths, perimeter, area, radius of inside circle.");
	printf_s("\n %s", "Input x1, y1, x2, y2, x3, y3: ");
	scanf_s("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3);

	l1 = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
	l2 = sqrt(pow(x2 - x3, 2) + pow(y2 - y3, 2));
	l3 = sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2));

	per = l1 + l2 + l3;
	half_per = per / 2;
	area = sqrt(half_per*(half_per - l1)*(half_per - l2)*(half_per - l3));
	r_in_circle = area / per;
	
	printf_s("\n %s %5.2lf %c %5.2lf %c %5.2lf", "Side lengths: ", l1, ',', l2, ',', l3);
	printf_s("\n %s %5.2lf", "Perimeter: ", per);
	printf_s("\n %s %5.2lf", "Area: ", area);
	printf_s("\n %s %5.2lf", "R inside circle: ", r_in_circle);

	_getch();
	return 0;
}

