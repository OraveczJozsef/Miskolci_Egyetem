#include "simulation.h"
#include "util.h"
#include "quicksort.h"

void simulation(int array_size) {
    int i;
    ArrayStruct arrays[STRUCT_SIZE];
    
    srand(time(NULL));

    init_struct(arrays, STRUCT_SIZE, array_size);

    for (i = 0; i < STRUCT_SIZE; i++) {
        arrays[i].start_time = omp_get_wtime();

        omp_set_dynamic(arrays[i].threads);
        omp_set_num_threads(arrays[i].threads);

        #pragma omp parallel
        {
            #pragma omp single nowait
            {
                quick_sort(arrays[i].array, 0, (arrays[i].size - 1));
            }
        } 

        arrays[i].end_time = omp_get_wtime();
    }

    
    printf("\n========= [[ %d ]] =========\n", array_size);
    for (i = 0; i < STRUCT_SIZE; i++) {
        printf("[Thread: %d] Run time: %lf\n", arrays[i].threads, (arrays[i].end_time - arrays[i].start_time));
    }
    
}