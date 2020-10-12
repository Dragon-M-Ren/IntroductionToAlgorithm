#pragma once

#include <iostream>

#include "15_s04_lcs_commom.h"

#include "../util/mem.h"
#include "../util/print.h"

#define UNAVAILABLE -1

// Note the differrent start between lcs_matrix and index
// indexe starts from 1(The number of elements)
// lcs_matrix starts from 1
// just decrease them when accesssing the string
int lcs_top_down(int **lcs_matrix, const char *x, const char *y, int lenx, int leny){
  if(UNAVAILABLE != lcs_matrix[lenx][leny])
    return lcs_matrix[lenx][leny];
  // The base case is initialized in the driver function
  
  // If the end character is the same
  if(x[lenx-1] == y[leny-1]){
    lcs_matrix[lenx][leny] = 1 + lcs_top_down(lcs_matrix, x, y, lenx-1, leny-1);
    return lcs_matrix[lenx][leny];
  }

  // Compare which is larger
  int up = lcs_top_down(lcs_matrix, x, y, lenx-1, leny);
  int left = lcs_top_down(lcs_matrix, x, y, lenx, leny-1);

  if(up >= left)
    lcs_matrix[lenx][leny] = up;
  else
    lcs_matrix[lenx][leny] = left;
  
  return lcs_matrix[lenx][leny];         
}

void lcs_td_driver(const char * x, const char * y, int lenx, int leny){
  int ** lcs_matrix;
  lcs_matrix = new_2d_int_array(lenx+1, leny+1);
  
  // Init all elements to  -1
  for(int i = 0; i < lenx + 1; i++)
    for(int j = 0; j < leny + 1; j++)
      lcs_matrix[i][j] = UNAVAILABLE;

  // Init the first line
  for(int i = 0; i < lenx+1; i++)
     lcs_matrix[i][0] = 0;
  
  for(int j = 0; j < leny+1; j++)
     lcs_matrix[0][j] = 0;

  // Compute    
  int ret = lcs_top_down(lcs_matrix, x, y, lenx, leny);
  
  // Print the matrix
  std::cout << "max length: " << ret;
  print_2d_int_array(lcs_matrix, lenx+1, leny+1); 
  
  // Print the computed array
  print_result(lcs_matrix, lenx, leny, x);

  delete_2d_array(lcs_matrix, lenx+1);
}