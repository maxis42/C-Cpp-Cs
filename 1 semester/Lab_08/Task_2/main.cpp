#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_array_sum(int **ptr, size_t r,  size_t c);

int main() {
	size_t r(0), c(0);
	int **p_arr = NULL, **p_arr_new = NULL;
	bool *p_arr_flag = NULL;
	size_t i(0), j(0);

	printf("\n\tTask:");
	printf("\n\t1. Create dynamic random integer array.");
	printf("\n\t2. Input number.");
	printf("\n\t3. If the row sum is bigger then the inputted number,");
	printf("\n\t   insert zero row after that row in the new array.\n");

	printf("\n\tInput number of rows and columns: ");
	scanf("%d %d", &r, &c);

	//Allocating memory for initial array
	p_arr = (int **)calloc(r, sizeof(int *));
	p_arr[0] = (int *)calloc(r*c, sizeof(int));
	for(i = 1; i < r; i++)
		p_arr[i] = p_arr[i - 1] + c;
	//----------

	srand((unsigned)time(NULL));

	//Initializing initial array
	for(i = 0; i < r; i++)
		for(j = 0; j < c; j++)
			p_arr[i][j] = rand() % 10;
	//----------

	printf("\n\tInitial random array:");
	print_array_sum(p_arr, r, c);

	printf("\n\tInput limit: ");
	int limit = 0;
	scanf("%d", &limit);

	//Allocating memory for flag array
	p_arr_flag = (bool *)calloc(r, sizeof(bool *));
	//----------

	//Marking the exceeded rows
	size_t exc_limit = 0;
	for(i = 0; i < r; i++)
	{
		int sum = 0;
		for(j = 0; j < c; j++)
			sum += p_arr[i][j];
		if(sum > limit){
			exc_limit++;
			p_arr_flag[i] = 1;
		}
		else p_arr_flag[i] = 0;
	}
	//----------

	//Check on new rows
	if(exc_limit > 0) {
		//Allocating memory for new array if there are new zero rows
		size_t r_new = r + exc_limit;
		p_arr_new = (int **) calloc(r_new, sizeof(int *));
		p_arr_new[0] = (int *) calloc(r_new * c, sizeof(int));
		for (i = 1; i < r_new; i++)
			p_arr_new[i] = p_arr_new[i - 1] + c;
		//----------

		//New array with zero rows
		size_t cnt = 0;
		for(i = 0; i < r; i++){
			if(p_arr_flag[i] == 1) {
				for (j = 0; j < c; j++) {
					p_arr_new[cnt][j] = p_arr[i][j];
					p_arr_new[cnt + 1][j] = 0;
				}
				cnt += 2;
			}
			else {
				for(j = 0; j < c; j++)
					p_arr_new[cnt][j] = p_arr[i][j];
				cnt++;
			}
		}
		//----------

		printf("\n\tNew array:");
		print_array_sum(p_arr_new, r_new, c);

		//Deallocate the memory
		free((void *)p_arr_new[0]);
		free((void *)p_arr_new);
		//----------
	}
	else printf("\n\tNo rows with exceeded sum!");
	//----------

	//Deallocate the memory
	free((void *)p_arr[0]);
	free((void *)p_arr);

	free((void *)p_arr_flag);
	//
	getch();
}

void print_array_sum(int **ptr, size_t r,  size_t c)
{
	printf("\n\t");
	for(size_t i = 0; i < r; i++)
	{
		int sum = 0;
		for(size_t j = 0; j < c; j++)
		{
			printf("%4d",ptr[i][j]);
			sum += ptr[i][j];
		}
		printf("   -%4d\n\t", sum);
	}
}