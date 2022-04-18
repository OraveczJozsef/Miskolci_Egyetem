#ifndef MAIN_HEADER
    #define MAIN_HEADER

    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>

    #include <time.h>

    #include <omp.h>

    //#define ARRAY_SIZE 150000
    int* arrays[4]; // 1 Thread | 2 Thread | 4 Thread | 8 Thread


    void run_code(int array_size);

    /**
     * Init Arrays.
     */
    void init_array(int array_size);

    /**
     * Random, integer generation.
     */
    int random_int(int min, int max);

    /**
     * Print array.
     */
    void print_array(int* array, int size);

    /**
     * 
     */
    void quick_sort(int* array, int low, int high);

    /**
     * Partition.
     */
    int partition(int* array, int low, int high);

    /**
     * Two number replacement.
     */
    void swap(int* a, int* b);
#endif