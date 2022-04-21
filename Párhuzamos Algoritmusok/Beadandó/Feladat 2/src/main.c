#include "simulation.h"

int main(int argc, char** argv) {
    int i;

    for (i = 0; i <= 200000; i = i + 10000) {
    // for (i = 1000; i <= 5000; i++) {
    // for (i = 0; i <= 25000; i = i + 1000) {
        simulation(i);
    }

    return 0;
}