#include "08_s02_e4_interval_size.h"

#include <iostream>
#include <vector>

#include "../util/print.h"
#include "../util/random.h"

using namespace std;

int length = 10000;
int lower_bound_ = 0;
int upper_bound_ = 100;

int main(){
  int *nums = new int[length];
  int *buffer = new int[upper_bound_ - lower_bound_ + 1];

  random_int_array_positive(nums,length, upper_bound_);
  
  cout << "Origianl Array: " << endl;
  print_int_array(nums, length);
  
  preprocess(nums, buffer, lower_bound_, upper_bound_, length);

  int start, end;
  while((cin >> start) && (cin >> end)){
    cout << naive_query(nums, start, end, length) << endl;
    cout << processed_query(buffer, lower_bound_, start, end) << endl;
  }

  return 0;
}