#include <stdio.h>

#include <pthread.h>
#include <windns.h>

#define ARRAY_SIZE 10

int main(int argc, char** argv) {
    int i;
    pthread_t threads[ARRAY_SIZE];

    for (i = 0; i < ARRAY_SIZE; i++) {
        pthread_create(&threads[i], NULL, NULL, NULL);
    }

    return 0;
}

void 