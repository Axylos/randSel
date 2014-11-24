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



int partition(int arr[], int start, int end, int pivot) {
    assert(*arr >= 0);
    assert(*(arr + pivot) >= 0);
    swap(arr + start, arr + pivot);

    int i = start;
    int k = start + 1;

    while (k <= end)  {
       if (arr[k] < arr[i]) {
           swap(arr + k, arr + i + 1);
           swap(arr + i + 1, arr + i);
           i++;
       }
       k++;
    }

    return i;
}

int randSel(int target, int arr[], int length) {
    srand(time(NULL));

    int pivot, new_pivot;
    int offset = 0;
    bool done = false;
    int end = length - 1;


    new_pivot = rand() % length;
    pivot = partition(arr, offset, end, new_pivot);
    while (done == false) {
        if (pivot == target) {
            done = true;
        } else if (pivot > target) {
            end = pivot - 1;

            length = end - offset + 1;
            new_pivot = rand() % (length);
            new_pivot += offset;

            pivot = partition(arr, offset, end, new_pivot);
        } else {

            offset = pivot + 1;
            length = end - offset + 1;
            new_pivot = rand() % (length);
            new_pivot += offset;

            pivot = partition(arr, offset, end, new_pivot);
        }
    }


    return arr[pivot];

}




