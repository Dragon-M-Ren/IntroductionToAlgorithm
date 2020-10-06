#include <iostream>
#include <vector>

#include "../util/print.h"
#include "../util/random.h"

#include "08_s02_counting_sort.h"

using namespace std;

// test settings
int length = 10;

int main(){
  int *nums = new int[length];
  int *res = new int[length];
  random_int_array(nums,length);
  
  cout << "Origianl Array: " << endl;
  print_int_array(nums, length);

  CountingSort(nums, res, length, -100, 100);
  cout << "Sorted Arrray: " << endl;
  print_int_array(res, length);
  
  delete [] nums;
  delete [] res;
  return 0;
}