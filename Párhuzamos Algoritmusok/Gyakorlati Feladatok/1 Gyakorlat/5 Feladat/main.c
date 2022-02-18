#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randomInteger(int minimum, int maximum);

int main(int argc, char** argv) {
    int aNumber, bNumber;
    int randomNumber = 0;

    srand(time(NULL));

    if (argc != 3) {
        printf("[Error] Minimum 2 adatt kell!\n\n");
        return 1;
    }

    aNumber = atoi(argv[1]);
    bNumber = atoi(argv[2]);

    if (bNumber >= aNumber) {
        randomNumber = randomInteger(aNumber, bNumber);
    } else {
        randomNumber = randomInteger(bNumber, aNumber);
    }

    printf("%d\n", randomNumber);
    
    return 0;
}

int randomInteger(int minimum, int maximum) {
    return (rand() % (maximum-minimum+1)) + 1;
}