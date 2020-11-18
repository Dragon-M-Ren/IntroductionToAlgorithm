#include "06_s04_heap_sort.h"

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
  
  random_int_array(nums,length);
  BuildElementVector<Empty>(input_data, nums, length);

  HeapSort(input_data);
    
  cout << "Origianl Array: " << endl;
  print_int_array(nums, length); 
  cout << "Sorted content: " << endl;
  input_data.size = input_data.capacity;
  PrintHeapKeys(input_data);
  
  delete [] nums;
  return 0;
}