#include <iostream>
#include <vector>

#include "../util/print.h"
#include "../util/random.h"

#include "08_s03_radix_sort.h"

using namespace std;

// test settings
int length = 10;

int main(){
  int *nums = new int[length];
  int *res = new int[length];
  random_int_array_positive(nums,length, 10000);
  
  cout << "Origianl Array: " << endl;
  print_int_array(nums, length);

  RadixSort(nums, res, length, 4);
  cout << "Sorted Arrray: " << endl;
  print_int_array(nums, length);
  
  delete [] nums;
  delete [] res;
  return 0;
}