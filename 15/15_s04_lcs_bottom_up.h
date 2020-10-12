#pragma once

#include <iostream>

#include "15_s04_lcs_commom.h"

#include "../util/mem.h"
#include "../util/print.h"


// Note the array's index start form 0
// But in the lcs_matrix, the array's index start from 1
// Be careful if the change 
int lcs_bottom_up(int **lcs_matrix, const char *x, const char *y, int lenx, int leny){
  for(int i = 0; i < lenx; i++){
    for(int j = 0; j < leny; j++){
      if(x[i] == y[j])
        lcs_matrix[i+1][j+1] = lcs_matrix[i][j] + 1;
      else if(lcs_matrix[i][j+1] > lcs_matrix[i+1][j])
        lcs_matrix[i+1][j+1] = lcs_matrix[i][j+1];
      else
        lcs_matrix[i+1][j+1] = lcs_matrix[i+1][j];
    }
  }

  return lcs_matrix[lenx][leny];
}

void lcs_bu_driver(const char * x, const char * y, int lenx, int leny){
  int ** lcs_matrix;
  lcs_matrix = new_2d_int_array(lenx+1, leny+1);
  
  // Init the first line
  for(int i = 0; i < lenx+1; i++)
     lcs_matrix[i][0] = 0;
  
  for(int j = 0; j < leny+1; j++)
     lcs_matrix[0][j] = 0;

  // Compute    
  int ret = lcs_bottom_up(lcs_matrix, x, y, lenx, leny);
  
  // Print the matrix
  std::cout << "max length: " << ret;
  print_2d_int_array(lcs_matrix, lenx+1, leny+1); 
  
  // Print the computed array
  print_result(lcs_matrix, lenx, leny, x);

  delete_2d_array(lcs_matrix, lenx+1);
}