#include <iostream>
#include <vector>

#include "../util/print.h"
#include "../util/random.h"

#include "02_s01_insertion_sort.h"
#include "02_s01_e2_insertion_sort_noninsc.h"
#include "02_s02_e2_selection_sort.h"
#include "02_s03_merge_sort.h"
#include "02_s04_p2_bubble_sort.h"

using namespace std;

// test settings
int length = 10;
auto sort_func = bubble_sort;

int main(){
  int *nums = new int[length];
  random_int_array(nums,length);
  
  cout << "Origianl Array: " << endl;
  print_int_array(nums, 10);

  sort_func(nums, 10);
  cout << "Sorted Arrray: " << endl;
  print_int_array(nums, 10);
  
  delete [] nums;
  return 0;
}