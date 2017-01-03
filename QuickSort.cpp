#include<stdio.h>
#include <ctime>
#include <iostream>
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

long length = 10;
const long max_length = 10;
int list[max_length];
void quickSort(int arr[], int l, int h);
void printArray(int arr[], int size);
void random() {
	srand((unsigned) time(0));

	for (int i = 0; i < length; i++) {
		list[i] = (rand() % 100) + 1;
	}
}

void swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int arr[], int l, int h) {
	int x = arr[h];
	int i = (l - 1);

	for (int j = l; j <= h - 1; j++) {

		if (arr[j] <= x) {
			i++;
			printArray(arr, length);
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[h]);
	return (i + 1);
}

void quickSort(int arr[], int l, int h) {

	if (l < h) {
		int p = partition(arr, l, h);
		quickSort(arr, l, p - 1);
		quickSort(arr, p + 1, h);
	}
}

void printArray(int arr[], int size) {
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int main() {
	double t1, t2;
	cout << "\nLength\t: " << length << '\n';
	random();
	t1 = clock();
	quickSort(list, 0, length - 1);
	t2 = clock();
	cout << "Quick Sort\t: " << (t2 - t1) / CLK_TCK << " sec\n";

	return 0;
}
