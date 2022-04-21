#include "quicksort.h"
#include "util.h"

void quick_sort(int* array, int low, int high) {
    int pivot;

    if (low < high) {
        pivot = partition(array, low, high);

        #pragma omp task firstprivate(array, low, pivot)
        {
            quick_sort(array, low, (pivot - 1));
        }
    
        #pragma omp task firstprivate(array, high, pivot)
        {
            quick_sort(array, (pivot + 1), high);
        }
    }
}

int partition(int* array, int low, int high) {
    int j, i = (low - 1);
    int pivot = array[high];

    for (j = low; j < high; j++) {
        if (array[j] <= pivot) {
            i++;
            swap(&array[i], &array[j]);
        }
    }

    swap(&array[i + 1], &array[high]);
    return (i + 1);
}

void swap(int* a, int* b) {
    int t = *a;

    *a = *b;
    *b = t;
}