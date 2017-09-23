#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_array(int *ptr, size_t k);
void rotate_array(int *ptr, size_t N, ptrdiff_t k);

int main() {
    const size_t N(10);
    int a_rand[N] = {0};
    size_t i, j, k;

    printf("\n\tTask:");
    printf("\n\t1. Create random array without repeats.");
    printf("\n\t2. Rotate the array so that the minimum element will be on the first position.");
    printf("\n\t3. Rotate the array so that the maximum element will be on the first position.\n");

    //Initializing random variable.
    srand((unsigned int)time(NULL));

    //Creating random array "a_rand" without repeats.
    for(i = 0; i < N; i++)
    {
        k = 0;
        int tmp = rand() % 50 + 1;
        for(j = 0; j < i; j++)
        {
            if(a_rand[j] == tmp)
            {
                i--;
                break;
            }
            k++;
        }
        if(k == i) a_rand[i] = tmp;
    }
    //

    printf("\n\tInitial random array:\n");
    print_array(a_rand, N);

    //Looking for the min and max elements indices.
    size_t min_i, max_i;
    min_i = max_i = 0;
    for(i = 0; i < N; i++)
    {
        if(a_rand[i] > a_rand[max_i]) max_i = i;
        if(a_rand[i] < a_rand[min_i]) min_i = i;
    }
    //

    //Rotating the array so that the minimum element will be on the first position.
    rotate_array(a_rand, N, -min_i);
    printf("\n\tRotated array with the minimum element on the first position:\n");
    print_array(a_rand, N);
    rotate_array(a_rand, N, min_i); //return to initial state
    //

    //Rotating the array so that the maximum element will be on the first position.
    printf("\n\tRotated array with the maximum element on the first position:\n");
    rotate_array(a_rand, N, -max_i);
    print_array(a_rand, N);
    rotate_array(a_rand, N, max_i); //return to initial state
    //

    getch();
}



void print_array(int *ptr, size_t N)
{
    printf("\n\t");
    for(size_t i = 0; i < N; i++) printf("%4d", ptr[i]);
    printf("\n\t");
}



void rotate_array(int *ptr, size_t N, ptrdiff_t k)
{
    int tmp(0);
    size_t i, j;

    //Check on left/right array rotation.
    if(k >= 0) j = N - k;
    else j = (size_t)(-k);
    //

    //Reversing left and right parts of the array.
    for(i = 0; i < (j / 2); i++)
    {
        tmp = ptr[i];
        ptr[i] = ptr[(j - 1) - i];
        ptr[(j - 1) - i] = tmp;
    }
    for(i = j; i < (N + j) / 2; i++)
    {
        tmp = ptr[i];
        ptr[i] = ptr[(N - 1) - (i - j)];
        ptr[(N - 1) - (i - j)] = tmp;
    }
    //

    //Reversing the whole array with reversed parts.
    for(i = 0; i < (N / 2); i++)
    {
        tmp = ptr[i];
        ptr[i] = ptr[(N - 1) - i];
        ptr[(N - 1) - i] = tmp;
    }
    //
}