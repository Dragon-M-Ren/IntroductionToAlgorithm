#include <iostream>
#include <algorithm>
#include <tuple>

#include "../util/print.h"
#include "../util/random.h"

#include "09_s01_minmax.h"

using std::cout;
using std::endl;
using std::sort;

int length = 11;

int main(){
  int *nums = new int[length];
  random_int_array(nums,length);
  
  cout << "Origianl Array: " << endl;
  print_int_array(nums, length);

  int max_index = Maximum(nums, length);
  int min_index = Minimum(nums, length);

  std::tuple<int, int> min_max = MinMax(nums, length);

  cout << "Max value: " << nums[max_index] << endl;
  cout << "Min value: " << nums[min_index] << endl;
  cout << "Max: " << nums[std::get<0>(min_max)] << endl;
  cout << "Min: " << nums[std::get<1>(min_max)] << endl;

  std::sort(nums, nums + length);
  cout << "Sorted Arrray: " << endl;
  print_int_array(nums, length);
}