#include <iostream>

#include "../util/print.h"
#include "../util/random.h"

#include "04_s01_max_subarray_brute.h"
#include "04_s01_max_subarray_dc.h"
#include "04_s01_max_subarray_linear.h"

using std::cout;
using std::endl;

int length = 10;

int main(){
  int *nums = new int[length];
  random_int_array(nums,length);
  
  cout << "Array: " << endl;
  print_int_array(nums, length);

  cout << "# Brute-force result:\n";
  max_subarray_brute(nums,length).print();

  cout << "# Divide and conquer:\n";
  max_subarray_interface(nums, length).print();

  cout << "# Linear:\n";
  max_subarray_linear(nums, length).print();


  
  delete [] nums;
  return 0;
}