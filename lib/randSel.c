#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <assert.h>
#include "randSel.h"

void swap(int *a, int *b) {
   int tmp = *a;
   *a = *b;
   *b = tmp;
}


void parr(int arr[], int length) {
    int i = 0;
    while (i < length) {
        printf("%d  ", arr[i]);
        i++;
        if (i % 10 == 0) {
            printf("\n");
        }

    }
    printf("\n");
}



int partition(int arr[], int start, int length, int pivot) {
    assert(*arr > 0);
    assert(*(arr + pivot) > 0);
    swap(arr + start, arr + start + pivot);

    int i = start;
    int k = start + 1;

    while (k < length) {
       if (arr[k] < arr[i]) {
           swap(arr + start + k, arr + start + i + 1);
           swap(arr + start + i + 1, arr + start + i);
           i++;
       }
       k++;
    }

    return i - 1;
}

int randSel(int target, int arr[], int length) {
    srand(time(NULL));

    int pivot, new_pivot;
    int offset = 0;
    bool done = false;


    new_pivot = rand() % length;
    pivot = partition(arr, 0, length, new_pivot);
    printf("%d\n", pivot);
    while (done == false) {

        if (pivot == target + 1) {
            done = true;
        } else if (pivot > target) {
            length = pivot - offset + 1;
            new_pivot = rand() % length;
            pivot = partition(arr, offset, length, new_pivot);
        } else {
            length = 50 - offset;
            new_pivot = rand() % length;
            pivot = partition(arr, offset, length, new_pivot);
        }
    }

    return arr[pivot + offset] - 1;

}




