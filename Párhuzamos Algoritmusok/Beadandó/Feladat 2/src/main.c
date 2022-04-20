#include "simulation.h"

int main(int argc, char** argv) {
    int i;

    for (i = 0; i <= 500000; i = i + 25000) {
    //for (i = 0; i <= 10; i++) {
        simulation(i);
    }

    return 0;
}