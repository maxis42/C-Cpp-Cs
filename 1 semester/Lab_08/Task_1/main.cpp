#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_array(int **ptr, size_t r,  size_t c);

int main() {
	size_t r(0), c(0);
	int **p_arr = NULL, **p_arr_tr = NULL;
	size_t i(0), j(0);

	printf("\n\tTask:");
	printf("\n\tTranspose dynamic random integer array.\n");

	printf("\n\tInput number of rows and columns: ");
	scanf("%d %d", &r, &c);

	//Allocating memory for initial array
	p_arr = (int **)calloc(r, sizeof(int *));
	p_arr[0] = (int *)calloc(r*c, sizeof(int));
	for(i = 1; i < r; i++)
		p_arr[i] = p_arr[i - 1] + c;
	//

	srand((unsigned)time(NULL));

	for(i = 0; i < r; i++)
		for(j = 0; j < c; j++)
			p_arr[i][j] = rand() % 100;

	printf("\n\tInitial random array:");
	print_array(p_arr, r, c);

	//Allocating memory for transposed array
	p_arr_tr = (int **)calloc(c, sizeof(int *));
	p_arr_tr[0] = (int *)calloc(r*c, sizeof(int));
	for(i = 1; i < c; i++)
		p_arr_tr[i] = p_arr_tr[i - 1] + r;
	//

	//Transpose array
	for(i = 0; i < r; i++)
		for (j = 0; j < c; j++)
			p_arr_tr[j][i] = p_arr[i][j];
	//

	printf("\n\tTransposed random array:");
	print_array(p_arr_tr, c, r);

	//Deallocate the memory
	free((void *)p_arr[0]);
	free((void *)p_arr);

	free((void *)p_arr_tr[0]);
	free((void *)p_arr_tr);
	//

	getch();
	return 0;
}

void print_array(int **ptr, size_t r,  size_t c)
{
	printf("\n\t");
	for(size_t i = 0; i < r; i++)
	{
		for(size_t j = 0; j < c; j++)
			printf("%4d",ptr[i][j]);
		printf("\n\t");
	}
}