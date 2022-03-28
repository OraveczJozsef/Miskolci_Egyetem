#include "../include/random.h"

int random_integer() {
    return (rand() % (INT_MAX + INT_MIN));
}
long random_long() {
    return (rand() % (LONG_MAX - LONG_MIN + 1)) + 1;
}
double random_double() {
    return ((double) rand() / (DBL_MAX - DBL_MIN)) + DBL_MIN;
}