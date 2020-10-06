#ifndef PRINT_H
#define PRINT_H

#include <cstdio>
#include <vector>


void print_int_array(int * ar, int len, int line_volume = 10)
{
    for(int i = 0; i < len; i++)
    {
        if(i != 0 && i%line_volume == 0)
            printf("\n");
        
        printf("%8d ",*(ar + i));
    }

    printf("\n");
}


void print_2d_int_array(int *ar[], int la, int lb, int line_volume = 10)
{
    for(int i = 0; i < la; i++)
        print_int_array(ar[i], lb, line_volume);
}

void print_int_vector(std::vector<int> v, int line_volume = 10){
    int len = v.size();

    for(int i = 0; i < len; i++)
    {
        if(i != 0 && i%line_volume == 0)
            printf("\n");
        
        printf("%8d ",v[i]);
    }

    printf("\n");
}
#endif