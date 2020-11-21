#include "09_s02_select.h"

#include <iostream>
#include <algorithm>

#include "../util/print.h"
#include "../util/random.h"

using namespace std;

// test settings
int length = 10;

int main(){
  int target;
  int *nums = new int[length];
  random_int_array(nums,length);
  
  cout << "Origianl Array: " << endl;
  print_int_array(nums, length);

  while(cin >> target){
    int res = RandomizedSelect(nums, 0, length - 1, target);
    cout << "res: " << res << endl;
  }

  sort(nums, nums + length);
  cout << "Sorted Arrray: " << endl;
  print_int_array(nums, length);
  
  delete [] nums;
  return 0;
}