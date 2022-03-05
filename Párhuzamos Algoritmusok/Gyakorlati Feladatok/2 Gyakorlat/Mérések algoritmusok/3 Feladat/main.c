#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define ARRAY_SIZE 600
#define FOR_SIZE 10000

#define TICK(X) clock_t X = clock()
#define TOCK(X) printf("Eltelt ido: %g sec.\n", (double)(clock() - (X)) / CLOCKS_PER_SEC)

void generation_double_array(double* double_array);
double generation_double(double minimum_value, double maximum_value);
int generation_integer(int minimum_value, int maximum_value);
void sorting(double* double_array);

bool is_strictly_monotonically_increasing(double* double_array);

int binary_search(double* double_array, double search_value);
int binary_search_recursive(double* double_array, double search_value, int front, int over);

int main(int argc, char** argv) {
    int i;
    double double_array[ARRAY_SIZE + 1];
    int index, index_r;
    int random_index;
    double random_value;
    bool is_smi = false;

    srand(time(NULL));

    generation_double_array(double_array);
    is_smi = is_strictly_monotonically_increasing(double_array);

    random_index = generation_integer(0, ARRAY_SIZE);
    random_value = double_array[random_index];

    TICK(BINARY_SEARCH);
    for (i = 0; i < FOR_SIZE; i++) {
        index = binary_search(double_array, random_value);
    }
    TOCK(BINARY_SEARCH);

    TICK(BINARY_SEARCH_RECURSIVE);
    for (i = 0; i < FOR_SIZE; i++) {
        index = binary_search_recursive(double_array, random_value, 0, ARRAY_SIZE);
    }
    TOCK(BINARY_SEARCH_RECURSIVE);

    //index = binary_search(double_array, 0.9500);
    //index_r = binary_search_recursive(double_array, 0.9500, 0, ARRAY_SIZE);

    //for (i = 0; i < ARRAY_SIZE; i++)
    //    printf("%f | ", double_array[i]);

    //printf("\n%s\n", is_smi ? "true" : "false");
    //printf("%s - %d\n", (index == -1 ? "false" : "true"), index);
    //printf("%s - %d\n", (index_r == -1 ? "false" : "true"), index_r);

    return 0;
}

void generation_double_array(double* double_array) {
    int i, j;
    double new_value = 0.0;
    bool is_equal = true;

    for (i = 0; i < ARRAY_SIZE; i++) {
        new_value = generation_double(0.0, (ARRAY_SIZE * 4));

        while (i > 0 && is_equal) {
            new_value = generation_double(0.0, (ARRAY_SIZE * 4));

            for (j = 0; j < i; j++) {
                if (double_array[j] != new_value) {
                    is_equal = false;
                }
            }    
        }
        double_array[i] = new_value;
    }

    sorting(double_array);
}

double generation_double(double minimum_value, double maximum_value) {
    return minimum_value + (rand() / (RAND_MAX / (maximum_value - minimum_value)));
}

int generation_integer(int minimum_value, int maximum_value) {
    return rand() % (maximum_value + 1 - minimum_value) + minimum_value;
}

void sorting(double* double_array) {
    int i, j;
    double t;

    for (i = 0; i < ARRAY_SIZE - 1; i++){
        for (j = i + 1; j < ARRAY_SIZE; j++){
            if (double_array[i] > double_array[j]){
                t = double_array[i];
                double_array[i] = double_array[j];
                double_array[j] = t;
            }
        }
    }
}

bool is_strictly_monotonically_increasing(double* double_array) {
    int i;
    bool return_value = true;

    for (i = 1; i < ARRAY_SIZE; i++) {
        if (double_array[i - 1] >= double_array[i]) {
            return_value = false;
            break;
        }
    }

    return return_value;
}

int binary_search(double* double_array, double search_value) {
    int return_value = -1;
    int front = 0;
    int over = ARRAY_SIZE;
    int index;

    while (front < over) {
        index = (front + over) / 2;

        if (double_array[index] == search_value) {
            return_value = index;
            break;
        } else if (double_array[index] < search_value) {
            front += 1;
        } else if (double_array[index] > search_value) {
            over -= 1;
        }
    }

    return return_value;
}
int binary_search_recursive(double* double_array, double search_value, int front, int over) {
    int middle = (front + over) / 2;

    if (front > over) {
        return -1;
    }

    if (search_value == double_array[middle]) {
        return double_array[middle];
    }
    if (search_value > double_array[middle]) {
        return binary_search_recursive(double_array, search_value, middle + 1, over);
    }
    if (search_value < double_array[middle]) {
        return binary_search_recursive(double_array, search_value, front, middle - 1);
    }
}