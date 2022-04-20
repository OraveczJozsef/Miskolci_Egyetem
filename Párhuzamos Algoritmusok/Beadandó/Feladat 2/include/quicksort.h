#ifndef QUICKSORT_HEADER
    #define QUICKSORT_HEADER

    #include <omp.h>

    /**
     * @brief Array sorting main method.
     * 
     * @param array 
     * @param low 
     * @param high 
     */
    void quick_sort(int* array, int low, int high);

    /**
     * @brief Splitting an array.
     * 
     * @param array 
     * @param low 
     * @param high 
     * @return int 
     */
    int partition(int* array, int low, int high);

    /**
     * @brief Swapping two values.
     * 
     * @param a 
     * @param b 
     */
    void swap(int* a, int* b);
#endif