#include<stdio.h>
#include <ctime>
#include <iostream>
#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;
long length = 10;
const long max_length = 40000;
int list[max_length];
void quickSort(int arr[], int l, int h);

void random() {
    srand((unsigned) time(0));

    for (int i = 0; i < length; i++) {
        list[i] = (rand() % 100) + 1;
    }
}
void sorted(){

    for (int i = 0; i < length; i++) {
        list[i] = i;
    }}
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

    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
void selectionSort(int arr[], int n) {

     for (int i = n-1; i > 0; i--) {
    int maxIndex = i;
    for (int j = 0; j < i; j++) {
       if (arr[j] > arr[maxIndex])
         maxIndex = j;
    }
    if (maxIndex != i)
      swap (arr[i], arr[maxIndex]);

  }
}

int main() {
    double t1, t2;
    for (length = 10; length <= max_length;) {

     cout << "\nLength\t: " << length << '\n';
		random();
		t1 = clock();
		quickSort(list, 0, length - 1);
		t2 = clock();
		cout << "Quick Sort with Random List With Last Element As Pivot\t: " << (t2 - t1) / CLK_TCK << " sec\n";
		//*****************
		random();
		t1 = clock();
		selectionSort(list, length );
		t2 = clock();
		cout << "Selection Sort with Random List\t: " << (t2 - t1) / CLK_TCK << " sec\n";
		//*****************
		sorted();
		t1 = clock();
		quickSort(list, 0, length - 1);
		t2 = clock();
		cout << "Quick Sort with Sorted List With Last Element As Pivot\t: " << (t2 - t1) / CLK_TCK << " sec\n";
		//*****************
		sorted();
		t1 = clock();
		selectionSort(list, length);
		t2 = clock();
		cout << "Selection Sort with Sorted List\t: " << (t2 - t1) / CLK_TCK << " sec\n";

        switch (length) {
        case 10:
            length = 100;
            break;
        case 100:
            length = 1000;
            break;
        case 1000:
            length = 5000;
            break;
        case 5000:
            length = 10000;
            break;
         case 10000:
            length = 15000;
            break;
        case 15000:
            length = 20000;
            break;
        case 20000:
            length = 25000;
            break;
        case 25000:
            length = 30000;
            break;
        case 30000:
            length = 40000;
            break;
        case 40000:
            length = 40001;
            break;


        }
    }

    return 0;
}
