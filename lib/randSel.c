#include "randSel.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int randSel(int target, int arr[], int length) {
    srand(time(NULL));

    int pivot;
    int offset = 0;
    bool done = false;


    pivot = partition(arr, length);
    while (done == false) {

        if (pivot == target) {
            done = true;
        } else if (pivot > target) {
            pivot = partition(arr + offset, pivot);
        } else {
            offset += pivot + 1;
            partition(arr + offset, length);
        }
    }

    return pivot + offset;

}

void swap(int *a, int *b) {
   int tmp = *a;
   *a = *b;
   *b = tmp;
}

int partition(int arr[], int length) {
    int pivot = rand() % length;
    swap(arr, arr + pivot);

    int i = 0;
    int k = 1;

    while (k < length) {
       if (arr[k] < arr[i]) {
           swap(arr + k, arr + i);
           i++;
       }
       k++;
    }

    return pivot;
}
