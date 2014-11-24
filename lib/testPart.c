#include "../include/randSel.h"
#include "testPart.h"
#include <assert.h>

void testPart() {
    int data[] = {5, 2, 4, 1, 7};
    int piv = 2;
    int pivot = partition(data, 0, 5, 2);
    int i = 0;
    while (i < 5) {
        if (data[i] == 4) {
            break;
        }
        i++;
    }
    int j = 0;
    while (j < 5) {
        if (data[j] == 7) {
            break;
        }
        j++;
    }
    int z = 0;
    while (z < 5) {
        if (data[z] == 5) {
            break;
        }
        z++;
    }

    assert (z > i);
    assert(j > i);
    assert(pivot == 2);

    printf("done\n");
}
