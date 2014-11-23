#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int TARG = 30;

int gen_rand(int max_num) {
    long rando = rand() % max_num;

    return rando;
}

void yates_shuf(int data[], int length) 
{
    if (length < 2) {
        return;
    } else {
        int swapper = gen_rand(length);
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

    int seed, targ;
    srand (time(NULL));

    int data[50], sorted_data[50];

    for (int i = 0; i < 50; i++) {
        int tmp = gen_rand(100);
        data[i] = tmp;
    }

    targ = data[TARG];
    printf("%d\n", targ);
    yates_shuf(data, 50);

    int i = 0;
    for (int i = 0; i < sizeof(data) / sizeof(int); i++) {
        sorted_data[i] = data[i];
    }

    qsort(sorted_data, (sizeof(data) / sizeof(*data)), sizeof(*data), comp);

    /*
    for (int j = 0; j < 20; j++ ) {
        printf("%d\n", sorted_data[j]);
    }
    */

    int sorted_targ = data[TARG];
    int proposed_targ = randSel(TARG, data, sizeof(data) / sizeof(data[0]));
    printf("%d %d\n", sorted_targ, proposed_targ);

    assert(data[TARG] == proposed_targ);
    return 0;
}
