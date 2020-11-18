#include "06_s01_heap.h"

#include <iostream>
#include <functional>

#include "../util/print.h"
#include "../util/random.h"

#define build_heap BuildHeapNonRecur

using namespace std;

const int length = 10;
const int big_length = 100;

const int inter = 10;

int main(){
  int *nums = new int[length];
  heap<Empty> input_data(length);
  
  for(int i = 0; i < inter; i++){
    random_int_array(nums,length);
    BuildElementVector<Empty>(input_data, nums, length);

    build_heap(input_data);
    
    if(TestHeapInteface(input_data)){
      cout << i << " passed.\n";
       continue;
    }
    
    cout << "Test failed: " << endl;
    cout << "Origianl Array: " << endl;
    print_int_array(nums, length); 
    cout << "Heap content: " << endl;
    PrintHeapKeys(input_data);

    return 1;
  }
  
  delete [] nums;
  
  nums = new int[big_length];
  input_data = heap<Empty>(big_length + 1);

  for(int i = 0; i < inter; i++){
    random_int_array(nums, big_length);
    BuildElementVector<Empty>(input_data, nums, length);

    build_heap(input_data);
    
    if(TestHeapInteface(input_data)){
      cout << i << " big passed.\n";
      continue;
    }
    
    cout << "Test failed: " << endl;
    cout << "Origianl Array: " << endl;
    print_int_array(nums, big_length); 
    cout << "Heap content: " << endl;
    PrintHeapKeys(input_data);
    return 1;
  }
    
  delete [] nums;
  return 0;
}