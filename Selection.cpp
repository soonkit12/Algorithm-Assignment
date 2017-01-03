#include<stdio.h>
#include <ctime>
#include <iostream>
#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;
long length = 10;
const long max_length = 300000;

int list[max_length];
void quickSort(int arr[], int l, int h);
void printArray(int arr[], int size);
void random()
{
   srand((unsigned)time(0));

    for(int i=0; i<length; i++){
        list[i] = (rand()%100)+1;

}
}
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
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
printArray(arr,n);

  }
}

int main()
{
        double t1, t2;

        cout << "\nLength\t: " << length << '\n';
        random();
        cout<<"this is the array befor sort"<<endl;
        cout<<"*********************"<<endl;
        printArray(list,length);
        cout<<"*********************"<<endl;
        t1 = clock();
        selectionSort(list, length);
        t2 = clock();



    return 0;
}
