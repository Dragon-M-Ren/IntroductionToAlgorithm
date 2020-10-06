#include <iostream>
#include <vector>

#include "heap.h"
#include "../util/print.h"
#include "../util/random.h"

using namespace std;

int length = 10;

int main(){
  int *nums = new int[length];
  random_int_array(nums,length);
  
  cout << "Origianl Array: " << endl;
  print_int_array(nums, length);

  vector<int> heap_v(nums, nums + length);
  
  auto input = BuildElementVector(heap_v);
  Heap<Empty> heap(input);
  cout << "Build heap finished: " << endl;
  heap.Show();
  heap.Sort();
  cout << "After heap sort: " << endl;
  heap.ShowAll();

  return 0;
}