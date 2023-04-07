#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "arr.h"

namespace arr_util {
int* random_array(int size) {
	srand((unsigned) time(NULL));
        int* arr = new int[size];

        for (int i=0;i<size;i++) {
                int random = rand() % 10; // 0 to 9 pseudo-random value
                arr[i] = random;
        }
	return arr;
}
}
