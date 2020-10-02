// std::map can be used to impelment this algorithm
// But it can be achieved using sort, just sort first 
// and then use binary search to find the solution
// The sort will take O(n lg n)
// Each binary search will take O(lg n) and for n elements
#include <iostream>

#include "../util/print.h"
#include "../util/random.h"

#include "02_s03_merge_sort.h"
#include "02_s01_e3_binary_search.h"

using std::cout;
using std::cin;
using std::endl;


// test settings
int length = 10;
auto sort_func = merge_sort_interface;

int main(){
  int *nums = new int[length];
  random_int_array(nums,length);
  
  cout << "Origianl Array: " << endl;
  print_int_array(nums, 10);

  sort_func(nums, 10);
  cout << "Sorted Arrray: " << endl;
  print_int_array(nums, 10);

  int sum;

  while(cin >> sum){
    bool find_flag = false;
    for(int i = 0; i < length; i++){
      int cur = nums[i];
      int target = sum - cur;
      int find;
      if(binary_search(nums, length, target) != -1){
        cout << "find " << cur << " " << target << endl;
        find_flag = true;
        break;
      }
    }
    if(!find_flag)
      cout << "Not find" << endl;
  }
  delete [] nums;
  return 0;
}