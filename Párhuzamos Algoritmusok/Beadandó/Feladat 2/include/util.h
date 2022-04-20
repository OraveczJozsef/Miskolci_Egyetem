#ifndef UTIL_HEADER
    #define UTIL_HEADER

    #include <stdio.h>
    #include <stdlib.h>

    #include <math.h>

    typedef struct ArrayStruct {
        int* array;

        int size;
        int threads;

        double start_time;
        double end_time;
    } ArrayStruct;

    /**
     * @brief Print array.
     * 
     * @param array 
     * @param size 
     */
    void print_array(int* array, int size);

    /**
     * @brief Random, integer generation between intervals.
     * 
     * @param min 
     * @param max 
     * @return int 
     */
    int random_integer(int min, int max);

    /**
     * @brief Initializes the struct.
     * 
     * @param arrays 
     * @param struct_size 
     * @param array_size 
     */
    void init_struct(ArrayStruct* arrays, int struct_size, int array_size);
#endif