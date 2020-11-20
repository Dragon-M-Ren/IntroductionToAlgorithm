#include "06_s06_p2_dary_heap.h"

#include <iostream>
#include <functional>

#include "../util/print.h"
#include "../util/random.h"

using namespace std;

const int d = 3;
const int length = 10;
const int big_length = 100;

const int inter = 10;
const int extract = 20;

int test_heapify();
int test_build();

int main(){
  test_heapify();
  return 0;
}
int test_heapify(){
  int *nums = new int[big_length];
  dary_heap dh(d, big_length);
  
  random_int_array_positive(nums, big_length);
  build_dary_heap(dh, nums, big_length);

  for(int i = 0; i < extract; i++){
    extract_max(dh);
    if(is_dary_heap(dh)){
      cout << i << " heapify passed.\n";
      continue;
    }
    
    cout << "Test failed: " << endl;
    cout << "Origianl Array: " << endl;
    print_int_array(nums, big_length); 
    cout << "Heap content: " << endl;
    print_dary_heap(dh);
    return 1;
  }
    
  delete [] nums;
  return 0; 
}

int test_build(){
  int *nums = new int[length];
  dary_heap dh(d, length);
  
  for(int i = 0; i < inter; i++){
    random_int_array_positive(nums,length);

    build_dary_heap(dh, nums, length);
    
    if(is_dary_heap(dh)){
      cout << i << " passed.\n";
       continue;
    }
    
    cout << "Test failed: " << endl;
    cout << "Origianl Array: " << endl;
    print_int_array(nums, length); 
    cout << "Heap content: " << endl;
    print_dary_heap(dh);

    return 1;
  }
  
  delete [] nums;
  
  nums = new int[big_length];
  dh = dary_heap(d, big_length);

  for(int i = 0; i < inter; i++){
    random_int_array_positive(nums, big_length);
    build_dary_heap(dh, nums, big_length);

    if(is_dary_heap(dh)){
      cout << i << " big passed.\n";
      continue;
    }
    
    cout << "Test failed: " << endl;
    cout << "Origianl Array: " << endl;
    print_int_array(nums, big_length); 
    cout << "Heap content: " << endl;
    print_dary_heap(dh);
    return 1;
  }
    
  delete [] nums;
  return 0;
}