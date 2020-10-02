#include <iostream>
#include "../util/print.h"
#include "../util/random.h"

#include "02_s01_e3_binary_search.h"
#include "02_s01_insertion_sort.h"

using namespace std;

int length = 10;

int main(){
  int *nums = new int[length];
  random_int_array(nums,length);
  
  cout << "Origianl Array: " << endl;
  print_int_array(nums, 10);

  insertion_sort(nums, 10);
  cout << "Sorted Arrray: " << endl;
  print_int_array(nums, 10);

  int target;
  while(cin >> target){
    int res = binary_search(nums, length, target);
    cout << res << endl;
  }
  
  delete [] nums;
  return 0;
}