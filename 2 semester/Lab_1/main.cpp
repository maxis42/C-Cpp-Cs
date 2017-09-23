#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void sort1(int *, int);
void sort2(int *, int);
void sort3(int *, int);
void swap1(int *, int *);
void swap2(int &, int &);
int get_index(int *arr, int N, int num);

int main() {
	int N(10);
	int *arr;

	arr = new int [N];
	srand((unsigned)time(NULL));

	for(int i = 0; i < N; i++)
		arr[i] = rand() % 100;

	for(int i = 0; i < N; i++)
		cout << arr[i] << ' ';
	cout << endl;

	sort2(arr, N);

	for(int i = 0; i < N; i++)
		cout << arr[i] << ' ';
	cout << endl;

	int num = arr[4];
	cout << num << endl;
	int index = get_index(arr, N, num);
	cout << index << endl;

	return 0;
}

void swap1(int *a, int *b) {
	int buf;
	buf = *a;
	*a = *b;
	*b = buf;
}

void swap2(int &a, int &b) {
	int buf;
	buf = a;
	a = b;
	b = buf;
}

void sort1(int *arr, int N) {
	int flag;
	do {
		flag = 0;
		for (int i = 0; i < N - 1; i++) {
			if (arr[i] > arr[i + 1]) {
				swap2(arr[i], arr[i + 1]);
				flag = 1;
			}
		}
	} while(flag);
}

void sort2(int *arr, int N) {
	int buf;
	for(int i = 1; i < N; i++) {
		buf = arr[i];
		int j = 0;
		while(j < i - 1 && buf >= arr[j]) j++;
		if (buf <= arr[j]) for(int k = i - 1; k >= j; k--) arr[k + 1] = arr[k];
		arr[j] = buf;
	}
}

void sort3(int *arr, int N) {
	int buf;
	for(int i = 1; i < N; i++) {
		buf = arr[i];
		int j = 0;
		while(j < i - 1 && buf >= arr[j]) j++;
		if (buf <= arr[j]) for(int k = i - 1; k >= j; k--) swap2(arr[k + 1], arr[k]);
		arr[j] = buf;
	}
}

int get_index(int *arr, int N, int num) {
	int index = -1;
	for(int i = 0; i < N; i++)
		if (arr[i] == num) index = i;
	return index;
}