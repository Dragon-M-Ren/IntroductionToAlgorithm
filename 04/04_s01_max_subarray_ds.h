#pragma once

#include <iostream>


// This is the data stucture for the solution of maximum subarray
struct max_subarray_solution{
  int start;
  int end;
  int sum;

  void print();
};

typedef max_subarray_solution ms_ret;

void max_subarray_solution::print(){
  std::cout << "Start: " << start << "  End: " <<\
     end << "  Sum: " << sum << std::endl;
}
