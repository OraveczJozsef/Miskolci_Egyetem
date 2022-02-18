#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10

#define FILE_NAME_INT "intfile"
#define FILE_NAME_LONG "longfile"
#define FILE_NAME_DOUBLE "doublefile"

int randomInteger(int minimum, int maximum);
double randomDouble(int minimum, int maximum);

void writeInteger(int intArray[]);
void writeLong(long longArray[]);
void writeDouble(double doubleArray[]);

long fileSize(char* fileName);

void readInteger(int intArray[]);
void readLong(long longArray[]);
void readDouble(double doubleArray[]);

void printfArray(int intArray[], long longArray[], double doubleArray[]);

int main(int argc, char** argv) {
    int i;
    int intArray[ARRAY_SIZE];
    long longArray[ARRAY_SIZE];
    double doubleArray[ARRAY_SIZE];

    int newIntArray[ARRAY_SIZE];
    long newLongArray[ARRAY_SIZE];
    double newDoubleArray[ARRAY_SIZE];
    
    srand(time(NULL));
    
    for (i = 0; i < ARRAY_SIZE; i++) {
        intArray[i] = randomInteger(0, 999);
        longArray[i] = randomInteger(0, 999999);
        doubleArray[i] = randomDouble(0.00, 999.99);
    }

    printfArray(intArray, longArray, doubleArray);
    printf("\n");

    writeInteger(intArray);
    writeLong(longArray);
    writeDouble(doubleArray);

    printf("Int File: %li byte\n", fileSize(FILE_NAME_INT));
    printf("Long File: %li byte\n", fileSize(FILE_NAME_LONG));
    printf("Double File: %li byte\n", fileSize(FILE_NAME_DOUBLE));
    printf("\n");

    readInteger(newIntArray);
    readLong(newLongArray);
    readDouble(newDoubleArray);
    
    printfArray(newIntArray, newLongArray, newDoubleArray);
    printf("\n");
    return 0;
}

int randomInteger(int minimum, int maximum) {
    return (rand() % (maximum-minimum+1)) + 1;
}
double randomDouble(int minimum, int maximum) {
    return ((double) rand() / (maximum - minimum)) + minimum;
}

void writeInteger(int intArray[]) {
    FILE* f;

    f = fopen(FILE_NAME_INT, "w+");
    if (f == NULL) {
        printf("[Error-1] File not open!\n");
        exit(1);
    }
    
    fprintf(f, "%d, %d, %d, %d, %d, %d, %d, %d, %d, %d", intArray[0], intArray[1], intArray[2], intArray[3], intArray[4], intArray[5], intArray[6], intArray[7], intArray[8], intArray[9]);
    fclose(f);
}
void writeLong(long longArray[]) {
    FILE* f;

    f = fopen(FILE_NAME_LONG, "w+");
    if (f == NULL) {
        printf("[Error-2] File not open!\n");
        exit(1);
    }
    
    fprintf(f, "%li, %li, %li, %li, %li, %li, %li, %li, %li, %li", longArray[0], longArray[1], longArray[2], longArray[3], longArray[4], longArray[5], longArray[6], longArray[7], longArray[8], longArray[9]);
    fclose(f);
}
void writeDouble(double doubleArray[]) {
    FILE* f;

    f = fopen(FILE_NAME_DOUBLE, "w+");
    if (f == NULL) {
        printf("[Error-3] File not open!\n");
        exit(1);
    }
    
    fprintf(f, "%lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf", doubleArray[0], doubleArray[1], doubleArray[2], doubleArray[3], doubleArray[4], doubleArray[5], doubleArray[6], doubleArray[7], doubleArray[8], doubleArray[9]);
    fclose(f);
}

long fileSize(char* fileName) {
    long int size;

    FILE* f = fopen(fileName, "r");
    if (f == NULL) {
        printf("[Error-4] File not open!\n");
        exit(1);
    }

    fseek(f, 0L, SEEK_END);
    size = ftell(f);
    fclose(f);

    return size;
}

void readInteger(int intArray[]) {
    FILE* f;

    f = fopen(FILE_NAME_INT, "r");
    if (f == NULL) {
        printf("[Error-3] File not open!\n");
        exit(1);
    }

    fscanf(f, "%d, %d, %d, %d, %d, %d, %d, %d, %d, %d", &intArray[0], &intArray[1], &intArray[2], &intArray[3], &intArray[4], &intArray[5], &intArray[6], &intArray[7], &intArray[8], &intArray[9]);
    fclose(f);
}
void readLong(long longArray[]) {
    FILE* f;

    f = fopen(FILE_NAME_LONG, "r");
    if (f == NULL) {
        printf("[Error-3] File not open!\n");
        exit(1);
    }

    fscanf(f, "%li, %li, %li, %li, %li, %li, %li, %li, %li, %li", &longArray[0], &longArray[1], &longArray[2], &longArray[3], &longArray[4], &longArray[5], &longArray[6], &longArray[7], &longArray[8], &longArray[9]);
    fclose(f);
}
void readDouble(double doubleArray[]) {
    FILE* f;

    f = fopen(FILE_NAME_DOUBLE, "r");
    if (f == NULL) {
        printf("[Error-3] File not open!\n");
        exit(1);
    }

    fscanf(f, "%lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf", &doubleArray[0], &doubleArray[1], &doubleArray[2], &doubleArray[3], &doubleArray[4], &doubleArray[5], &doubleArray[6], &doubleArray[7], &doubleArray[8], &doubleArray[9]);
    fclose(f);
}

void printfArray(int intArray[], long longArray[], double doubleArray[]) {
    int i;

    for (i = 0; i < ARRAY_SIZE; i++) {
        printf("%d | ", intArray[i]);
    }
    printf("\n");
    
    for (i = 0; i < ARRAY_SIZE; i++) {
        printf("%li | ", longArray[i]);
    }
    printf("\n");
    
    for (i = 0; i < ARRAY_SIZE; i++) {
        printf("%lf | ", doubleArray[i]);
    }
    printf("\n");
}