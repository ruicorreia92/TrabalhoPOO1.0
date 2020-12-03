#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utilis.h"


void initRandom()
{
    srand(time(NULL));
}

int intUniformRnd(int a, int b)
{
    return a + rand()%(b-a+1);
}

