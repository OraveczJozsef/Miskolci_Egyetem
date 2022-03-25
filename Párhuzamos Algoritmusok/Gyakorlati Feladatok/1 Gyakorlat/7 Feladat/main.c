#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 20

int rand_integer(int minimum, int maximum);
void tick_tock(clock_t time);
//void print_prime_number(int number);
void count_primes(int number);

int main(int argc, char** argv) {
    int i = 7;
    clock_t time = clock();
    int intArray[ARRAY_SIZE];

    //for (i = 0; i < ARRAY_SIZE; i++) {
        intArray[i] = (i+1) * 1000;
        printf("%d\n", intArray[i]);
    //}

    //for (i = 0; i < ARRAY_SIZE; i++) {
        time = clock();
        //print_prime_number(intArray[i]);
        count_primes(intArray[i]);
        tick_tock(time);
    //}

    return 0;
}

int rand_integer(int minimum, int maximum) {
    return (rand() % (maximum-minimum+1)) + 1;
}

void tick_tock(clock_t time) {
    printf("Eltelt ido: %g sec.\n", (double)(clock() - (time)) / CLOCKS_PER_SEC);
}

/*void print_prime_number(int number) {
    int j = 1, i = 1, c = 0;

    while (i < number) {
        j = 1;
        c = 0;

        while (j <= i) {
            if (i % j == 0) {
                c++;
            }

            j++;
        }

        if (c == 2) {
            printf("%d | ", i);
        }

        i++;
    }
}*/
void count_primes(int number) {
    int j = 1, i = 1, c = 0;
    int count = 0;
    while (i < number) {
        j = 1;
        c = 0;

        while (j <= i) {
            if (i % j == 0) {
                c++;
            }

            j++;
        }

        if (c == 2) {
            count++;
        }

        i++;
    }

    printf("%d - %d \n", number, count);
}