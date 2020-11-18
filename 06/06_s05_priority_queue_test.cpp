#include "06_s05_priority_queue.h"
#include "../util/print.h"
#include "../util/random.h"

using namespace std;

const int length = 10;

int main(){
  int *nums = new int[length];
  heap<Empty> h(length);
  
  random_int_array_positive(nums,length);
  cout << "Origianl Array: " << endl;
  print_int_array(nums, length, 20);

  cout << "Test insert \n";
  for(int i = 0; i < length; i++){
    insert(h, nums[i], Empty());
    PrintHeapKeys(h);
  }

  for(int i = 0; i < 2; i++){
    extract_max(h);
    PrintHeapKeys(h);
  }

  heap_delete(h, 3);
  PrintHeapKeys(h);
  heap_delete(h, 4);
  PrintHeapKeys(h);

  delete [] nums;
  return 0;
}