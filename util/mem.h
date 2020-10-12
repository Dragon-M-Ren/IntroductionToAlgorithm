#pragma once

int ** new_2d_int_array(int la, int lb){
    int **ar;

    ar = new int*[la];
    for(int i = 0; i < la; i++)
        ar[i] = new int[lb];
    
    return ar;
}

void delete_2d_array(int **a, int la){
    for(int i = 0; i < la; i++)
        delete [] a[i];
    
    delete a;
}