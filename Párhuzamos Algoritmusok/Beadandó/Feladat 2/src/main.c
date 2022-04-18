#include "../include/main.h"

int main(int argc, char** argv) {
    int i = 0;
    
    for (i = 0; i <= 1000000; i = i + 50000) {
        run_code(i);
    }

    return 0;
}

void run_code(int array_size) {
    int i;
    int rand_int;
    
    double start_time[4], end_time[4];

    srand(time(NULL));

    init_array(array_size);

    // print_array(arrays[0], array_size);
    // print_array(arrays[1], array_size);
    // print_array(arrays[2], array_size);
    // print_array(arrays[3], array_size);

    start_time[0] = omp_get_wtime();
    omp_set_num_threads(1);
    #pragma omp parallel
    {
        #pragma omp single nowait
        {
            quick_sort(arrays[0], 0, array_size - 1);
        }
    }
    end_time[0] = omp_get_wtime();

    
    start_time[1] = omp_get_wtime();
    omp_set_num_threads(2);
    #pragma omp parallel
    {
        #pragma omp single nowait
        {
            quick_sort(arrays[1], 0, array_size - 1);
        }
    }
    end_time[1] = omp_get_wtime();
    
    
    start_time[2] = omp_get_wtime();
    omp_set_num_threads(4);
    #pragma omp parallel
    {
        #pragma omp single nowait
        {
            quick_sort(arrays[2], 0, array_size - 1);
        }
    }
    end_time[2] = omp_get_wtime();
    

    start_time[3] = omp_get_wtime();
    omp_set_num_threads(8);
    #pragma omp parallel
    {
        #pragma omp single nowait
        {
            quick_sort(arrays[3], 0, array_size - 1);
        }
    }
    end_time[3] = omp_get_wtime();

    printf("\n========= [[ %d ]] =========\n", array_size);
    printf("[Thread: 1] Run time: %f\n", (end_time[0] - start_time[0]));
    printf("[Thread: 2] Run time: %f\n", (end_time[1] - start_time[1]));
    printf("[Thread: 4] Run time: %f\n", (end_time[2] - start_time[2]));
    printf("[Thread: 8] Run time: %f\n\n", (end_time[3] - start_time[3]));

    //print_array(arrays[0], array_size);
    //print_array(arrays[1], array_size);
}

void init_array(int array_size) {
    int i, j;
    int random_number;

    for (i = 0; i < 4; i++) {
        arrays[i] = malloc(array_size * sizeof(int));
    }
    
    for (i = 0; i < array_size; i++) {
        random_number = random_int(0, 10000);

        for (j = 0; j < 4; j++) {
            arrays[j][i] = random_number;
        }
    }
}

int random_int(int min, int max) {
    return (rand() % (max - min + 1)) + 1;
}

void print_array(int* array, int size) {
    int i;

    for (i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }

    printf("\n");
}

void quick_sort(int* array, int low, int high) {
    if (low < high) {
        int pivot = partition(array, low, high);

        #pragma omp task firstprivate(array, low, pivot)
        {
            //printf("[Thread - %d] Pivot: %d\n", omp_get_thread_num(), pivot);
            quick_sort(array, low, (pivot - 1));
        }
        /*
        #pragma omp task firstprivate(array, low, pivot)
        {
            printf("[Thread - %d] Pivot: %d\n", omp_get_thread_num(), pivot);
            quick_sort(array, (pivot + 1), high);
        }
        */
    }
}

int partition(int* array, int low, int high) {
    int j;
    int i = (low - 1);
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
