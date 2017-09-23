#ifndef LAB_2_FUNCTIONS_H
#define LAB_2_FUNCTIONS_H

#include <iostream>
#include <ctime>
using namespace std;

//template <typename Type>
int ** create_rand_2d_arr(size_t *pR, size_t *pC) {
	int rand_max(0);

	srand((unsigned)time(NULL));

	cout << "Please input number of rows: ";
	size_t R;
	cin >> R;
	*pR = R;
	cout << "Please input number of columns: ";
	size_t C;
	cin >> C;
	*pC = C;
	cout << "Please input max random number: ";
	cin >> rand_max;
	cout << endl;

	int **arr = new int *[R];
	for(size_t i = 0; i < R; i++)
		arr[i] = new int[C];

	for(size_t i = 0; i < R; i++)
		for(size_t j = 0; j < C; j++)
			arr[i][j] = rand() % rand_max;
	return arr;
}

int * create_rand_1d_arr(size_t *pN) {
	int rand_max(0);

	srand((unsigned)time(NULL));

	cout << "Please input number of elements: ";
	size_t N;
	cin >> N;
	*pN = N;
	cout << "Please input max random number: ";
	cin >> rand_max;
	cout << endl;

	int *arr = new int[N];

	for(size_t i = 0; i < N; i++)
		arr[i] = rand() % rand_max;
	return arr;
}

template <class T>
void print_2d_arr(T **arr, const size_t R, const size_t C) {
	for(size_t i = 0; i < R; i++) {
		for (size_t j = 0; j < C; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}

template <class T>
void print_1d_arr(T *arr, const size_t N) {
	for(size_t i = 0; i < N; i++)
		cout << arr[i] << " ";
	cout << endl;
}

template <class T>
void del_arr(T **arr, const size_t R) {
	for(size_t i = 0; i < R; i++)
		delete[] arr[i];
	delete[] arr;
}

template <class T>
bool sum_arr(T **arrA, T **arrB, T **&arrC, const size_t R1, const size_t C1, const size_t R2, const size_t C2) {
	bool flag_row(true), flag_col(true);
	if (R1 != R2) flag_row = false;
	if (C1 != C2) flag_col = false;

	if (!flag_row or !flag_col) {
		if (!flag_row ) cout << "Numbers of rows are not equal: R1 = " << R1 << ", R2 = " << R2 << endl;
		if (!flag_col) cout << "Numbers of columns are not equal: C1 = " << C1 << ", c2 = " << C2 << endl;
		return false;
	}

	arrC = new T *[R1];
	for(size_t i = 0; i < R1; i++)
		arrC[i] = new T[C1];

	for(size_t i = 0; i < R1; i++)
		for (size_t j = 0; j < C1; j++)
			arrC[i][j] = arrA[i][j] + arrB[i][j];

	return true;
}

template <class T>
bool product_arr(T **arrA, T **arrB, T **&arrC, const size_t R1, const size_t C1, const size_t R2, const size_t C2) {
	bool flag(true);
	if (R2 != C1) flag = false;

	if (!flag) {
		cout << "Wrong dimensions for arrays product: arr1 = " << R1 << "x" << C1 << ", arr2 = " << R2 << "x" << C2 << endl;
		return flag;
	}

	arrC = new T *[R1];
	for(size_t i = 0; i < R1; i++)
		arrC[i] = new T[C2];

	for(size_t i = 0; i < R1; i++)
		for (size_t j = 0; j < C2; j++) {
			arrC[i][j] = 0;
			for (size_t k = 0; k < C1; k++)
				arrC[i][j] += arrA[i][k] * arrB[k][j];
		}

	return flag;
}

template <class T>
bool dot_product(T *arr1, T *arr2, const size_t N1, const size_t N2, T *psum) {
	bool flag(true);
	if (N1 != N2) flag = false;

	if (!flag) {
		cout << "Wrong lengths for dot product: n1 = " << N1 << ", n2 = " << N2 << endl;
		return flag;
	}

	T sum = 0;
	for(size_t i = 0; i < N1; i++)
		sum += arr1[i] * arr2[i];

	*psum = sum;

	return flag;
}

template <class T>
void insertion_sort_arr(T *arr, const size_t N) {
	size_t i = 1;
	while (i < N) {
		size_t j = i;
		while ((j > 0) and (arr[j - 1] > arr[j])) {
			swap(arr[j], arr[j - 1]);
			j = j - 1;
		}
		i = i + 1;
	}
}

#endif //LAB_2_FUNCTIONS_H