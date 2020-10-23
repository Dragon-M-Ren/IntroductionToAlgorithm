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
  Element<Empty> *input_data = new Element<Empty>[length + 1];
  
  for(int i = 0; i < inter; i++){
    random_int_array(nums,length);
    BuildElementVector<Empty>(nums, input_data, length);

    build_heap(input_data, length);
    
    if(TestHeapInteface(input_data, length)){
      cout << i << " passed.\n";
       continue;
    }
    
    cout << "Test failed: " << endl;
    cout << "Origianl Array: " << endl;
    print_int_array(nums, length); 
    cout << "Heap content: " << endl;
    PrintHeapKeys(input_data, length);

    return 1;
  }
  
  delete [] nums;
  delete [] input_data;
  
  nums = new int[big_length];
  input_data = new Element<Empty>[big_length + 1];

  for(int i = 0; i < inter; i++){
    random_int_array(nums, big_length);
    BuildElementVector<Empty>(nums, input_data, big_length);

    build_heap(input_data, big_length);
    
    if(TestHeapInteface(input_data, big_length)){
      cout << i << " big passed.\n";
      continue;
    }
    
    cout << "Test failed: " << endl;
    cout << "Origianl Array: " << endl;
    print_int_array(nums, big_length); 
    cout << "Heap content: " << endl;
    PrintHeapKeys(input_data, big_length);
    return 1;
  }
    
  delete [] nums;
  delete [] input_data;
  return 0;
}