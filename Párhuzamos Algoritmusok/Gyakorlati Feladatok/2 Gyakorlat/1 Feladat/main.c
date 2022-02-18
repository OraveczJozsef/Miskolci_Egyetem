#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define TICK(X) clock_t X = clock()
#define TOCK(X) printf("Eltelt ido: %g sec.\n", (double)(clock() - (X)) / CLOCKS_PER_SEC)

#define ARRAY_SIZE 110

int randomInteger(int minimum, int maximum);

int getInputInteger();

int getArraySum(int intArray[]);
int getArrayMinimum(int intArray[]);
int getArrayMaximum(int intArray[]);

int getArraySumR(int intArray[], int arrayIndex);
int getArrayMinimumR(int intArray[], int arrayIndex);
int getArrayMaximumR(int intArray[], int arrayIndex);

int main(int argc, char** argv) {
    int i;
    int intArray[ARRAY_SIZE];
    int arraySum, arrayMin, arrayMax;

    for (i = 0; i < ARRAY_SIZE; i++) {
        // printf("Kerlek add meg a(z) %d. elemet:\n", (i + 1));
        // intArray[i] = getInputInteger();
        intArray[i] = randomInteger(0, 100000);
    }

    TICK(START_SUM_1);
    for (i = 0; i < 10000; i++) {
        arraySum = getArraySum(intArray);
    }
    TOCK(START_SUM_1);
    TICK(START_SUM_2);
    for (i = 0; i < 10000; i++) {
        arraySum = getArraySumR(intArray, 0);
    }
    TOCK(START_SUM_2);

    printf("\n");
    
    TICK(START_MIN_1);
    for (i = 0; i < 10000; i++) {
        arraySum = getArrayMinimum(intArray);
    }
    TOCK(START_MIN_1);
    TICK(START_MIN_2);
    for (i = 0; i < 10000; i++) {
        arraySum = getArrayMinimumR(intArray, 0);
    }
    TOCK(START_MIN_2);

    printf("\n");

    TICK(START_MAX_1);
    for (i = 0; i < 10000; i++) {
        arraySum = getArrayMaximum(intArray);
    }
    TOCK(START_MAX_1);
    TICK(START_MAX_2);
    for (i = 0; i < 10000; i++) {
        arraySum = getArrayMaximumR(intArray, 0);
    }
    TOCK(START_MAX_2);

    return 0;
}

int randomInteger(int minimum, int maximum) {
    return (rand() % (maximum-minimum+1)) + 1;
}

int getInputInteger() {
    int isValid = false;
    int number;

    do {
        isValid = false;

        if (scanf("%d", &number) == 1) {
            isValid = true;
        } else {
            printf("[Error] Szamot adj meg!\n");
        }

        while (getchar() != '\n');
    } while(!isValid);

    return number;
}

int getArraySum(int intArray[]) {
    int sum = 0;
    int i;

    for (i = 0; i < ARRAY_SIZE; i++) {
        sum += intArray[i];
    }

    return sum;
}
int getArrayMinimum(int intArray[]) {
    int index = 0;
    int i;

    for (i = 1; i < ARRAY_SIZE; i++) {
        if (intArray[index] > intArray[i]) {
            index = i;
        }
    }

    return intArray[index];
}
int getArrayMaximum(int intArray[]) {
    int index = 0;
    int i;

    for (i = 1; i < ARRAY_SIZE; i++) {
        if (intArray[index] < intArray[i]) {
            index = i;
        }
    }

    return intArray[index];
}

int getArraySumR(int intArray[], int arrayIndex) {
    int sum = 0;
    
    if (arrayIndex >= ARRAY_SIZE) {
        return 0;
    }

    return intArray[arrayIndex] + getArraySumR(intArray, (arrayIndex + 1));
}
int getArrayMinimumR(int intArray[], int arrayIndex) {
    int next;
    int min = intArray[arrayIndex];

    if (arrayIndex == (ARRAY_SIZE - 1)) {
        return min;
    }

    next = getArrayMinimumR(intArray, (arrayIndex + 1));

    if (min > next) {
        return next;
    }
    return min;
}
int getArrayMaximumR(int intArray[], int arrayIndex) {
    int next;
    int max = intArray[arrayIndex];

    if (arrayIndex == (ARRAY_SIZE - 1)) {
        return max;
    }

    next = getArrayMaximumR(intArray, (arrayIndex + 1));

    if (max < next) {
        return next;
    }
    return max;
}