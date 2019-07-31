#include<iostream>
#include<stdlib.h>
#include<time.h>

int partition(int*arr, int start, int end) {
    //pivot is an random element between start and end;
    int pivot = start + rand() % (end - start + 1);
    // swap pivot and end, thus the pivot will be stored at the end of the array.
    std::swap(arr[pivot], arr[end]);
    int i = start;
    for (int j = start; j < end; j++) {
        if (arr[j] < arr[pivot]) {
            std::swap(arr[i], arr[j]);
            i++;
        }
    }
    std::swap(arr[i], arr[end]);
    return i;
}

void qsort(int* arr, int low, int high) {
    if (low >= high) return;
    int p = partition(arr, low, high);
    qsort(arr, low, p - 1);
    qsort(arr, p + 1, high);
}

int main() {
    srand(time(NULL));
    int size = 10000;
    int arr[size];
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 1000;
    }
    qsort(arr, 0, size - 1);
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << std::endl;
    }
}