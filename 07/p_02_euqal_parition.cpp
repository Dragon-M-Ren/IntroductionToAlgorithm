#include "p_02_equal_elements.h"

#include <iostream>
#include <cstring>
#include <algorithm>

#include "../util/print.h"
#include "../util/random.h"

using namespace std;

const int length = 10;
const int big_length = 100;
const int iterations = 100;

bool test(int length);

int main(){
  for(int i = 0; i < iterations; i++){
    if(test(length))
      cout << "Test " << i << " passed\n";
    else{
      cout << "Test " << i << " Not passed\n"; 
      return 1;
    }
  }
  for(int i = 0; i < iterations; i++){
    if(test(big_length))
      cout << "Big test " << i << " passed\n";
    else{
      cout << "Test " << i << " Not passed\n"; 
      return 1;
    }
  }

  return 0;
}

bool test(int length){
  int *nums = new int[length];
  int *sorted = new int[length];
  bool ret;

  random_int_array(nums,length);
  memcpy(sorted, nums, sizeof(int) * length);
  sort(sorted, sorted + length);
  QuickSortForEqual(nums, 0, length - 1);

  if(memcmp(nums, sorted, sizeof(int) * length) == 0)
    ret = true;
  else
    ret = false;
  
  
  if(!ret){
    cout << "Origianl Array: " << endl;
    print_int_array(sorted, length);

    cout << "Sorted Arrray: " << endl;
    print_int_array(nums, length);
  }

  delete [] sorted;
  delete [] nums;
  return ret;
}