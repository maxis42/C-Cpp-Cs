#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_array(int *ptr, size_t N);

int main() {
  const size_t N(10);
  int a_rand[N][N] = {0};
  int *ptr;
  size_t i, j, k;

  printf("\n\tTask:");
  printf("\n\t1. Create random array NxN.");
  printf("\n\t2. Sort the array* so that the elements will be placed in ascending order by the columns.");
  printf("\n\t*swap two elements\n");

  //Initializing random variable.
  srand((unsigned int)time(NULL));

  //Creating random array "a_rand" NxN.
  for(i = 0; i < N; i++)
    for(j = 0; j < N; j++)
      a_rand[i][j] = rand() % 50 + 1;
  //

  printf("\n\tInitial random array %dx%d:\n", N, N);
  print_array(&a_rand[0][0], N);

  //Sorting the array with "bubble" algorithm.
  size_t i_prev, j_prev, cnt1(N), cnt2(N);
  k = 0;
  while (k < N * N)
  {
    i_prev = j_prev = 0;
    for(j = 0; j < cnt1; j++)
    {
      for(i = 0; i < cnt2; i++)
      {
        if(a_rand[i_prev][j_prev] > a_rand[i][j])
        {
			    int tmp = a_rand[i][j];
			    a_rand[i][j] = a_rand[i_prev][j_prev];
			    a_rand[i_prev][j_prev] = tmp;
        }
        i_prev = i;
        j_prev = j;
      }
    }
    k++;
    if(cnt2 != 1) cnt2--;
    else
    {
      cnt1--;
      cnt2 += N - 1;
    }
  }
  //

  printf("\n\tSorted array %dx%d:\n", N, N);
  print_array(&a_rand[0][0], N);
  getch();
}



void print_array(int *ptr, size_t N)
{
  printf("\n\t");
  for(int i = 0; i < N; i++)
  {
    for(int j = 0; j < N; j++)
      printf("%3d",*(ptr + i * N + j));
    printf("\n\t");
  }
}