// Lab 3 Task 2.cpp
// Task: Show all palindromes for the number.

#include "stdafx.h"
#include <conio.h>

int main()
{
	int num_a, num_b, i, new_num, x;

	printf_s("\n %s \n", "Task: Show all palindromes for the number.");
	printf_s("\n %s", "Input range a, b: ");
	scanf_s("%i %i", &num_a, &num_b);

	i = num_a;
	while (i <= num_b)
	{
		x = i;
		new_num = 0;
		while ((x / 10 != 0) || (x % 10 != 0))
		{
			new_num *= 10;
			new_num += x % 10;
			x /= 10;
		}
		if (new_num == i) printf_s("\n %i", new_num);
		i++;
	}

	_getch();
	return 0;
}
