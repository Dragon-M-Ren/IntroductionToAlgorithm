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
  Element<Empty> *input_data = new Element<Empty>[length + 1];
  
  random_int_array(nums,length);
  BuildElementVector<Empty>(nums, input_data, length);

  HeapSort(input_data, length);
    
  cout << "Origianl Array: " << endl;
  print_int_array(nums, length); 
  cout << "Sorted content: " << endl;
  PrintHeapKeys(input_data, length);
  
  delete [] nums;
  delete [] input_data;
  return 0;
}