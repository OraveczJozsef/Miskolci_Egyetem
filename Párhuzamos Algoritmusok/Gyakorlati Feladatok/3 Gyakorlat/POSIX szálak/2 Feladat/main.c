#include <stdio.h>
//#include <math.h>

#include <pthread.h>
#include <windns.h>

#define ARRAY_SIZE 10

void* prime_number();

int main(int argc, char** argv) {
    /*int i;
    pthread_t threads[ARRAY_SIZE];

    for (i = 0; i < ARRAY_SIZE; i++) {
        pthread_create(&threads[i], NULL, prime_number, NULL);
    }

    for (i = 0; i < ARRAY_SIZE; i++) {
        pthread_join(threads[i], NULL);
    }*/

    return 0;
}

void* prime_number() {
    printf("%d\n", 0);
}