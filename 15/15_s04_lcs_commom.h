#pragma once

#include <algorithm>
#include <vector>
#include <iostream>

#include "../util/print.h"
// x, y is the index in lcs_matrix
// To get the array index, decrement it by 1
void print_result(int ** lcs_matrix, int x, int y, const char *array_x){
  std::vector<int> index_x, index_y;

  while((x > 0) && (y > 0)){
    if(lcs_matrix[x-1][y-1]+1 == lcs_matrix[x][y]){
      index_x.push_back(x-1);
      index_y.push_back(y-1);
      x--;
      y--;
    }else if(lcs_matrix[x][y-1] >= lcs_matrix[x-1][y]){
      y--;
    }else{
      x--;
    }
  }

  // The result is pushed reversed, so revrse it to the normal order 
  std::reverse(index_x.begin(), index_x.end());
  std::reverse(index_y.begin(), index_y.end());

  // get the common array
  std::vector<char> subarray;
  for(int index: index_x)
    subarray.push_back(array_x[index]);
  
  // Print result
  std::cout << "Index of array x: \n";  
  print_int_vector(index_x);
  std::cout << "Index of array y: \n";
  print_int_vector(index_y);
  std::cout << "The subarray: \n";
  print_char_vector(subarray);
}