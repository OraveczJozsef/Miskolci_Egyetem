#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define FILE_NAME "test.txt"

int generation_integer(int minimum_value, int maximum_value);
int main(int argc, char** argv) {
    if (argc != 2) {
        printf("[Error] Arguments!\n");
        exit(1);
    }

    int i;
    int j = 0;
    int char_set[64];
    char char_array[char_array_size];

    FILE* f;

    printf("%d\n", argc);

    for (i = 65; i <= 90; i++) {
        char_set[j] = i;
        j++;
    }
    for (i = 97; i <= 122; i++) {
        char_set[j] = i;
        j++;
    }
    for (i = 48; i <= 57; i++) {
        char_set[j] = i;
        j++;
    }
    char_set[j] = 32;
    j++;
    char_set[j] = 10;
    j++;
    
    for (i = 0; i < char_array_size; i++) {
        char_array[i] = char_set[generation_integer(0, 64)];
    }

    for (i = 0; i < char_array_size; i++) {
        printf("%c", char_array[i]);
    }

    f = fopen(FILE_NAME, "w+");
    if (!f) {
        printf("[Error] File Open!\n");
        exit(1);
    }

    for (i = 0; i < char_array_size; i++) {
        fprintf(f, "%c", char_array[i]);
    }

    fflush(f);
    fclose(f);
    
    return 0;
}

int generation_integer(int minimum_value, int maximum_value) {
    return rand() % (maximum_value + 1 - minimum_value) + minimum_value;
}