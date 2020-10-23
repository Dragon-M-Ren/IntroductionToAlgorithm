#include <iostream>
#include <vector>

#include "../util/print.h"
#include "../util/random.h"

#include "quick_sort.h"

using namespace std;

// test settings
int length = 10;
auto sort_func = QuickSortNonIncrInterface;

int main(){
  int *nums = new int[length];
  random_int_array(nums,length);
  
  cout << "Origianl Array: " << endl;
  print_int_array(nums, length);

  sort_func(nums, length);
  cout << "Sorted Arrray: " << endl;
  print_int_array(nums, length);
  
  delete [] nums;
  return 0;
}