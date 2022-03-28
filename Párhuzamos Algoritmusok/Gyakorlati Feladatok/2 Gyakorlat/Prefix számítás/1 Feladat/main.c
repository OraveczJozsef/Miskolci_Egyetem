#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 8

/*void crew_prefix(int x[]);
void print_array(int x[]);*/
void crew_prefix_calculator(int input[], int output[]);
void print_int_array(int input[]);

int random_integer(int min, int max);

int main(int argc, char** argv) {
    int i;
    int integer_array[ARRAY_SIZE];
    int crew_array[ARRAY_SIZE];

    srand(time(NULL));

    for (i = 0; i < ARRAY_SIZE; i++) {
        integer_array[i] = random_integer(1, 1000);
        crew_array[i] = 0;
    }

    crew_prefix_calculator(integer_array, crew_array);

    print_int_array(integer_array);
    print_int_array(crew_array);

    return 0;
}

void crew_prefix_calculator(int input[], int output[]) {
    int i, j;

    for (i = 0; i < ARRAY_SIZE; i++) {
        for (j = 0; j <= i; j++) {
            output[i] += input[j];
        }
    }
}

void print_int_array(int input[]) {
    int i;

    for (i = 0; i < ARRAY_SIZE; i++) {
        printf("%d | ", input[i]);
    }

    printf("\n");
}

int random_integer(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}