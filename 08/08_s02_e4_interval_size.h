#pragma once

// The buffer should have size upper_bound - lower_bound + 1
void preprocess(int *nums, int *buffer, int lower_bound, int upper_bound, int length){
  for(int i = 0; i < upper_bound - lower_bound + 1; i++) buffer[i] = 0;

  // count
  for(int i = 0; i < length; i++){
    buffer[nums[i] - lower_bound]++;
  }

  // reduce
  for(int i = 1; i < upper_bound - lower_bound + 1; i++)
    buffer[i] += buffer[i-1];
}

int naive_query(int *nums, int start, int end, int length){
  int counter = 0;
  
  for(int i = 0; i < length; i++)
    if(nums[i] >= start && nums[i] <= end)
      counter++;

  return counter;
}

int processed_query(int *buffer, int lower_bound, int start, int end){
  int counter = buffer[end-lower_bound];
  if(start != lower_bound)
    counter -= buffer[start-lower_bound-1];

  return counter;
}