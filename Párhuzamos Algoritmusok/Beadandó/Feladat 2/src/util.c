#include "util.h"

void print_array(int* array, int size) {
    int i;

    for (i = 0; i < size; i++) {
        printf("%d, ", array[i]);
    }

    printf("\n\n");
}

int random_integer(int min, int max) {
    return (rand() % (max - min + 1)) + 1;
}

void init_struct(ArrayStruct* arrays, int struct_size, int array_size) {
    int i, j, random_int;

    for (i = 0; i < struct_size; i++) {
        arrays[i].array = malloc(array_size * sizeof(int));
        arrays[i].size = array_size;
        arrays[i].threads = (int) pow(2, i);
    }

    for (i = 0; i < array_size; i++) {
        random_int = random_integer(0, 50);

        for (j = 0; j < struct_size; j++) {
            arrays[j].array[i] = random_int;
        }
    }
}