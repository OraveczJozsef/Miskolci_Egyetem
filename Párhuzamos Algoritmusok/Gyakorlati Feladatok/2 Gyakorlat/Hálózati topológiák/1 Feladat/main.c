#include <stdio.h>

#define ARRAY_SIZE 50
#define ARRAY_SIZE_2 24

int main(int argc, char** argv) {
    /*int climax[ARRAY_SIZE];
    int edges[ARRAY_SIZE];
    int i;

    for (i = 0; i < ARRAY_SIZE; i++) {
        climax[i] = ((i+1) * (i+1));
        edges[i] = climax[i] * 2 - (i+1)*2;

        printf("Vertices: %d - Edges: %d\n", climax[i], edges[i]);
    }

    printf("\n\n\n\n");*/
    int i;
    printf("0\n");
    long int climax_3d[ARRAY_SIZE_2];
    long int edges_3d[ARRAY_SIZE_2];
    printf("1\n");

    for (i = 0; i < ARRAY_SIZE_2; i++) {
        climax_3d[i] = ((i+1) * (i+1) * (i+1));
        edges_3d[i] = (climax_3d[i] * (i+2)) / 2;

        printf("Vertices: %d - Edges: %d\n", climax_3d[i], edges_3d[i]);
    }

    return 0;
}
