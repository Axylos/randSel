#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "randSel.h"

unsigned long TARG = 300;
unsigned long RAW_DATA_LENGTH = 1000;
unsigned long INPUT_DATA_LENGTH = 500;

int gen_rand(int max_num) {
    long rando = rand() % max_num;

    return rando;
}

void yates_shuf(int data[], int length) {
    srand(time(NULL));
    if (length < 2) {
        return;
    } else {
        int swapper = rand() % length;
        int tmp = data[0];
        data[0] = data[swapper];
        data[swapper] = tmp;
        yates_shuf(data + 1, length - 1);

    }
}

int comp(const void * elem1, const void * elem2) {
   int f = *((int*) elem1);
   int s = *((int*) elem2);
   if (f > s) {
       return 1;
   } else if (s > f) {
       return -1;
   } else {
       return 0;
   }
}

int main(int ARGC, char *ARGV[]) {
    int c = 1;
    while (c < ARGC) {
        switch (c)
        {
            case 1:
                RAW_DATA_LENGTH = strtoul(ARGV[c], NULL, 10);
                break;
            case 2:
                INPUT_DATA_LENGTH = strtoul(ARGV[c], NULL, 10);
                break;
            case 3:
                TARG = strtoul(ARGV[c], NULL, 10);
                break;
            default:
                abort();
        }
        c++;
    }

        assert(RAW_DATA_LENGTH > INPUT_DATA_LENGTH);
        assert(TARG < INPUT_DATA_LENGTH);




    int targ;

    int data[RAW_DATA_LENGTH], sorted_data[INPUT_DATA_LENGTH];
    int input_data[INPUT_DATA_LENGTH];

    for (int i = 0; i < RAW_DATA_LENGTH; i++) {
        data[i] = i;
    }

    yates_shuf(data, RAW_DATA_LENGTH);

    int i = 0;
    for (i = 0; i < INPUT_DATA_LENGTH; i++) {
        input_data[i] = data[i];
    }

    for (int i = 0; i < sizeof(input_data) / sizeof(int); i++) {
        sorted_data[i] = input_data[i];
    }


    qsort(sorted_data, (sizeof(sorted_data) / sizeof(*sorted_data)), sizeof(*sorted_data), comp);
    targ = sorted_data[TARG];

    int sorted_targ = sorted_data[TARG];
    int proposed_targ = randSel(TARG, input_data, sizeof(input_data) / sizeof(input_data[0]));

    printf("the set targ is %d and the test targ is %d\n\n", targ, proposed_targ);
    assert(targ == proposed_targ);
    printf("YOU WIN!!!\n\n\n");
    return 0;
}
