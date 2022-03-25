#include "../../header/utils/util.h"

int randomInteger(int minimum, int maximum) {
    return (rand() % (maximum-minimum+1)) + 1;
}