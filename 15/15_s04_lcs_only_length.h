#pragma once

#include <functional>
#include <iostream>

int lcs_two_row(const char *x, const char *y, int lenx, int leny){
  // just switch the two rows back and forth
  // skipped
  return 0;
}

int lcs_one_row(const char *x, const char *y, int lenx, int leny){
  int *row = new int[leny + 1];
  // the up-left element, it will be overwirtten by the new value
  int up_left, next_up_left; 

  // init the frist line
  for(int i = 0; i < lenx + 1; i++)
    row[i] = 0;
  
  for(int i = 0; i < lenx; i++){
    up_left = 0;
    for(int j = 0; j < leny; j++){
      // set it to the current value
      // The original value will be overwritten
      next_up_left = row[j+1];
      if(x[i] == y[j]){
        row[j+1] = up_left + 1;
      }
      else if(row[j] > row[j+1]){
        row[j+1] = row[j];
      }else{
        // do nothing
        // it's actually row[j+1] = row[j+1]
      }
      up_left = next_up_left;
    }
  }
  return row[leny];
}

void lcs_driver(const char * x, const char * y, int lenx, int leny){
  // Compute    
  int ret = lcs_one_row(x, y, lenx, leny);
  
  // Print the matrix
  std::cout << "max length: " << ret << std::endl;
}