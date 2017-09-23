#include <iostream>
#include "functions.h"
using namespace std;

int main() {

	// Create two random 2d arrays
	int **arrA(nullptr), **arrB(nullptr);
	size_t R1(0), C1(0), R2(0), C2(0);
	cout << "Create random 2d array #1:" << endl;
	arrA = create_rand_2d_arr(&R1, &C1);
	cout << "Create random 2d array #2:" << endl;
	arrB = create_rand_2d_arr(&R2, &C2);

	// Print two random 2d arrays
	cout << "Array 2d #1:" << endl;
	print_2d_arr(arrA, R1, C1);
	cout << "Array 2d #2:" << endl;
	print_2d_arr(arrB, R2, C2);

	// Sum two arrays
	int **arrC(nullptr);
	cout << "Sum of two arrays:" << endl;
	bool flag_sum = sum_arr(arrA, arrB, arrC, R1, C1, R2, C2);
	if (flag_sum) {
		print_2d_arr(arrC, R1, C1);
		del_arr(arrC, R1);
	}
	else cout << endl;

	// Multiply two arrays
	int **arrD(nullptr);
	cout << "Dot product of two arrays:" << endl;
	bool flag_prod = product_arr(arrA, arrB, arrD, R1, C1, R2, C2);
	if (flag_prod) {
		print_2d_arr(arrD, R1, C2);
		del_arr(arrD, R1);
	}
	else cout << endl;

	// Create two random 1d arrays
	int *arrE(nullptr), *arrF(nullptr);
	size_t N1(0), N2(0);
	cout << "Create random 1d array #1:" << endl;
	arrE = create_rand_1d_arr(&N1);
	cout << "Create random 1d array #2:" << endl;
	arrF = create_rand_1d_arr(&N2);

	// Print two random 1d arrays
	cout << "Array 1d #1:" << endl;
	print_1d_arr(arrE, N1);
	cout << endl;
	cout << "Array 1d #2:" << endl;
	print_1d_arr(arrF, N2);
	cout << endl;

	// Dot product of two random 1d arrays
	int sum(0);
	cout << "Dot product:" << endl;
	bool flag_dp = dot_product(arrE, arrF, N1, N2, &sum);
	if (flag_dp) cout << sum << endl << endl;
	else cout << endl;

	// Sort two random 1d arrays inplace
	cout << "Sorted array 1d #1:" << endl;
	insertion_sort_arr(arrE, N1);
	print_1d_arr(arrE, N1);
	cout << endl;
	cout << "Sorted array 1d #2:" << endl;
	insertion_sort_arr(arrF, N2);
	print_1d_arr(arrF, N2);
	cout << endl;

	// Bye-bye!
	cout << "The program has finished successfully!" << endl;

	system("pause");

	return 0;
}