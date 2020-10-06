#ifndef RANDOM_H
#define RANDOM_H
#include <cstdlib>
#include <ctime>


// Get the random number between start and end
// Both ends are inclusion
int random_int(int start, int end){
    srand(time(NULL));

    int interval = end - start;

    return rand()%interval + start;
}

void random_int_array_positive(void * buffer, int len, int max = 100)
{
    int *ar = (int *) buffer;
    srand(time(NULL));

    for(int i = 0; i < len; i++)
        *(ar + i) = rand()%max;
}

void random_int_array(void * buffer, int len, int max = 100)
{
    int *ar = (int *) buffer;
    srand(time(NULL));

    for(int i = 0; i < len; i++)
    {
        if(rand()%2)
            *(ar + i) = rand()%max;
        else
            *(ar + i) = -1 * rand()%max;
    }
}

#endif