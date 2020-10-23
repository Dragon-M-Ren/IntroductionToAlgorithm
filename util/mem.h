#pragma once

/// Preserved since some old code use this function
int ** new_2d_int_array(int la, int lb){
    int **ar;

    ar = new int*[la];
    for(int i = 0; i < la; i++)
        ar[i] = new int[lb];
    
    return ar;
}

template <class Element>
Element **new_2d_array(int la, int lb){
    Element **ar;

    ar = new Element*[la];
    for(int i = 0; i < la; i++)
        ar[i] = new Element[lb];
    
    return ar;
}

template <class Element>
void delete_2d_array(Element **a, int len){
   for(int i = 0; i < len; i++)
        delete [] a[i];
    
    delete a; 
}