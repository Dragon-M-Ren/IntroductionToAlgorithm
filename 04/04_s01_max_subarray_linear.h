#pragma once

#include "04_s01_max_subarray_ds.h"

ms_ret max_subarray_linear(const int *nums, int length){
  // Initialization, set the first element to be max
  int max_start = 0, max_end = 0;
  int max_sum = nums[0];
  ms_ret ret;
  
  // Set start to 0, and sum to 0
  // Then the first element will be add to cur_sum before
  // it is compared with max_sum
  int cur_start = 0;
  int cur_sum = 0;

  for(int i = 0; i < length; i++){
    cur_sum += nums[i];
    
    // Get a larger sum, update the result
    if(cur_sum > max_sum){
      max_sum = cur_sum;
      max_start = cur_start;
      max_end = i;
    }
    // If the cur_sum < 0, reset
    if(cur_sum < 0){
      cur_sum = 0;
      cur_start = i+1;
    }
  }

  ret.start = max_start;
  ret.end = max_end;
  ret.sum = max_sum;

  return ret;
}
