#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TICK(X) clock_t X = clock()
#define TOCK(X) printf("Eltelt ido: %g sec.\n", (double)(clock() - (X)) / CLOCKS_PER_SEC)

int randomInteger(int minimum, int maximum);

int main(int argc, char** argv) {
    FILE *f;
    char* fileName;
    int countNumber;
    int i;

    srand(time(NULL));

    if (argc != 3) {
        printf("[Error] Minimum 2 adatt kell!\n\n");
        exit(1);
    }

    fileName = argv[1];
    countNumber = atoi(argv[2]);

    TICK(START_TIME);
    f = fopen(fileName, "w+");
    if (f == NULL) {
        printf("[Error-1] File not open!\n");
        exit(1);
    }

    for (i = 0; i < countNumber; i++) {
        fseek(f, 0L, SEEK_END);
        fprintf(f, "%d: %d | ", (i + 1), randomInteger(0, 99999));
    }
    fclose(f);
    TOCK(START_TIME);

    return 0;
}

int randomInteger(int minimum, int maximum) {
    return (rand() % (maximum-minimum+1)) + 1;
}