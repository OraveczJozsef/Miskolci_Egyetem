#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randomInteger(int minimum, int maximum);
double randomDouble(int minimum, int maximum);

int main(int argc, char * argv[]) {
    int i;

    srand(time(NULL));
    for (i = 0; i < 10; i++) {
        printf("Integer: %d\n", randomInteger(500, 1000));
        printf("Double: %f\n", randomDouble(500.00, 1000.00));
    }

    return 0;
}

int randomInteger(int minimum, int maximum) {
    return (rand() % (maximum-minimum+1)) + 1;
}

double randomDouble(int minimum, int maximum) {
    return ((double) rand() / (maximum - minimum)) + minimum;
}