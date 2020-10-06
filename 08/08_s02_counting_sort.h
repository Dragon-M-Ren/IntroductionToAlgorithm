#pragma once

#include <functional>>

void CountingSort(int *nums, int *res, int length, int lower_bound, int upper_bound){
  int size = upper_bound - lower_bound + 1;
  int *counter = new int[size];

  // Initialize  
  for(int i = 0; i < size; i++){
    counter[i] = 0;
  }

  // count  
  for(int i = 0; i < length; i++){
    counter[nums[i] - lower_bound]++;
  }

  // Use span to compute index
  for(int i = 1; i < size; i++){
    counter[i] += counter[i-1];
  }

  // Write the result to res
  for(int i = length - 1; i >= 0; i--){
    res[counter[nums[i] - lower_bound] - 1] = nums[i];
    counter[nums[i] - lower_bound]--;
  }

  delete [] counter;
}


void CountingSortKeyed(int *nums, int *res, int length, int lower_bound, int upper_bound,
                  std::function<int(int)GetKey> get_key){
  int size = upper_bound - lower_bound + 1;
  int *counter = new int[size];

  // Initialize  
  for(int i = 0; i < size; i++){
    counter[i] = 0;
  }

  // count  
  for(int i = 0; i < length; i++){
    counter[get_key(nums[i]) - lower_bound]++;
  }

  // Use span to compute index
  for(int i = 1; i < size; i++){
    counter[i] += counter[i-1];
  }

  // Write the result to res
  for(int i = length - 1; i >= 0; i--){
    res[counter[get_key(nums[i]) - lower_bound] - 1] = nums[i];
    counter[get_key(nums[i]) - lower_bound]--;
  }

  delete [] counter;
}